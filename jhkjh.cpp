#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited)
{
    visited[node] = true;
    cout << node << " ";

    for (int neighbor : adj[node])
    {
        if (!visited[neighbor])
        {
            dfs(neighbor, adj, visited);
        }
    }
}

int main()
{
    int n = 5;
    vector<vector<int>> adj(n);

    // Example graph
    adj[0] = {1, 2};
    adj[1] = {0, 3, 4};
    adj[2] = {0};
    adj[3] = {1};
    adj[4] = {1};

    vector<bool> visited(n, false);
    dfs(0, adj, visited);

    return 0;
}