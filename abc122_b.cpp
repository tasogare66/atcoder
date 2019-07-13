//AtCoder ABC122 B - ATCoder
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
int main() {
    string S; cin>>S;    
    ll mxans=0;
    ll tmp=0;
    for(const auto& s:S){
        if(s=='A'||s=='C'||s=='G'||s=='T'){
            ++tmp;
        } else {
            tmp=0;
        }
        mxans=max(tmp,mxans);
    }
    cout<<mxans<<endl;
    return 0;
}
