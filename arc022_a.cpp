//https://atcoder.jp/contests/arc022/tasks/arc022_1
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    string S; cin>>S;
    string ictl="ict";
    string ictu="ICT";
    ll pt=0;
    bool ans=false;
    for(const auto& c:S){
        if(c==ictl[pt]||c==ictu[pt]){
            ++pt;
			if(pt >= ictl.size()) {
                ans=true;
                break;
			}
		}
    }    
    cout<<(ans?"YES":"NO")<<endl;
    return 0;
}