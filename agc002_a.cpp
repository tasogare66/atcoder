//https://atcoder.jp/contests/agc002/tasks/agc002_a
//A - Range Product
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll a,b; cin>>a>>b;
    ll ans=0;
    do{
        if(a==0||b==0) {
            ans=0;
            break;
        }
        if(a<0&&b>0){
            ans=0;
            break;
        }
        if(a>0){
            ans=1;
            break;
        }
        if(b<0){
            if ((b-a)%2==1) ans=1;
            else ans=-1;
            break;
        }
        assert(0);
    }while(false);
    if(ans==0){
        cout<<"Zero"<<endl;
    } else {
        cout<<(ans>0?"Positive":"Negative")<<endl;
    }
    return 0;
}