//https://atcoder.jp/contests/joisc2007/tasks/joisc2007_score
//Score: 得点
//https://www.ioi-jp.org/camp/2007/2007-sp-tasks/2007-sp-day1_20.pdf
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
struct Info {
    ll no;
    ll score;
    ll ans;
};
int main() {
    ll n; cin>>n;
    vector<Info> infos(n); //score,番号
    REP(i,n){
        auto&& s=infos.at(i);
        cin>>s.score;
        s.no=i;
    }
    sort(infos.begin(),infos.end(),[](auto& a,auto& b){return a.score>b.score;});
    REP(i,n){
        auto&& s=infos.at(i);
        s.ans=i;
    }
    FOR(i,1,n){
        const auto& prev = infos.at(i-1);
        auto& cur=infos.at(i);
        if(cur.score == prev.score){
            cur.ans=prev.ans;
        }
    }
    sort(infos.begin(),infos.end(),[](auto& a,auto& b){return a.no<b.no;});
    for(auto& i:infos){
        cout<<i.ans+1<<endl;
    }

    return 0;
}