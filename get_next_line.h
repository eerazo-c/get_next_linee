/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elerazo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:06:15 by elerazo-          #+#    #+#             */
/*   Updated: 2024/12/05 15:26:55 by elerazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

//BIBLIOTECA
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

//FUNCIONES PROTOTIPO
char	*get_next_line(int fd);
char	*up_date(char	*space);
char	*extract_line(char *space);
char	*ft_read(int fd, char *space);
//funciones utils
size_t	ft_strlen(char *string);
void	*ft_clean(char **alloc_memory);
char	*ft_strchr(char *string, int c);
char	*ft_strjoin(char *space, char *buffer);

#endif
