/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaarich <akaarich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 22:15:20 by akaarich          #+#    #+#             */
/*   Updated: 2025/11/13 23:38:57 by akaarich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_and_store(char *buf,int fd)
{
	read(fd ,buf ,100);
	return buf;
}
int main ()
{
	char buf[100];
	int fd = open("txt.txt" ,O_RDONLY);
	printf("%s",get_and_store(buf,fd));
}