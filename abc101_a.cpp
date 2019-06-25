//AtCoder ABC101 A - Eating Symbols Easy
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
    string S;
    cin>>S;
    ll ans=0;
    for(const auto&s:S){
        if(s=='+') ++ans;
        else --ans;
    }
    cout<<ans<<endl;
    return 0;
}