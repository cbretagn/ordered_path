#include "../ordered_path.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv){
    if (argc == 2 && !(strcmp(argv[1], "--help"))){
        puts("Expected format is :\nwidth height\nvalue1 value2 ...\nOutput: starting index value\nPath using north/east/west/south\n");
        return 0;
    }
    if (argc > 1){
	    puts("usage: path_finder < [file_name] or write to standard input\nuse --help for more infos.");
	    return 0;
    }

    t_map *map = parse_input();
    t_map_display(map);

    find_path(map);
    
    t_map_free(map);
    return 0;
}