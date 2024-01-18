#include "monty.h"

/**
 * ft_substr - gets a substring
 * @s: the string
 * @start: the start index
 * @len: the length of the substring
 * Return: the substring
 */
char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char			*dst;
	size_t			slen;
	size_t			i;
	size_t			j;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	i = 0;
	if (!len || !slen || start >= slen)
	{
		dst = (char *)malloc(sizeof(char));
		dst[0] = '\0';
		return (dst);
	}
	while (i < len && s[i + start] != '\0')
		i++;
	dst = (char *)malloc((i + 1));
	if (!dst)
		return (NULL);
	j = 0;
	while (j < i)
		dst[j++] = s[start++];
	dst[j] = '\0';
	return (dst);
}

/**
 * count_words - counts the number of words in a string
 * @str: the string to count
 * @c: the delimiter
 * Return: the number of words
 */
static	size_t	count_words(char *str, char c)
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
char	**split(char *s, char c)
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
