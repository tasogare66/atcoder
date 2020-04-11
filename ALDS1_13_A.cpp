//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_13_A&lang=ja
//ALDS1_13_A
//8 Queens Problem
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
#if LOCAL&01
    //std::ifstream in("./test/sample-1.in");
    std::ifstream in("./input.txt");
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll k; cin>>k;
    vector<pair<ll,ll>> rcs(k);
    map<ll,ll> rcmap;
    for(auto&& p:rcs){
        cin>>p.first>>p.second; //y,x
        rcmap[p.first]=p.second;
    }    

    vector<ll> lst(8);
    iota(lst.begin(), lst.end(), 0);
    do {
        bool flag=true;
        FOR(y,0,8){
            auto x=lst.at(y);
            auto it=rcmap.find(y);
            if(it!=rcmap.end()){
                if(it->second!=x) {flag=false;break;} //次へ
            }

            FOR(chy,0,8){
                if(y==chy) continue;
                ll chx=lst.at(chy);
                if(abs(chy-y)==abs(chx-x)){
                    flag=false;
                    break;
                }
            }
            if(not flag) break;
        }

        if(flag){
            vector<vector<char>> ans(8,vector<char>(8,'.'));
            FOR(yy,0,8){
                ans.at(yy).at(lst.at(yy))='Q';
            }
            FOR(yy,0,8){
                FOR(xx,0,8){
                    cout<<ans[yy][xx];
                }
                cout<<endl;
            }
            return 0; //終わり
        }
    } while(next_permutation(lst.begin(),lst.end()));

    return 0;
}

int main_() {
#if LOCAL&01
    std::ifstream in("./test/sample-1.in");
    //std::ifstream in("./input.txt");
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll k; cin>>k;
    vector<pair<ll,ll>> rcs(k);
    for(auto&& p:rcs){
        cin>>p.first>>p.second; //y,x
    }    

    constexpr ll xymax=8;
    vector<vector<ll>> mat(xymax,vector<ll>(xymax,0));

    auto check_func = [&mat](size_t y, size_t x){
        auto check = [&mat](size_t iy, size_t ix){
            if(iy>=xymax)return;
            if(ix>=xymax)return;
            mat.at(iy).at(ix)=1;
        };
        FOR(i,0,xymax){
            mat.at(i).at(x)=1;
            mat.at(y).at(i)=1;
            if(i==0)continue;
            check(y+i,x+i);
            check(y+i,x-i);
            check(y-i,x+i);
            check(y-i,x-i);
        }
    };

    vector<vector<char>> ans(xymax,vector<char>(xymax,'.'));
    set<ll> ytbl;
    for(const auto& p:rcs){
        check_func(p.first, p.second);
        ytbl.insert(p.first);
        ans.at(p.first).at(p.second)='Q';
    }

    FOR(y,0,xymax){
        if(ytbl.count(y)==0){
            FOR(x,0,xymax){
                if(mat.at(y).at(x)==0){
                    check_func(y,x);
                    ans.at(y).at(x)='Q';
                    break;
                }
            }
        }
    }
    dump(mat);
    FOR(y,0,xymax){
        FOR(x,0,xymax){
            cout<<ans[y][x];
            cout<<" ";
        }
        cout<<endl;
    }

    return 0;
}