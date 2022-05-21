/*
You have a business with several offices;
you want to lease phone lines to connect them up with each other;
and the phone company charges different amounts of money to connect different pairs of cities.You want a set of lines that connects all your offices with a minimum total cost.Solve the problem by suggesting appropriate data structures.
*/
#include <iostream>
using namespace std;

#define ROW 10
#define COL 10
#define INFINITY 9999

class prims
{
    int graph[ROW][COL], nodes;

public:
    void createGraph();
    void PrimsAlgo();
};

void prims::createGraph()
{
    cout << "Enter Total Offices: ";
    cin >> nodes;

    cout << "\nEnter Adjacency Matrix: \n";
    for (int i = 0; i < nodes; i++)
    {
        for (int j = i; j < nodes; j++)
        {
            cout << "Enter distance between " << i << " and " << j << endl;
            cin >> graph[i][j];        // what is the dist/cost between two vertex
            graph[j][i] = graph[i][j]; // dist from a to b is equal to b to a
        }
    }

    for (int i = 0; i < nodes; i++)
    {
        for (int j = 0; j < nodes; j++)
        {
            if (graph[i][j] == 0)
            {
                graph[i][j] = INFINITY; // fill infinity where path is not present
            }
        }
    }
}
void prims::PrimsAlgo()
{
    int selected[ROW], ne = 0;
    int min = 0, x, y;
    int cost = 0;

    for (int i = 0; i < nodes; i++)
    {
        selected[i] = 0;  // initially no node is visited

    }
// near array ne
    selected[0] = 1; // starting vertex is always node-0

    while (ne < nodes - 1)
    {
        min = INFINITY;

        for (int i = 0; i < nodes; i++)
        {
            if (selected[i] == 1)
            {
                for (int j = 0; j < nodes; j++)
                {
                    if (selected[j] == 0)
                    {
                        if (min > graph[i][j])
                        {
                            min = graph[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
        selected[y] = 1;
        cout << "\n"
             << x << " --> " << y;
        cost += graph[x][y];
        ne++;
    }
    cout << "\nTotal cost is: " << cost << endl;
}

int main()
{
    prims MST;
    cout << "\nPrims Algorithm to connect several offices\n";
    MST.createGraph();
    MST.PrimsAlgo();
}
