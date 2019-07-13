//AtCoder ABC107 B - Grid Compression
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
int main() {
    ll H,W; cin>>H>>W;
    vector<string> hw(H);
    for(auto& a:hw){
        cin>>a;
    }
    //
    unordered_set<ll> drow;
    unordered_set<ll> dcol;
    auto check_row=[&](ll y){
        bool rslt=true;
        for(auto&& s:hw[y]){
            if(s!='.') {
                rslt=false;
                break;
            }
        }
        if(rslt) drow.insert(y);
    };
    auto check_col=[&](ll x){
        bool rslt=true;
        for(ll y=0;y<hw.size();++y){
            if(hw[y][x]!='.'){
                rslt=false;
                break;
            }
        }
        if(rslt) dcol.insert(x);
        return false;
    };
    for(ll y=0;y<hw.size();++y){
        check_row(y);
    }
    for(ll x=0;x<hw[0].size();++x){
        check_col(x);
    }
    for(ll y=0;y<hw.size();++y){
        if(drow.count(y)) continue;
        for(ll x=0;x<W;++x){
            if(dcol.count(x)) continue;
            cout<<hw[y][x];
        }
        cout<<endl;
    }
    return 0;
}