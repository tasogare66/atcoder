//https://atcoder.jp/contests/agc003/tasks/agc003_a
//A - Wanna go back home
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    string S; cin>>S; 
    bool has_n=false,has_w=false,has_s=false,has_e=false;
    for(const auto& c:S){
        if(c=='N'){
            has_n=true;
        }else if(c=='W'){
            has_w=true;
        }else if(c=='S'){
            has_s=true;
        }else if(c=='E'){
            has_e=true;
        }else{
            assert(0);
        }
    }   
    bool ans=(has_n==has_s&&has_w==has_e);
    cout<<(ans?"Yes":"No")<<endl;
    return 0;
}