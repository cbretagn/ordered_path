#include "../ordered_path.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

static char is_numeric(char c){
    return (isdigit(c) || c == '-');
}

static void parser_exit(char *line, t_map *map){
    free(line);
    t_map_free(map);
    puts("Parser error\n");

    exit(-1);
}

static int read_next_int(char *line, int *index, int max){
    char buffer[NUMERIC_BUFFER];
    int i = *index;
    int j = 0;

    while (i < max && !(is_numeric(line[i]))){
        i++;
    }
    
    if (!(is_numeric(line[i]))){
        parser_exit(line, (t_map *)NULL);
    }
    if (line[i] == '-' && !(isdigit(line[i + 1]))){
        parser_exit(line, NULL);
    }
    
    while (i < max && is_numeric(line[i])){
        buffer[j] = line[i];
        i++;
        j++;
    }
    buffer[j]='\0';

    *index = i;
    return(atoi(buffer));
}

static void fill_map(t_map *map){
    char *line = NULL;
    size_t size = 0;
    int index = 0;
    int nodes_count = 0;
    int read;

    for (int i = 0; i < map->height && nodes_count < map->size; i++){
        if ((read = getline(&line, &size, stdin)) < 0){
            parser_exit(line, map);
        }
        index = 0;
        for (int j = 0; j < map->width && nodes_count < map->size; j++){
            map->nodes[nodes_count] = read_next_int(line, &index, read);
            nodes_count++;
        }
        free(line);
        line = NULL;
    }
}

static t_map *parse_dimension_line(char *line, int read){
    int index = 0;
    t_map *map = NULL;
    
    int width = read_next_int(line, &index, read);
    int height = read_next_int(line, &index, read);

    if (width > 0 && height > 0){
        map = t_map_init(width, height);
    }
    return map;
}

t_map *parse_input(){
    t_map *map = NULL;
    char *line = NULL;
    size_t size = 0;
    int read;

    if ((read = getline(&line, &size, stdin)) < 0){
        free(line);
        exit(-1);
    }
    map = parse_dimension_line(line, read);
    free(line);
    line = NULL;
    
    if (map == NULL){
        parser_exit(NULL, NULL);
    }

    fill_map(map);
    return map;
}