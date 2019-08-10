//https://atcoder.jp/contests/arc003/tasks/arc003_2
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
struct Data{
    string orig;
    string rev;
};
int main() {
#if LOCAL&01
    std::ifstream in("./test/sample-1.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#endif
    ll N; cin>>N;
    vector<Data> tbl(N);
    for(auto&& d:tbl){
        cin>>d.orig;
        d.rev=d.orig;
        reverse(d.rev.begin(),d.rev.end());
    }   
    sort(tbl.begin(),tbl.end(),[](auto& a,auto&b){
        return a.rev < b.rev;
    });
    for(const auto& d:tbl){
        cout<<d.orig<<endl;
    }
    return 0;
}