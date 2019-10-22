//https://atcoder.jp/contests/abc143/tasks/abc143_e
//warshall_floyd 2回
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
using Mat = vector<vector<ll>>;
int main() {
#if LOCAL&01
    std::ifstream in("./test/sample-1.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll N,M,L; cin>>N>>M>>L;
    Mat mat(N+1,vector<ll>(N+1,INT32_MAX));    
    REP(e,M){
        ll a,b,c;
        cin>>a>>b>>c;
        mat.at(a).at(b) = c;
        mat.at(b).at(a) = c;
    }
    ll Q; cin>>Q;
    vector<pair<ll,ll>> stq(Q); //s->t
    for(auto&& st:stq){
        cin>>st.first>>st.second;
    }

	auto warshall_floyd = [&](Mat& d) {
		REP(i, N+1)		   // 経由する頂点
			REP(j, N+1)	 // 開始頂点
				REP(k,N+1) // 終端
					d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
	};
    warshall_floyd(mat);

    auto mat2=mat;
    for(auto&& y:mat2){
        for(auto&& x:y){
            if(x<=L) x=1;
            else x=INT32_MAX;
        }
    }
    warshall_floyd(mat2);

    for(const auto& st:stq){
        auto res=mat2.at(st.first).at(st.second);
        if(res>=INT32_MAX) cout<<-1<<endl;
        else cout<<res-1<<endl;
    }
    return 0;
}