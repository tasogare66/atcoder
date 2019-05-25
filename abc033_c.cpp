//AtCoder ABC033 C - 数式の書き換え
#include <bits/stdc++.h>
using namespace std;
using lli=int64_t;

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
    string S;
    cin>>S;
    auto tbl=split(S,'+');
    int cnt=0;
    for (const auto&t:tbl) {
        for (int i=0;i<t.size();++i){
            if (t[i]=='0'){++cnt;break;}
        }
    }
    cout<<(tbl.size()-cnt)<<endl;
    return 0;
}