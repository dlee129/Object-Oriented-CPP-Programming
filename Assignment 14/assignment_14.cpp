#include <iostream>

using namespace std;

long long fib(int n);
long long fib(int n, long long a, long long b);

long long fib(int n)
{
    return fib(n, 1, 1);
}
long long fib(int n, long long a, long long b)
{
    if (n < 3) return 1;
    return a+fib(n-1, b, a+b);
}

int main()
{
    for (int i=1; i<50; i++)
        cout << "fib(" << i << ")= " << fib(i) << endl;
    return 0;
}
