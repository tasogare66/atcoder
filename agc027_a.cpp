//AtCoder AGC027 A - Candy Distribution Again
//ソートして少ない順にひいていく,余ったら最後に押し付ける,足りなかった分は答えにカウントしない
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll N,x; cin>>N>>x;
    vector<ll> an(N);
    for(auto&& a:an){
        cin>>a;
    }
    sort(an.begin(),an.end());
    ll rst=x;
    ll ans=0;
    for(ll i=0;i<an.size();++i){
        if (rst>0){
			if(rst - an[i] >= 0) {
				rst -= an[i];
				ans++;
			} else {
                rst = -1;
            }
		}
    }
    if(rst>0) ans=std::max<ll>(0,ans-1);
    cout<<ans<<endl;
    return 0;
}