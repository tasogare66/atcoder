//ABC023 C - 収集王
#include <bits/stdc++.h>
using namespace std;
using lli=int64_t;
using Mat=vector<vector<int>>;
int main() {
    lli R,C,K;
    lli N;
#if LOCAL&01
  	std::ifstream in("input.txt");
  	std::cin.rdbuf(in.rdbuf());
#endif
    cin>>R>>C>>K;
    cin>>N;
    Mat rmat=Mat(R+1,vector<int>(C+1,0));
    vector<lli> rn(R+1,0);
    vector<lli> cn(C+1,0);
    for(lli i=0;i<N;++i){
		lli r, c;
		cin >> r >> c;
		rmat[r][c]=1;
        ++rn[r];
        ++cn[c];
    }
    lli ans=0;
	for(lli rr = 1; rr <= R; ++rr) {
		for(lli cc = 1; cc <= C; ++cc) {
			lli cnt = rn[rr] + cn[cc];
			if(rmat[rr][cc])
				--cnt;
			if(cnt == K)
				++ans;
		}
	}
	cout << ans << endl;
	return 0;
}