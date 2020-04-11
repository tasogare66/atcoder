//https://atcoder.jp/contests/hitachi2020/tasks/hitachi2020_c
//C - ThREE
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
    edge(int _to, T _cost) : src(-1), to(_to), cost(_cost) {}
    edge(int _src, int _to, T _cost) : src(_src), to(_to), cost(_cost) {}
    edge &operator=(const int &x) {
        to = x;
        return *this;
    }
    operator int() const { return to; }
};

template< typename T>
struct node {
    vector<edge<T>> edges;
    int blue_red=0; //0,青 1,赤
    bool visited=false;
};

template< typename T >
using Edges = vector< edge< T > >;
template< typename T >
using WeightedGraph = vector< node< T > >;
using UnWeightedGraph = vector< vector< int > >;
template< typename T >
using Matrix = vector< vector< T > >;

int main() {
#if LOCAL&01
    std::ifstream in("./test/sample-1.in");
    //std::ifstream in("./input.txt");
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll N; cin>>N;
    WeightedGraph<ll> graph(N+1);
    FOR(i,0,N-1){
        ll a,b; cin>>a>>b;
        graph.at(a).edges.emplace_back(a,b,1);
        graph.at(b).edges.emplace_back(b,a,1);
        assert(a<=N&&b<=N);
    }

    //1からbfsする
#if 1
    queue<ll> que;
    que.push(1);
    graph.at(1).blue_red=1;
    graph.at(1).visited=true;
    while(not que.empty()){
        const auto&n = que.front();
        que.pop();
        const auto& cur_n=graph.at(n);
        for(const auto& e:cur_n.edges){
            auto& next_p = graph.at(e.to);
             if (next_p.visited) continue;	
             next_p.blue_red = (cur_n.blue_red+1)%2;
             next_p.visited=true;
             que.push(e.to);
        }
    }
#else //通った
    stack<ll> que;
    que.push(1);
    graph.at(1).blue_red=1;
    graph.at(1).visited=true;
    while(not que.empty()){
        const auto&n = que.top();
        que.pop();
        const auto& cur_n=graph.at(n);
        for(const auto& e:cur_n.edges){
            auto& next_p = graph.at(e.to);
             if (next_p.visited) continue;	
             next_p.blue_red = (cur_n.blue_red+1)%2;
             next_p.visited=true;
             que.push(e.to);
        }
    }
#endif
    // cout<<-1<<endl;
    // return 0;

    //count blue
    vector<ll> numtbl[2];
    FOR(i,1,N+1){
        auto br = graph.at(i).blue_red;
        assert(br==0||br==1);
        numtbl[br].push_back(i);
    }
    vector<ll> ans(N+1);
    auto result_func = [&](const auto& tbl){
        //0に3いれ
        ll n3=3;
        for(const auto& n:tbl){
            ans[n]=n3;
            n3+=3;
        }
        ll v=1;
        FOR(i,1,N+1){
            auto&& a=ans[i];
            if(a>0)continue;
            if(v%3==0&&v<n3)++v;
            a=v++;
        }
    };
    if(numtbl[0].size()<=N/3){
        result_func(numtbl[0]);
    } else if(numtbl[1].size()<=N/3){
        //1に3いれ
        result_func(numtbl[1]);
    } else {
        //mod1,mo2をそれぞれつめて、のこりを3で
        FOR(i,0,2){
            ll n3=0;
            for(auto n:numtbl[i]){
                ll v=3*n3+1+i;
                if(v>N)break;
                ans[n]=v;
                ++n3;
            }
        }
        ll n3=3;
        FOR(i,1,N+1){
            auto&& a=ans[i];
            if(a>0)continue;
            ans[i]=n3;
            n3+=3;
        }
    }

    FOR(i,1,N+1){
        if(i!=1)cout<<" ";
        cout<<ans.at(i);
    }
    cout<<endl;

    return 0;
}