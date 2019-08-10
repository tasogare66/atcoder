//https://atcoder.jp/contests/arc044/tasks/arc044_a
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    ll N; cin>>N;
    bool ans=true;
    if(N==1){ //素数でない,合成数でない
        ans=false;
    }else if(N==2||N==5||N==3){
    }else if(N%2==0||N%5==0||N%3==0){
        ans=false;
    }
    cout<<(ans?"Prime":"Not Prime")<<endl;
    return 0;
}