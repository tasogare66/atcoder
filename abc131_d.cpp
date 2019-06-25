//AtCoder 
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
struct Job{
    ll a;
    ll b;
};
int main() {
    ll N;cin>>N;
    vector<Job> abn(N);
    for(auto&& j:abn){
        cin>>j.a>>j.b;
    }
    sort(abn.begin(),abn.end(),[](auto& a,auto& b){ return (a.b < b.b); });
    ll t=0;
    bool ans=true;
    for(auto&& j:abn){
        t += j.a;
        if(t>j.b){
            ans=false;
            break;
        }
    }
    cout<<(ans?"Yes":"No")<<endl;
    return 0;
}