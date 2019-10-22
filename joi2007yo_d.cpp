//https://atcoder.jp/contests/joi2007yo/tasks/joi2007yo_d
//D - カードの並び替え
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
#if LOCAL&01
    std::ifstream in("./test/sample-1.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll n; cin>>n; //2n枚
    ll m; cin>>m;
    vector<ll> km(m);
    for(auto&& k:km){
        cin>>k;
    }

    vector<ll> nxt(2*n+1),now(2*n+1);
    FOR(i,1,2*n+1){
        now.at(i)=i;
    }

    for(const auto& k:km){
        if (k==0){
            //shuffle
            FOR(i,1,n+1){
                nxt.at(2*i-1)=now.at(i);
                nxt.at(2*i)=now.at(n+i);
            }
        }else{
            //cut
            copy(now.begin()+k+1,now.end(),nxt.begin()+1);
            copy(now.begin()+1,now.begin()+k+1,nxt.begin()+2*n-k+1);
        }
        now=nxt;//copy
    }

    FOR(i,1,2*n+1){
        cout<<now.at(i)<<endl;
    }
    return 0;
}