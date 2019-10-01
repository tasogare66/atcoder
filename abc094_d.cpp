//https://atcoder.jp/contests/abc094/tasks/arc095_b
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll n; cin>>n;
    vector<ll> an(n);    
    for(auto&& a: an){
        cin>>a;
    }
    sort(an.begin(),an.end());
    ll ai=*(an.end()-1);
    ll aj;
    ll max=-1;    
    REP(i,an.size()-1){
        ll candidate = an.at(i);
        assert(ai>candidate);
        ll tmp=min(candidate,ai-candidate);
        if (tmp > max){
            max = tmp;
            aj=candidate;
        }
    }
    cout<<ai<<" "<<aj<<endl;
    return 0;
}