//https://atcoder.jp/contests/abc019/tasks/abc019_4
//D - 高橋くんと木の直径
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll N; cin>>N;
    ll st=1;
    ll maxid=0;
    ll maxdist=0;
    FOR(n,2,N+1){ //stは1にするので2から
        cout << "? " << st << " " << n << endl;
        ll dist;
        cin >> dist;
        if(maxdist<dist){
            maxdist=dist;
            maxid=n;
        }
    }    
    ll ans=0;
    FOR(n,1,N+1){
        if(n==maxid) continue;
        cout << "? " << maxid << " " << n << endl;
        ll dist;
        cin >> dist;
        ans=max(ans,dist);
    }
    cout<<"! "<<ans<<endl;

    return 0;
}
