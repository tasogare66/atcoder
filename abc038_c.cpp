//AtCoder C - 単調増加
#include <bits/stdc++.h>
using namespace std;
using lli=int64_t;

int main() {
    int N;
#if LOCAL&01
    std::ifstream in("input.txt");
    std::cin.rdbuf(in.rdbuf());
#endif
    cin>>N;
    vector<int> atbl(N);
    for(auto&& a:atbl){
		cin >> a;
	}
    lli ans=0;
    lli step=0;
    for(int i=1;i<atbl.size();++i){ //増加している数を調べる
        if (atbl[i-1] < atbl[i]){
            ++step;
        } else {
            if (step>0) {
                //(step+1)C2
                ans += (step+1)*step/2;
            }
            step=0;
        }
    }
    //終端...
	if(step > 0) {
		//(step+1)C2
		ans += (step + 1) * step / 2;
	}
    ans += (atbl.size());
	cout<<ans<<endl;
    return 0;
}