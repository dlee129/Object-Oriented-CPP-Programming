#include <iostream>
using namespace std;

double line(double x)
{
    return x;
}
double square(double x)
{
    return x*x;
}
double cube(double x)
{
    return x*x*x;
}

typedef double(*FUNC)(double);
double integrate(FUNC f, double a, double b);


int main()
{
    cout << "The integral of f(x)=x between 1 and 5 is: " << integrate(line, 1, 5) << endl;
    cout << "The integral of f(x)=x^2 between 1 and 5 is: " << integrate(square, 1, 5) << endl;
    cout << "The integral of f(x)=x^3 between 1 and 5 is: " << integrate(cube, 1, 5) << endl;
    return 0;
}

double integrate(FUNC f, double a, double b)
{
    double sum=0;
    double x=a;
    for (double i=a; i<=(b-a)*10000; i++)
        {
        sum=sum+f(x)*0.0001;
        x=x+0.0001;
        }
    return sum;
}
