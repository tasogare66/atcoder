//https://atcoder.jp/contests/agc016/tasks/agc016_a
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
#if LOCAL&01
    std::ifstream in("./test/sample-1.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#endif
    string s; cin>>s;
    auto check = [](string& ins){
        assert(ins.size()>0);
        char c=ins[0];
        bool ret=true;
        for(ll i=1;i<ins.size();++i){
            if(c!=ins[i]) {
                ret=false;
                break;
            }
        }
        return ret;
    };
    ll ans=INT64_MAX;
    for(char c='a';c<='z';++c){
        string cur=s;
        ll cnt=0;
        while(!check(cur)){
            //消すの決める
            ll i=cur.size()-1;
            for(;i>=0;--i){
                if(cur[i]!=c) {
                    break;
                }
            }
            for(ll j=0;j<i;++j){
                if(cur[j+1]==c) cur[j]=c;
            }
            cur.erase(cur.begin()+i);
            ++cnt;
        }
        ans=min(cnt,ans);
    }
    cout<<ans<<endl;
    return 0;
}