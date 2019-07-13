//AtCoder ABC110 B - 1 Dimensional World's Tale
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
int main() {
    ll N,M,X,Y; cin>>N>>M>>X>>Y;
    vector<ll> xn(N);
    vector<ll> ym(M);
    for(auto&& x:xn){
        cin>>x;
    }
    for(auto&& y:ym){
        cin>>y;
    }
    sort(xn.begin(),xn.end());
    sort(ym.begin(),ym.end());
    ll xn_max=xn.back();
    ll ym_min=ym.front();
    bool ans=false;
    for(ll z=X+1;z<=Y;++z){
        if (xn_max<z&&ym_min>=z) {
            ans=true;
            break;
        }
    }
    cout<<(ans?"No War":"War")<<endl;
    return 0;
}
