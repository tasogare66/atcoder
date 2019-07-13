//AtCoder ABC122 C - GeT AC
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
    ll N,Q; cin>>N>>Q;
    string S; cin>>S;
    vector<ll> sum(S.size(),0);
    ll cnt=0;
    for(ll i=1;i<S.size();++i){
        if (S[i-1]=='A'&&S[i]=='C') {
            ++cnt;
        }
        sum[i]=cnt;
    }
    vector<ll> ans;
    for(int i=0;i<Q;++i){
        ll l,r; cin>>l>>r;
        --l;
        --r;
        ans.push_back(sum[r]-sum[l]);
    }
    for(const auto& a:ans){
        cout<<a<<endl;
    }
    return 0;
}
