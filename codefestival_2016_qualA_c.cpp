//https://atcoder.jp/contests/code-festival-2016-quala/tasks/codefestival_2016_qualA_c
//C - 次のアルファベット / Next Letter
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
    string is; cin>>is;
    string s=is;
    ll K; cin>>K;    
    ll p=0;
    while(K>0&&p<s.size()){
        auto ch=s.at(p);
        if(ch!='a'){
            ll dif=26-s.at(p)+'a';
            if(dif<=K&&dif>0){
                s.at(p)='a';
                K-=dif;
            }
        }
        ++p;
    }
    //のこり
    K%=26;
    s.back()+=K;
    if(s.back()>'z') s.back()-=26;
    cout<<s<<endl;
    return 0;
}