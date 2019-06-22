//AtCoder ABC093 B - Small and Large Integers
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
#if LOCAL&0
    std::ifstream in("input.txt");
    std::cin.rdbuf(in.rdbuf());
#endif
    ll A,B,K;
    cin>>A>>B>>K;
    unordered_set<ll> tbl;
    for(ll i=A;i<A+K&&i<=B;++i){
        tbl.insert(i);
    }
    for(ll i=B;i>B-K&&i>=A;--i){
        tbl.insert(i);
    }
    vector<ll> ans(tbl.size()); //setからvectorのコピー,確保しておく or std::back_inserter(output)
    std::copy(tbl.begin(), tbl.end(), ans.begin()); //setからvectorのコピー
    sort(ans.begin(),ans.end());
    for(const auto& a:ans){
        cout<<a<<endl;
    }
    return 0;
}