# Ordered path

Naive algorithm which, given a table of int, finds a path
through the table to read the ints in order.

## How to run

`make all` to generate the executable

`./pathfinder < map` or `./pathfinder` and write on stdin.

## Tests

I didn't have time to write full-fledged tests but there's a
couple of maps in maps to try it out.
Expected format for a map is :

width heigh
value1 value2
value3 ...

## Algo

`./path_finder` writes the map to a char * and searches the smallest
value to take as a starting point.
From there it checks every possible direction (north, south, east, west)
and selects the closest one (value that is the closest to current) from
the legal moves. It marks the node as seen and keeps goins until all nodes
have been visited or there is no more legal moves.

Note : if the same number is present in multiple, the program might not take
the right path to terminate the map, as there is no backtracking implemented.