//https://atcoder.jp/contests/abc150/tasks/abc150_d
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

ll lcm(ll num1,ll num2){
    return num1 / __gcd(num1,num2) * num2;
}

int main() {
#if LOCAL&01
    //std::ifstream in("./test/sample-2.in"); //input.txt
    std::ifstream in("input.txt"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif    
    ll N, M; cin>>N>>M;
    vector<ll> an(N);
    for(auto&& a:an){
        cin>>a;
    }
#if 1
    auto test2 = [&](){
        //a*(2*p+1) <= 100
        ll a=5;
        ll p=0;
        ll cnt=0;
        while(true){
            if (a*(2*p+1) <= 100){
                ++cnt;
            }else{
                break;
            }
			++p;
		}
        ll num=floor((100-a)/(2*a));
        dump(cnt,num);
    };
    test2();
#endif
    ll lcmv=an[0]/2;
    ll lcmv2=an[0];
    FOR(i,1,N){
        lcmv=lcm(lcmv,an[i]/2);
        lcmv2=lcm(lcmv2,an[i]);
    }
    for(auto& a:an){
        ll tmp = lcmv2 / a;
        if (tmp %2 ==0) {
            cout<<0<<endl;
            return 0;
        }
    }
#if 0
    auto test = [&](){
        vector<int> is_lcm(M+1, 0);
        for(auto ak:an){
            ll p=0;
            while (true) {
                auto x = ak * p + ak / 2;
                if (x>M) break;
                is_lcm.at(x)++;
                ++p;    
            }
        }
        vector<ll> o;
        FOR(i,0,M+1){
            if(is_lcm.at(i)==an.size()) o.emplace_back(i);
        }
        dump(o,o.size());
    };
    test();
#endif
    dump(lcmv);
    ll ans=max((M-lcmv)/(lcmv*2),0LL);
    if(M-lcmv>=0) ++ans;
    dump(M-lcmv);
    cout<<ans<<endl;
    return 0;
}
