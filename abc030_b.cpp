//AtCoder ABC030 A - 勝率計算
#include <bits/stdc++.h>
using namespace std;
using lli=int64_t;
double calc(int in,int im){
    double n=(in>=12)?in-12:in;
    double m=im;
    double deg_m=m*6.0;
    double deg_h=n*30.0+30.0*(m/60.0);
    double dif=std::abs(deg_m-deg_h);
    if (dif>180.0) dif=std::abs(dif-360.0);
    return dif;
}
int main() {
#if LOCAL & 01
	for(int in = 0; in <= 12; ++in) {
		for(int im = 0; im <= 59; ++im) {
			cout << in << ":" << im << " " << calc(in, im) << endl;
		}
	}return 0;
#endif
#if LOCAL & 0
	std::ifstream in("input.txt");
  	std::cin.rdbuf(in.rdbuf());
#endif
    int in,im; //時、分
    cin>>in>>im;
    auto ans = calc(in,im);
    cout<<fixed<<std::setprecision(4)<<ans<<endl;
    return 0;
}