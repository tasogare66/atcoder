//https://atcoder.jp/contests/exawizards2019/tasks/exawizards2019_c
//C - Snuke the Wizard
#include <bits/stdc++.h>
#if LOCAL
#include "dump.hpp"
#else
#define dump(...)
#endif
using namespace std;
using ll=long long;
#define FOR(i,a,b) for(ll i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
template<class T>bool chmax(T &a, const T &b) {if (a<b) { a=b; return 1; } return 0;}
template<class T>bool chmin(T &a, const T &b) {if (b<a) { a=b; return 1; } return 0;}
int main() {
#if LOCAL&01
    std::ifstream in("./test/sample-2.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll N,Q; cin>>N>>Q;
    string s; cin>>s;
    struct Info{
        char c;
        char d;
        ll ofs=0;
    };
    vector<Info> tdq(Q);
    for(auto&& tq:tdq){
        cin>>tq.c>>tq.d;
        tq.ofs = tq.d=='L'?-1:1;
    }

    auto check_t = [&](ll v,ll pos){ //vが到達するか?
        for(const auto& tq:tdq){
            auto c=s.at(v);
            if (c==tq.c) v+=tq.ofs;
            if (v==pos) return true;
            if (v<0||v>=s.size()) break;
        }
        return false;
    };
    auto check_func = [&](ll pos,bool is_flag){
        ll lb=0,ub=s.size();
        while(ub-lb>1){
            ll mid=(lb+ub)/2;
            if(check_t(mid,pos)==is_flag){
                ub=mid;
            } else {
                lb=mid;
            }
            dump(mid,lb,ub);
        }
        return ub;
    };
    // REP(i,s.size()){
    //     dump(i,check_t(i,-1));
    //     dump(i,check_t(i,s.size()));
    // }

    ll r=check_func(s.size(),true)-1;
    dump(r);
    ll l=check_func(-1,false);
    dump(l);
    //assert(r>=l);
    cout<<r-l+1<<endl;
    return 0;
}
int main_() {
#if LOCAL&01
    std::ifstream in("./test/sample-1.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll N,Q; cin>>N>>Q;
    string s; cin>>s;
    vector<ll> num(N,1);
    unordered_map<char,vector<ll>> c_pos;    
    REP(i,s.size()){
        auto c=s[i];
        c_pos[c].push_back(i);
    }

    REP(i,Q){
        char t,d; cin>>t>>d;
        ll ofs=d=='L'?-1:1;
        for(auto& pos :c_pos[t]){
            if(pos+ofs>=0&&pos+ofs<num.size()) num[pos+ofs]+=num[pos];
            num[pos]=0;
        }
    }
    ll ans=accumulate(num.begin(),num.end(),0LL);
    cout<<ans<<endl;

    return 0;
}