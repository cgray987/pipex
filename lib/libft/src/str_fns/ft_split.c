/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgray <cgray@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:23:43 by cgray             #+#    #+#             */
/*   Updated: 2024/01/30 16:35:07 by cgray            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* counts number of strings to create from 's'
delineated by 'c'*/
static size_t	count_strings(const char *s, char c)
{
	size_t	count;
	int		jump;

	count = 0;
	jump = 0;
	while (*s)
	{
		if (*s == c)
			jump = 0;
		else if (jump == 0)
		{
			jump = 1;
			count++;
		}
		s++;
	}
	return (count);
}

/*counts length of string 's' to next delin 'c' needed for array*/
static size_t	find_delin(const char *s, char c)
{
	size_t	length;

	length = 0;
	while (*s && *s != c)
	{
		length++;
		s++;
	}
	return (length);
}

/*Returns array of strings split from 's' delineated by 'c'*/
char	**ft_split(char const *s, char c)
{
	char	**strings;
	size_t	string_len;
	size_t	i;

	strings = (char **)malloc((count_strings(s, c) + 1) * sizeof(char *));
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			string_len = find_delin(s, c);
			strings[i] = (char *)malloc((string_len + 1) * sizeof(char));
			if (!strings[i])
				return (NULL);
			ft_strlcpy(strings[i], s, string_len + 1);
			strings[i][string_len] = '\0';
			s += string_len;
			i++;
		}
		else
			s++;
	}
	strings[i] = NULL;
	return (strings);
}
// #include <stdio.h>
// int	main(void)
// {
// 	int		i;
// 	char	**split;
// 	i = 0;
// 	split = ft_split("lorem ipsum dolor sit amet,
// consectetur adipiscing elit. Sed non risus. Suspendisse", ' ');
// 	while (split[i] != NULL)
// 	{
// 		printf("%s\n", split[i]);
// 		i++;
// 	}
// 	i = 0;
// 	while (split[i] != NULL)
// 	{
// 		free(split[i]);
// 		i++;
// 	}
// 	free(split);
// }
