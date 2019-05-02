//ABC019 B - 高橋くんと文字列圧縮
#include <bits/stdc++.h>
using namespace std;
int main() {
    string s="aabbbaad";
    cin>>s;
    string out;
    char tmp=s[0];
    int cnt=0;
    for(int i=0;i<s.size();++i){
        if (i+1>=s.size()||tmp != s[i+1]) {
            out += tmp;
            out += std::to_string(cnt+1);
            cnt = 0;
            tmp = s[i+1];
        } else {
            tmp=s[i];
            ++cnt;
        }
    }
    cout<<out<<endl;
    return 0;
}