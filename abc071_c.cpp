//AtCoder ABC071 C - Make a Rectangle
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
    ll N;
    cin>>N;
    unordered_map<ll,ll> lm;
    for(int i=0;i<N;++i){
        ll a;
        cin>>a;
        lm[a]++;
    }
    vector<pair<ll,ll>> tbl(lm.size());
    ll no=0;
    for(const auto& i:lm){
        tbl[no++]=i;
    }
    sort(tbl.begin(),tbl.end(),[](auto& a, auto& b){
        return (a.first>b.first);
    });
    ll a=0,b=0;
    for (auto&& t:tbl) {
        if(t.second>=2 && a<=0) {
            a=t.first;
            t.second -= 2;
        }
        if(t.second>=2 && b<=0) {
            b=t.first;
            t.second -= 2;
            break;
        }
    }
    cout<<a*b<<endl;
    return 0;
}