//AtCoder ABC062 C - Chocolate Bar
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

ll calc_max_min(ll s1,ll s2,ll s3){
	ll smax = max(s1, s2);
	smax = max(smax, s3);
	ll smin = min(s1, s2);
	smin = min(smin, s3);
    return smax-smin;
}

ll check_func(ll h, ll w){
    ll ret=INT64_MAX;
    for(ll y=1;y<h;++y){
        ll s1=y*w;
		ll rest = h - y;
		{//横
			ll y2 = rest / 2;
			ll y3 = h - y - y2;
			if(y2 > 0 && y3 > 0) {
				ll s2 = y2 * w;
				ll s3 = y3 * w;
				ret = min(ret, calc_max_min(s1, s2, s3));
			}
		}
        {//縦
            ll x2 = w/2;
            ll x3 = w-x2;
            if (x2>0&&x3>0&&rest>0){
                ll s2 = x2 * rest;
                ll s3 = x3 * rest;
                ret = min(ret, calc_max_min(s1, s2, s3));
            }
        }
	}
    return ret;
}

int main() {
#if LOCAL&01
    std::ifstream in("input.txt");
    std::cin.rdbuf(in.rdbuf());
#endif
    ll H,W;
    cin>>H>>W;
    ll ans = min(check_func(H,W),check_func(W,H));
    cout<<ans<<endl;
    return 0;
}