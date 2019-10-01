//https://atcoder.jp/contests/agc011/tasks/agc011_b
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll N;cin>>N;
    vector<ll> an(N);
    for(auto&& a:an){
        cin>>a;
    }
    sort(an.begin(), an.end());
    //sortして累積和
    ll sum=0;
    vector<ll> sumtbl(N);
    REP(i,N){
        sum+=an[i];
        sumtbl.at(i)=sum;
    }
    //後ろから
    ll ans=1; //終端はok
    for(ll i=N-2; i>=0; --i){
        if (sumtbl[i]*2>=an[i+1]){
			++ans;
		} else {
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}