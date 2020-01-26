//https://atcoder.jp/contests/aising2019/tasks/aising2019_d
//D - Nearest Card Game
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
    ll N, Q; cin>>N>>Q;
    vector<ll> an(N);
    for(auto&& a:an){
        cin>>a;
    }
    sort(an.begin(),an.end());
    vector<ll> xq(Q);
    for(auto&& x:xq){
        cin>>x;
    }    

}
int main_() {
#if LOCAL&01
    std::ifstream in("./test/sample-1.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll N, Q; cin>>N>>Q;
    vector<ll> an(N);
    for(auto&& a:an){
        cin>>a;
    }
    sort(an.begin(),an.end());
    vector<ll> xq(Q);
    for(auto&& x:xq){
        cin>>x;
    }    

    auto simulate = [&](ll x){
        auto tmp = an;
        ll sc[2]={};
        while(tmp.size() > 0){
            sc[0] += tmp.back();
            tmp.pop_back();

            if (tmp.size()<=1){
                break;
            }
            bool flag=true;
            for(auto it=tmp.begin();it!=tmp.end();++it){
                if(x<*it){
                    if(it==tmp.begin()){
                        sc[1]+=(*it);
                        tmp.erase(it);
                        flag=false;
                        break;
                    }else{
                        ll p0=abs(x-*(it-1));
                        ll p1=abs(x-*it);
                        if (p0<=p1){
                            sc[1]+=*(it-1);
                            tmp.erase(it-1);
                        }else{
                            sc[1]+=*it;
                            tmp.erase(it);
                        }
                        flag=false;
                        break;
                    }
                }
            }
            if (flag) {
                sc[1] += tmp.back();
                tmp.pop_back();
            }
        }
        return sc[0];
    };
    //dump(simulate(9));
    for(const auto& x:xq){
        ll ans=simulate(x);
        //dump(x);
        cout<<ans<<endl;
    }

    return 0;
}