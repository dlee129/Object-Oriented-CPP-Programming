#include <iostream>
using namespace std;

void solution(int board[], int n, int k, int row);
int ok(int board[], int n, int row, int col);
int nOfc=0;

int main()
{
    int n=0, k=0;

    while (1)
    {
        cout << "Enter the size of the board: ";
        cin >> n;
        cout << "Enter the number of bishops: ";
        cin >> k;

        if (n < 0 || k < 0) break;

        int *board = new int[n*n];

        solution(board, n, k, 0);
        cout << "Size of the board: " << n << "x" << n << endl;
        cout << "Number of bishops: " << k << endl;
        cout << "Number of configurations: " << nOfc << endl;
        nOfc = 0;
        delete[] board;
        cout << endl;
    }
    return 0;
}

void solution(int board[], int n, int k, int row)
{
    static int bishop=0;

    if (bishop == k)
    {
        nOfc++;
        return;
    }
    if (row == n*n)
        return;

    for (int i=row; i<n*n; i++)
    {
        board[i] = 1;
        bishop++;

        if (ok(board, n, i, i/n))
        {
            solution(board, n, k, i+1);
        }

        board[i] = 0;
        bishop--;
    }
    return;
}

int ok(int board[], int n, int row, int col)
{
    for (int i=1; i<=col && i<=(row%n); i++)
        if (board[row-(i*n)-i]) return false;

    for (int j=1; j<=col && j<(n-(row%n)); j++)
        if (board[row-(j*n)+j]) return false;

    return true;
}
