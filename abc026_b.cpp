//ABC026 B - N重丸
#include <bits/stdc++.h>
using namespace std;
using lli=int64_t;
int main() {
    int N;
    cin>>N;
    vector<double> rtbl(N,0.0);
    for(auto&& r:rtbl){
		cin >> r;
	}
    double ans=0.0f;
    sort(rtbl.begin(),rtbl.end());
    reverse(rtbl.begin(),rtbl.end());
    for(int i=0;i<rtbl.size();++i){
        double x=(i%2==0)?1.0:-1.0;
        ans += (rtbl[i]*rtbl[i])*x*M_PI;
    }
    cout<<fixed<<std::setprecision(10)<<ans<<endl;
    return 0;
}