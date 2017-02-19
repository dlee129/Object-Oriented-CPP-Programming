#include <iostream>
#include <cmath>
using namespace std;

bool sol(int adj[][5], int q[], int col);
bool ok(int adj[][5], int q[], int col);
void print(int q[]);

int main()
{
    int adj[8][5] = {{-1}, {0, -1}, {0, -1}, {0, 1, 2, -1}, {0, 1, 3, -1}, {1, 4, -1}, {2, 3, 4, -1}, {3, 4, 5, 6, -1}};
    int q[8];

    sol(adj, q, 0);
    return 0;
}

bool sol(int adj[][5], int q[], int col)
{
    if (col >= 8)
    {
        print(q);
        return false;
    }

    for (int i=1; i<=8; i++)
    {
        q[col]=i;
        if (ok(adj, q, col))
        {
            if (sol(adj, q, col+1)) return true;
        }
    }
    return false;
}

bool ok(int adj[][5], int q[], int column)
{
    for (int i=0; i<column; i++)
    {
        if (q[column] == q[i]) return false;
    }

    for (int j=0; adj[column][j] != -1; j++)
    {
        if (1 == abs(q[column] - q[adj[column][j]])) return false;
    }

    return true;
}

void print(int q[])
{
    cout << " ";
    for (int i=0; i<=1; i++)
        cout << q[i];
    cout << " " << endl;
    for (int i=2; i<=5; i++)
        cout << q[i];
    cout << "\n ";
    for (int i=6; i<=7; i++)
        cout << q[i];
    cout << " " << endl;
    cout << endl;
}
