// Algoritmo guloso de dijkstra, que retorna o caminho mínimo entre um vértice A e um destino B.. e também a menor distancia entre todos os vértices do grafo!!..
#include "dijkstra.h"

void dijkstra(int graph[V][V], int src)
{
     int dist[V];

     bool sptSet[V];

     for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

     dist[src] = 0;


     for (int count = 0; count < V-1; count++)
     {

       int u = minDistance(dist, sptSet);


       sptSet[u] = true;


       for (int v = 0; v < V; v++)


         if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                                       && dist[u]+graph[u][v] < dist[v])
            dist[v] = dist[u] + graph[u][v];
     }


     printSolution(dist, V);
}


int main()
{

   int graph[V][V] = {{0, 5, 0, 0, 0, 0, 0, 10, 0},
                      {3, 0, 7, 0, 0, 0, 0, 12, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 1},
                      {0, 0, 5, 0, 8, 15, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 5, 11, 13, 0, 5, 0, 0},
                      {0, 0, 0, 0, 0, 3, 0, 2, 7},
                      {11, 10, 0, 0, 0, 0, 4, 0, 5},
                      {0, 0, 1, 0, 0, 0, 8, 9, 0}
                     };

    dijkstra(graph, 0);

    return 0;
}
