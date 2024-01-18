#include "monty.h"

/**
 * get_first - gets the first line
 * @stat: the static variable
 * Return: the first line
 */
char	*get_first(char *stat)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!stat[i])
		return (NULL);
	while (stat[i] != '\n' && stat[i])
		i++;
	if (stat[i] == '\n')
		line = malloc(i + 2);
	else
		line = malloc(i + 1);
	if (!line)
		return (NULL);
	while (j < i)
	{
		line[j] = stat[j];
		j++;
	}
	if (stat[j] == '\n')
		line[j++] = '\n';
	line[j] = '\0';
	return (line);
}

/**
 * get_rest - gets the rest of the string
 * @stat: the static variable
 * Return: the rest of the string
 */
char	*get_rest(char *stat)
{
	int		j;
	int		i;
	char	*rest;

	j = 0;
	i = 0;
	while (stat && stat[i] && stat[i] != '\n')
		i++;
	if (stat[i] == '\0')
	{
		free(stat);
		return (NULL);
	}
	if (stat[i] == '\n')
		i++;
	rest = malloc(ft_strlen(stat) - i + 1);
	while (stat && stat[i])
		rest[j++] = stat[i++];
	rest[j] = '\0';
	free(stat);
	return (rest);
}

/**
 * readfd - reads a file descriptor
 * @fd: the file descriptor
 * @stat: the static variable
 * Return: the static variable
 */
char	*readfd(int fd, char *stat)
{
	int			reading_index;
	char		*buffer;

	reading_index = 1;
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (reading_index && ft_strchr(stat, '\n') == 0)
	{
		reading_index = read(fd, buffer, BUFFER_SIZE);
		if (reading_index < 0)
		{
			free(stat);
			free(buffer);
			return (NULL);
		}
		buffer[reading_index] = '\0';
		stat = ft_strjoin(stat, buffer);
	}
	free(buffer);
	return (stat);
}

/**
 * get_next_line - reads a file line by line
 * @fd: the file descriptor
 * Return: the line
 */
char	*get_next_line(int fd)
{
	char		*line;
	static char	*stat;

	stat = readfd(fd, stat);
	if (!stat)
		return (NULL);
	line = get_first(stat);
	stat = get_rest(stat);
	return (line);
}
