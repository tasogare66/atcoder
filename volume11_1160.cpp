//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1160&lang=jp
//How Many Islands?
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

//2重配列上でdfs
bool solve2(){
    ll w,h; cin>>w>>h;
    if(w==0&&h==0)return false;//終わり
    vector<vector<ll>> chw(h,vector<ll>(w));
    FOR(y,0,h){
        FOR(x,0,w){
            ll c; cin>>c;
            chw.at(y).at(x)=c;
        }
    }

    auto available_node = [&](ll x,ll y)->bool{
        if(x<0||x>=w)return false;
        if(y<0||y>=h)return false;
        return chw.at(y).at(x);
    };

    function<void(ll,ll)> dfs = [&](ll x,ll y){
        if(not available_node(x,y)) return;
        chw.at(y).at(x)=0;//訪問済、flag落す
        pair<ll,ll> ofstbl[] = {
            {0,1},{0,-1},{1,0},{-1,0},
            {1,1},{1,-1},{-1,1},{-1,-1},        
        };
        for(const auto&p:ofstbl){
            dfs(x+p.first,y+p.second);
        } 
    };
    ll ans=0;
    FOR(y,0,h){
        FOR(x,0,w){
            if(available_node(x,y)){
                ++ans;
                dfs(x,y);
            }
        }
    }
    cout<<ans<<endl;

    return true;
}
int main(){
    while(solve2()){
    }
    return 0;
}

//template graph使ってるけど冗長
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
    bool flag=false;;
};

template< typename T >
using Edges = vector< edge< T > >;
template< typename T >
using WeightedGraph = vector< node< T > >;
using UnWeightedGraph = vector< vector< int > >;
template< typename T >
using Matrix = vector< vector< T > >;

bool solve(){
    ll w,h; cin>>w>>h;
    if(w==0&&h==0)return false;//終わり
    vector<vector<ll>> chw(h,vector<ll>(w));
    ll node_num=0;
    FOR(y,0,h){
        FOR(x,0,w){
            ll c; cin>>c;
            if(c==1)++node_num;
            chw.at(y).at(x)=c;
        }
    }

    auto pos2id = [&](ll x,ll y)->ll{
        return y*w+x;
    };
    auto available_node = [&](ll x,ll y)->bool{
        if(x<0||x>=w)return false;
        if(y<0||y>=h)return false;
        return chw.at(y).at(x);
    };
    ll node_max=w*h;
    WeightedGraph<ll> graph(node_max);
    pair<ll,ll> ofstbl[] = {
        {0,1},{0,-1},{1,0},{-1,0},
        {1,1},{1,-1},{-1,1},{-1,-1},        
    };
    FOR(y,0,h){
        FOR(x,0,w){
            if (available_node(x,y)) {
                ll xy=pos2id(x,y);
                auto&& node=graph.at(xy);
                node.flag=true;
                for(const auto& o:ofstbl){
                    ll nx =x+o.first;
                    ll ny =y+o.second;
                    if(available_node(nx,ny)){
                        ll nxy=pos2id(nx,ny);
                        node.edges.emplace_back(nxy,1);
                    }
                }
            }
        }
    }

    function<void(ll)> dfs = [&](ll id){
        auto& node=graph.at(id);
        if (node.flag==false)return; //訪問済orない
        node.flag=false;
        for(const auto& e :graph.at(id).edges){
            dfs(e);
        }
    };

    ll ans=0;
    FOR(i,0,node_max){
        if(graph.at(i).flag){
            ++ans;
            dfs(i);
        }
    }
    cout<<ans<<endl;

    return true;
}

int main_() {
#if LOCAL&01
    //std::ifstream in("./test/sample-1.in");
    std::ifstream in("./input.txt");
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    while(solve()){
    }
    return 0;
}