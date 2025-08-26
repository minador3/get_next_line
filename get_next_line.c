/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwei <mwei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 15:18:02 by mwei              #+#    #+#             */
/*   Updated: 2025/08/26 17:08:16 by mwei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_until_newline(int fd, char *unread_data)
{
	char	buffer[BUFFER_SIZE + 1];
	int		bytes_read;
	char	*temp;

	bytes_read = 1;
	while (!ft_strchr(unread_data, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(unread_data);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(unread_data, buffer);
		free(unread_data);
		unread_data = temp;
	}
	return (unread_data);
}

static char	*extract_line(char *unread_data)
{
	size_t	line_len;
	char	*line;

	line_len = 0;
	if (!unread_data || !*unread_data)
		return (NULL);
	while (unread_data[line_len] && unread_data[line_len] != '\n')
		line_len++;
	if (unread_data[line_len] == '\n')
		line_len++;
	line = ft_substr(unread_data, 0, line_len);
	return (line);
}

static char	*update_unread_data(char *unread_data)
{
	size_t	i;
	char	*new_data;

	i = 0;
	while (unread_data[i] && unread_data[i] != '\n')
		i++;
	if (!unread_data[i])
	{
		free(unread_data);
		unread_data = NULL;
		return (NULL);
	}
	new_data = ft_substr(unread_data, i + 1, ft_strlen(unread_data) - i - 1);
	free(unread_data);
	unread_data = NULL;
	return (new_data);
}

char	*get_next_line(int fd)
{
	static char	*unread_data;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= INT_MAX)
		return (NULL);
	unread_data = read_until_newline(fd, unread_data);
	if (!unread_data)
		return (NULL);
	line = extract_line(unread_data);
	unread_data = update_unread_data(unread_data);
	return (line);
}
