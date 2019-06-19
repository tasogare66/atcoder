//AtCoder ABC061 B - Counting Roads
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
    int N,M; //都市、道
    cin>>N>>M;
    vector<int> roadnum(N+1,0);
    for(int i=0;i<M;++i){
        int a,b;
        cin>>a>>b;
        ++roadnum[a];
		++roadnum[b];
	}
    for(int i=1;i<=N;++i){
        cout<<roadnum[i]<<endl;
    }
    return 0;
}