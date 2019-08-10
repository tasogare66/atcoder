//https://atcoder.jp/contests/arc004/tasks/arc004_1
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

void recursive_comb(int *indexes, int s, int rest, std::function<void(int *)> f) {
	if(rest == 0) {
		f(indexes);
	} else {
		if(s < 0)
			return;
		recursive_comb(indexes, s - 1, rest, f);
		indexes[rest - 1] = s;
		recursive_comb(indexes, s - 1, rest - 1, f);
	}
}

// nCkの組み合わせに対して処理を実行する
void foreach_comb(int n, int k, std::function<void(int *)> f) {
  int indexes[k];
  recursive_comb(indexes, n - 1, k, f);
}

struct vec{
    ll x,y;
};
int main() {
    ll N; cin>>N;
    vector<vec> tbl(N);
    for(auto& t:tbl){
        cin>>t.x>>t.y;
    }

    auto calc_len = [](const vec& a, const vec& b){
        double l=(a.x-b.x) * (a.x-b.x) + (a.y-b.y) * (a.y-b.y);
        return sqrt(l);
    };
    double ans=0;
	foreach_comb(N, 2, [&](int *indexes) {
		//std::cout << indexes[0] << ',' << indexes[1]<<endl;
        //ans += ntbl[indexes[0]] * ntbl[indexes[1]] * ntbl[indexes[2]];
        ans = max(calc_len(tbl[indexes[0]],tbl[indexes[1]]), ans);
	});
    cout<<fixed<<std::setprecision(10)<<ans<<endl;
    return 0;
}