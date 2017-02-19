
#include <iostream>

#include <cmath>

using namespace std;


int main(){
    
int Q[8], i, c, count=0;
    
c=0;
    
Q[0] =0;


nextCol:
 c++;

    if(c==8){ 
	goto Print;
}
    
Q[c] =-1;


nextRow:
  Q[c]++;
    
	if(Q[c]==8){ 
		goto BackTrack;
	}
for(i=0; i<c; i++){

        	if(Q[i]==Q[c] || abs(Q[c]-Q[i]) == (c - i)){

	            goto nextRow;
        
		}
    
	}
    
	goto nextCol;
    
	
BackTrack:
    c--;

	    if(c==-1){
	
        cout<<"Termination of program"<<endl;

	        return 0;
	
    }
    
	goto nextRow;


Print:
    ++count;

    cout << "Solution #"<<count<< endl;

    for(int i=0; i<8; i++){

        cout << Q[i];

    }
    
	cout<<endl;

    goto BackTrack;

}
