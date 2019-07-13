//AtCoder ABC102 B - Maximum Difference
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
int main() {
    ll N; cin>>N;
    vector<ll> an(N);
    for(auto&& a:an){
        cin>>a;
    }
    sort(an.begin(),an.end());
    cout<<abs(an.back()-an[0])<<endl;
    return 0;
}