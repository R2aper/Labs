// Вариант 13
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define V 10
#define INF INT_MAX

int *dijkstra(int graph[V][V], int src) {
  int *dist = (int *)calloc(sizeof(int), V);
  bool visited[V];

  // Initilizing
  for (int i = 0; i < V; i++) {
    dist[i] = INF;
    visited[i] = false;
  }
  dist[src] = 0;

  for (int count = 0; count < V - 1; count++) {
    // Выбираем вершину с минимальным расстоянием (из непосещенных)
    int u = -1;
    int min_dist = INF;
    for (int v = 0; v < V; v++) {
      if (!visited[v] && dist[v] < min_dist) {
        min_dist = dist[v];
        u = v;
      }
    }

    if (u == -1)
      break;
    visited[u] = true;

    for (int v = 0; v < V; v++) {
      if (!visited[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
        dist[v] = dist[u] + graph[u][v];
      }
    }
  }
  return dist;
}

int main() {
  int graph[V][V] = {
      // X1 X2 X3 X4 X5 X6 X7 X8 X9 X10
      {0, 1, 0, 10, 0, 0, 0, 3, 0, 0},  // X1
      {1, 0, 10, 10, 0, 0, 0, 0, 0, 0}, // X2
      {0, 10, 0, 1, 0, 0, 0, 0, 0, 5},  // X3
      {10, 10, 1, 0, 4, 4, 0, 0, 0, 0}, // X4
      {0, 0, 2, 4, 0, 0, 5, 0, 0, 2},   // X5
      {6, 0, 0, 4, 10, 0, 3, 2, 0, 0},  // X6
      {0, 0, 0, 1, 5, 3, 0, 0, 3, 8},   // X7
      {3, 0, 0, 0, 0, 2, 6, 0, 8, 0},   // X8
      {0, 0, 0, 0, 0, 0, 3, 8, 0, 5},   // X9
      {0, 0, 5, 0, 0, 0, 8, 0, 5, 0}    // 10
  };
  int s = 0, t = 10;
  int *dist = dijkstra(graph, s);

  printf("Вершина \t Расстояние от источника\n");
  for (int i = 0; i < V; i++) {
    printf("X%d \t\t %d\n", i + 1, dist[i]);
  }

  free(dist);
  return 0;
}