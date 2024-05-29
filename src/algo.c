#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../ordered_path.h"


static bool is_out_of_bonds(int index, int width, int map_size, char move){
    if (index < 0 || index >= map_size){
        return true;
    }
    if (move == EAST && index % width == 0){
        return true;
    }
    if (move == WEST && index % width == -1){
        return true;
    }
    return false;
}

static void check_direction(t_map *map, int add, char move){
    int candidate_next = map->current + add;

    
    if (is_out_of_bonds(candidate_next, map->width, map->size, move)){
        return;
    }
    if (map->nodes[candidate_next] < map->nodes[map->current]){
        return;
    }
    if (map->seen_nodes[candidate_next] == 1){
        return;
    }
    
    int candidate_distance = abs(map->nodes[candidate_next] - map->nodes[map->current]);
    if (map->distance < 0 || candidate_distance < map->distance) {
        map->distance = candidate_distance;
        map->move = move;
        map->next = candidate_next;
    }
}

static int get_next_node(t_map *map, int seen){
    map->distance = -1;
    map->move = 0;
    map->next = -1;

    check_direction(map, 1, EAST);
    check_direction(map, -1, WEST);
    check_direction(map, map->width, SOUTH);
    check_direction(map, (map->width * -1), NORTH);

    if (map->next < 0){
        return -1;
    }
    map->current = map->next;
    map->seen_nodes[map->current] = 1;
    map->path[seen] = map->move;
    return map->current;
}

void find_path(t_map *map){
    int current_node = t_map_get_index_min(map);
    map->current = current_node;
    printf("Starting on node of value %d\n", map->nodes[current_node]);

    int seen = 0;
    while (seen < map->size - 1){
        current_node = get_next_node(map, seen);
        if (current_node == -1){
            puts("This map is not solvable. Max path found :\n");
            break;
        }
        seen += 1;
    }
    puts(map->path);
}