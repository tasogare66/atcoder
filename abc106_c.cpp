//AtCoder ABC106 C - To Infinity
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
int main() {
    string S;
    ll K; cin>>S>>K;
    char ans='1';
    for(ll i=0;i<K;++i){
        if (S[i]!='1'){
            ans=S[i];
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}