//https://atcoder.jp/contests/arc002/tasks/arc002_3
//C - コマンド入力
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
    ll N; cin>>N;
    string s; cin >> s;
    vector<string> buttons = {"AA", "AB", "AX", "AY",
                      "BA", "BB", "BX", "BY",
                      "XA", "XB", "XX", "XY",
                      "YA", "YB", "YX", "YY"};

	ll ans = INT64_MAX;

	REP(x, buttons.size()) {
		REP(y, buttons.size()) {
			string r = buttons[x];
			string l = buttons[y];
			vector<ll> dp(s.size() + 1);
			REP(i, s.size() + 1) dp[i] = i; // コマンドを使わない場合

			for(int i = 0; i < s.size(); i++) {
				chmin(dp[i + 1], dp[i] + 1);
				if((s[i] == r[0] && s[i + 1] == r[1]) ||
				   (s[i] == l[0] && s[i + 1] == l[1])) {
					chmin(dp[i + 2], dp[i] + 1);
				}
			}
			if (chmin(ans, dp.back())){
				dump(r, l, ans);
				dump(dp);
			}
		}
    }
 
    cout << ans << endl;
    return 0;
}

int main_() {
#if LOCAL&0
    std::ifstream in("./test/sample-1.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll N; cin>>N;
    string cn; cin>>cn;
    auto shortcut = [](char a,char b, char lr, const string str){
        string result;
        for(ll i=0; i<str.size();++i){
            if(i+1<str.size()&&str[i]==a&& str[i+1]==b){
                result.push_back(lr);
                ++i;
            } else {
                result.push_back(str[i]);
            }
        }
        return result;
    };
    char cmdtbl[]={'A','B','X','Y'};
    ll ans0=INT64_MAX;
    ll ans=INT64_MAX;
    string r0;
    for(auto a:cmdtbl){
        for(auto b:cmdtbl){
            auto r = shortcut(a,b,'L',cn);
            //if (chmin(ans0, (ll)r.size())){
                //r0=r;
                //dump(a,b,r);
				for(auto aa : cmdtbl) {
					for(auto bb : cmdtbl) {
						auto rr = shortcut(aa, bb, 'R', r);
						if(chmin(ans, (ll)rr.size())) {
							dump(rr);
						}
					}
				}
			//}
        }
    }
    cout<<ans<<endl;
    return 0;
}