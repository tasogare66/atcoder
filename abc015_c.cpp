//ABC015 C - 高橋くんのバグ探し
#include <bits/stdc++.h>
using namespace std;
int N,K;
vector<vector<int>> ttt;
void calc_func(int l, int val){
    if (l>=N){
//        cout<<"---" <<val<<endl;
        if (val == 0) {
			cout << "Found" << endl;
            exit(0);
		}
        return;
    }
    for(int x=0;x<K;++x) {
        auto tmp = ttt[l][x]^val;
//        cout<<l<<","<<x<<endl;
        calc_func(l+1,tmp);
    }
}
int main() {
#if LOCAL&0
  	std::ifstream in("input.txt");
  	std::cin.rdbuf(in.rdbuf());
#endif
    cin>>N>>K;
	//int tbl[N][K]={};
    ttt.resize(N);
	for (int i=0;i<N;++i) {
        ttt[i].resize(K);
        for (int j=0;j<K;++j) {
            cin>>ttt[i][j];
        }
    }
    calc_func(0,0);
    cout<<"Nothing"<<endl;
	return 0;
}