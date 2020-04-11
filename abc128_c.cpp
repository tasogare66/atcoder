//https://atcoder.jp/contests/abc128/tasks/abc128_c
//C - Switches
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
int main() { //bit全探索
#if LOCAL&01
    std::ifstream in("./test/sample-1.in");
    //std::ifstream in("./input.txt");
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll N,M; cin>>N>>M;    
    vector<ll> masks(M);
    FOR(i,0,M){
        ll k; cin>>k;
        ll mask=0;
        FOR(j,0,k){
            ll s; cin>>s;
            mask |= (1LL<<(s-1LL));
        }
        masks.at(i)=mask;
    }
    vector<ll> pm(M);
    for(auto&& p:pm){
        cin>>p;
    }

    ll ans=0;
    ll max=1LL<<N;
    FOR(i,0,max){
        bool flag=true;
        FOR(j,0,M){
            const auto& m = masks.at(j);
            auto tmp=i&m;
            auto num=__builtin_popcountll(tmp);
            if(num%2!=pm.at(j)){
                flag=false;
                break;
            }
        }
        if(flag)++ans;
    }
    cout<<ans<<endl;
    return 0;
}

//dfs
struct Denk{
    vector<int> sw;
    int p=0;
    bool check(const vector<int>& onoff){
        int cnt=0;
        for(auto n:sw){
            if(onoff[n-1]) ++cnt;
        }
        return(cnt%2==p);
    }
};

int N,M;
vector<Denk> ds;
vector<int> onoff(11,0);
int ans=0;

bool judge(const vector<int>& sw)
{
    for(auto&& d:ds){
        if(!d.check(sw)) return false;
    }
    return true;
}

void check(int i, vector<int> sw){
    if (i >= N){//hantei
        if(judge(sw)){
            ++ans;
        }
        return;
    }
    //on
    sw[i]=0;
    check(i+1, sw);
    //off
    sw[i]=1;
    check(i+1, sw);
}

int _main() {
#if LOCAL&01
    std::ifstream in("input.txt");
    std::cin.rdbuf(in.rdbuf());
#endif
    cin>>N>>M;
    ds.resize(M);    
    for(auto&& d:ds){
        int k;
        cin>>k;
        for(int i=0;i<k;++i){
            int sw;
            cin>>sw;
            d.sw.push_back(sw);
        }
    }
    for(auto&& d:ds){
        cin>>d.p;
    }
    //全sw試す
    vector<int> sw(N,0);
    check(0,sw);
    cout<<ans<<endl;
    return 0;
}