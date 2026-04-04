#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers/algorithm.h"
#include "headers/graph.h"
#include <time.h>
int main(int argc, char *argv[]) 
{
    char *input;
    char *output ="out";
    char *format ="txt";
    int number = 0;
    for (int i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "-n") == 0 && i + 1 < argc) 
        {
            input = argv[++i];
        } 
        else if (strcmp(argv[i], "-a") == 0 && i + 1 < argc) 
        {
            number = atoi(argv[++i]);
        } 
        else if (strcmp(argv[i], "-o") == 0 && i + 1 < argc)
        {
            output = argv[++i];
        } 
        else if (strcmp(argv[i], "-f") == 0 && i + 1 < argc) 
        {
            format = argv[++i];
        }
    }
    if (input == NULL || number == 0) 
    {
        printf("Zla liczba argumentow.\n");
        return EXIT_FAILURE;
    }
    srand(time(NULL));
    Graph *g = create_graph();
    if (load_file(g, input) != 0) 
    {
        printf("Zly plik %s\n", input);
        return 1;
    }
    if (number == 1) 
    {
        fruchterman(g, 500);
    } else 
    {
        tutte(g, 500);
    }
    save_file(g, output, format);
    free_graph(g);
}