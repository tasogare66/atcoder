//AtCoder ABC104 B - AcCepted
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
int main() {
    string S; cin>>S;
    bool ans=true;
    if(S[0]!='A') ans=false;
    ll idx=-1;
    for(ll i=0;i<S.size();++i){
        if(S[i]=='C'){
            if(i>=2&&i<=S.size()-2){
                idx=i;
            } else {
                ans=false;
            }
        }
    }
    if(idx<0) ans=false; //ない
    for(ll i=1;i<S.size();++i){
        if(i==idx) continue;
        if(S[i]>='a'&&S[i]<='z'){
        } else {
            ans=false;
        }
    }
    cout<<(ans?"AC":"WA")<<endl;
    return 0;
}