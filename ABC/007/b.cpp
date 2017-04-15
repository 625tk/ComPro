#include<iostream>

using namespace std;

int main(void){
  string s;
  cin >> s;
  if(s.size() == 1 && s[0] == 'a')
    cout << -1 << endl;
  else
    cout << "a" << endl;
  return 0;
}
