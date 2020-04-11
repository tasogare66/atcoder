//https://atcoder.jp/contests/chokudai_S002/tasks/chokudai_S002_i
//I - カツサンドくん β
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
#if LOCAL&0
    std::ifstream in("./test/sample-4.in");
    //std::ifstream in("./input.txt");
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll N; cin>>N;
    vector<pair<ll,ll>> abn(N);
    REP(i,N){
        ll A,B;
        cin>>A>>B;
        abn.at(i).first=A;
        abn.at(i).second=B;
    }
    auto check_vs = [&](ll f,ll s)->ll{
        assert(f!=s);
        const auto& fd = abn.at(f);
        const auto& sd = abn.at(s);
        ll f_atk = (sd.first + (fd.second-1)) / fd.second;
        ll s_atk = (fd.first + sd.second -1) / sd.second;
        if(f_atk>s_atk) return s;
        else if(f_atk<s_atk) return f;
        return -1;
    };
    // dump(check_vs(0,1));
    // dump(check_vs(1,2));
    // dump(check_vs(0,2));
    ll cur=0;
    ll ans=1;//-1;
    FOR(i,1,abn.size()){
        auto result = check_vs(cur, i);
        if(result !=-1){
            cur = result;
            ans=cur+1;
        }else{
            ans=-1;
        }
    }
    //暫定が本当に勝てるか?
    if(ans>=0){
        ll provisional = ans-1;
        FOR(i,0,abn.size()){
            if(i==provisional) continue;
            if(provisional != check_vs(i,provisional)){
                ans = -1;
                break;
            }
        }
    }

    cout<<ans<<endl;
    return 0;
}