//https://atcoder.jp/contests/arc019/tasks/arc019_1
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
int main() {
    string S; cin>>S;
    unordered_map<char,char> rep = {
        {'O','0'},
        {'D','0'},
        {'I','1'},
        {'Z','2'},
        {'S','5'},
        {'B','8'},
    };
    for(auto&& c:S){
        auto it=rep.find(c);
        if(it!=rep.end()){
            c=it->second;
        }
    }    
    cout<<S<<endl;
    return 0;
}