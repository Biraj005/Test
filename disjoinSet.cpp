#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll MOD=1e9 + 7 ;

class disjointSet{
    vector<int> rank,parrent;
    disjointSet(int n){
        rank.resize(n+1,0);
        parrent.resize(n+1);
        for(int i=0;i<=n;i++){
            parrent[i]=i;
        }
    }
    int ulParent(int n){
        if(n==parrent[n]) return n;

        return parrent[n]=(parrent[n]);
    }
    void unioByRank(int u,int v){
      int up_u=ulParent(u);
      int up_v=ulParent(v);
      if(up_u==up_v) return;
       
      if(up_u<up_v){
        parrent[up_u]=up_v;
      }else if(up_u>up_v){
        parrent[up_v]=up_u;
      }else{
        parrent[up_u]=up_v;
        rank[up_v]++;
      }
    }

};
int main() {
    return 0;
}