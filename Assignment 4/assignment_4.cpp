#include <iostream>
#define N 8
using namespace std;

int main()
{
    int i, j, r, c=0, n=0;
    int board[N][N]={0};
    board[0][0]=1;

NC: c++;
    if(c >= 8) goto print;
    r = -1;

NR: r++;
    if (r >= 8) goto backtrack;

    for (i=0; i<c; i++)
        if (board[r][i]) goto NR;

    for (i=r-1, j=c-1; i>=0 && j>=0; i--, j--)
        if (board[i][j]) goto NR;

    for (i=r+1, j=c-1; i<8 && j>=0; i++, j--)
        if (board[i][j]) goto NR;

    board[r][c]=1;
    goto NC;

backtrack: c--;
    if (c <= -1)
    {
        cout << n << " solutions found." << endl;
        return 0;
    }

    for (i=0; i<8; i++)
    {
        if (board[i][c])
        {
            board[i][c]=0;
            r=i;
            break;
        }
    }
    goto NR;

print:
    for (i=0; i<N; i++)
    {
        for (j=0; j<N; j++)
        {
            cout << board[i][j];
        }
        cout << endl;
    }

    n++;
    cout << "solution " << n << endl;
    cout << endl;
    goto backtrack;
}
