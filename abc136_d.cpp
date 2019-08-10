//https://atcoder.jp/contests/abc136/tasks/abc136_d
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
#if LOCAL&01
    std::ifstream in("./input.txt"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#endif
    string S; cin>>S;
    vector<ll> ans(S.size());
    ll a=0;
    ll b=0;
    for(ll i=0;i<S.size()-1;++i){
        swap(a,b);
        if(S[i]=='R'&&S[i+1]=='L'){
            ans[i]=1+a;
            ans[i+1]=1+b;
            a=0;
            b=0;
        } else if(S[i]=='R'){
            ++a;
        }
    }    
    //反対から
    a=0,b=0;
    for(ll i=S.size()-1;i>=1;--i){
        swap(a,b);
        if(S[i-1]=='R'&&S[i]=='L'){
            ans[i-1]+=b;
            ans[i]+=a;
            a=0;
            b=0;
        } else if(S[i]=='L'){
            ++a;
        }
    }    
    REP(i,ans.size()){
        if(i==0){
            cout<<ans[i];
        } else {
            cout<<" "<<ans[i];
        }
    }
    cout<<endl;
    return 0;
}