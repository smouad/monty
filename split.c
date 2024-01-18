#include "monty.h"

/**
 * count_words - counts the number of words in a string
 * @str: the string to count
 * @c: the delimiter
 * Return: the number of words
 */
static	size_t	count_words(const char *str, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i] != '\0')
			count++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (count);
}

/**
 * split - splits a string into words
 * @s: the string to split
 * @c: the delimiter
 * Return: the array of words
 */
char	**split(char const *s, char c)
{
	char	**split;
	size_t	start;
	size_t	end;
	size_t	i;

	if (!s)
		return (NULL);
	split = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	start = 0;
	end = 0;
	i = -1;
	while (++i < count_words(s, c))
	{
		while (s[start] == c)
			start++;
		end = start;
		while (s[end] != c && s[end])
			end++;
		split[i] = ft_substr(s, start, (end - start));
		start = end;
	}
	split[i] = 0;
	return (split);
}
