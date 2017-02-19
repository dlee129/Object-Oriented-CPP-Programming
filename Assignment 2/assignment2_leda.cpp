#include <iostream>
using namespace std;
bool equivalent (int a[], int b[], int n){
  bool check_if_same = true;
    for(int i = 0; i < n; i++)
      if( a[i] != b[(i+4)%n]){
        check_if_same = false;
	break;
      }
      return check_if_same;
}
void printA(int a[], int n){
  for(int i = 0; i <6; i++)
    cout<<a[i]<<" ";
}
int main(){
  int a[6] = {1,2,3,4,5,1};
   int b[6] = {3,4,5,1,1,2};
   cout << "a: ";
   printA(a,6);
   cout << endl << "b: ";
   printA(b,6);
   string equiv = "";
   if (!equivalent(a,b,6)) equiv = " not";
   cout << endl << "are" << equiv << " shift equivalent!" << endl;
   return 0;
}
