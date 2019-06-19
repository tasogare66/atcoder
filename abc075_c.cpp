//AtCoder ABC075 C - Bridge
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
struct Node{
    bool enable=true;
    vector<ll> edges;
};
int main() {
    ll N,M;
    cin>>N>>M;
    vector<Node> nodes(N+1);
    for(int i=0;i<M;++i){
        ll a,b;
        cin>>a>>b;
        nodes[a].edges.push_back(b);
        nodes[b].edges.push_back(a);
    }
    //探索
    ll ans=0;
    bool found=true;
    while(found){
        found=false;
		for(ll i = 1; i <= N; ++i) {
			if(nodes[i].edges.size() == 1) {
				auto no = nodes[i].edges[0];
				nodes[i].edges.clear();
				auto it =
					find(nodes[no].edges.begin(), nodes[no].edges.end(), i);
				nodes[no].edges.erase(it); //連結消す
				++ans;
				found=true;
				break;
			}
		}
	}
    cout<<ans<<endl;
	return 0;
}