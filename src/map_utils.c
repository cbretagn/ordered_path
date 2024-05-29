#include "../ordered_path.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


t_map *t_map_init(int width, int height){
    t_map *map = NULL;
    int map_size = width * height;

    if (!(map = (t_map *)malloc(sizeof(t_map)))){
        exit(-2);
    }
    if (!(map->nodes = (int *)malloc(sizeof(int) * map_size))){
        exit(-2);
    }
    if (!(map->seen_nodes = (char *)malloc(sizeof(char) * map_size))){
        exit(-2);
    }
    memset(map->seen_nodes, '\0', map_size);
    if (!(map->path = (char *)malloc(sizeof(char) * (map_size + 1)))){
        exit(-2);
    }
    memset(map->path, '\0', map_size + 1);
    
    map->width = width;
    map->height = height;
    map->size = map_size;

    return map;
}

void t_map_free(t_map *map){
    free(map->nodes);
    map->nodes = NULL;
    free(map->seen_nodes);
    map->seen_nodes = NULL;
    free(map->path);
    map->path = NULL;
    free(map);
    map = NULL;
}

void t_map_display(t_map *map){
    for (int i = 0; i < map->size; i++){
        if ((i + 1) % map->width == 0) {
            printf("%d\n", map->nodes[i]);
        }
        else {
            printf("%d ", map->nodes[i]);
        }
    };
}

int t_map_get_index_min(t_map * map){
    int min = map->nodes[0];
    int index = 0;

    for (int i = 0; i < map->size; i++){
        if (map->nodes[i] < min){
            min = map->nodes[i];
            index = i;
        }
    }
    return index;
}