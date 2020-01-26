//https://atcoder.jp/contests/keyence2020/tasks/keyence2020_d
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
#if 0
int main___(){
    ll N; cin>>N;
    vector<ll> an(N);
    vector<ll> bn(N);
    for(auto& a: an){
        cin>>a;
    }
    for(auto& b:bn){
        cin>>b;
    }

    auto calc_tentou = [](const auto& an){
        ll ret=0;
        FOR(i,0,an.size()){
            FOR(j,i,an.size()){
                if(an[i]>an[j]){
                    ++ret;
                }
            }
        }
        return ret;
    };

    auto at = calc_tentou(an);
    auto bt = calc_tentou(bn);
    bool ok_flag=false;
    if(at==0){
        ok_flag=true;
    }
    if(at==bt){
        ok_flag=true;
    }
    if(ok_flag){
        cout<<at<<endl;
    }else{
        cout<<-1<<endl;
    }

    return 0;
}
#endif
int main() {
#if LOCAL&01
    std::ifstream in("./test/sample-1.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll N; cin>>N;
    vector<ll> an(N);
    vector<ll> bn(N);
    for(auto& a: an){
        cin>>a;
    }
    for(auto& b:bn){
        cin>>b;
    }

    auto bubble = [&](ll i,ll j){
        swap(an[i],bn[j]);
        swap(an[j],bn[i]);
    };
    auto calc_tentou = [&](){
        ll ret=0;
        FOR(i,0,an.size()){
            FOR(j,i,an.size()){
                if(an[i]>an[j]){
                    ++ret;
                }
            }
        }
        return ret;
    };
 
    bool ok_flag=false;
    auto ans=calc_tentou();

    while(true){
        auto t = calc_tentou();
        if(t==0) ok_flag=true;

        for(ll i=an.size()-2;i>=0;--i){
            if(an[i]>an[i+1]){
                bubble(i,i+1);
            }
        }

        auto tp = calc_tentou();
        dump(t,tp);
        if(t==tp) {
            cout<<-1<<endl;
            return 0;
        }
    }
    cout<<ans<<endl;

    return 0;
}


int main_() {
#if LOCAL&01
    std::ifstream in("./test/sample-5.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll N; cin>>N;
    vector<ll> an(N);
    vector<ll> bn(N);
    for(auto& a: an){
        cin>>a;
    }
    for(auto& b:bn){
        cin>>b;
    }
    ll ans=0;
    FOR(i,0,an.size()){
        FOR(j,i,an.size()){
            if(an[i]>an[j]){
                if(bn[i]<bn[j]){
                    dump(i,j);
                    cout<<-1<<endl;
//                    return 0;
                }
                ++ans;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}