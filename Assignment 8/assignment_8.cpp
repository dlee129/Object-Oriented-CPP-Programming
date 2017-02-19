#include <iostream>
#include <cmath>
using namespace std;

bool sol(int a[][5], int x[], int col);
bool ok(int b[][5], int y[], int column);
void print(int z[]);

int main()
{
    int adj[8][5] = {{-1}, {0, -1}, {0, -1}, {0, 1, 2, -1}, {0, 1, 3, -1}, {1, 4, -1}, {2, 3, 4, -1}, {3, 4, 5, 6, -1}};
    int q[8];

    sol(adj, q, 0);
    return 0;
}

bool sol(int a[][5], int x[], int col)
{
    if (col >= 8)
    {
        print(x);
        return false;
    }

    for (int i=1; i<=8; i++)
    {
        x[col]=i;
        if (ok(a, x, col))
        {
            if (sol(a, x, col+1)) return true;
        }
    }
    return false;
}

bool ok(int b[][5], int y[], int column)
{
    for (int i=0; i<column; i++)
    {
        if (y[column] == y[i]) return false;
    }

    for (int j=0; b[column][j] != -1; j++)
    {
        if (1 == abs(y[column] - y[b[column][j]])) return false;
    }

    return true;
}

void print(int z[])
{
    cout << " ";
    for (int i=0; i<=1; i++)
        cout << z[i];
    cout << " " << endl;
    for (int i=2; i<=5; i++)
        cout << z[i];
    cout << "\n ";
    for (int i=6; i<=7; i++)
        cout << z[i];
    cout << " " << endl;
    cout << endl;
}
