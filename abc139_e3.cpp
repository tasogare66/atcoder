//https://atcoder.jp/contests/abc139/tasks/abc139_e
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

struct Edge{
    ll st; //start
    ll tr; //end
    ll weight;
	Edge(ll s, ll t, ll w) : st(s), tr(t), weight(w) {}
	Edge() : Edge(0, 0, 0) {}
};
using Edges = vector<Edge>;
using Graph = vector<Edges>;
//topological sort の一つを得る、１つの入力に対して複数の解答がる。
std::vector<int> tsort(const Graph &g, ll &mlop) {
    int n = g.size();
    enum class State { NEW, ACTIVE, FINISHED };
    std::vector<int> res;
    vector<State> state(n, State::NEW);
    vector<ll> length(n,1); //間違ってる
    static const std::function<bool(int)> dfs = [&](int v) {
        state[v] = State::ACTIVE;
        for (auto &e : g[v]) {
            int w = e.tr;
            if (state[w] == State::ACTIVE) return false;
            else if (state[w] == State::NEW) {
                auto rf = dfs(w);
                length[v] = max(length[v],length[w]+1);
				if(!rf) {
					return false;
				}
			}
		}
        state[v] = State::FINISHED;
        res.push_back(v);
        return true;
    };
    for (int i = 0; i < n; ++i){
        if (state[i] == State::NEW && !dfs(i)) return {-1};
    }
    std::reverse(res.begin(), res.end());
    mlop = *max_element(length.begin(),length.end());
    return res;
}

int main() {
    // cin.tie(0);
    // ios::sync_with_stdio(false);
#if LOCAL&01
    std::ifstream in("./test/sample-1.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#endif    
    ll N; cin>>N;
    vector<vector<ll>> aij(N,vector<ll>(N-1));
    for(auto&& an: aij){
        for(auto&& a:an){
            cin>>a; --a; //0start
        }
    }
    //match id取る
    ll cur_match_id=0;
    map<pair<ll,ll>,ll> match_id_map{};
    auto match_id = [&](ll i, ll j){
        assert(i!=j);
        assert(i<N&&j<N);
        if(i>j) swap(i,j);
        pair<ll,ll> ij={i,j};
        auto it = match_id_map.find(ij);
        if(it==match_id_map.end()){
			match_id_map[ij] = cur_match_id++;
            return match_id_map[ij];
        }
        return it->second;
    };

    ll match_num = N*(N-1)/2;
    Graph graph(match_num);
    REP(i, aij.size()){
        FOR(j, 1, aij[i].size()){
            auto s = match_id(i,aij[i][j-1]); //前の試合
            auto t = match_id(i,aij[i][j]);
            graph.at(s).emplace_back(s,t,0);
        }
    }
    ll ans=-1;
    auto ord = tsort(graph,ans);
    if (ord[0]<0) {
        cout<<-1<<endl;
        return 0;
    }

    //日数数える,max length of path from start
#if 1
    vector<ll> len(match_num,1);
    for(const auto& o:ord){
        for(const auto& e:graph.at(o)){
            len.at(e.tr) = max(len.at(e.tr), len.at(e.st)+1);
        }
    }
    ans = *max_element(len.begin(),len.end());
#endif
    cout<<ans<<endl;

    return 0;
}