//AtCoder ABC046 C - AtCoDeerくんと選挙速報 / AtCoDeer and Election Report
#include <bits/stdc++.h>
using namespace std;
using lli=int64_t;

int main() {
#if LOCAL&0
    std::ifstream in("input.txt");
    std::cin.rdbuf(in.rdbuf());
#endif
    int N;
    cin>>N;
    lli a=0,b=0;
    cin>>a>>b;

    auto get_rate = [](lli c,lli n){
        lli r=c/n;
        while(c > n*r){
            ++r;
        }
        return r;
    };

    for(int i=1;i<N;++i){
        lli aa,bb;
        cin>>aa>>bb;
        lli r=max(get_rate(a,aa),get_rate(b,bb));
        a=aa*r;
        b=bb*r;
    }
    cout<<a+b<<endl;
    return 0;
}