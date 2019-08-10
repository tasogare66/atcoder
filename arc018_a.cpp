//https://atcoder.jp/contests/arc018/tasks/arc018_1
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    double height, bmi; cin>>height>>bmi;
    height /= 100;
    double w=bmi*height*height;
    cout<<fixed<<std::setprecision(10)<<w<<endl;
    return 0;
}