//AtCoder ABC066 B - ss
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
    string S;
    cin>>S;
    ll ans=0;
    S.pop_back();
    while(!S.empty()){
        if (S.size()%2==0){
            auto p = S.size()/2;
            if (strncmp(&S[0],&S[p],p) == 0){
                ans=S.size();
                break;
            }
        }
        S.pop_back();
    }
    cout<<ans<<endl;
    return 0;
}