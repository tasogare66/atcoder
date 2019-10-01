//https://atcoder.jp/contests/abc088/tasks/abc088_d
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

struct edge {
    int to, cost;
	edge(ll _to) : to(_to), cost(1) {}
};
typedef vector<vector<edge> > AdjList;
AdjList graph;

typedef pair<int, int> P;

const int INF = 10000000;

vector<int> dist; 
vector<int> prever;

void dijkstra(int n, int s){
    dist = vector<int>(n,INF);
    prever = vector<int>(n,-1);
    dist[s] = 0;

    priority_queue<P, vector<P>, greater<P> > que;
    que.push(P(0,s));

    while(!que.empty()){
        P p = que.top();
        que.pop();
        int v = p.second;
        if(dist[v] < p.first){
            continue;
        }
        for(int i=0;i<graph[v].size();i++){
            edge e = graph[v][i];
            if(dist[e.to] > dist[v] + e.cost){
                dist[e.to] = dist[v] + e.cost;
                prever[e.to] = v;
                que.push(P(dist[e.to],e.to));
            }
        }
    }
}

vector<int> get_path(int t){ //頂点tへの最短路
    vector<int> path;
    for(; t != -1;t=prever[t]){
        path.push_back(t);
    }

    reverse(path.begin(), path.end());
    return path;
}

int main() {
#if LOCAL&0
    std::ifstream in("./input.txt"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#endif
    ll H,W; cin>>H>>W;
    vector<string> swh(H);
    ll n=0;//node数
    ll w=0;//wall数
    for(auto&& sw:swh){
        cin>>sw;
        for(const auto c:sw){
            if (c=='.') ++n;
            else ++w;
        }
    }

    auto getsw = [&](ll _x,ll _y){
        auto c = '#';
        assert(_x>=0);
        assert(_y>=0);
        if(_x < W && _y< H){
            c = swh.at(_y).at(_x);
        }
        return c;
    };
    auto getid = [&](ll _x, ll _y){
        return _y*W + _x;
    };
    auto check_and_add_edge = [&](ll from_x, ll from_y, ll to_x, ll to_y){
        auto c = getsw(to_x,to_y);
        if (c=='.'){
            auto from = getid(from_x, from_y);
            auto to = getid(to_x, to_y);
            graph.at(from).emplace_back(to);
            graph.at(to).emplace_back(from); //反対もいけるので
        }
    };

    graph = AdjList(H*W);
    REP(y,H){
        const auto& sw = swh.at(y);
        REP(x,W){
            auto c = sw.at(x);
            if (c=='.') {
                check_and_add_edge(x,y, x+1,y); //right
                check_and_add_edge(x,y, x,y+1); //down
            }
        }
    }

    dijkstra(H*W, 0);
    auto r = get_path(H*W-1);
#if LOCAL&0
    for(auto v:r){
        cout<<v<<endl;
    }
#endif
    if (r.size() <= 0 || *(r.begin()) != 0) cout<<-1<<endl;
    else {
        ll ans = H*W - w -r.size();
        cout<<ans<<endl;
    }
    return 0;
}
