//AtCoder ABC095 A - Something on It
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
    string s;
    cin>>s;
    ll ans=700;
    for(const auto& t:s){
        if(t=='o'){
            ans+=100;
        }
    }  
    cout<<ans<<endl;
    return 0;
}