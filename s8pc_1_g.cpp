//https://atcoder.jp/contests/s8pc-1/tasks/s8pc_1_g
//G - Revenge of Traveling Salesman Problem
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

template< typename T >
struct edge {
	int src, to;
	T cost;
    ll time;
	edge(int _to, T _cost, ll _time) : src(-1), to(_to), cost(_cost), time(_time) {}
	//edge(int _src, int _to, T _cost) : src(_src), to(_to), cost(_cost) {}
	edge &operator=(const int &x) {
		to = x;
		return *this;
	}
	operator int() const { return to; }
};

template< typename T>
struct node {
	vector<edge<T>> edges;
};

template< typename T >
using Edges = vector< edge< T > >;
template< typename T >
using WeightedGraph = vector< node< T > >;
using UnWeightedGraph = vector< vector< int > >;
template< typename T >
using Matrix = vector< vector< T > >;

int main() {
    ll N, M; cin>>N>>M;    
    WeightedGraph<ll> graph(N);
    REP(i,M){
        ll s,t,d,time; cin>>s>>t>>d>>time;
        --s; --t;
        graph.at(s).edges.emplace_back(t,d,time);
        graph.at(t).edges.emplace_back(s,d,time);
    }
    constexpr ll INF=2LL<<60;
    ll max_bit=1LL<<N;
    vector<vector<ll>> dp(N,vector<ll>(max_bit,INF));
    vector<vector<ll>> cnt(N,vector<ll>(max_bit));
    dp[0][0]=0;
    cnt[0][0]=1;
    FOR(m,0,max_bit){
        FOR(i,0,N){
            if(dp[i][m]==INF) continue;
            //if(not(m & (1LL<<i))) continue;
            for(const auto& e:graph.at(i).edges){
                if (m & (1LL<<e.to)) continue;
                ll next_m = m|(1LL<<e.to);
                const ll next_cost = dp[i][m]+e.cost;
                if (e.time < next_cost) continue;
                if (dp[e.to][next_m] == next_cost) {
                    cnt[e.to][next_m] += cnt[i][m];
                } else if (chmin(dp[e.to][next_m],next_cost)){
                    cnt[e.to][next_m] = cnt[i][m];
                }
            }
        }
    }
    ll ans=dp[0][max_bit-1];
    if(ans==INF) {
         cout<<"IMPOSSIBLE"<<endl;
    } else{
        cout<<ans<<" "<<cnt[0][max_bit-1]<<endl;
    }

    return 0;
}
