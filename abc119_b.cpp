//AtCoder ABC119 B - Digital Gifts
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
int main() {
#if LOCAL&0
    std::ifstream in("./test/sample-1.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#endif
    ll N; cin>>N;
    vector<pair<string,double>> xun(N);
    for(auto&& xu:xun){
        cin>>xu.second>>xu.first;
    }
    double ans=0;
    for(const auto& xu:xun){
        if(xu.first=="JPY")ans+=xu.second;
        else ans+=xu.second*380000;
    }
	cout << fixed << std::setprecision(10) << ans << endl;
	return 0;
}