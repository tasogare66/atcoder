//https://atcoder.jp/contests/agc033/tasks/agc033_b
//B - LRUD Game
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
int main() {
#if LOCAL&01
    std::ifstream in("./test/sample-1.in");
    //std::ifstream in("./input.txt");
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll H,W,N; cin>>H>>W>>N;    
    ll sr,sc; cin>>sr>>sc;
    string S; cin>>S;
    string T; cin>>T;

    unordered_map<char,pair<int,int>> ofs = {
        {'U',{0,-1}},
        {'D',{0,1}},
        {'L',{-1,0}},
        {'R',{1,0}},
    };
    char sts[][2] = {
        {'U','D'},
        {'D','U'},
        {'L','R'},
        {'R','L'},
    };
    for(auto st:sts) {
        //char st[2]={'U','D'};
        ll py=sr;
        ll px=sc;
        REP(i,S.size()){
            const auto& f = ofs[st[0]];
            const auto& s = ofs[st[1]];
            if(S.at(i)==st[0]){
                px+=f.first;
                py+=f.second;
            }
            if(px<1||px>W||py<1||py>H){
                cout<<"NO"<<endl;
                return 0;
            }
            if(T.at(i)==st[1]){
                px+=s.first;
                py+=s.second;
            }
            px=max(1LL,px); px=min(W,px);
            py=max(1LL,py); py=min(H,py);
        }
    }
    cout<<"YES"<<endl;

    return 0;
}