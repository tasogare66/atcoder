//AtCoder 
#include <bits/stdc++.h>
using namespace std;
using lli=int64_t;

void recursive_comb(int *indexes, int s, int rest,
					std::function<void(int *)> f) {
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
    int N,M,K;
    cin>>N>>M>>K;
    lli mas = N*M;
    lli ans=0;
	foreach_comb(mas, K, [](int *indexes) {
		std::cout << indexes[0] << ',' << indexes[1] << ',' << indexes[2]
				  << std::endl;
	});
    cout<<ans<<endl;
	return 0;
}