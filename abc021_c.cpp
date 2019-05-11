//ABC021 C - 正直者の高橋くん
#include <bits/stdc++.h>
using namespace std;
using lli=int64_t;
struct Edge{
    //int m_no;
    int m_dist=0;
    vector<int> m_p;
    int m_open_cnt=-1;
    int m_tmp=0;
    lli m_ans=0;
};
int main() {
    int N;
    int a,b;
    int M;
#if LOCAL&0
  	std::ifstream in("input.txt");
  	std::cin.rdbuf(in.rdbuf());
#endif
    cin>>N;
    cin>>a>>b;
    cin>>M;
    vector<std::array<int,2>> path(M);
    for(auto&&p:path){
        cin>>p[0]>>p[1];
    }
    //edgeの情報
    vector<Edge> edges(N+1); //one-based
    for(const auto& p:path){
        edges[p[0]].m_p.push_back(p[1]); //p0-p1
		edges[p[1]].m_p.push_back(p[0]); //p1-p0
	}
    //startからの各edgeの距離を調べる
    edges[a].m_tmp=0;
    for(int i=1;i<=N;++i){
        queue<int> q;
        auto start=a;
        auto goal=i;
		edges[start].m_open_cnt = i;
		q.emplace(start);
		auto bfs = [&]() {
            while(!q.empty()){
                auto now=q.front();
                q.pop();
                //停止条件
				auto &now_edge = edges[now];
                if (now == goal) {
                    return now_edge.m_tmp;
                }
				for (auto&& next:now_edge.m_p){
					auto &e = edges[next];
					if(e.m_open_cnt != i){
						e.m_open_cnt = i;
                        e.m_tmp=now_edge.m_tmp+1;
						q.push(next);
                    }
				}
            }
            return 0;
        };
        edges[i].m_dist = bfs();
	}
    //
    auto goal_dist = edges[b].m_dist;
    vector<vector<int>> dtbl(goal_dist+1);
    for(int i=1;i<=N;++i){
        auto& e = edges[i];
        if (e.m_dist <= goal_dist) {
            dtbl[e.m_dist].push_back(i);
        }
    }
    edges[a].m_ans=1;
    for (int dist=1;dist<dtbl.size();++dist) {
        const auto& tbl= dtbl[dist];
        for (const auto& d : tbl){
            for (auto&& p:edges[d].m_p){
				if(edges[p].m_dist == (dist - 1)) {
					edges[d].m_ans = (edges[d].m_ans + edges[p].m_ans)%1000000007;
				}
			}
        }
    }
    cout<<edges[b].m_ans<<endl;
	return 0;
}