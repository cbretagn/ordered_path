#ifndef ORDERED_PATH_H
# define ORDERED_PATH_H

# define EAST 'E'
# define WEST 'W'
# define SOUTH 'S'
# define NORTH 'N'

# define NUMERIC_BUFFER 12

typedef struct s_map {
    int *nodes;
    int width;
    int height;
    int size;
    int current;
    int distance;
    char move;
    int next;
    char *seen_nodes;
    char *path;
}   t_map;

t_map *t_map_init(int width, int height);
void t_map_free(t_map *map);
void t_map_display(t_map *map);
int t_map_get_index_min(t_map *map);

t_map *parse_input();
void find_path(t_map *map);

#endif