//AtCoder ABC095 
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
    ll A,B,C,X,Y;
    cin>>A>>B>>C>>X>>Y;
    ll ans=A*X+B*Y;
    ll cnum=2;
    while(true){
        ll tmp=A*max(X-cnum/2,(ll)0)+B*max(Y-cnum/2,(ll)0)+cnum*C;
        if(ans > tmp){
            ans=tmp;
            cnum+=2;
        } else {
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}