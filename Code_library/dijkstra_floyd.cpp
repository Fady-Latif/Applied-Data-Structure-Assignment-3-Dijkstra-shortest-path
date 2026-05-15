/********************************************************************************
* WARNING: Please do not remove or modify this comment block.
 *
 * Student Information:
 * Name: Fady Latif
 * Student ID: 900241677
 * Section Number: 2
 *
 * Instructions:
 * - Fill out your name, student ID, and section number above.
 * - This information is mandatory for the submission of your assignment.
 * - Do not modify this file beyond the specified tasks and guidelines.
 *
 ********************************************************************************/

#include "dijkstra.h"
#include "floyd.h"
#include "graph.h"
#include <vector>
#include <queue>

using namespace std;

vector<int> dijkstra(int src) {
    vector<int> dist(n, 1e9);

  
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

      
        if (d > dist[u]) continue;

        for (auto [v, w] : adjList[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

vector<vector<int>> repeatedDijkstra() {
    vector<vector<int>> all(n, vector<int>(n));

    for (int i = 0; i < n; i++)
        all[i] = dijkstra(i);

    return all;
}

vector<vector<int>> floydWarshall() {
    vector<vector<int>> dist = adjMatrix;

    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (dist[i][k] < 1e9 && dist[k][j] < 1e9)
                    if (dist[i][k] + dist[k][j] < dist[i][j])
                        dist[i][j] = dist[i][k] + dist[k][j];

    return dist;
}
