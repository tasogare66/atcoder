//https://atcoder.jp/contests/code-festival-2017-quala/tasks/code_festival_2017_quala_c
//C - Palindromic Matrix
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
#if LOCAL&0
    std::ifstream in("./test/sample-1.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll H,W; cin>>H>>W;
    vector<string> ahw(H);
    for(auto&& ah:ahw){
        cin>>ah;
    }
    unordered_map<char,ll> ch_cnt;
    REP(y,H){
        REP(x,W){
            auto c=ahw.at(y).at(x);
            ch_cnt[c]++;
        }
    }
    unordered_map<int,ll> needs;
    ll tw=W,th=H;
    if(tw%2==1 && th%2==1){
        needs[2]+=tw/2;
        needs[2]+=th/2;
        needs[1]+=1;
        --tw;
        --th;
    }else if(tw%2==1){
        needs[2]+=th/2;
        //needs[1]=1;
        --tw;
    }else if(th%2==1){
        needs[2]+=tw/2;
        dump(tw/2);
        //needs[1]=1;
        --th;
    }
    needs[4]+=(th/2)*(tw/2);

    bool ans=true;

    auto count_check = [&](ll type){
        FOR(i,0,needs[type]){
            bool found=false;
            for(auto& cnt:ch_cnt){
                if(type==1){
                    if(cnt.second!=0&&cnt.second%2==1){
                        cnt.second -= type;
                        found=true;
                        break;
                    }
                }else if(type==4){
                    if(cnt.second!=0&&cnt.second>=4){
                        cnt.second -= type;
                        found=true;
                        break;
                    }                    
                }else if(cnt.second!=0&&cnt.second%type==0){
                    cnt.second -= type;
                    found=true;
                    break;
                }
            }
            if(not found) ans=false;
        }
    };

    count_check(1);
    count_check(4);
    count_check(2);

    cout<<(ans?"Yes":"No")<<endl;

    return 0;
}