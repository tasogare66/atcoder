//AtCoder 
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
    vector<ll> cn(N); //時間
    vector<ll> sn(N); //開始
    vector<ll> fn(N); //間隔
    for(ll i=0;i<N-1;++i){
        cin>>cn[i]>>sn[i]>>fn[i];
    }
    vector<ll> ans(N,0);
    for(ll s=0;s<N;++s){
        auto& av=ans[s];
        for(ll i=s;i<N-1;++i){
            if(av<=sn[i]) av=sn[i];
            else if (av%fn[i]!=0) {
                av = av+fn[i] - av%fn[i];
            }
            av += cn[i];
        }
    }
    for(const auto& a:ans){
        cout<<a<<endl;
    }
    return 0;
}