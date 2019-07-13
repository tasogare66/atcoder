//AtCoder AGC032 A - Limited Insertion
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
#if LOCAL&0
    std::ifstream in("./test/sample-3.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#endif
    ll N; cin>>N;
    vector<ll> bn(N+1);
    FOR(i,1,N+1){
        cin>>bn[i];
    }
    //差分出す
    auto search = [&](ll n)->ll{
        vector<ll> ofsn(n,0);
        ll minofs=INT64_MAX;
        ll minofs_idx=-1;
        FOR(i,1,n){
            auto ofs=i-bn[i];
            if(ofs<0) return -1; //無理
            ofsn[i]=ofs;
            if(minofs>=ofs){
                minofs=ofs;
                minofs_idx=i;
            }
        }
        return minofs==0?minofs_idx:-1;
    };

    vector<ll> ans;
    while(bn.size()>1) {
        ll idx = search(bn.size());
        if(idx<0){
            cout<<-1<<endl;
			return 0;
		}
        ans.push_back(bn[idx]);
        bn.erase(bn.begin()+idx);
    }

    reverse(ans.begin(),ans.end()); //反対に
    for(const auto& a:ans){
        cout<<a<<endl;
    }
    return 0;
}