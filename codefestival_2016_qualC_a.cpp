//https://atcoder.jp/contests/code-festival-2016-qualc/tasks/codefestival_2016_qualC_a
//A - CF
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    string s; cin>>s;
    bool cf=false,ff=false;
    bool ans=false;
    REP(i,s.size()){
        if(cf){
            if(s.at(i)=='F'){
                ans=true;
            }
        }else{
            if(s.at(i)=='C') cf=true;
        }
    }
    if(ans){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
    return 0;
}