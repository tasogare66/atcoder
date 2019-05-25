//AtCoder ABC035 C - オセロ
#include <bits/stdc++.h>
using namespace std;
using lli=int64_t;

int main() {
    int N,Q;
    cin>>N>>Q;
    vector<int> tbl(N+2,0);
    for(int i=0;i<Q;++i){
        int l,r;
        cin>>l>>r;
        tbl[l]+=1;
        tbl[r+1]+=1;
    }
    lli cnt=0;
    for(int i=1;i<=N;++i){
        cnt+=tbl[i];
        cout<<cnt%2;
    }
    cout<<endl;
    return 0;
}