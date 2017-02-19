#include <iostream>
using namespace std;

int cost(int i, int j);
const int rows = 5;
const int cols = 6;
int shortestPath[6];
int tShortestPath[6];


int main()
{
    int minimumCost;
    for (int i=0; i<5; i++)
        minimumCost = cost(i, 5);
    cout << "cost: " << minimumCost << endl;
    for (int j=0; j<6; j++)
        cout << shortestPath[j] << " ";
    cout << endl;
    return 0;
}

int cost(int i, int j)
{
    int weight[rows][cols] =
    {
        {3,4,1,2,8,6},
        {6,1,8,2,7,4},
        {5,9,3,9,9,5},
        {8,4,1,3,2,6},
        {3,7,2,8,6,4}
    };

    static int costOfPath=0;

    if (j < 0)
    {
        static int tmin = costOfPath;

        if (costOfPath < tmin)
        {
            tmin = costOfPath;
            for (int x=0; x<6; x++)
                shortestPath[x] = tShortestPath[x];
        }
        return tmin;
    }

    tShortestPath[j] = weight[i][j];
    costOfPath = costOfPath + weight[i][j];

    static int min;
    min = cost((i+4)%5, j-1);
    min = cost(i, j-1);
    min = cost((i+1)%5, j-1);

    costOfPath = costOfPath - weight[i][j];
    return min;
}
