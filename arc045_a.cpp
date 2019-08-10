//https://atcoder.jp/contests/arc045/tasks/arc045_a
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
#define FOR(i,a,b) for(int64_t i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
std::vector<std::string> split(const std::string& input, char delimiter){
    std::istringstream stream(input);
    std::string field;
    std::vector<std::string> result;
    while (std::getline(stream, field, delimiter)) {
        result.push_back(field);
    }
    return result;
}
int main() {
#if LOCAL&0
    std::ifstream in("./test/sample-1.in"); //input.txt
    std::cin.rdbuf(in.rdbuf());
#endif
    string S; getline(cin,S);
    auto tbl=split(S,' ');
    bool st=true;
    for(const auto& t:tbl){
        if(!st) cout<<" ";
        if(t=="Left") cout<<"<";
        else if(t=="Right") cout<<">";
        else if(t=="AtCoder") cout<<"A";
        else assert(0);
        st=false;
    }
    cout<<endl;
    return 0;
}