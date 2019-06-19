//AtCoder ABC084 B - Postal Code
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
    ll A,B;
    string S;
    cin>>A>>B;
    cin>>S;
    bool ans=(A+B+1==S.size());
    for(ll i=0;i<S.size();++i){
        if(i==A){
            if(S[i]!='-')ans=false;
        }else{
            if(S[i]>='0'&&S[i]<='9'){
            } else {
                ans=false;
            }
        }
    }
    cout<<(ans?"Yes":"No")<<endl;
    return 0;
}