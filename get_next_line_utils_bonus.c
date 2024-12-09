/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elerazo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:10:22 by elerazo-          #+#    #+#             */
/*   Updated: 2024/12/09 23:32:04 by elerazo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

void	*ft_clean(char **memory)
{
	if (memory && *memory)
	{
		free(*memory);
		*memory = NULL;
	}
	return (NULL);
}

size_t	ft_strlen(char	*str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != c && str[i] != '\0')
		i++;
	if (str[i] == c)
		return (str);
	else
		return (NULL);
}

char	*ft_strjoin(char *space, char *buffer)
{
	char	*new;
	int		j;
	int		i;

	if (space == NULL)
	{
		space = malloc(sizeof(char) + 1);
		if (!space)
			return (NULL);
		space[0] = '\0';
	}
	new = malloc(sizeof(char) * (ft_strlen(buffer) + ft_strlen(space) + 1));
	if (!new)
		return (ft_clean(&space));
	i = -1;
	while (space[++i])
		new[i] = space[i];
	j = 0;
	while (buffer[j])
		new[i++] = buffer[j++];
	new[i] = '\0';
	ft_clean(&space);
	return (new);
}
