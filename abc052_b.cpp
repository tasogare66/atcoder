//AtCoder ABC052 B - Increment Decrement
#include <bits/stdc++.h>
using namespace std;
using lli=int64_t;

int main() {
    int N;
    string S;
    cin>>N>>S;
    int v=0;
    int ans=0;
    for(auto&& s:S){
        if(s=='I') ++v;
        else --v;
        ans=max(v,ans);
    }
    cout<<ans<<endl;
    return 0;
}