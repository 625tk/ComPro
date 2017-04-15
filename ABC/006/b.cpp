#include<iostream>
using namespace std;

int a[3000000];

int main(void){
  int t;
  cin >> t;
  a[0] = 0;
  a[1] = 0;
  a[2] = 0;
  a[3] = 1;
  for(int i = 4; i <= t; ++i){
    a[i] = (a[i-1] + a[i-2] + a[i-3])%10007;
  }
  cout << a[t] << endl;

  return 0;
}
