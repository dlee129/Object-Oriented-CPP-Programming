#include <iostream>
#include <cstdlib>
using namespace std;

bool solution(int q[], int col);
bool validMove(int q[], int col);
void print(int q[]);


int main()
{
    int q[8];
    solution(q, 0);
    return 0;
}

bool solution(int q[], int col)
{
    if (col >= 8)
    {
        print(q);
        return true;
    }

    for (int i=0; i<8; i++)
    {
        q[col]=i;
        if (validMove(q, col))
        {
            if (solution(q, col+1)) return true;
        }
    }

    return false;
}

bool validMove(int q[], int col)
{
    for (int i=0; i<col; i++)
        if (q[i]==q[col]) return false;

    for (int i=0; i<col; i++)
        if (col-i==abs(q[col]-q[i])) return false;

    return true;
}

void print(int q[])
{
    int i,j,k,l;
    typedef char box[5][7];
    box bb, wb, *board[8][8];
    box wq, bq;

    for(i=0; i<5; i++)
        for(j=0; j<7; j++)
        {
            wb[i][j]=' ';
            bb[i][j]=char(219);
        }

    for (i=0; i<5; i++)
        for (j=0; j<7; j++)
        {
            if ((i==1 && j==2) || (i==1 && j==4) || i==0 || i==4 || j==0 || j==6)
            {
                wq[i][j]=char(219);
                bq[i][j]=' ';
            }
            else
            {
                wq[i][j]=' ';
                bq[i][j]=char(219);
            }
        }

    for (i=0; i<8; i++)
        for (j=0; j<8; j++)
            if ((i+j)%2==0)
                board[i][j]=&wb;
            else
                board[i][j]=&bb;

    for (i=0; i<8; i++)
        for (j=0; j<8; j++)
            if (q[j]==i)
            {
                if ((i+j)%2==0)
                    board[i][j]=&bq;
                else
                    board[i][j]=&wq;
            }

    cout << " ";
    for (i=0; i<7*8; i++)
        cout << '_';
    cout << endl;

    for (i=0; i<8; i++)
        for (k=0; k<5; k++)
        {
            cout << " " << char(179);
            for (j=0; j<8; j++)
                for (l=0; l<7; l++)
                    cout << (*board[i][j])[k][l];
            cout << char(179) << endl;
        }

    cout << " ";
    for (i=0; i<7*8; i++)
        cout << char(196);
    cout << endl;
}

