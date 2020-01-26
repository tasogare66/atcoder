//https://atcoder.jp/contests/past201912-open/tasks/past201912_j
//J - 地ならし / Leveling
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
using Mat = vector<vector<ll>>;

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
};

template< typename T >
using Edges = vector< edge< T > >;
template< typename T >
using WeightedGraph = vector< node< T > >;
using UnWeightedGraph = vector< vector< int > >;
template< typename T >
using Matrix = vector< vector< T > >;

//s start node
//return 各nodeへの最短の距離が入る,numeric_limits<T>::max()の場合、到達できない
template< typename T >
vector< T > dijkstra(const WeightedGraph< T > &g, int s, vector<int>& prev) {
	const auto INF = numeric_limits<T>::max();
	vector<T> dist(g.size(), INF);
	prev.assign(g.size(),-1);

	using Pi = pair<T, int>; //dist,node id
	priority_queue<Pi, vector<Pi>, greater<Pi>> que;
	dist[s] = 0;
	que.emplace(dist[s], s);
	while(!que.empty()) {
		T cost;
		int idx; //node id
		tie(cost, idx) = que.top();
		que.pop();
		if(dist[idx] < cost)
			continue;
		for(auto &e : g[idx].edges) {
			auto next_cost = cost + e.cost;
			if(dist[e.to] <= next_cost)
				continue;
			dist[e.to] = next_cost;
			prev[e.to] = idx;
			que.emplace(dist[e.to], e.to);
		}
	}
	return dist;
}

int main(){ //下と同じことを,dijkstraで
    ll H,W; cin>>H>>W;
    Mat ahw(H, vector<ll>(W,0));
    FOR(y,0,H){
        FOR(x,0,W){
            cin>>ahw.at(y).at(x);
        }
    }

    auto getid = [&](int y, int x)->ll{
        if(y<0||y>=H) return -1;
        if(x<0||x>=W) return -1;
        return y*W+x;
    };

    int num=H*W;;
    pair<int,int> ofs_tbl[] = {
        { 1, 0 }, { -1, 0},
        { 0, -1}, { 0, 1},
    };
    WeightedGraph<ll> graph(num);
    FOR(y,0,H){
        FOR(x,0,W){
            auto f = getid(y,x);
            for(const auto& ofs:ofs_tbl){
                auto ey = y+ ofs.first;
                auto ex = x + ofs.second;
                auto t = getid(ey, ex);
                if (t<0) continue;
                graph.at(f).edges.emplace_back(t,ahw[ey][ex]);
                graph.at(t).edges.emplace_back(f,ahw[y][x]);
            }
        }
    }

    auto id_a = getid(H-1,0);
    auto id_b = getid(H-1,W-1);
    auto id_c = getid(0,W-1);
	vector<int> prev_a;
	auto res_a = dijkstra(graph, id_a, prev_a);
	vector<int> prev_b;
	auto res_b = dijkstra(graph, id_b, prev_b);
	vector<int> prev_c;
	auto res_c = dijkstra(graph, id_c, prev_c);
    dump(res_a);

    ll ans=INT64_MAX;
    FOR(y,0,H){
        FOR(x,0,W){
            auto pt=getid(y,x);
            auto tmp=res_a[pt] + res_b[pt] + res_c[pt] - 2*ahw[y][x];
            chmin(ans,tmp);
        }
    }
    cout<<ans<<endl;
    return 0;
}

int main_() { //ワーシャルフロイドして全探索,pと左下+pと右下+pと右上が最小になるところを全探索したらTLE...
#if LOCAL&01
    std::ifstream in("./input.txt"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll H,W; cin>>H>>W;
    Mat ahw(H, vector<ll>(W,0));
    FOR(y,0,H){
        FOR(x,0,W){
            cin>>ahw.at(y).at(x);
        }
    }

    auto getid = [&](int y, int x)->int{
        if(y<0||y>=H) return -1;
        if(x<0||x>=W) return -1;
        return y*W+x;
    };

    int num=H*W;;
    pair<int,int> ofs_tbl[] = {
        { 1, 0 }, { -1, 0},
        { 0, -1}, { 0, 1},
    };
    Mat mat(num, vector<ll>(num,INT32_MAX));
    FOR(y,0,H){
        FOR(x,0,W){
            auto f = getid(y,x);
            mat[f][f]=0; //同じところ0いれ
            for(const auto& ofs:ofs_tbl){
                auto ey = y+ ofs.first;
                auto ex = x + ofs.second;
                auto t = getid(ey, ex);
                if (t<0) continue;
                mat[f][t]=ahw[ey][ex];
                mat[t][f]=ahw[y][x];
            }
        }
    }

    auto warshall_floyd = [&](int n) //nは頂点数
    {
	    for(int i = 0; i < n; i++) // 経由する頂点
		    for(int j = 0; j < n; j++) // 開始頂点
			    for(int k = 0; k < n; k++) // 終端
				    mat[j][k] = std::min(mat[j][k], mat[j][i] + mat[i][k]);
    };
	warshall_floyd(num); //O(n^3)

    auto id_a = getid(H-1,0);
    auto id_b = getid(H-1,W-1);
    auto id_c = getid(0,W-1);
    ll cost01=mat[id_a][id_b];
    dump(cost01);
    //経路
    ll ans=INT64_MAX;
#if 1
    FOR(y,0,H){
        FOR(x,0,W){
            auto pt=getid(y,x);
            auto tmp=mat[id_a][pt] + mat[pt][id_b] + mat[pt][id_c];
            chmin(ans, tmp);
            // if(cost01 == mat[id_a][pt]+mat[pt][id_b]){//最短経路の経路の途中、ではない場合もあるようだ
            //     auto tmp=mat[pt][id_c]+cost01;
            //     chmin(ans,tmp);
            // }
        }
    }
#else
    ll pt=getid(H-1,0);
    auto check_id =[&](ll id){
        return (id>=0&&id<num);
    };
    auto dump_xy = [&](ll id){
        ll deb_x=id%W;
        ll deb_y=id/W;
        assert(getid(deb_y,deb_x)==pt);
        dump(deb_y,deb_x);
    };
    vector<int> ofsid = { -1,1,(int)(-W),(int)W};
    vector<bool> visit(num);
    while(pt!=id_b){
        ll tmp=cost01 + mat[pt][id_c];
        chmin(ans,tmp);
        visit[pt]=true;
        for(auto d:ofsid){
            auto nx=pt+d;
            if(check_id(nx)){
                if(!visit[nx] && cost01==mat[id_a][nx]+mat[nx][id_b]){
                    dump_xy(pt);
                    pt = nx;
                    dump_xy(nx);
                    break;
                }
            }
        }
    }
#endif
    cout<<ans<<endl;
    return 0;
}