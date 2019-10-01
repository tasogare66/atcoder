//https://atcoder.jp/contests/abc140/tasks/abc140_d
//D - Face Produces Unhappiness
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
//    cin.tie(0);
//    ios::sync_with_stdio(false);
#if LOCAL&01
    std::ifstream in("./test/sample-1.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#endif
    ll N,K; cin>>N>>K;
    string S; cin>>S;

    ll count=0;
    auto sha=[&](ll no){
        if (no<0||no>=S.size()) return 'x';
        return S[no];
    };
    REP(i,S.size()){
        if(sha(i)=='R'){
            if(sha(i+1)=='R') ++count;
        } else { //L
            if(sha(i-1)=='L') ++count;
        }
    }
    //lr,rl    
    ll lr=0,rl=0;
    REP(i,S.size()){
        if(sha(i)=='L'&&sha(i+1)=='R') ++lr;
        if(sha(i)=='R'&&sha(i+1)=='L') ++rl;
    }
//    cout<<"LR:"<<lr<<endl;;
//    cout<<"RL:"<<rl<<endl;;
    auto tmp = min(lr,rl);
    tmp=min(K,tmp);
    count+=tmp*2;
    K-=tmp;
    if(K>0){
        lr-=tmp;
        rl-=tmp; 
        tmp=max(lr,rl);       
        count += min(K,tmp);
    }
    cout<<count<<endl;
    return 0;
}