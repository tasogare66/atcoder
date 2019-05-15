//ABC027 C - 倍々ゲーム
#include <bits/stdc++.h>
using namespace std;
using lli=int64_t;
lli N=5;
int bfs(int cnt,lli n){
    if (N<2*n){
        return (cnt%2);
    } else if (N<2*n+1) {
        return (cnt%2);
    }
    int next_cnt=cnt+1;
    if (cnt%2==0){
        auto r1=bfs(next_cnt,2*n);
        auto r2=bfs(next_cnt,2*n+1);
        return max(r1,r2);
    } else {
        auto r1=bfs(next_cnt,2*n);
        auto r2=bfs(next_cnt,n);
        return min(r1,r2);
    }
}
int main() {
    cin>>N;
#if 0
    int cnt=0;
    auto ans = bfs(cnt,1);
    cout<<((ans==0)?"Aoki":"Takahashi")<<endl;
#else
    lli depth=0;
    for(lli n=N;n>0;n/=2){
        ++depth;
    }
    bool al=(depth%2==0);
    int cnt=0;
    lli n=1;
    while(N>=n){
        if (cnt%2==0){ //Takahashi
            if(al){
                n=2*n;
            } else {
                n=2*n+1;
            }
        } else { //Aoki
            if(al){
                n=2*n+1;
            } else {
                n=2*n;
            }
        }
        ++cnt;
    }
    cout<<((cnt%2==1)?"Aoki":"Takahashi")<<endl;
#endif 
    return 0;
}