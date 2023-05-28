// Bellman Ford
#include <stdio.h>
#include <limits.h>

int dist[1000];
int edges[1000][3];

void BellmanFord(int n, int m, int start_node)
{
  int i, j;
  int source, destination, weight;
  for (i = 0; i < n; i++)
  {
    if (i == start_node)
    {
      dist[i] = 0;
    }
    else
    {
      dist[i] = INT_MAX;
    }
  }

  for (i = 1; i < n; i++)
  {
    for (j = 0; j < m; j++)
    {
      source = edges[j][0];
      destination = edges[j][1];
      weight = edges[j][2];

      if (dist[source] != INT_MAX && dist[source] + weight < dist[destination])
      {
        dist[destination] = dist[source] + weight;
      }
    }
  }

  for (i = 0; i < m; i++)
  {
    source = edges[i][0];
    destination = edges[i][1];
    weight = edges[i][2];

    if (dist[source] != INT_MAX && dist[source] + weight < dist[destination])
    {
      printf("Graph contains negative-weight cycle\n");
      return;
    }
  }
  for (i = 0; i < n; i++)
  {
    printf("Shortest distance from node %d to %d is %d\n", start_node, i, dist[i]);
  }
}

int main()
{
  int n, m, i, start_node;
  printf("Enter number of nodes, edges and starting node: ");
  scanf("%d %d %d", &n, &m, &start_node);

  printf("Enter the edges in the format <source> <destination> <weight>:\n");
  for (i = 0; i < m; i++)
  {
    scanf("%d %d %d", &edges[i][0], &edges[i][1], &edges[i][2]);
  }

  BellmanFord(n, m, start_node);
}