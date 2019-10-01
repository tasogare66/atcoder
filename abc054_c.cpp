//https://atcoder.jp/contests/abc054/tasks/abc054_c
//AtCoder ABC054 C - One-stroke Path
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#if LOCAL
#define debug(var) do{std::cout << #var << " : ";view(var);}while(0)
template<typename T> void view(T e){std::cout << e << std::endl;}
template<typename T> void view(const std::vector<T>& v){for(const auto& e : v){ std::cout << e << " "; } std::cout << std::endl;}
template<typename T> void view(const std::vector<std::vector<T> >& vv){ for(const auto& v : vv){ view(v); } }
#else
#define debug(var)
#endif

struct Edge{
    int s0,e0;
    int s1,e1;
    Edge(int a,int b)
        : s0(a), e0(b)
        , s1(b), e1(a)
    {}
};

int main() {
#if LOCAL&01
    std::ifstream in("./test/sample-1.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    int N,M; cin>>N>>M;
    vector<Edge> edges;
    for(int i=0;i<M;++i){
        int a,b;
        cin>>a>>b;
        edges.emplace_back(a,b);
    }
    //dp[node][到達したnodeマスク]
    vector<vector<int>> dp(N+1,vector<int>(1<<N+1,0));
    dp[1][1<<0] = 1;
    FOR(msk,1,1<<N){ //状態を進めるので、その過去は決まってる
		for(const auto &e : edges) {
			auto setfunc = [&](ll st, ll ed) {
				ll n = st;
				ll nn = ed;
				if((msk & (1 << (st - 1))) == 0)
					return;
				if(msk & (1 << (ed - 1)))
					return;
				ll nmsk = msk | (1 << (nn - 1));
                debug(nn);
                debug(nmsk);
				dp[nn].at(nmsk) += dp[n].at(msk);
			};
			setfunc(e.s0, e.e0);
			setfunc(e.s1, e.e1);
		}
	}

    ll ans = 0;
    REP(t,N+1){
        ans += dp[t][(1<<N)-1];
    }
    cout<<ans<<endl;
    return 0;
}