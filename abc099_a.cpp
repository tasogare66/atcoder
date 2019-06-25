//AtCoder ABC099 A - ABD
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
    ll N; cin>>N;
    if(N>=1000){
        cout<<"ABD"<<endl;
        N-=999;
    }else{
        cout<<"ABC"<<endl;
    }
    //std::cout << std::setfill('0') << std::right << std::setw(3) << N <<endl;
    return 0;
}