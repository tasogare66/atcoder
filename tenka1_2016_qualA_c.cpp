//https://atcoder.jp/contests/tenka1-2016-quala/tasks/tenka1_2016_qualA_c
//kahnで、トポロジカルソート、priority_queでやって昇順に出す
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

struct Edge {
    ll st,tr;
    Edge(ll s, ll t)
        : st(s), tr(t)
    {}
};
struct Node{
    vector<Edge> edges;
    ll indeg=0; //入次数
};
using Graph = vector<Node>;

//gの入次数を更新する
vector<ll> tsort_kahn(Graph& g){
    //入次数をカウント,O(E)
    for(auto& n:g){
        for(auto& e:n.edges){
            g.at(e.tr).indeg++;
        }
    }
    //入次数0をstack
    //deque<ll> s;
    priority_queue<ll,vector<ll>,greater<ll>> s; //greaterだと小さい順
    for(ll i=0;i<g.size();++i){
        if (g.at(i).indeg == 0) {
            //s.push_back(i);
            s.push(i);
        }
    }
    //入次数0を取っていく
    vector<ll> ret;
    while(s.size() > 0){
        auto u = s.top(); s.pop();
        ret.emplace_back(u);
        for(const auto& e : g.at(u).edges){
            auto v = e.tr;
            g.at(v).indeg--;
            assert(g.at(v).indeg >= 0);
            if (g.at(v).indeg == 0) s.push(v); //入次数,0の頂点を追加
        }
    }
    auto it = std::max_element(g.begin(), g.end(), [](auto&a, auto&b){ return a.indeg < b.indeg; });
    return it->indeg == 0 ? ret : decltype(ret)();
}

int main() {
    // cin.tie(0);
    // ios::sync_with_stdio(false);
#if LOCAL&01
    std::ifstream in("./test/sample-4.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#endif
    ll N; cin>>N;
    vector<pair<string,string>> ab(N);
    for(auto&& s: ab){
        cin>>s.first>>s.second;
    }

    auto compare_pos = [](const string&a, const string&b)->ll{
        ll len = min(a.size(),b.size());
        REP(i,len){
            if (a.at(i) != b.at(i)){
                return i;
            }
        }
        return -1;
    };
    Graph grp(26);
    for(const auto& s:ab){
        //auto p = s.first.compare(s.second);
        auto p = compare_pos(s.first, s.second);
        if(p<0){
            auto c = s.first.compare(s.second);
            if (c > 0){
                cout<<-1<<endl;
                return 0;
            }
            continue;
        }
        auto st = s.first[p] - 'a';
        auto ed = s.second[p] - 'a';
        grp.at(st).edges.emplace_back(st,ed);
    }

    auto ans = tsort_kahn(grp);
    if (ans.size()<=0){
         cout<<-1<<endl;
    } else {
        for(const auto& a:ans){
            cout<<(char)(a+'a');
        }
        cout<<endl;
    }

    return 0;
}