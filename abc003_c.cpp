//ABC002 C - AtCoderプログラミング講座
#include <bits/stdc++.h>
using namespace std;
int main() {
    int total, viewnum;
    cin>>total>>viewnum;
    std::vector<int> rate(total,0);
    for(int i=0; i<rate.size();++i){
        cin >> rate[i];
    }
    std::sort(rate.begin(),rate.end());
    double ans = 0;
    for (int i=viewnum;i>0;--i) {
        ans = (ans + rate[rate.size()-i])/2.0;
    }
    cout<<fixed<<std::setprecision(10)<<ans<<endl;
    return 0;
}