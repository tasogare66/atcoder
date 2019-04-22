//ABC008 C - コイン
#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
#if 0
  	std::ifstream in("input.txt");
  	std::cin.rdbuf(in.rdbuf());
#endif
    cin>>N;
    vector<int> ctbl(N);
    for (auto& c: ctbl) {
        cin>>c;
    }
    sort(ctbl.begin(), ctbl.end());
#if 1
    double expected = 0;
    for (int i=0;i<N;++i) {
		auto c = ctbl[i];
        //約数の数
        int s = 0;
        for (int j=0;j<N;++j) {
			if(i != j && c % ctbl[j] == 0) {
				++s;
            }
        }
        //
        if (s%2==0){
			expected += double(s + 2) / double(2*s + 2);
		}else{
            //奇数
            expected += 0.5;
        }
	}
	cout << fixed << std::setprecision(10) << expected << endl;
#else
    //brute-force
    int num=0;
    double expected = 0;
	do {
		vector<bool> flag(N,true);
        for (int i= 0; i < N; ++i) {
            auto c = ctbl[i];
            for (int j = i+1; j <N; ++j) {
				if(ctbl[j] % c == 0) {
					flag[j] = !flag[j];
				}
			}
            if (flag[i]) {
                expected += 1;
            }
		}
        ++num;
	} while(std::next_permutation(ctbl.begin(), ctbl.end()));
	cout << fixed << std::setprecision(10) << expected / num << endl;
#endif
	return 0;
}