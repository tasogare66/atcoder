//AtCoder ABC059 C - Sequence
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
#if LOCAL&0
    std::ifstream in("input.txt");
    std::cin.rdbuf(in.rdbuf());
#endif
    int n;
    cin>>n;
    vector<ll> atbl(n);
    vector<ll> sum(n,0);
    for(auto&& a:atbl){
        cin>>a;
    }
    ll ad=0;
    for(int i=0;i<atbl.size();++i){
        ad+=atbl[i];
        sum[i]=ad;
    }
    auto check1 = [&](){
        ll ans=0;
        ll cur=0;
        for(int i=0;i<sum.size();++i){
            auto cur_sum=sum[i]+cur;
            if(i%2){
                if(cur_sum>=0) {
                    auto c=cur_sum+1;
                    cur -= c;
                    ans += abs(c);
                }
            }else{
                if(cur_sum<=0){
                    auto c=cur_sum-1;
                    cur -= c;
                    ans += abs(c);
                }
            }
        }
        return ans;
    };
    auto check2 = [&](){
        ll ans=0;
        ll cur=0;
        for(int i=0;i<sum.size();++i){
            auto cur_sum=sum[i]+cur;
            if(i%2){
                if(cur_sum<=0){
                    auto c=cur_sum-1;
                    cur -= c;
                    ans += abs(c);
                }
            }else{
                if(cur_sum>=0) {
                    auto c=cur_sum+1;
                    cur -= c;
                    ans += abs(c);
                }
            }
        }
        return ans;
    };
    cout<<min(check1(),check2())<<endl;
    return 0;
}