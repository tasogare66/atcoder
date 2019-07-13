//AtCoder ABC103 B - String Rotation
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
int main() {
    string S,T; cin>>S>>T;
    bool ans=S==T;
    for(ll i=0;i<S.size();++i){
        auto s = S.back();
        S.pop_back();
        S.insert(S.begin(),s);
        if(S==T)ans=true;
    }
    cout<<(ans?"Yes":"No")<<endl;
    return 0;
}
