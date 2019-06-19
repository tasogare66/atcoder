//AtCoder 
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

vector<ll> vtbl(4);
vector<ll> ans;
ll search(int i, bool minus, vector<ll> tbl){
    if(i >= vtbl.size()){
        ll sum=0;
        for(const auto& t:tbl){
            sum+=t;
        }
        if (sum==7){
            //ans
            ans=tbl;
            return 1;
        }
        return 0;
    }

    ll v=minus?-vtbl[i]:vtbl[i];
    tbl[i]=v;
    if(search(i+1, false, tbl)){
        return 1;
    }
    if(search(i+1, true, tbl)){
        return 1;
    }
    return 0;
}
int main() {
#if LOCAL&0
    std::ifstream in("input.txt");
    std::cin.rdbuf(in.rdbuf());
#endif
    string S;
    cin>>S;
    for(int i=0;i<S.length();++i){
        vtbl[i] = S[i]-'0';
    }

    search(0,false,vtbl);
    for(ll i=0;i<ans.size();++i){
        if(i==0)cout<<ans[i];
        else {
            cout<<(ans[i]>=0?"+":"")<<ans[i];
        }
    }
    cout<<"=7"<<endl;
    return 0;
}