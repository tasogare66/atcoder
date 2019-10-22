//https://atcoder.jp/contests/abc109/tasks/abc109_d
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
    ll H,W; cin>>H>>W;
    vector<vector<ll>> ahw(H+1,vector<ll>(W+1));
    FOR(y,1,H+1){
        auto&& v=ahw.at(y);
        FOR(x,1,W+1){
            cin>>v.at(x);
        }
    }
    bool flag=false;
    ll px=-1,py=-1;
    vector<tuple<ll,ll,ll,ll>> ans;
    FOR(y,1,H+1){
        auto&& v=ahw.at(y);
        auto check_func = [&](ll iy,ll ix){
            if (flag){
                ans.emplace_back(make_tuple(py,px,iy,ix));
                //cout<<py<<" "<<px<<" "<<iy<<" "<<ix<<endl;
            }
            if(ahw.at(iy).at(ix)%2==1){
                flag = !flag;
            }
            px=ix;
            py=iy;
        };
        if(y%2==0){//<-
            for(ll x=W;x>=1;--x){
                check_func(y,x);
            }
        } else {//->
            FOR(x,1,W+1){
                check_func(y,x);
            }
        }
    }
    cout<<ans.size()<<endl;
    for(const auto& a:ans){
        cout<<get<0>(a)<<" "<<get<1>(a)<<" "<<get<2>(a)<<" "<<get<3>(a)<<endl;
    }

    return 0;
}