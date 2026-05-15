/********************************************************************************
* WARNING: Please do not remove or modify this comment block.
 *
 * Student Information:
 * Name: ______________________________________
 * Student ID: __________________________________
 * Section Number: ______________________________
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

    // TODO: Initialize priority queue
    // TODO: Set dist[src] = 0 and push into pq
    // TODO: Write Dijkstra main loop

    return dist;
}

vector<vector<int>> repeatedDijkstra() {
    vector<vector<int>> all(n, vector<int>(n));

    // TODO: Run dijkstra(i) for all i

    return all;
}

vector<vector<int>> floydWarshall() {
    vector<vector<int>> dist = adjMatrix;

    // TODO: Implement triple loop

    return dist;
}
