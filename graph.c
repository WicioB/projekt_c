#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers/graph.h"
#define MAX_VERTICLES 10000
#define MAX_EDGES 100000
Graph* create_graph()
{
    Graph *g = malloc(sizeof(Graph));
    g->edges = malloc(MAX_EDGES * sizeof(Edge));
    g->vertices = malloc(MAX_VERTICLES * sizeof(Vertex));
    g->number_of_edges=0;
    g->number_of_vertices=0;
    return g;
}
void free_graph(Graph *g)
{
    free(g->edges);
    free(g->vertices);
    free(g);
}