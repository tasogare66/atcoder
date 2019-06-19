//AtCoder ABC071 B - Not Found
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
    string S;
    cin>>S;
    vector<ll> tbl(26,0);
    for(const auto& s: S){
        ++tbl[s-'a'];
    }
    for(int i=0;i<tbl.size();++i){
        if (tbl[i]==0) {
            cout<<(char)('a'+i)<<endl;
            return 0;
        }
    }
    cout<<"None"<<endl;
    return 0;
}