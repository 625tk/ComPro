#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < n; i++)

using namespace std;

const int MAX = 500000;
const int MS = 2;
const long long mod[] = { 999999937LL, 1000000007LL };
const long long base = 9973;
class RollingHash{
  public:
  int n;
  vector<long long> hs[MS], pw[MS];

  RollingHash(){};
  RollingHash(const string &s){
    n = s.size();
    rep(i,MS){
      hs[i].assign(n+1, 0);
      pw[i].assign(n+1, 0);
      hs[i][0] = 0;
      pw[i][0] = 1;
      rep(j,n){
        pw[i][j+1] = pw[i][j] * base%mod[i];
        hs[i][j+1] = (hs[i][j]*base+s[j])%mod[i];
      }
    }
  }
  long long hash(int l, int r, int i){return ((hs[i][r]-hs[i][l] * pw[i][r-l])%mod[i] + mod[i]);}
};

int main(void){
  string s,t;
  int q;
  int a,b,c,d,k;
  cin >> s >> t;
  cin >> q;
  RollingHash rs(s);
  RollingHash rt(t);

  rep(i,q){
    cin >> k >> a >> b >> c >> d;
    a--;b--;c--;d--;
    if(b-a == d-c){
      int rm = 0;
      int lm = 0;
      int len = b-a;
      int r,l,mid;
      puts("right");
      //right
      l = 0;
      r = len;
      while(l <= r){
        mid = (r+l)/2;
        if(rs.hash(b-mid, b, 1) == rt.hash(d-mid, d, 1) && rs.hash(b-mid, b, 0) == rt.hash(d-mid, d, 0)){l = mid+1;rm=mid;}
        else r = mid-1;
      }
      rm = len-rm;
      puts("left");
      //left
      l = 0;
      r = len;
      while(l <= r){
        mid = (r+l)/2;
        if(rs.hash(a, a+mid, 1) == rt.hash(c,c+mid, 1) && rs.hash(a, a+mid, 0) == rt.hash(c, c+mid, 0)){l = mid+1;lm=mid;}
        else r=mid-1;
      }
      cout << lm << ":" << rm << endl;
      if(lm==len){
        puts("YES");
      }else if( rm-lm == 4){
        // puts("diff = 4");
        // cout << s.substr(a+lm, rm-lm-1) << endl;
        // cout << t.substr(c+lm, rm-lm-1) << endl;
        // cout << s[a+lm] << ":" << s[a+rm-2] << endl;
        // cout << t[c+lm] << ":" << t[c+rm-2] << endl;
        if( k == 2 && s[a+lm] == t[c+lm+1] && s[a+lm+1] == t[c+lm] && s[a+rm-1] == t[c+rm-2] && s[a+rm-2] == t[c+rm-1]){
          puts("YES");
        }else{
          puts("NO");
        }
      }else if( rm-lm == 3){
        puts("diff = 3");
        if( k == 2 && s[a+lm] == t[c+lm+2] && s[a+lm+1] == t[c+lm+1] && s[a+lm+2] == t[c+lm]){
          puts("YES");
        }else{
          puts("NO");
        }
      }else if( k > 0 && rm-lm == 2){
        puts("diff = 2");
        if(s[a+lm] == t[c+lm+1] && s[a+lm+1] == t[c+lm]){
          puts("YES");
        }else{
          puts("NO");
        }
      }else{
        puts("diff > 4");
        if(k == 2 && s[a+lm] == t[c+lm+1] && s[a+lm+1] == t[c+lm] && s[a+rm-1] == t[c+rm-2] && s[a+rm-2] == t[c+rm-1]){
          if(rs.hash(a+lm+2, a+rm-2, 0) == rt.hash(c+lm+2, c+rm-2, 0) &&rs.hash(a+lm+2, a+rm-2, 1) == rt.hash(c+lm+2, c+rm-2, 1)){
            puts("YES");
          }else puts("NO");
        }else{
          puts("NO");
        }
      }
    }else{
      puts("NO");
    }
  }
  return 0;
}
/*

ababcacbcbabacaaaababcacbcbabac
ababacbccbabacaaaababccbacbabac
2
2 0 13 0 13
ababcacbcbabaca
ababacbccbabaca
----****-------
0123456789012345
      987654321

abcacbcbabac
abccbacbabac

*/
