//AtCoder ABC080 B - Harshad Number
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
    string N;
    cin>>N;
    ll sum=0;
    ll val=stoi(N);
    for(const auto& s:N){
        sum+=s-'0';
    }
    cout<<(val%sum==0?"Yes":"No")<<endl;
    return 0;
}