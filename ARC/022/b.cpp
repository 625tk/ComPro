#include<iostream>
#include<vector>
#include<map>

#define rep(i,n) for(int i = 0; i < n; ++i)
using namespace std;

map<int,int> mp;

int main(void){
    int n;
    int ans = 0;
    vector<int> a;


    cin >> n;
    a.resize(n);
    for(auto &b: a)cin >> b;

    int l, r;
    l = 0;
    r = -1;

    rep(i, n){
        r++;
        if(mp[a[r]] == 0){
            mp[a[r]] = 1;
        }else{
            while(mp[a[r]]){
                mp[a[l++]] = 0;
            }
            mp[a[r]] = 1;
        }
        ans = max(ans, r-l+1);
    }

    cout << ans << endl;;
    return 0;
}
