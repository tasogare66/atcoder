//AtCoder ABC031 B - 運動管理
#include <bits/stdc++.h>
using namespace std;
using li=int64_t;

int main() {
#if LOCAL&0
  	std::ifstream in("input.txt");
  	std::cin.rdbuf(in.rdbuf());
#endif
    int L,H;
    int N;
    cin>>L>>H;
    cin>>N;
    vector<int> at(N);
    for(auto&&a:at){
		cin >> a;
	}
    for (int i=0;i<N;++i) {
        int a=at[i];
        if(a>=L&&a<=H){
            cout<<0<<endl;
        } else if(a>H) {
            cout<<-1<<endl;
        } else {
            cout<<(L-a)<<endl;
        }
    }
    return 0;
}