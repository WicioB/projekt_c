#ifndef GRAPH_H
#define GRAPH_H
#define WIDTH 10
#define HEIGHT 10
typedef struct {
    int id;
    double x,y,dx,dy;
}Vertex;

typedef struct{
    int x,y;
    double weight;
}Edge;

typedef struct{
    Vertex *vertices;
    Edge *edges;
    int number_of_vertices;
    int number_of_edges;
} Graph;

Graph* create_graph();
void free_graph(Graph *g);
int load_file(Graph *g, char *file);
void save_file(Graph *g, char *file, char *filetype);
#endif  