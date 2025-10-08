/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwei <mwei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 15:43:21 by mwei              #+#    #+#             */
/*   Updated: 2025/10/03 20:13:23 by mwei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
// #include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>


// int main(void)
// {
//     int   fd;
//     char *str;

//     fd = open("txt", O_RDONLY);
//     if (fd == -1)
//         return (1);
//     while ((str = get_next_line(fd)) != NULL)
//     {
//         printf("%s", str);
//         free(str);
//     }
//     close(fd);
//     return (0);
// }

int main(void)
{
    int fd = open("txt", O_RDONLY);
    int fd1 = open("xtx", O_RDONLY);
    char *str;
    char *str1;

    if (fd < 0 || fd1 < 0)
        return (1);
    while (1)
    {
        str = get_next_line(fd);
        str1 = get_next_line(fd1);

        if (!str && !str1)
            break;
        if (str)
        {
            printf("str: %s", str);
            free(str);
        }
        if (str1)
        {
            printf("str1: %s", str1);
            free(str1);
        }
    }
    close(fd);
    close(fd1);
    return (0);
}
