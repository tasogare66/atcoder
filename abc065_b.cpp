//AtCoder ABC065 B - Trained?
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
    ll N;
    cin>>N;
    vector<ll> atbl(N+1,0);
    vector<bool> flags(N+1,false);
    for(ll i=1;i<=N;++i){
        cin>>atbl[i];
    }
    ll cur=1;
    ll count=0;
    while(true){
        flags[cur]=true;
        cur=atbl[cur];
        ++count;
        if(cur==2){
            break;
        } else if(flags[cur]){
            count=-1;
            break;
        }
    }
    cout<<count<<endl;
    return 0;
}