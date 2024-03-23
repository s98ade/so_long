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

int valid_file(char *argv)
{
    int i;

    i = 0;
    if (!argv)
        return (0);
    while (argv[i])
        ++i;
    i -= 1;
    if (argv[i] == 'r' && argv[i - 1] == 'e' && argv[i - 2] == 'b' && argv[i - 3] == '.')
        return (1);
    return (0);
}

int main(int argc, char **argv)
{
    t_data *data;

    if (argc != 2)
        return (write(2, "Error\n", 6));
    if (!valid_file(argv[1]))
        return (write(2, "Error\nMap file invalid\n", 23));
    data = init_map(argv[1]);
    if (!data)
        return (write(2, "Error\nMap invalid\n", 18));
    mlx_loop(data);
    free_data(data);
}