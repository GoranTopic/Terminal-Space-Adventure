#ifndef GRAPH_H_
#define GRAPH_H_
#include <stdio.h>


typedef struct Graphrec* graph;

extern void graph_free(graph g);
extern int graph_add_edge (graph g, int vertice1, int vertice2, int is_bidirectonal);
extern graph graph_new(int vertices);
extern void graph_print(graph g);
extern int graph_search(graph g, char *str);

extern int graph_bfs(graph g, int source);
extern void graph_print_bfs(graph g);
#endif
