#include "headers/algorithm.h"
#include <math.h>
double vector_length(double a, double b)
{
    return sqrt((a*a) + (b*b));
}
void fruchterman(Graph *g, int count)
{
    double area = WIDTH * HEIGHT;
    double n = sqrt(area / g->number_of_vertices);
    double t = WIDTH / 10;
    for(int i =0; i < count;i++)
    {
        for(int j=0; j<g->number_of_vertices;j++)
        {
            Vertex *v = &g->vertices[j];
            v->dx = 0;
            v->dy = 0;
            for(int k=0;k< g->number_of_vertices;k++)
            {
                if(j !=k)
                {
                    Vertex *v2 = &g->vertices[k];
                    double dx = v->x - v2->x;
                    double dy = v->y - v2->y;
                    double distance = vector_length(dx, dy);
                    if(distance > 0)
                    {
                        double pom = (n*n) / distance;
                        v->dx +=(dx/distance) * pom;
                        v->dy +=(dy/distance) * pom;
                    }
                }
            }
        }
        for(int i=0;i<g->number_of_edges;i++)
        {
            Vertex *x = &g->vertices[g->edges[i].x];
            Vertex *y = &g->vertices[g->edges[i].y];
            double dx = x->x - y->x;
            double dy = x->y - y->y;
            double distance = vector_length(dx, dy);
            if(distance > 0)
            {
                double pom = (distance * distance) / n;
                x->dx -= (dx / distance) * pom;
                x->dy -=(dy/distance);
                y->dx+=(dx/distance)*pom;
                y->dy+=(dy/distance) * pom;
            }
        }
        for(int i=0; i< g->number_of_edges;i++)
        {
            Vertex *v = &g->vertices[i];
            double distance = vector_length(v->dx, v->dy);
            if(distance > 0)
            {
                double limited = fmin(distance, t);
                v->x += (v->dx / distance) * limited;
                v->y += (v->dy / distance) * limited;
                v->x = fmin(WIDTH / 2.0, fmax(-WIDTH / 2.0, v->x));
                v->y = fmin(HEIGHT / 2.0, fmax(-HEIGHT / 2.0, v->y));
            }
        }
        t*=0.95;
    }
}