//AtCoder ABC089 C - March
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

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

int main() {
    ll N;
    cin>>N;
	unordered_map<char, ll> march = {
		{'M', 0}, {'A', 1}, {'R', 2}, {'C', 3}, {'H', 4},
	};
	unordered_map<int,ll> ntbl;
    for(ll i=0;i<N;++i){
        string s;
        cin>>s;
        auto it=march.find(s[0]);
        if(it!=march.end()){
            ++ntbl[it->second];
        }
    }
    ll ans=0;
	foreach_comb(5, 3, [&](int *indexes) {
		//std::cout << indexes[0] << ',' << indexes[1] << ',' << indexes[2] << std::endl;
        ans += ntbl[indexes[0]] * ntbl[indexes[1]] * ntbl[indexes[2]];
	});
    cout<<ans<<endl;
	return 0;
}
