//https://atcoder.jp/contests/arc022/tasks/arc022_2
//B - 細長いお菓子
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
#if LOCAL&01
    std::ifstream in("./test/sample-1.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll N; cin>>N;
    vector<ll> an(N+1);
    FOR(i,1,N+1){
        cin>>an.at(i);
    }

    ll left=1;
    ll right=1;
    ll ans=0;
    ll sum=0;
    map<ll,int> tbl;
    while(right<=N){
        ll v=an.at(right);
        //登録済だとleftを進める
        while (tbl.count(v)) {
            auto it = tbl.find(an.at(left));
            if (it==tbl.end()) assert(0);
            sum -= an.at(left);
            tbl.erase(it);
            ++left;
        }

        sum += v;
        tbl[v]++;
        ++right;
        //ans=max(ans,sum);
        ans=max(ans,right-left);
    }
    cout<<ans<<endl;

    return 0;
}