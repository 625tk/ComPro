#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

unsigned long long a[20];

unsigned long long f(unsigned long long x){
  unsigned long long t = (unsigned long long)10000000000000000000;
  int index = 19;
  int p = 0;
  unsigned long long ret = 0;
  a[0] = 0;

  while(t > 0){
    p = x / t;
    x -= p * t;
    //cout << "loop: x: (ind) :" << x << " ( " << index <<  ")"  << endl;
    if(p == 4){
      if(index == 0) ret++;
      if(index != 0) ret += x+1;
      ret += a[index] * (p);
      return ret;
    }
    if(p == 9){
      if(index == 0) ret++;
      if(index != 0)ret += x+1;
      ret += a[index] * (p-1);
      ret += t; //4の分
      return ret;
    }


    if( p < 4) ret += a[index] * p;
    else if( p < 9) ret += a[index] * (p - 1) + t;

    t/=10;
    index--;
  }
  return ret;
}

int main(void){
  unsigned long long A, B;
  cin >> A >> B;
  A--;

  unsigned long long t = 1;

  a[0] = 0;
  for(int i = 1; i < 20; i++){
    a[i] = a[i-1] * 8 + t * 2;
    t *= 10;
    //cout << i << "," << a[i] << endl;
  }
//   for(int i = 0; i < 500; i++){
//     cout << "f(" << i << ")" <<  f(i) << endl;
//   }


  // cout << "f(" << B << ")" <<  f(B) << endl;
  // cout << "f(" << A << ")" <<  f(A) << endl;
  //
  cout << f(B) - f(A) << endl;

  //[1,10] -> 2 => 2
  //[1,100] -> 2 * 8 + 10 * 2 => 36
  //[1,1000] -> 36 * 8 + 100 * 2
  //左から1桁分ずつ計算．
  //174だと100まで+ 70まで + 4まで
  //
  //
  return 0;
}
