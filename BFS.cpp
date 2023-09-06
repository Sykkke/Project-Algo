#include <iostream>
#include "Algo.h" // Include the header file for your code
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n = 6; // Number of nodes
    int s = 0; // Source vertex
    vector<vector<int>> adjacency_list;

    adjacency_list.resize(n);
    adjacency_list[0].push_back(1);
    adjacency_list[0].push_back(2);
    adjacency_list[1].push_back(3);
    adjacency_list[2].push_back(4);
    adjacency_list[3].push_back(5);

    bfs();

    for (int u = 0; u < n; u++)
    {
        printShortestPath(u);
    }

    return 0;
}
