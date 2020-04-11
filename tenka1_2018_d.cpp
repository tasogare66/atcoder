//https://atcoder.jp/contests/tenka1-2018-beginner/tasks/tenka1_2018_d
//D - Crossing
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
    std::ifstream in("./test/sample-1.in");
    //std::ifstream in("./input.txt");
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll N; cin>>N;
    bool yn=false;
    ll num=-1;
    FOR(i,1,1e+5){
        ll tmp = (i+1)*i/2;
        if(tmp==N) {
            num=i;
            break;
        }
        if(N<tmp){
            break;
        }
    }
    if(num<=0){
        cout<<"No"<<endl;
        return 0;
    }
    cout<<"Yes"<<endl;

    vector<vector<ll>> ans(num+1);
    ll cnt=1;
    FOR(no,1,num+1){
        ll pos = no-1;
		FOR(i, no-1, num) {
			// ans.at(pos).push_back(no + i);
		    // ans.at(i+1).push_back(no + i);
			ans.at(pos).push_back(cnt);
		    ans.at(i+1).push_back(cnt);
            ++cnt;
		}
	}
    dump(ans);
    cout<<ans.size()<<endl;
    for(const auto& s:ans){
        cout<<s.size();
        for(const auto& v:s){
            cout<<" "<<v;
        }
        cout<<endl;
    }

	return 0;
}