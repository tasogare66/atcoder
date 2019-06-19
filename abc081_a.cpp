//AtCoder ABC081 A - Placing Marbles
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
    string S;
    cin>>S;
    ll ans=0;
    for(const auto& s:S){
        if(s=='1') ++ans;
    }
    cout<<ans<<endl;
    return 0;
}