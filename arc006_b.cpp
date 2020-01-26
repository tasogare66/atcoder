//https://atcoder.jp/contests/arc006/tasks/arc006_2
//B - あみだくじ
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
    std::ifstream in("./test/sample-1.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll N,L; cin>>N>>L;
    cin.ignore();    
    vector<string> sl(L+1);
    for(auto&& s:sl){
        //cin>>s;
        getline(cin, s);
    }
    ll ans=0;
    for(auto c:sl.back()){
        if (c=='o'){
            break;
        }
        ++ans;
    }
    for(ll i=sl.size()-1;i>=0;--i){
        const auto& str=sl[i];
        auto get_ch =[&](ll pos){
            if(pos<0) return 'x';
            if(pos>=str.size()) return 'x';
            return str[pos];
        };
        if(get_ch(ans-1)=='-'){
            ans-=2;
        } else if (get_ch(ans+1)=='-'){
            ans+=2;
        }
    }
    ans=ans/2+1;
    cout<<ans<<endl;
    return 0;
}