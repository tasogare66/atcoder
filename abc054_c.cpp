//AtCoder ABC054 C - One-stroke Path
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

struct Edge{
    int s0,e0;
    int s1,e1;
    Edge(int a,int b)
        : s0(a), e0(b)
        , s1(b), e1(a)
    {}
};
struct Node{
    int no;
    vector<const Edge*> etbl;
};

int main() {
    int N,M;
    cin>>N>>M;
    vector<Node> nodes(N);
    for(int i=0;i<N;++i){
        nodes[i].no=i+1;
    }
    vector<Edge> edges;
    for(int i=0;i<M;++i){
        int a,b;
        cin>>a>>b;
        edges.emplace_back(a,b);
        auto it = edges.back();
        nodes[a-1].etbl.push_back(&it);
        nodes[b-1].etbl.push_back(&it);
    }
    //bfs
    //queue<>


    return 0;
}