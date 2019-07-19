//https://atcoder.jp/contests/agc014/tasks/agc014_a
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll A,B,C; cin>>A>>B>>C;
    ll ans=0;
    auto check = [&](){
        return(A%2==1||B%2==1||C%2==1);
    };
    if (A==B&&B==C&&A%2==0){
        cout<<-1<<endl;
        return 0;
    }
    while(!check()){
        ll a=A,b=B,c=C;
        A=b/2+c/2;
        B=a/2+c/2;
        C=a/2+b/2;
#if LOCAL
        cout<<A<<","<<B<<","<<C<<endl;
#endif
        ++ans;
    }
    cout<<ans<<endl;
    return 0;
}