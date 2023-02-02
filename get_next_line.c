/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 11:39:58 by hsebille          #+#    #+#             */
/*   Updated: 2023/01/26 13:36:17 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* - null_stash
 * This function in meant to make the function "read_and_stash" less charged.
 * The principle is to handle when stash is equal to null. 
 * <- (at the very first call of the "get_next_line" function).
 * Its return value is either the stash string unchanged 
 * <- or the stash string malloc'd and filled with read. */

static char	*null_stash(char *stash, int by_read, int fd)
{
	if (stash != NULL)
		return (stash);
	stash = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (stash == NULL)
		return (NULL);
	by_read = read(fd, stash, BUFFER_SIZE);
	if (by_read < 0)
	{
		free(stash);
		return (NULL);
	}
	stash[by_read] = '\0';
	return (stash);
}

/* - read_and_stash
 * This function is meant to... read and then stash (suprinsing?).
 * The content of the file is first stored in the buffer,
 * <- then stored in the stash using the function "strjoin".
 * Its return value in the stash which contains the 
 * <- very first line of the file according to the buffer_size. */

static char	*read_and_stash(char *stash, int by_read, int fd)
{
	char	*buffer;

	if (by_read <= 0 || fd < 0)
		return (NULL);
	stash = null_stash(stash, by_read, fd);
	while (!ft_strchr(stash, '\n') && by_read > 0)
	{
		buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
		if (buffer == NULL)
			return (NULL);
		by_read = read(fd, buffer, BUFFER_SIZE);
		if (by_read < 0)
			free(buffer);
		if (by_read < 0)
			return (NULL);
		buffer[by_read] = '\0';
		stash = ft_strjoin(stash, buffer);
		free(buffer);
	}
	if (stash[0] == '\0')
	{
		free(stash);
		return (NULL);
	}	
	return (stash);
}

/* - extract_line
 * This function is meant to... 
 * <- extract the line that we want from the stash (yes, that simple).
 * It uses the function "substr" to get the exact wanted string.
 * Its return value is the line wanted (terminated by a '\n'). */

static char	*extract_line(char *stash, char *line)
{
	int		i;

	if (stash == NULL)
		return (NULL);
	i = 0;
	while (stash[i] != '\n' && stash[i])
		i++;
	line = ft_substr(stash, 0, i + 1);
	return (line);
}

/* - clean_stash
 * This function is meant to... clean the stash (yes, actually).
 * The former stash is cleaned and free. And the new_stash contains
 * <- the rest of the string that wasn't taken into the line.
 * It's return value is the new stash. */

static char	*clean_stash(char *stash)
{
	int			i;
	int			j;
	char		*new_stash;

	if (stash == NULL)
		return (NULL);
	new_stash = NULL;
	i = 0;
	while (stash[i] != '\n' && stash[i])
		i++;
	if (stash[i])
		i++;
	j = i;
	while (stash[j])
		j++;
	new_stash = ft_substr(stash, i, j);
	free(stash);
	if (j == i + 1)
		stash = NULL;
	return (new_stash);
}

/* - get_next_line
 * This is our main function (I mean, not literally but... nvm).
 * Its purpose is to call the three functions that we've created
 * <- one after the other.
 * It's return value is the line that we wanted. */

char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	char		*line;
	int			by_read;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	by_read = 1;
	line = NULL;
	stash = read_and_stash(stash, by_read, fd);
	line = extract_line(stash, line);
	stash = clean_stash(stash);
	return (line);
}
