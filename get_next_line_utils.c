#include "monty.h"

/**
 * ft_strlen - gets the length of a string
 * @str: the string
 * Return: the length of the string
 */
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

/**
 * ft_strjoin - joins two strings
 * @s1: the first string
 * @s2: the second string
 * Return: the joined string
 */
char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		len, i, j;

	if (s1 == NULL)
	{
		s1 = malloc(1);
		s1[0] = '\0';
	}
	len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j])
		str[i++] = s1[j++];
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	return (str);
}

/**
 * ft_strchr - checks if a string contains a character
 * @str: the string
 * @c: the character
 * Return: 1 if the string contains the character, 0 otherwise
 */
int	ft_strchr(char *str, char c)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}
