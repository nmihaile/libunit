/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare_stdout.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmihaile <nmihaile@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 19:04:25 by nmihaile          #+#    #+#             */
/*   Updated: 2025/09/02 11:36:28 by nmihaile         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

static int	redirect_stdout(int *pipe_fds, int *saved_stdout)
{
	*saved_stdout = dup(STDOUT_FILENO);
	if (*saved_stdout == -1)
		return (-1);
	if (pipe(pipe_fds) == -1)
	{
		close(*saved_stdout);
		return (-1);
	}
	if (dup2(pipe_fds[1], STDOUT_FILENO) == -1)
	{
		close(pipe_fds[0]);
		close(pipe_fds[1]);
		close(*saved_stdout);
		return (-1);
	}
	return (0);
}

static int	restore_stdout(int saved_stdout, int *pipe_fds)
{
	if (dup2(saved_stdout, STDOUT_FILENO) == -1)
	{
		close(pipe_fds[0]);
		close(pipe_fds[1]);
		close(saved_stdout);
		return (-1);
	}
	close(saved_stdout);
	return (0);
}

// cl -> Cap Len
static char	*capture_stdout(int fd)
{
	size_t	cl[2];
	ssize_t	bytes_read;
	char	*buf_tmp[2];

	memcpy(cl, (size_t[]){1024, 0}, sizeof(cl));
	buf_tmp[0] = malloc(cl[0]);
	if (buf_tmp[0] == NULL)
		return (NULL);
	while (42)
	{
		if (cl[1] + 512 > cl[0])
		{
			cl[0] *= 2;
			buf_tmp[1] = realloc(buf_tmp[0], cl[0]);
			if (buf_tmp[1] == NULL)
				return (free(buf_tmp[0]), NULL);
			buf_tmp[0] = buf_tmp[1];
		}
		bytes_read = read(fd, buf_tmp[0] + cl[1], cl[0] - cl[1] - 1);
		if (bytes_read <= 0)
			break ;
		cl[1] += bytes_read;
	}
	buf_tmp[0][cl[1]] = '\0';
	return (buf_tmp[0]);
}

int	compare_stdout(void (*f)(void), char *expected)
{
	int		saved_stdout;
	int		pipe_fds[2];
	char	*buff;
	int		result;

	if (redirect_stdout(pipe_fds, &saved_stdout) == -1)
		return (-1);
	f();
	fflush(stdout);
	if (restore_stdout(saved_stdout, pipe_fds) == -1)
		return (-1);
	close(pipe_fds[1]);
	buff = capture_stdout(pipe_fds[0]);
	close(pipe_fds[0]);
	if (buff == NULL)
		return (-1);
	if (expected == NULL && buff[0] == '\0')
		return (free(buff), 0);
	else if (expected == NULL && buff[0] != '\0')
		return (free(buff), -1);
	result = strcmp(buff, expected);
	free(buff);
	return (result);
}
