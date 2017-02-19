#include <iostream>
#define N 8
using namespace std;

int main()
{
    int q[8];
    int c=0, i, n=0;
    q[0]=0;

NC: c++;
    if (c >= N) goto print;
    q[c]=-1;

NR: q[c]++;
    if (q[c] >= N) goto backtrack;

    for (i=0; i<c; i++)
        if (q[c] == q[i]) goto NR;

    for (i=1; i<=c; i++)
        if (q[c]-i == q[c-i]) goto NR;

    for (i=1; i<=c; i++)
        if (q[c]+i == q[c-i]) goto NR;

    goto NC;

backtrack: c--;
    if (c <= -1)
    {
        cout << "all solutions found." << endl;
        return 0;
    }

    goto NR;

print: n++;
    for (i=0; i<N; i++)
    {
        for (int j=0; j<N; j++){
            if (q[j] == i) cout << "1";
            else cout << "0";
        }
        cout << endl;
    }
    cout << "solution " << n << endl;
    goto backtrack;
}
