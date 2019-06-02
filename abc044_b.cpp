//AtCoder ABC044 B - 美しい文字列 / Beautiful Strings
#include <bits/stdc++.h>
using namespace std;
using lli=int64_t;

int main() {
    string w;
    cin>>w;
    unordered_map<char,int> cm;
    for(auto c:w){
        cm[c]++;
    }
    bool ans=true;
    for(auto&& d:cm){
        if(d.second%2) {
            ans=false;
            break;
        }
    }
    cout<<(ans?"Yes":"No")<<endl;
    return 0;
}