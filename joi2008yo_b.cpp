//https://atcoder.jp/contests/joi2008yo/tasks/joi2008yo_b
//B - JOIとIOI
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    string s; cin>>s;    
    ll joi=0;
    ll ioi=0;

    auto solv = [&s](string fstr){
        ll ret=0;
        std::string::size_type pos = s.find(fstr);
        while (pos != std::string::npos) {
            ++ret;
            pos = s.find(fstr, pos + 1);
        }
        return ret;
    };
    cout<<solv("JOI")<<endl;
    cout<<solv("IOI")<<endl;
    return 0;
}