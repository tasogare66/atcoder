//AtCoder ABC086 C - Traveling
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
struct Pt{
    ll t=0;
    ll x=0,y=0;
};
int main() {
    ll N;
    cin>>N;
    vector<Pt> tbl(N+1); //0はスタート位置
    for(ll i=1;i<=N;++i){
        auto&& p=tbl[i];
        cin>>p.t>>p.x>>p.y;
    }
    bool ans=true;
    for(int i=0;i<tbl.size()-1;++i){
        //次にいけるか
        const auto& st = tbl[i];
        const auto& ed = tbl[i+1];
        ll dist=abs(ed.x-st.x)+abs(ed.y-st.y);
        ll dur=ed.t-st.t;
        if (dist>dur) {
            ans=false;
        } else if((dur-dist)%2!=0){
            ans=false;
        }
        if (!ans)break;
    }
    cout<<(ans?"Yes":"No")<<endl;
    return 0;
}