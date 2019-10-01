//https://atcoder.jp/contests/agc038/tasks/agc038_a
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll H,W,A,B; cin>>H>>W>>A>>B;

    REP(y,H){
        REP(x,W){
            if (y>=B){
				if(x >= A) {
					cout << 0;
				} else {
					cout << 1;
				}
            } else {
				if(x < A) {
					cout << 0;
				} else {
					cout << 1;
				}
			}
		}
        cout<<endl;
    }

    return 0;
}