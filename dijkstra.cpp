#include <stdio.h>
#include <iostream>
#include <string> 
using namespace std; 
#define GRAPHSIZE 2048
#define INFINITY GRAPHSIZE*GRAPHSIZE
#define MAX(a, b) ((a > b) ? (a) : (b))
 
int e; /* The number of nonzero edges in the graph */
int f; /* Source vertex */
int t; /* number of edges */
int n; /* The number of nodes in the graph */
long dist[GRAPHSIZE][GRAPHSIZE]; /* dist[i][j] is the distance between node i and j; or 0 if there is no direct connection */
long d[GRAPHSIZE]; /* d[i] is the length of the shortest path between the source (s) and node i */
void printD() { 
    int i; 
  for (i = 1; i <= n; ++i) 

        cout << d[i] << ": "<< f<< " -> "<< i-1 <<" -> " << i << endl; //just for reference until i finish  
  }
 
void dijkstra(int s) {
    int i, k, mini;
    int visited[GRAPHSIZE];
  
  
 
    for (i = 1; i <= n; ++i) {
        d[i] = INFINITY;
        visited[i] = 0; /* the i-th element has not yet been visited */
    }
 
    d[s] = 0;
 
    for (k = 1; k <= n; ++k) {
        mini = -1;
        for (i = 1; i <= n; ++i)
            if (!visited[i] && ((mini == -1) || (d[i] < d[mini])))
                mini = i;
 
        visited[mini] = 1;
 
        for (i = 1; i <= n; ++i)
            if (dist[mini][i])
                if (d[mini] + dist[mini][i] < d[i]) 
                    d[i] = d[mini] + dist[mini][i];
    }
}
 
int main(int argc, char *argv[]) {
    int i, j;
    int u, v, w;


 
    FILE *fin = fopen("inputFile.txt", "r");
    fscanf(fin, "%d", &f);
    fscanf(fin, "%d%d", &t, &e);
    for (i = 0; i < e; ++i)
        for (j = 0; j < e; ++j)
            dist[i][j] = 0;
    n = -1;
    for (i = 0; i < e; ++i) {
        fscanf(fin, "%d%d%d", &u, &v, &w);
        dist[u][v] = w;
        n = MAX(u, MAX(v, n));
    }
    fclose(fin);
    dijkstra(1);
    printD();
    return 0;
}