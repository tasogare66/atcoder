//https://atcoder.jp/contests/abc136/tasks/abc136_c
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
#if LOCAL&01
    std::ifstream in("./test/sample-1.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#endif
    ll N; cin>>N;    
    vector<ll> hn(N);
    for(auto&& h:hn){
        cin>>h;
    }
    //まま
    bool ans1=true;
    vector<ll> tmp=hn;
    for(ll i=N-1;i>=1;--i){
        if(tmp[i-1]>tmp[i]){
            --tmp[i-1];
            if(tmp[i-1]>tmp[i]){
                ans1=false;
                break; //無理
            }
        }
    }
    //おろす
    bool ans2=true;
    tmp=hn;
    --tmp[N-1];
    for(ll i=N-1;i>=1;--i){
        if(tmp[i-1]>tmp[i]){
            --tmp[i-1];
            if(tmp[i-1]>tmp[i]){
                ans2=false;
                break; //無理
            }
        }
    }
    cout<<((ans1||ans2)?"Yes":"No")<<endl;
    return 0;
}