//ABC024 B - 自動ドア
#include <bits/stdc++.h>
using namespace std;
using lli=int64_t;
int main() {
    lli N,T;
    cin>>N>>T;
    vector<lli> atbl(N,0);
    for(auto& a:atbl){
        cin>>a;
	}
    lli ans=0;
    for(int i=0;i<N-1;++i){
        ans += std::min(atbl[i+1] - atbl[i], T);
    }
    ans += T;
    cout<<ans<<endl;
    return 0;
}