//AtCoder ABC088 B - Card Game for Two
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
    ll N;
    cin>>N;
    vector<ll> an(N);
    for(auto&& a:an){
        cin>>a;
    }
    sort(an.begin(),an.end());
    ll alice=0,bob=0;
    for(ll i=0;i<N;++i){
        if(i%2==0){
            alice+=an.back();
        } else{
            bob+=an.back();
        }
        an.pop_back();
    }
    cout<<alice-bob<<endl;
    return 0;
}