//AtCoder ABC089 B - Hina Arare
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
    ll N;
    cin>>N;
    unordered_map<char,ll> tbl;
    for(ll i=0;i<N;++i){
        char c;
        cin>>c;
        ++tbl[c];
    }
    cout<<(tbl.size()==4?"Four":"Three")<<endl;
    return 0;
}