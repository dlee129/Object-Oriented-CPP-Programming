#include <iostream>
#include <vector>

// NOTE: This program uses the vector container from the stl.
using namespace std;
int main(){
    vector<int> t[3]; // three towers A,B,C represented as an array of 3 vectors
    int n, candidate,to, from, move=0; // move counts the move number
    cout<<"Please enter an ODD number of rings to move: ";
    cin>>n;
    cout<<endl;

//intitialize the 3 towers
    for(int i=n+1;i>=1;i--)
        t[0].push_back(i);
    t[1].push_back(n+1);
    t[2].push_back(n+1);

// initialize towers and candidate
    from=0;
    to=1;

    candidate=1;

    while( t[1].size()<n+1){ // there are still rings to transfer to tower B = t[1]
//write it
        cout<<"move number " << ++move << ": Transfer ring " << candidate << " from tower " << char(from+65) << " to tower " << char(to+65) << endl;
//do it: move the disks around

//1. Push the top of the “from” tower to the “to” tower
        t[to].push_back(t[from].back());

//2. Remove the ring from the “from” tower
        t[from].pop_back();

//get next “from tower” It’s not the most recent “to” – so which is it?
        if(t[(to+1)%3].back() < t[(to+2)%3].back())
            from = (to+1)%3;
        else
            from = (to+2)%3;

// get next “to tower”
        if(t[from].back() < t[(from+1)%3].back())
            to= (from+1)%3;
        else
            to= (from+2)%3;

//get next candidate
        candidate= t[from].back(); // it’s on the top of the current “from tower”
    }
    return 0;
}
