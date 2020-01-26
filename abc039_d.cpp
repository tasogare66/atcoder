//https://atcoder.jp/contests/abc039/tasks/abc039_d
//D - 画像処理高橋君
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
     std::ifstream in("./test/sample-1.in"); //input.txt
     std::cin.rdbuf(in.rdbuf());
 #else
     cin.tie(0);
     ios::sync_with_stdio(false);
 #endif
    ll H,W; cin>>H>>W;
    vector<string> sh(H);
    for(auto&& s:sh){
        cin>>s;
    }
    vector<string> ans(H);
    vector<string> work(H, string(W,'.'));

    auto check_xy = [&](ll x, ll y){
        if(x<0||x>=W) return false;
        if(y<0||y>=H) return false;
        return true;
    };
    pair<ll,ll> ofs[]={
        {-1,-1},{-1,0},{-1,1},
        {0,-1},{0,0},{0,1},
        {1,-1},{1,0},{1,1},
    };
    auto check_black = [&ofs,&check_xy](auto& m, ll ix, ll iy){
        for(const auto& o:ofs){
            ll cx=ix+o.first;
            ll cy=iy+o.second;
            if(check_xy(cx,cy)){
                if (m.at(cy).at(cx)!='#'){
                    return false;
                }
            }
        }
        return true;
    };
    auto set_black = [&ofs,&check_xy](auto& m, ll ix, ll iy){
        for(const auto& o:ofs){
            ll cx=ix+o.first;
            ll cy=iy+o.second;
            if(check_xy(cx,cy)){
                m.at(cy).at(cx)='#';
            }
        }
        return true;
    };

    REP(y,H){
        REP(x,W){
            if(check_black(sh, x, y)){
                ans.at(y).push_back('#');
                set_black(work, x, y);
            } else {
                ans.at(y).push_back('.');
            }
        }
    }
    bool possible=true;
    REP(y,H){
        if(work[y]!=sh[y]){
            possible=false;
            break;
        }        
    }
    if(possible){
        cout<<"possible"<<endl;
        for(const auto& s:ans){
            cout<<s<<endl;
        }
    }else {
        cout<<"impossible"<<endl;
    }

    return 0;
}