//https://atcoder.jp/contests/abc123/tasks/abc123_d
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
#if LOCAL&01
    std::ifstream in("./test/sample-1.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll X,Y,Z,K; cin>>X>>Y>>Z>>K;
    vector<ll> ax(X);
    vector<ll> by(Y);
    vector<ll> cz(Z);
    for(auto&& a:ax){ cin>>a; }
    for(auto&& b:by){ cin>>b; }
    for(auto&& c:cz){ cin>>c; }
#if 1
    using SumABC=tuple<ll,ll,ll,ll>; //sum,a_id,b_id,c_id
    priority_queue<SumABC> que;
    sort(ax.begin(),ax.end(),greater<ll>());
    sort(by.begin(),by.end(),greater<ll>());
    sort(cz.begin(),cz.end(),greater<ll>());

    set<tuple<ll,ll,ll>> se;
    auto que_pb = [&](ll ix,ll iy, ll iz){
        if(ix<ax.size()&&iy<by.size()&&iz<cz.size()){
            tuple<ll,ll,ll> s = make_tuple(ix,iy,iz);
            if (se.count(s)) return;
            auto tmp=ax[ix]+by[iy]+cz[iz];
            que.emplace(make_tuple(tmp,ix,iy,iz));
            se.emplace(s);
        }
    };

    //que.emplace(make_tuple(ax[0]+by[0]+cz[0],0,0,0));
    que_pb(0,0,0);
    REP(k,K){
        ll sum,x,y,z;
        tie(sum,x,y,z)=que.top();
        que.pop();
        cout<<sum<<endl;
        que_pb(x+1,y,z);
        que_pb(x,y+1,z);
        que_pb(x,y,z+1);
    }
#else
    //半分列挙
    vector<ll> abw(X*Y);
    REP(x,X){
        REP(y,Y){
            abw.at(y*X+x) = ax.at(x) + by.at(y);
        }
    }
    sort(abw.begin(),abw.end(),greater<ll>());
    sort(cz.begin(),cz.end(),greater<ll>());

    vector<ll> tt;
    tt.reserve(K*K);
    REP(i,min<ll>(K,abw.size())){
        REP(j,min<ll>(K,cz.size())){
            tt.emplace_back(abw.at(i)+cz.at(j));
        }
    }

    sort(tt.begin(),tt.end(),greater<ll>());
    REP(i,K){
        cout<<tt.at(i)<<endl;
    }
#endif
    return 0;
}
