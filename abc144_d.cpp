//https://atcoder.jp/contests/abc144/tasks/abc144_d
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
using ld=long double;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#if LOCAL
#include "dump.hpp"
#else
#define dump(...)
#endif
double deg2rad(double deg){
	return deg*M_PI/180.0;
}
double rad2deg(double rad){
	return rad*180.0/M_PI;
}
int main() {
#if LOCAL&01
    std::ifstream in("./test/sample-2.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ld a,b,x; cin>>a>>b>>x;
#if 1 //二分法
	auto calc = [&](ld deg){
		ld rad=deg*M_PI/180.0; //deg2rad
		ld bb=a*tan(rad);
		ld ft=-1.0;
		if (b>bb){
			ft=(bb*a/2 + (b-bb)*a)*a;
		} else {
			ft=b*b/tan(rad)/2*a;
		}
		return ft;
	};
//	dump(calc(5)-x);
//	dump(calc(4.2363947991)-x);
//	dump(calc(4)-x);
    ld lb=0, ub=90;
    REP(i,1000){
        auto deg=(lb+ub)/2.0;
		auto ft=calc(deg)-x;
        if (ft>0){
            lb=deg;
        } else {
            ub=deg;
        }
		//dump(lb,ub,ft);
    }
    cout<<fixed<<std::setprecision(10)<<lb<<endl;
#else
    dump(a*a*b);
    {
		ld t = (2 * a * a * b - 2 * x) / (a * a);
		if(b - t < 0) {
			ld t2 = 2 * x / (b * a);
			ld at = b/ t2;
			ld rad = atan(at);
            //ld rad2=atan2(t2,b);
		    ld deg = rad * 180.0 / M_PI;
			cout << fixed << std::setprecision(10) << deg << endl;
            return 0;
		}
		dump(t);
		ld at = t / a;
		ld rad = atan(at);
		ld deg = rad * 180.0 / M_PI;
        cout<<fixed<<std::setprecision(10)<<deg<<endl;
	}
#endif
    return 0;
}