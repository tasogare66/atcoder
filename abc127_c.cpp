//AtCoder 
#include <bits/stdc++.h>
using namespace std;
using lli=int64_t;

int main() {
    int N,M;
    cin>>N>>M;
    vector<int> card(N+2);
    for(int i=1;i<=M;++i){
        int l,r;
        cin>>l>>r;
        card[l]+=1;
        card[r+1]-=1;
    }
    int no=0;
    int ans=0;
    for(int i=1;i<=N;++i){
        no+=card[i];
        if (no==M){
            ++ans;
        }
    }
    cout<<ans<<endl;
    return 0;
}