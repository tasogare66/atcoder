//AtCoder 
#include <bits/stdc++.h>
using namespace std;
using lli=int64_t;
 
int main() {
#if LOCAL&01
  	std::ifstream in("input.txt");
  	std::cin.rdbuf(in.rdbuf());
#endif
    int N,K;
    cin>>N>>K;
 
    auto calc = [&](lli num){
        lli cnt=1;
        while(num<K){
            num *= 2;
            cnt *= 2;
        }
        return (double)1/(double)cnt;
    };
   
    double t=0.0;
    double tmp = (double)1/(double)N;
    for (int i=1;i<=N;++i) {
        if (i>=K) {
            break;
        } else {
            t += (double)calc(i);
        }
    }
    //t /= (double)N;
    //t += double(max(N-K+1,0))/(double)N;
    t += (double)(max(N-K+1,0));
    t /= (double)N;
    cout<<fixed<<std::setprecision(10)<<t<<endl;
    return 0;
}