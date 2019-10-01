//https://atcoder.jp/contests/abc064/tasks/abc064_d
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
#if LOCAL&01
    std::ifstream in("./test/sample-1.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#else
    cin.tie(0);
    ios::sync_with_stdio(false);
#endif
    ll N; cin>>N;
    string S; cin>>S;
    ll count=0;
    ll head=0;
    REP(i,S.size()){
        auto c = S.at(i);
        if(c=='('){
            ++count;
        }else{
            --count;
        }
        if(count<0){
            head -= count;
            count = 0;
        }
    }
    assert(count>=0);
    string h(head,'(');
    string f(max(count,(ll)0), ')');
    cout<<(h+S+f)<<endl;
    return 0;
}