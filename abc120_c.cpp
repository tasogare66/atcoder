//AtCoder ABC120 C - Unification
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
std::string replaceStringAll(std::string str,
                             const std::string& replace,
                             const std::string& with) {
    if(!replace.empty()) {
        std::size_t pos = 0;
        while ((pos = str.find(replace, 0)) != std::string::npos) {
            str.replace(pos, replace.length(), with);
            //pos += with.length();
        }
    }
    return str;
}
int main() {
#if LOCAL&0
    std::ifstream in("./test/sample-1.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#endif
    string S="0011";
    cin>>S;
    ll cnt0=0;
    for(const auto& c:S){
        if(c=='0'){
            ++cnt0;
        }
    }
    ll cnt1=S.size()-cnt0;
    cout<<min(cnt0,cnt1)*2<<endl;
    return 0;
}