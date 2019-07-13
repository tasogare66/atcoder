//AtCoder 
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
int main() {
#if LOCAL&0
    std::ifstream in("input.txt");
    std::cin.rdbuf(in.rdbuf());
#endif
    ll N; cin>>N;
    ll base=-2;
    string ans;
    while(N!=1&&N!=0){
        ll s0=1;
        if (abs(N-s0)%2==0) {
            //s0が1
            ans.push_back('1');
            N=(N-s0)/base;
        } else {
            //s0が0
            ans.push_back('0');
            N=N/base;
        }
    }
    ans.push_back('0'+N);
    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;   
    return 0;
}