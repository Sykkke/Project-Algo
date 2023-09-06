#ifndef ALGO_H
#define ALGO_H
#include <math.h>
#include <vector>
#include <bits/stdc++.h>
#include <queue>
#include <algorithm>

namespace std
{
    // Numerical Methods:
    //     1. Search
    //          a. Binary Search
    //          b. Ternary Search
    //          c. Newton's method for finding roots
    //     2. Integration
    //          a. Integration by Simpson's formula

    // a. Binary search function for a sorted array
    int binarySearch(const int *arr, int size, int target)
    {
        int left = 0;
        int right = size - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (arr[mid] == target)
            {
                return mid; // Element found, return its index
            }
            else if (arr[mid] < target)
            {
                left = mid + 1; // Adjust the left boundary
            }
            else
            {
                right = mid - 1; // Adjust the right boundary
            }
        }

        return -1; // Element not found
    }

    // b. Ternary Search
    // Define a typedef for the objective function type
    typedef double (*ObjectiveFunction)(double);

    // Function to perform ternary search
    // double ternary_search(double left, double right, double epsilon, ObjectiveFunction f)
    // {
    //     const double phi = (1.0 + sqrt(5.0)) / 2.0; // Golden ratio constant

    //     double x1 = left + (1.0 - 1.0 / phi) * (right - left);
    //     double x2 = left + 1.0 / phi * (right - left);

    //     double f_x1 = f(x1);
    //     double f_x2 = f(x2);

    //     while ((right - left) > epsilon)
    //     {
    //         if (f_x1 < f_x2)
    //         {
    //             right = x2;
    //             x2 = x1;
    //             f_x2 = f_x1;
    //             x1 = left + (1.0 - 1.0 / phi) * (right - left);
    //             f_x1 = f(x1);
    //         }
    //         else
    //         {
    //             left = x1;
    //             x1 = x2;
    //             f_x1 = f_x2;
    //             x2 = left + 1.0 / phi * (right - left);
    //             f_x2 = f(x2);
    //         }
    //     }

    //     return (left + right) / 2;
    // }

    double f(double x)
    {
        // Replace this with your actual function
        return -(x * x); // Example: Maximizing -x^2
    }

    double ternary_search(double l, double r)
    {
        double eps = 1e-9; // Set the error limit here
        while (r - l > eps)
        {
            double m1 = l + (r - l) / 3;
            double m2 = r - (r - l) / 3;
            double f1 = f(m1); // Evaluates the function at m1
            double f2 = f(m2); // Evaluates the function at m2
            if (f1 < f2)
                l = m1;
            else
                r = m2;
        }
        return f(l); // Return the maximum of f(x) in [l, r]
    }

    // BFS TEST
    vector<vector<int>> adj; // adjacency list representation
    int n;                   // number of nodes
    int s;                   // source vertex

    queue<int> q;
    vector<bool> used;
    vector<int> d, p;

    void bfs()
    {
        q.push(s);
        used.assign(n, false);
        d.assign(n, 0);
        p.assign(n, -1);
        used[s] = true;
        while (!q.empty())
        {
            int v = q.front();
            q.pop();
            for (int u : adj[v])
            {
                if (!used[u])
                {
                    used[u] = true;
                    q.push(u);
                    d[u] = d[v] + 1;
                    p[u] = v;
                }
            }
        }
    }

    void printShortestPath(int u)
    {
        if (!used[u])
        {
            cout << "No path!" << endl;
        }
        else
        {
            vector<int> path;
            for (int v = u; v != -1; v = p[v])
                path.push_back(v);
            reverse(path.begin(), path.end());
            cout << "Shortest Path from " << s << " to " << u << ": ";
            for (int v : path)
                cout << v << " ";
            cout << endl;
        }
    }
}
#endif // ALGO_H
