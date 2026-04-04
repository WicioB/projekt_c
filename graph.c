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
    g->vertices[g->number_of_vertices].x = (double)rand() /(double) RAND_MAX;
    g->vertices[g->number_of_vertices].y = (double)rand() / RAND_MAX;
    return g->number_of_vertices++;
}
int load_file(Graph *g, char *file)
{
    FILE *in = fopen(file, "r");
    if(!in)
    {
        return EXIT_FAILURE;
    }
    char name[100];
    int a,b;
    double weight;
    while(fscanf(in, "%s %d %d %lf", name, &a, &b, &weight)!=EOF)
    {
        int a_id = new_edge(g, a);
        int b_id = new_edge(g, b);
        g->edges[g->number_of_edges].x = a_id;
        g->edges[g->number_of_edges].y = b_id;
        g->edges[g->number_of_edges++].weight = weight;
    }
    fclose(in);
    return 0;
}
void save_file(Graph *g, char *file, char *filetype)
{
    if(strcmp(filetype, "txt")==0)
    {
        FILE *out = fopen(file, "w");
        for(int i=0;i< g->number_of_vertices;i++)
        {
            fprintf(out, "%d %.2f %.2f \n", g->vertices[i].id, g->vertices[i].x, g->vertices[i].y);
        }
        fclose(out);
    }else
    {
        FILE *out = fopen(file, "wb");
        for(int i=0; i<g->number_of_vertices; i++)
        {
            fwrite(&g->vertices[i].id, sizeof(int), 1, out);
            fwrite(&g->vertices[i].x, sizeof(double), 1, out);
            fwrite(&g->vertices[i].y, sizeof(double), 1, out);
        }
        fclose(out);
    }
}