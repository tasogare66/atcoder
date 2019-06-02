//AtCoder ABC050 B - Contest with Drinks Easy
#include <bits/stdc++.h>
using namespace std;
using lli=int64_t;

int main() {
    int N;
    cin>>N;
    vector<int> tbl(N+1,0);
    for(int i=1;i<=N;++i){
        cin>>tbl[i];
    }
    int M;
    cin>>M;
    vector<pair<int,int>> pt(M);
    for(auto&& p:pt){
        cin>>p.first>>p.second;
    }
    //brute-force?
    for(const auto& p:pt){
        lli ans=0;
        for(int i=1;i<=N;++i){
            ans += (i==p.first)?p.second:tbl[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}