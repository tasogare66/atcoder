//AtCoder ABC082 C - Good Sequence
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
#if LOCAL&0
    std::ifstream in("input.txt");
    std::cin.rdbuf(in.rdbuf());
#endif
    ll N;
    cin>>N;
    vector<ll> atbl(N);
    unordered_map<ll,ll> anums;
    for(auto&& a:atbl){
        cin>>a;
        ++anums[a];
    }
    ll ans=0;
    for(auto&& t:anums){
        if(t.first>t.second){
            ans+=t.second;
        } else if(t.first<t.second){
            ans+=(t.second-t.first);
        }
    }
    cout<<ans<<endl;
    return 0;
}