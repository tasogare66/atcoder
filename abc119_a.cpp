//AtCoder A - Still TBD
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
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
    string S; cin>>S;
    auto tbl = split(S,'/');
    //20140430
    ll c=stol(tbl[0])*10000+stol(tbl[1])*100+stol(tbl[2]);
    bool ans=(c<=20190430);
    cout<<(ans?"Heisei":"TBD")<<endl;
    return 0;
}