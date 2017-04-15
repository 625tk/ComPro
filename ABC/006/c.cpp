#include<iostream>
using namespace std;

int a[3000000];

int main(void){
  int n,m,a,b,c;
  cin >> n >> m;
  // a + b + c = N;
  // 2a + 3b + 4c = M;
  //
  // b = N - a - c
  // 2(a+2c) + 3b = M;
  // 2(a+2c) + 3(N-a-c) = M;
  // 3N - a + c = M
  // c-a = M - 3N
  int ca = m-3*n;
  for(int i = 0; i < m; i++){
    a = i;
    c = ca + a;
    if((m-2*a-4*c)%3 == 0){
      b = (m-2*a-4*c)/3;
      if(a>=0 && b >=0 && c >=0 && b + a + c == n){
        cout << a << " " << b << " " << c << endl;
        return 0;
      }
    }
  }
  cout << "-1 -1 -1" << endl;
  return 0;
}
