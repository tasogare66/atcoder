//https://atcoder.jp/contests/abc098/tasks/arc098_b
//xor x^x で打ち消せる
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
#if LOCAL&01
    std::ifstream in("./test/sample-1.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll N; cin>>N;
    vector<ll> an(N);
    for(auto&& a:an){
        cin>>a;
    }
    ll left=0;
    ll right=0;
    ll sum=0;
    ll xo=0;
    ll ans=0;
#if 01
    REP(l,N){
        while(right<N&&((sum+an[right]) == (xo^an[right]))){ //r動かす
            sum += an.at(right);
            xo ^= an.at(right);
            ++right;
        }
        ans += (right-l);
        sum -= an.at(l);
        xo ^= an.at(l);
    }
#else
    while(right<N){
        if (right>=N) break;
        auto a=an.at(right);
        auto n_sum = sum + a;
        auto n_xo = xo ^ a;
        if (n_sum == n_xo) {
            sum = n_sum;
            xo = n_xo;
            ++ans;
            ++right;
        } else {
            do {
                auto dv=an.at(left);
                sum -= dv;
                xo ^= dv;
                ++left;
            } while(sum != xo);
            ans += (right-left);
        }
    }
    while(right - left > 0) {
		auto dv = an.at(left);
		sum -= dv;
		xo ^= dv;
		++left;
        if (sum == xo) {
	        ans += (right - left);
        }else{
            break;
        }
	}
#endif
    cout<<ans<<endl;
    return 0;
}