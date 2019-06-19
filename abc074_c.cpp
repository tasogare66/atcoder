//AtCoder C - Sugar Water
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
#if LOCAL&0
    std::ifstream in("input.txt");
    std::cin.rdbuf(in.rdbuf());
#endif
    ll A,B,C,D,E,F;
    cin>>A>>B>>C>>D>>E>>F;
    ll amax=F/(100*A);
    ll bmax=F/(100*B);
    double den_max=-1.0;
    ll ans_t=0,ans_s=0;
    for(ll a=0;a<=amax;++a){
		for(ll b = 0; b <= bmax; ++b) {
            ll sug_max=(A*a+B*b)*E;
            ll cmax=sug_max/C;
            for(ll c=0;c<=cmax;++c){
                ll dmax=(sug_max-c*C)/D;
                for (ll d=0;d<=dmax;++d){
                    ll sug = C*c + D*d;
                    ll wat = A*a+B*b;
                    ll ttl = 100*wat+sug;   
                    if (wat<=0) continue;
                    if (sug > sug_max) continue;
                    if (ttl > F) continue;
                    double den=(double)sug/(double)(A*a+B*b);
                    if (den>den_max) {
                        ans_t=ttl;
                        ans_s=sug;
						den_max = den;
					}
                }
            }
		}
	}
    cout<<ans_t<<" "<<ans_s<<endl;
	return 0;
}