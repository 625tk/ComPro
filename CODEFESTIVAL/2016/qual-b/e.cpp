#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pii,int> piii;
typedef pair<ll,ll> pll;

#define reps(i,f,n) for(int i = int(f); i <= int(n); i++)
#define rep(i,n) reps(i,0,int(n)-1)
#define rrep(i,n) for(int i = n-1; i >= 0; i--)

#define all(x) (x).begin(),(x).end()
#define X first
#define Y second

#define sz size()
#define eb emplace_back
#define pb push_back

//word kinds


/*Trie(coplex)*/
const int KINDS = 26;
char ToChar(int s){return s+'a';}
int ToNum(char s){return s-'a';}

struct Node{
  char value;
  shared_ptr<Node> parent;
  array<shared_ptr<Node>, KINDS> children;
  bool leaf;
  int edges;
  int count;
  array<string,KINDS> tail;
  Node(char v):value(v), leaf(false),count(0),edges(KINDS+1),tail(){}
};
class Trie{
  public:

    shared_ptr<Node> root;
    Trie():root(make_shared<Node>('\0')){}

    void insert(string &s){
      shared_ptr<Node> now = root;

      rep(i,s.size()){
        int ind = ToNum(s[i]);
        shared_ptr<Node> &next = now->children[ind];
        if(!next){
          next = make_shared<Node>(s[i]);
          next->parent = now;
          if(now->edges == KINDS+1) now->edges=-ind;
          else if(now->edges > 0)now->edges++;
          else now->edges=2;
        }
        now = next;
        now->count++;
      }
      now->leaf = true;
    }

    void compress(){
      queue<shared_ptr<Node>> q;
      q.push(root);
      while(!q.empty()){
        shared_ptr<Node> node = q.front();q.pop();
        rep(i, KINDS){
          shared_ptr<Node> child = node->children[i];
          if(!child)continue;
          
          if(child->edges<0 && !child->leaf){
            node->tail[i] += child->children[-child->edges]->value;
            node->children[i] = child->children[-child->edges];
            i--;continue;
          }
          q.push(child);
        }
      }
    }

    bool exist(string &s){
      shared_ptr<Node> node = root;
      rep(i, s.size()){
        int ind = ToNum(s[i]);
        if(node->children[ind]){
          if(node->tail[ind].size()>0){
          }
          rep(j,node->tail[ind].size()){
            if(s.size() == i+j+1)return false;
            if(s[i+j+1] != node->tail[ind][j]) return false;
          }
          i+= node->tail[ind].size();
          node = node->children[ind];
        }else{
          return false;
        }
      }
      return node->leaf;
    }
};

int memo[100010][32][32];
bool use[100010][32];
int match[100010];

vector<string> s;
int main(void){
  int n,q,tmp;
  string str;
  Trie trie;
  cin >> n;
  rep(i,n){
    cin >> str;
    trie.insert(str);
    s.pb(str);
  }
  trie.compress();
  
  rep(i,n){
    shared_ptr<Node> node = trie.root;
    int res = 0;
    rep(j, s[i].size()){
      int index = s[i][j]-'a';
      rep(k,KINDS){
        if( k == s[i][j]-'a') continue;
        if(node->children[k]){
          memo[i][k][index] += node->children[k]->count;
        }
      }
      tmp = node->tail[ToNum(s[i][j])].size();
      node = node->children[ToNum(s[i][j])];
      j+=tmp;
      if(node->leaf)res++;
    }
    match[i] = res;
  }

  cin >> q;
  rep(i,q){
    int res = 0 ,ind;
    cin >> ind;
    cin >> str;
    ind--;
    rep(j,KINDS){
      reps(k,j+1,KINDS-1){
        res += memo[ind][str[j]-'a'][str[k]-'a'];
      }
    }
    res += match[ind];

    /*
    shared_ptr<Node> node = trie.root;
    rep(j, s[ind].size()){
      rep(k,KINDS){
        if(str[k] == s[ind][j]) break;
        if(node->children[ToNum(str[k])])
          res+=node->children[ToNum(str[k])]->count;
      }
      
      if(node->leaf)res++;
      tmp = node->tail[ToNum(s[ind][j])].size();
      node = node->children[ToNum(s[ind][j])];
      j+=tmp;
    }
    */
    cout << res << endl;
  }



  return 0;
}
