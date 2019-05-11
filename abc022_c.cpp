//ABC022 C - Blue Bird
#include <bits/stdc++.h>
using namespace std;
using lli=int64_t;

using Mat=vector<vector<lli>>;
const int INF = INT32_MAX;

Mat d; //d[u][v]は辺e=(u,v)のコスト（辺が存在しない場合はINF、ただしd[i][i]=0）

void warshall_floyd(int n) //nは頂点数
{
	for(int i = 0; i < n; i++) // 経由する頂点
		for(int j = 0; j < n; j++) // 開始頂点
			for(int k = 0; k < n; k++) // 終端
				d[j][k] = std::min(d[j][k], d[j][i] + d[i][k]);
}

int main() {
    int N,M;
#if LOCAL&0
  	std::ifstream in("input.txt");
  	std::cin.rdbuf(in.rdbuf());
#endif
    cin>>N>>M;

    d = Mat(N+1, vector<lli>(N+1, INT32_MAX));
    for(int i=1;i<=N;++i){
        d[i][i]=0;
    }

    vector<pair<int,lli>> rinsetu; //1の隣接nodeとcost
    for (int i=1;i<=M;++i) {
		int from, to;
        lli cost;
        cin>>from>>to>>cost;
        if(from==1||to==1){//1の隣接はいれない
            int n=(from==1)?to:from;
            rinsetu.push_back({n,cost});
        }else{
			d[from][to] = cost;
			d[to][from] = cost; //双方向
		}
	}
	warshall_floyd(N + 1); //O(n^3)
    //search
    lli ans=INT32_MAX;
    for(int i=0;i<rinsetu.size();++i){
        auto& st= rinsetu[i];
        for(int j=0;j<rinsetu.size();++j){
            if (i==j) continue;
            auto& ed=rinsetu[j];
            lli cur_cst=st.second+ed.second+d[st.first][ed.first];
            ans=std::min(ans,cur_cst);
        }
    }
    if (ans>=INF) ans=-1;
    cout<<ans<<endl;
	return 0;
}