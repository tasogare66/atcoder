//https://atcoder.jp/contests/abc141/tasks/abc141_b
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
#if LOCAL&01
    std::ifstream in("./test/sample-5.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    string s; cin>>s;    
    bool ans=true;
    REP(i,s.size()){
        ll p=i+1;
        if(p%2==0){
            if (s[i]=='R'){ ans=false; break;}
        }else{
            if (s[i]=='L'){ans=false;break;}
        }
    }
    cout<<(ans?"Yes":"No")<<endl;
    return 0;
}