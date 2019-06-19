//AtCoder ABC088 C - Takahashi's Information
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
    ll ctbl[3][3];
    ll ttl=0;
    for(ll y=0;y<3;++y){
        for(ll x=0;x<3;++x){
            ll c;
            cin>>c;
            ctbl[y][x]=c;
            ttl+=c;
        }
    }
    ll xt[3]={}; //各行の和
    ll yt[3]={}; //各列の和
    for(int i=0;i<3;++i){
        for(int j=0;j<3;++j){
            yt[i]+=ctbl[i][j];
            xt[i]+=ctbl[j][i];
        }
    }
    bool ans=(ttl%3==0); //合計が3でわれる
    ans &= ((yt[0]-yt[1])%3==0); //3でわれる
    ans &= ((yt[0]-yt[2])%3==0);
    ans &= ((yt[1]-yt[2])%3==0);
    ans &= ((xt[0]-xt[1])%3==0);
    ans &= ((xt[0]-xt[2])%3==0);
    ans &= ((xt[1]-xt[2])%3==0);
    cout<<(ans?"Yes":"No")<<endl;
    return 0;
}