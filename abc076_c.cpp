//AtCoder ABC076 C - Dubious Document 2
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
    string Sd,T;
    cin>>Sd>>T;
    auto check_func = [&](ll p){
        bool ret = true;
        for(ll i=0;i<T.size();++i){
            auto sp=p+i;
            if(Sd[sp]=='?'||Sd[sp]==T[i]){
            } else {
                ret=false;
                break;
            }
        }
        return ret;
    };
    string ans=Sd;
    for(ll p=Sd.size()-T.size();p>=0;--p){
        if (check_func(p)){
            ans.replace(p,T.size(),T);
            for (auto&& s:ans){
                if (s=='?') {s='a';}
            }
            cout<<ans<<endl;
            return 0; //終わり
        }
    }
    cout<<"UNRESTORABLE"<<endl;
    return 0;
}