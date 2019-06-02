//AtCoder ABC037 B - 編集
#include <bits/stdc++.h>
using namespace std;
using lli=int64_t;

int main() {
    int N,Q;
    cin>>N>>Q;
    vector<int> at(N+1,0);
    for(int i=0;i<Q;++i){
        int l,r,t;
        cin>>l>>r>>t;
        for(int j=l;j<=r;++j){
			at[j] = t;
		}
    }
    for(int i=1;i<at.size();++i){
		cout << at[i] << endl;
    }
    return 0;
}