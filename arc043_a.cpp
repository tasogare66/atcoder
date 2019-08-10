//https://atcoder.jp/contests/arc043/tasks/arc043_a
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll N, A, B; cin>>N>>A>>B;
    vector<ll> sn(N);
    ll sum=0;
    for(auto&& s:sn){
        cin>>s;
        sum+=s;
    }
    sort(sn.begin(),sn.end());
    double dif=sn.back()-*sn.begin();
    if(dif<=0) {
		cout << -1 << endl;
		return 0;
	}
    double p=(double)B/dif;
    double q=(double)A-p*sum/(double)N;
    cout<<fixed<<std::setprecision(10)<<p<<" "<<q<<endl;
    return 0;
}