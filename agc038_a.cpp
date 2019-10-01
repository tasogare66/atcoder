//https://atcoder.jp/contests/agc038/tasks/agc038_a
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
#if LOCAL&01
    std::ifstream in("./test/sample-2.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll H,W,A,B; cin>>H>>W>>A>>B;
    vector<vector<ll>> ans(H,vector<ll>(W,0));
    //bは0,1をためす
    auto check = [&]() {
        //A
        REP(y,H){
            ll count=0;
            REP(x,W){
                if(ans[y][x]) ++count;
            }
            auto v = min(count, W-count);
            if (v!=A)return false;
        }
        //B
        REP(x,W){
            ll count=0;
            REP(y,H){
                if(ans[y][x]) ++count;
            }
            auto v = min(count, H-count);
            if (v!=B)return false;
        }
        return true;
    };
    auto output = [&]() {
        REP(y,H){
            REP(x,W){
                cout<<ans[y][x];
            }
            cout<<endl;
        }
    };

	auto fill = [&](ll ofsx, ll ofsy) {
		FOR(y, ofsy, ofsy+B) {
			FOR(x, ofsx, ofsx+A) {
                if(x<W&&y<H){
                    ans[y][x] = 1;
                }
            }
		}
	};
    ll ox=0,oy=0;
    bool ret=true;
    while(ret){
        fill(ox,oy);
        ox += A;
        oy += B;
        ret = (ox<W&&oy<H);
    }
    if (check()) {
        output(); return 0;
    }


	auto fill2 = [&](ll ofsx, ll ofsy, ll invb) {
		FOR(y, ofsy, ofsy+invb) {
			FOR(x, ofsx, ofsx+A) {
                if(x<W&&y<H){
                    ans[y][x] = 1;
                }
            }
		}
	};
    vector<vector<ll>> tmp(H,vector<ll>(W,0));
    ans = tmp;
    ox=0,oy=0;
    ret=true;
    while(ret){
        ll invb = H-B;
        fill2(ox,oy, invb);
        ox += A;
        oy += invb;
        ret = (ox<W&&oy<H);
    }
    if (check()) {
        output(); return 0;
    }

    cout<<"No"<<endl;

	return 0;
}