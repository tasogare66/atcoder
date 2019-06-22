//AtCoder ABC091 B - Two Colors Card Game
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
    ll N;
    cin>>N;
    unordered_map<string,ll> blue;
    for(ll i=0;i<N;++i){
        string s;
        cin>>s;
        ++blue[s];
    }
    ll M;
    cin>>M;
    unordered_map<string,ll> red;
    for(ll i=0;i<M;++i){
        string s;
        cin>>s;
        ++red[s];
    }
    ll ans=0;
    for(auto& b:blue){
        ll v=b.second;
        auto it = red.find(b.first);
        if (it !=red.end()){
            v-=it->second;
        }
        ans=max(ans,v);
    }
    cout<<ans<<endl;
    return 0;
}