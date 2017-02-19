#include <iostream>

using namespace std;

bool solution(int board[], int col, int x);
bool validMove(int board[], int col);

int n=0;

int main()
{
    int x;
    cout << "Enter the number of queens: ";
    cin >> x;

    for (int i=1; i<=x; i++)
    {
        int *board = new int[i];
        solution(board, 0, i);
        cout << i << ". There are " << n << " solutions to the " << i << " queens problem." << endl;
        n=0;
        delete [] board;
    }

    return 0;
}

bool solution(int board[], int col, int x)
{
    if (col >= x)
    {
        n++;
        return false;
    }

    for (int i=0; i<x; i++)
    {
        board[col] = i;
        if (validMove(board, col))
        {
            if (solution(board, col+1, x)) return true;
        }
    }

    return false;
}

bool validMove(int board[], int col)
{
    int i;

    for (i=0; i<col; i++)
    {
        if (board[i] == board[col]) return false;
    }

    for (i=1; i<=col; i++)
    {
        if (board[col-i] == board[col]-i) return false;
    }

    for (i=1; i<=col; i++)
    {
        if (board[col-i] == board[col]+i) return false;
    }

    return true;
}

