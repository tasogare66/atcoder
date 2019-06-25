//AtCoder ABC098 B - Cut and Count
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
    ll N;
    string S;
    cin>>N>>S;
    //全探索でいいや
    unordered_set<char> us;
    ll ans=0;
    for(ll i=0;i<N-1;++i){
        us.insert(S[i]);
        ll candi=0;
        for(auto& c:us){
            for(ll j=i+1;j<N;++j){
                if(c==S[j]) {
                    candi++;
                    break;
                }
            }
        }
        ans=max(ans,candi);
    }
    cout<<ans<<endl;
    return 0;
}