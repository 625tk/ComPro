#include<iostream>
#include<cmath>
#include<iomanip>

using namespace std;

int main(void){
  double l, x, y, s, d, ans;
  cin >> l >> x >> y >> s >> d;
  cout << fixed << setprecision(10); 

  if(d > s){
    ans = (d-s)/(x+y);
  }else{
    ans = (d-s+l)/(x+y);
  }

  if( y - x > 0){
    if(d > s){
      ans = min(ans, (s + (l-d))/(y-x));
    }else{
      ans = min(ans, (s-d)/(y-x));
    }
  }

  cout << ans << endl;


  return 0;
}

