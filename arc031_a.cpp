//https://atcoder.jp/contests/arc031/tasks/arc031_1
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    string name; cin>>name;
    bool ans=true;
    for(ll i=0;i<name.size()/2;++i){
        if(name[i]!=name[name.size()-i-1]){
            ans=false;
        }
    }    
    cout<<(ans?"YES":"NO")<<endl;
    return 0;
}