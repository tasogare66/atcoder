//AtCoder 
#include <bits/stdc++.h>
using namespace std;
using lli=int64_t;

int main() {
    int N,M;
#if LOCAL&01
  	std::ifstream in("input.txt");
  	std::cin.rdbuf(in.rdbuf());
#endif
    cin>>N>>M;
    vector<int> atbl(N+1,0);
    for(int i=0;i<=N;++i){
        cin>>atbl[i];
    }
    for(int i=0;i<M;++i){
        int b,c;
        cin>>b>>c;
        sort(atbl.begin(),atbl.end());
        for(int j=1;j<=b;++j){
            if(atbl[j] < c){
                atbl[j]==c;
            } else{
                break;
            }
        }
    }
    lli ans=0;
    for(int i=1;i<=N;++i){
		ans += atbl[i];
	}
    cout<<ans<<endl;
    return 0;
}