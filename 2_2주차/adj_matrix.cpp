#include <bits/stdc++.h>

using namespace std;
#define VE 10 // 노드의 개수

bool adjacency[VE][VE];
bool visited[VE];

void DFS(int i)
{

    visited[i] = 1;

    for (int d = 0; d < VE; ++d)
    {

        int next_i = d;

        if (next_i >= 0 && next_i < VE)
        {
            if (visited[next_i] == 0 && adjacency[i][next_i] == 1)
            {
                cout << i << "->" << next_i << endl;
                DFS(next_i);
            }
        }
    }
}

int main()
{

    // Q1.
    adjacency[1][2] = 1, adjacency[2][1] = 1;
    adjacency[1][3] = 1, adjacency[3][1] = 1;
    adjacency[3][4] = 1, adjacency[4][3] = 1;

    // Q2
    int i = 1;
    DFS(i);

    return 0;
}