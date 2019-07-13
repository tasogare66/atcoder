//AtCoder ABC105 B - Cakes and Donuts
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
int main() {
	cin.tie(0);
   	ios::sync_with_stdio(false);
    ll N; cin>>N;
    ll amx=N/4;
    ll bmx=N/7;
    bool ans=false;
    for(ll i=0;i<=amx;++i){
        for(ll j=0;j<=bmx;++j){
            if(N==i*4+j*7) ans=true;
        }
    }
    cout<<(ans?"Yes":"No")<<endl;
    return 0;
}