/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofia <sofia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 12:01:32 by sade              #+#    #+#             */
/*   Updated: 2024/06/29 19:54:09 by sofia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void read_line(int fd, int height, t_map *data)
{
    char *line;
    int width;
    t_object obj;

    line = get_next_line(fd);
    if(!line)
    {
        close(fd);
        map_error(3, NULL);
    }
    width = 0;
    while(line[width] != '\n' && line[width])
    {
        if(width < data->map_width)
        {
            obj = get_objects(line[width]);
            if(obj)
               data->objects[data->map_width * height + width] = get_image(data->window, obj); 
            else
            {
                close(fd);
                map_error(6, NULL);
            }
        }
        width++;
    }
    if(width != data->map_width)
    {
        close(fd);
        map_error(4, line);
    }
    free(line);
}

t_object get_objects(const char obj)
{
    if(obj == 'C')
        return(COLLECTABLE);
    else if(obj == 'E')
        return(EXIT);    
    else if(obj == '1')
        return(WALL); 
    else if(obj == '0')
        return(FLOOR);
    else if(obj == 'P')
        return(PLAYER);
    else
        map_error(6, NULL);
    return(0);
}

void read_map(const char *file, t_map *data)
{
    int fd;
    int i;

    i = 0;
    fd = open_file(file);
    while(i < data->map_height)
    {
        read_line(fd, i, data);
        i++;
    }
    close(fd);
}

