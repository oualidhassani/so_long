/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   implementation3_tools.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohassani <ohassani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 23:56:18 by ohassani          #+#    #+#             */
/*   Updated: 2024/04/26 00:02:00 by ohassani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**freearray(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

static char	**write_to_arr(char const *s, char **arr, char *tmp_str, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (s[0] != c)
	{
		arr[j] = ft_strdup(&tmp_str[0]);
		if (!arr[j])
			return (freearray(arr));
		j++;
	}
	while (s[i] != '\0')
	{
		if ((s[i] == c) && (s[i + 1] != c) && (s[i + 1] != '\0'))
		{
			arr[j] = ft_strdup(&tmp_str[i + 1]);
			if (!arr[j])
				return (freearray(arr));
			j++;
		}
		i++;
	}
	arr[j] = 0;
	return (arr);
}

int	get_size(char const *s, char *tmp_str, char c)
{
	int		i;
	size_t	size;

	i = 0;
	size = 0;
	while (s[i] != '\0')
	{
		if ((s[i] != c) && ((s[i + 1] == c) || (s[i + 1] == '\0')))
		{
			size++;
			tmp_str[i + 1] = '\0';
		}
		i++;
	}
	return (size);
}

char	**ft_split(char const *s, char c)
{
	char	*tmp_str;
	char	**arr;
	int		size;

	size = 0;
	if (!s)
		return (NULL);
	tmp_str = ft_strdup(s);
	if (!tmp_str)
		return (0);
	size = get_size(s, tmp_str, c);
	arr = (char **)malloc(sizeof(char *) * (size + 1));
	if (!arr)
	{
		free(tmp_str);
		return (NULL);
	}
	if (size == 0)
		arr[0] = NULL;
	else
		arr = write_to_arr(s, arr, tmp_str, c);
	free(tmp_str);
	return (arr);
}

char	*ft_strjoin1(char *s1, char const *s2)
{
	size_t	i;
	size_t	len1;
	size_t	len2;
	size_t	j;
	char	*concatenated;

	i = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	concatenated = (char *)malloc((len1 + len2) * sizeof(char) + 1);
	if (concatenated == NULL)
		return (NULL);
	while (s1 && len1 > i)
	{
		concatenated[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j])
		concatenated[i++] = s2[j++];
	if (s1)
		free(s1);
	concatenated[len1 + len2] = '\0';
	return (concatenated);
}
