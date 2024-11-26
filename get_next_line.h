/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elerazo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:06:15 by elerazo-          #+#    #+#             */
/*   Updated: 2024/11/26 16:45:38 by elerazo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
# ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

//BIBLIOTECA
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
 #include <fcntl.h>

//PROTOTIPO
char *get_next_line(int fd);
char *ft_read(int fd, char *space);


#endif
