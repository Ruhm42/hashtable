/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cost <rda-cost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/28 13:50:28 by rda-cost          #+#    #+#             */
/*   Updated: 2015/06/05 15:46:40 by rda-cost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashtable.h"
#include "gnl.h"

void	hash_from_file(t_map *map, char *file)
{
	int		fd;
	char	*line;
	size_t	ct;

	if ((fd = open(file, O_RDONLY)) == -1)
		return ;
	hash_create_str_str(map, 50000);
	ct = 0;
	while (gnl(fd, &line))
	{
		hash_put(map, line, line);
		if (line)
			free(line);
		ct++;
	}
	if (line)
	{
		ct++;
		hash_put(map, line, line);
		free(line);
	}
	close(fd);
	printf("Number of entries: %lu\n", ct);
}

void	print_entry(t_map *map, char *key)
{
	printf("map[%s] = %s\n", key, hash_get(map, key));
}

int		main(int argc, char **argv)
{
	t_map	map;

	if (argc == 1)
	{
		hash_create_str_str(&map, 150000);
		hash_put(&map, "test", "empty");
		hash_print(&map);
		printf("map[%s] = %s\n", "test", hash_get(&map, "test"));
		hash_del(&map, "test");
		printf("map[%s] = %s\n", "test", hash_get(&map, "test"));
		hash_put(&map, "test", "empty");
		printf("map[%s] = %s\n", "test", hash_get(&map, "test"));
		hash_update(&map, "test", "not anymore");
		printf("map[%s] = %s\n", "test", hash_get(&map, "test"));
		return (0);
	}
	hash_from_file(&map, argv[1]);
	hash_print(&map);
	print_entry(&map, "test");
	print_entry(&map, "shetlands");
	print_entry(&map, "accentuasses");
	print_entry(&map, "ennoblies");
	print_entry(&map, "rebaissaient");
	print_entry(&map, "taraudassent");
	return (0);
}
