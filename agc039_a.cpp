//https://atcoder.jp/contests/agc039/tasks/agc039_a
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#if LOCAL
#include "dump.hpp"
#else
#define dump(...)
#endif
int main() {
#if LOCAL&01
    //std::ifstream in("./test/sample-1.in"); //input.txt
    std::ifstream in("./input.txt"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
//    cin.tie(0);
//    ios::sync_with_stdio(false);
#endif
    string S; cin>>S;
    ll T; cin>>T;
    //先頭
    ll hlen=1;
    char hch=S[0];
    char fch=S.back();

    auto check_all_same = [&]{
        char c = S.at(0);
        FOR(i,1,S.size()){
            if(c!=S.at(i)){
                return false;
            }
        }
        return true;
    };
    auto get_num = [&](ll st, ll ed){
        ll ret=0;
        ll sc=1;
        char c = S.at(st);
        FOR(i,st+1,ed+1){
            if(c==S.at(i)){
                ++sc;
            } else {
                ret += (sc/2);
                sc = 1;
            }
            c=S.at(i);
        }
        ret += (sc/2);
        return ret;
    };
    auto get_head = [](const string& str){
        ll ret = 1;
        char c=str.at(0);
        FOR(i,1,str.size()) {
            if (str.at(i)==c){
                ++ret;
            }else{
                break;
            }
        }
        return ret;
    };
    ll ans = 0;
    ll tmp=get_num(0,S.size()-1);
    if (check_all_same()){
        //全部同じ
        dump("same");
        ans = S.size() * T / 2;
    } else if (hch==fch){
        ll hnum = get_head(S);
        auto Sr=S; std::reverse(Sr.begin(),Sr.end());
        ll fnum = get_head(Sr);
        auto aida = get_num(hnum,S.size()-fnum-1);
        ans= hnum / 2 + fnum / 2 + aida * T + ((hnum+fnum)/2) * (T-1);        
    } else {
        ans=tmp * T;
    }
    cout<<ans<<endl;
    return 0;
}