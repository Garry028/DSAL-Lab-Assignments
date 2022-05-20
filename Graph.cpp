#include <iostream>
#include <queue>
using namespace std;

const int N = 10;

class graph
{

    int n, e;

    int adj[N][N];

public:
    graph()
    {
        n = 0;
        e = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                adj[i][j] = 0;
            }
        }
    }
    graph(int n_vertices)
    {
        n = n_vertices;
        e = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                adj[i][j] = 0;
            }
        }
    }
    graph(int n_vertices, int n_edges)
    {
        n = n_vertices;
        e = n_edges;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                adj[i][j] = 0;
            }
        }
        for (int i = 0; i < e; i++)
        {
            int u, v;
            cout << "Enter the edge (u,v) ";
            cin >> u >> v;
            adj[u][v] = 1;
            adj[v][u] = 1;
        }
    }
    void create_graph(int n_vertices, int n_edges)
    {
        n = n_vertices;
        e = n_edges;

        cout << "Welcome to graph creation ... keep list of edges (u,v) ready for inserting the different edges of graph" << endl;

        for (int i = 0; i < e; i++)
        {
            int u, v;
            cout << "Enter the edge (u,v) number : " << i + 1;
            cin >> u >> v;
            adj[u][v] = 1;
            adj[v][u] = 1;
        }
    }

    void display_graph()
    {

        if (n > 0)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    cout << adj[i][j] << " ";
                }
                cout << endl;
            }
        }
        else
            cout << "Null Graph";
    }

    void bfs_traversal(int start_vertex)
    {
        int visited[N] = {0};
        queue<int> q;
        int u, v;

        for (v = 0; v < n; v++)
        {
            visited[v] = 0;
        }

        q.push(start_vertex);
        visited[start_vertex] = 1;

        cout << "BFS traversal of Graph is : " << endl;
        while (!q.empty())
        {
            u = q.front();
            cout << u << " ";
            q.pop();
            for (v = 0; v < n; v++)
            {
                // cout<<"current v = "<<v<<" ";
                if (adj[u][v] == 1 && visited[v] == 0)
                {
                    // cout<<"Adjacent "<<v<<" pushed in queue";
                    q.push(v);
                    visited[v] = 1;
                }
            }
        }
    }
};

int main()
{

    graph g;
    // graph g(4);
    // graph g(4,4);

    g.display_graph();

    g.create_graph(4, 4);

    g.display_graph();

    g.bfs_traversal(0);

    return 0;
}
