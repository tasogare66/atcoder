//AtCoder ABC068 C - Cat Snuke and a Voyage
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

struct Node {
    vector<int> m_e;
};

int main() {
    ll N,M; //M,edges
    cin>>N>>M;
    vector<Node> m_node(N+1);
    for(int i=0;i<M;++i){
        int a,b;
        cin>>a>>b;
        m_node[a].m_e.push_back(b);
        m_node[b].m_e.push_back(a);
    }
    //1から
    bool possible=false;
    for(const auto &id:m_node[1].m_e){//1からいけるところ
        for(const auto& g:m_node[id].m_e){
            if(g==N){
				possible = true;
                break;
			}
        }
    }
    cout<<(possible?"POSSIBLE":"IMPOSSIBLE")<<endl;
    return 0;
}