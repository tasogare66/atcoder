//AtCoder ABC118 C - Monsters Battle Royale
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
int main() {
#if LOCAL&0
    std::ifstream in("./test/sample-1.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#endif
    ll N; cin>>N;
    vector<ll> an(N);
    for(auto&& a:an){
        cin>>a;
    }    
    sort(an.begin(),an.end());
    ll ans=an[0];
    while(an.size()>1){
        for(ll i=1;i<an.size();++i){
            an[i]%=ans;
        }
        sort(an.begin(),an.end());
        an.erase(std::remove(an.begin(), an.end(), 0), an.end()); 
        ans=an[0];
    }
    cout<<ans<<endl;
    return 0;
}