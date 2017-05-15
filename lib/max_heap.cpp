#include<iostream>
#include<algorithm>
#include<vector>
#include<limits>

using namespace std;

template<typename T>
class MaxHeap{
  //AOJ ALDS1_9_C (AC)
  public:
    vector<T> a;
    const T INF;
    MaxHeap(int n):INF(numeric_limits<T>::max()/2){a.resize(n+1, INF);}
    MaxHeap():INF(numeric_limits<T>::max()/2){a.resize(1,INF);}
    T findMax(){return a[1];}
    T findMin(){ return a.size() > 3? min(a[2], a[3]): a[1+(a.size()==3)];}
    bool empty() { return a.size() == 1; }
    void insert(T x){a.push_back(x);rmx(a.size()-1);}
    void buildMaXHeap(){for(int i = (a.size()-1)/2; i > 0; --i) mx(i);}
    T pop(){
      T tmp = a[1];
      a[1] = a.back();
      a.pop_back();
      mx(1);
      return tmp;
    }

    // i番目の要素を下にずらしていく
    void mx(int i){
      int l = i*2;
      int r = i*2+1;
      T largest = INF;

      if(l < a.size() && a[l] > a[i]){
        largest = l;
      }else{
        largest = i;
      }

      if(r < a.size() && a[r] > a[largest])
          largest = r;

      if(largest != i){
        swap(a[i], a[largest]);
        mx(largest);
      }
    }

    // i番目の要素を上にずらしていく
    void rmx(int i){
      while(a[i/2] < a[i]){
        swap(a[i/2], a[i]);
        i/=2;
      }
    }
};




int main(void){
  int n, a;
  string str;
  MaxHeap<int> hp(0);

  while(1){
    cin >> str;
    if(str == "insert"){
      cin >> a;
      hp.insert(a);
    }else if(str == "extract"){
      cout << hp.pop() << endl;
    }else{
      break;
    }
  }
  return 0;
}
