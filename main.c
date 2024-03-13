/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sade <sade@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 20:57:57 by sade              #+#    #+#             */
/*   Updated: 2024/03/01 20:57:57 by sade             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
    t_data  *data;

    if (argc != 2)
        return(write(2, "Error\n", 6));
    if (!valid_file(argv[1]))
        return(write(2, "Error\nMap file invalid\n", 23));
    if (valid_map(&data))
    {
        data->map = read_map(argv[1]);
        init_map(&data);
    }
}