#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers/graph.h"
#define MAX_VERTICLES 10000
#define MAX_EDGES 10000
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
int new_edge(Graph *g, int id)
{
    for(int i=0;i<g->number_of_vertices;i++)
    {
        if(g->vertices[i].id == id) return i;
    }
    g->vertices[g->number_of_vertices].id = id;
    g->vertices[g->number_of_vertices].x = (double) (rand() % WIDTH);
    g->vertices[g->number_of_vertices].y = (double) (rand() % HEIGHT);
    return g->number_of_vertices++;
}
int load_file(Graph *g, char *file)
{
    
}