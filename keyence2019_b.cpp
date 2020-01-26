//https://atcoder.jp/contests/keyence2019/tasks/keyence2019_b
//B - KEYENCE String
#include <bits/stdc++.h>
#if LOCAL
#include "dump.hpp"
#else
#define dump(...)
#endif
using namespace std;
using ll=long long;
#define FOR(i,a,b) for(ll i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
template<class T>bool chmax(T &a, const T &b) {if (a<b) { a=b; return 1; } return 0;}
template<class T>bool chmin(T &a, const T &b) {if (b<a) { a=b; return 1; } return 0;}
int main(){
    string S; cin>>S;
    bool ans=false;
    string bs="keyence";
    auto difs=S.size()-bs.size();
    FOR(i,0,S.size()){
        if(difs<0)break;
        if(i+difs>S.size())break;
        string tmp=S;
        tmp.erase(i,difs);
        if(tmp==bs) {
            ans=true;
            break;
        }
    }
    cout<<(ans?"YES":"NO")<<endl;
    return 0;
}
int main_() {
#if LOCAL&01
    std::ifstream in("./test/sample-4.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    string S; cin>>S;
    auto check_func=[&](const string& h,const string& f){
        auto r1=S.find(h,0);
        if (r1==string::npos) return false;
        auto r2=S.find(f,r1+h.size());
        if (r2==string::npos) return false;
        return true;
    };
    bool ans=false;
    string bs="keyence";
    FOR(i,1,bs.size()){
        string h,f;
        h.append(bs,0,i);
        f.append(bs,i,bs.size()-i);
        dump(i,h,f);
        ans|=check_func(h,f);
        if(ans)break;
    }

    cout<<(ans?"YES":"NO")<<endl;    
    return 0;
}