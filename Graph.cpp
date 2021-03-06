#include <iostream>
#include <bits/stdc++.h>
#include <queue>
#define N 6
using namespace std;
class Graph
{
private:
    int Adj_Matrix[N][N]; // this is matrix
    int Number_Vertices;
    int Number_Edges;
    int Visited[N] = {0};

public:
    Graph()
    {
        Number_Vertices = 0;
        Number_Edges = 0;
        for (int i = 0; i < Number_Vertices; i++)
        {
            for (int j = 0; j < Number_Vertices; j++)
            {
                Adj_Matrix[i][j] = 0;
            }
        }
    }
    Graph(int Number_ver)
    {
        Number_Vertices = Number_ver;
        Number_Edges = 0;
        for (int i = 0; i < Number_ver; i++)
        {
            for (int j = 0; j < Number_ver; j++)
            {
                Adj_Matrix[i][j] = 0;
            }
        }
    }
    Graph(int Number_ver, int Number_edg)
    {
        Number_Vertices = Number_ver;
        Number_Edges = Number_edg;
        for (int i = 0; i < Number_ver; i++)
        {
            for (int j = 0; j < Number_ver; j++)
            {
                Adj_Matrix[i][j] = 0;
            }
        }
        for (int i = 0; i < Number_edg; i++)
        {
            int u, v;
            cout << "Enter the Edge (u,v): " << endl;
            cin >> u >> v;
            Adj_Matrix[u][v] = 1;
            Adj_Matrix[v][u] = 1;
        }
    }
    void Create_Graph();
    void BFS(int start_vertex);
    void DFS(int start_vertex);
    void Display_Graph();
};
void Graph::Create_Graph()
{
    cout << "Enter total vertices: " << endl;
    cin >> Number_Vertices;
    cout << "Enter The Total Number of Edges: " << endl;
    cin >> Number_Edges;
    for (int i = 0; i < Number_Vertices; i++)
    {
        for (int j = 0; j < Number_Vertices; j++)
        {
            Adj_Matrix[i][j] = 0;
        }
    }

    for (int i = 0; i < Number_Edges; i++)
    {
        int u, v;
        cout << "Enter the Start and Destination of the edge: " << i + 1 << endl;
        cin >> u >> v;
        Adj_Matrix[v][u] = 1;
        Adj_Matrix[u][v] = 1;
    }
}
void Graph::BFS(int start_vertex)
{
    int Visited[N] = {0};

    int v, u;
    queue<int> q;
    cout << start_vertex << " ";
    Visited[start_vertex] = 1;
    q.push(start_vertex);
    while (!q.empty())
    {
        u = q.front();
        q.pop();
        for (v = 0; v <= Number_Vertices; v++)
        {
            if (Adj_Matrix[u][v] == 1 && Visited[v] == 0)
            {
                // cout << "Adjecent " << v << "Pushed In Queue";
                cout << v << " ";
                q.push(v);
                Visited[v] = 1;
            }
        }
    }
}

void Graph::DFS(int start_vertex)
{

    if (Visited[start_vertex] == 0) // for unvisited vertex
    {
        cout << start_vertex << " ";
        Visited[start_vertex] = 1; // it become visited now
        for (int v = 0; v <=N; v++)
        {
            if (Adj_Matrix[start_vertex][v] == 1 && Visited[v] == 0)
            {
                DFS(v); // HERE We've used stack using recursion hence no need to add our external stack
            }
        }
    }
}

void Graph::Display_Graph()
{
    if (Number_Vertices > 0)
    {
        for (int i = 0; i < Number_Vertices; i++)
        {
            for (int j = 0; j < Number_Vertices; j++)
            {
                cout << Adj_Matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "Null Graph" << endl;
    }
}
int main()
{
    Graph g;
    int Strt, choice;

    bool flag = true;

    while (flag)
    {
        cout << "______________________________________________________________________\n";
        cout << endl;
        cout << "Welcome To Graph !!!" << endl;
        cout << "______________________________________________________________________\n";
        cout << "\n1.Create Graph\n2.BFS Traversal\n3.DFS Traversal\n4.Display Adjacency Adj_Matrix\n5.Exit\n\n"
             << endl;
        cout << "\nDo you want to continue" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            g.Create_Graph();
            break;
        case 2:
            cout << "Enter the starting vertex for BFS: " << endl;
            cin >> Strt;
            g.BFS(Strt);
            break;
        case 3:
            cout << "Enter the starting vertex for DFS: " << endl;
            cin >> Strt;
            g.DFS(Strt);
            break;
        case 4:
            g.Display_Graph();

            break;
        case 5:
            exit(0);
            break;
        default:
            break;
        }
        char flag2;
        cout << "Do you Want to continue: " << endl;
        cin >> flag2;
        if (flag2 == 'n')
        {
            flag = false;
        }
    }

    return 0;


}

