#include <iostream>
using namespace std;
int main(){

for( int i = 0; i <10000; i++){
	if(((i*i)/10)%2!=0 && (((i*i)%10)%2)!=0) cout<<i*i<<endl;
	}
return 0;
}

