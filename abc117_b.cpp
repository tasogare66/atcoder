//AtCoder ABC117 B - Polygon
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
int main() {
    ll N; cin>>N;
    vector<ll> ln(N);
    for(auto&& l:ln){
        cin>>l;
    }
    sort(ln.begin(),ln.end());
    ll sum=0;
    for(ll i=0;i<ln.size()-1;++i){
        sum+=ln[i];
    }
    cout<<(ln[N-1]<sum?"Yes":"No")<<endl; 
    return 0;
}