#include <iostream>
using namespace std;

class Rat{
    private:
        int n;
        int d;

    public:
        Rat()
        {
            n=0;
            d=1;
        }
        Rat(int i)
        {
            n=i;
            d=1;
        }
        Rat(int i, int j)
        {
            n=i;
            d=j;
        }

        void setN(int i)
        {
            n=i;
        }
        void setD(int i)
        {
            d=i;
        }
        int getN()
        {
            return n;
        }
        int getD()
        {
            return d;
        }

        Rat operator+(Rat r)
        {
            Rat t;
            t.n = n*r.d + d*r.n;
            t.d = d*r.d;
            nomalize(t);
            return reduceToLowestTerm(t);
        }
        Rat operator-(Rat r)
        {
            Rat t;
            t.n = n*r.d - d*r.n;
            t.d = d*r.d;
            nomalize(t);
            return reduceToLowestTerm(t);
        }
        Rat operator*(Rat r)
        {
            Rat t;
            t.n = n*r.n;
            t.d = d*r.d;
            nomalize(t);
            return reduceToLowestTerm(t);
        }
        Rat operator/(Rat r)
        {
            Rat t;
            t.n = n*r.d;
            t.d = d*r.n;
            nomalize(t);
            return reduceToLowestTerm(t);
        }

        int gcd(int i, int j)
        {
            if (j==0) return i;
            return gcd(j, i%j);
        }
        void nomalize(Rat& r)
        {

            if (r.n == 0 || r.d == 0)
            {
                r.n = 0;
                r.d = 1;
            }
            if (r.d < 0)
            {
                r.n = r.n*(-1);
                r.d = r.d*(-1);
            }
        }
        Rat reduceToLowestTerm(Rat r)
        {
            Rat t;
            int temp = gcd(r.n, r.d);
            t.n = r.n/temp;
            t.d = r.d/temp;
            return t;
        }

        friend ostream& operator<<(ostream& os, Rat r);
        friend istream& operator>>(istream& is, Rat& r);
};

ostream& operator<<(ostream& os, Rat r)
{
    if (r.n > r.d)
    {
        if (r.d == 1)
        {
            os << r.n << endl;
            return os;
        }
        if (r.d < 0)
        {
            os << r.n*(-1) << "/" << r.d*(-1) << endl;
            return os;
        }
        else
        {
            os << r.n/r.d << " " << r.n%r.d << "/" << r.d << endl;
            return os;
        }
    }

    os << r.n << "/" << r.d << endl;
    return os;
}
istream& operator>>(istream& is, Rat& r)
{
    is >> r.n >> r.d;
    return is;
}

int main()
{
    Rat x(1,2), y(2,3), z;
    z = x + y;
    cout << z << endl;

    x.setN(3);
    y.setD(2);
    z = x + y;
    cout << z;

    cin >> x;
    cout << x;
    z = x + 5;
    cout << z;
    return 0;
}
