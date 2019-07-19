//https://atcoder.jp/contests/agc022/tasks/agc022_a
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
#if LOCAL&0
    std::ifstream in("./test/sample-5.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#endif
    string S; cin>>S;
    unordered_map<char,ll> tbl;
    bool flag=false;
    for(const auto& s:S){
        ++tbl[s];
        if(tbl[s]>1) flag=true;
    }
    if(flag) {
        assert(0);
        cout<<-1<<endl;
        return 0;
    }
    if(tbl.size()>=26){
        for(ll i=S.size()-1;i>=1;--i){
            if(S[i-1]<S[i]){
                auto ss = S.substr(i);
                auto tgt = S[i-1];
                sort(ss.begin(),ss.end());
                S.erase(S.begin()+i-1,S.end());
                for(auto& c:ss){
                    if(c>tgt){
                        S.push_back(c);
                        break;
                    }
                }
                cout<<S<<endl;
                return 0;
            }
        }
        cout<<-1<<endl;
        return 0;
    }
    //後ろにつける
    for(char ch='a';ch<='z';++ch){
        auto it=tbl.find(ch);
        if(it==tbl.end()){
            S.push_back(ch);
            break;
        }
    }
    cout<<S<<endl;
    return 0;
}