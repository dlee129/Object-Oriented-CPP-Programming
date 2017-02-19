#include <iostream>
#include <cstdlib>
#define N 8
using namespace std;

bool NC(int &c, int q[N]);
bool NR(int &c, int q[N]);
bool backtrack(int &c, int q[N]);
bool print(int &c, int q[N], int &n);
int n=0;

int main()
{
    int q[8];
    int c=0;
    q[0]=0;
    NC(c, q);
}

bool NC(int &c, int q[N]){
    c++;
    if (c >= N) {
            print(c, q, n);

    }
    q[c]=-1;
    NR(c, q);
}

bool NR(int &c, int q[N]){
    q[c]++;
    int i;
    if (q[c] >= N) backtrack(c, q);

    for (i=0; i<c; i++)
        if (q[c] == q[i]) {
                NR(c, q);

        }

    for (i=1; i<=c; i++)
        if (q[c]-i == q[c-i]) {
                NR(c, q);

        }

    for (i=1; i<=c; i++)
        if (q[c]+i == q[c-i]) {
                NR(c, q);

        }

    NC(c, q);
}

bool backtrack(int &c, int q[N]){
    c--;
    if (c <= -1)
    {
        cout << "all solutions found." << endl;
        exit(0);
    }

    NR(c, q);
}

bool print(int &c, int q[N], int &n) {
    n++;
    for (int i=0; i<N; i++)
    {
        for (int j=0; j<N; j++){
            if (q[j] == i) cout << "1";
            else cout << "0";
        }
        cout << endl;
    }
    cout << "solution " << n << endl;
    cout << endl;
    backtrack(c, q);
}
