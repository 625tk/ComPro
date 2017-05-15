#include<iostream>
#include<vector>

#define rep(i,n) for(int i = 0; i < n; i++)

using namespace std;

vector<int> primes;
void eratosthenes(int n){
  vector<int> a;
  a.resize(n+1, 0);
  rep(i,n-1) a[i] = i+2;

  int bsize = n-1;
  for(int i = 0; 0<bsize; i++){
    primes.push_back(a[0]);
    int index = 0;
    for(int j = 1; j < bsize; ++j){
      if(a[j] % primes.back() != 0){
        a[index] = a[j];
        index++;
      }
    }
    bsize = index;
  }
}


bool is_prime(int n) {
  for (int j=2; j*j<=n; j++) {
    if (n % j == 0) return false;
  }
  return true;
}



int main(void){
  vector<int> x;
  int i, a;
  cin >> a >> i;
  cout << "i = " << i << "\t" << endl;

  if(a == 0){
    eratosthenes(i);
  }else{
    rep(j,i+1){
      if(is_prime(j)){
        primes.push_back(j);
      }
    }
  }

  for(auto& y: primes)cout << y << "," << endl;
  cout << endl;
  return 0;
}
