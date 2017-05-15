#include<iostream>
#include<cmath>

using namespace std;

int main(void){
  long long x,y;
  cin >> x >> y;
  if( abs(x-y) > 1){
    cout << "Alice" << endl;
  }else{
    cout << "Brown" << endl;
  }
  return 0;
}
