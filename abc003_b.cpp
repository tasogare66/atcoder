//ABC002 B - AtCoderトランプ
#include <bits/stdc++.h>
using namespace std;
int main() {
    string s,t;
    cin>>s>>t;
    bool lose=false;
    for(int i=0;i<s.size();++i){
        if (s[i] == t[i]) {
            continue;
        }
        if (s[i] == '@'
         && (t[i] == 'a' || t[i] == 't' || t[i] =='c' || t[i] == 'o' || t[i] == 'd' || t[i] == 'e' || t[i] =='r')){
            continue;
         }
        if (t[i] == '@'
         && (s[i] == 'a' || s[i] == 't' || s[i] =='c' || s[i] == 'o' || s[i] == 'd' || s[i] == 'e' || s[i] =='r')){
            continue;
         }
        lose=true;
        break;
    }
    if (lose) cout<<"You will lose"<<endl;
    else cout<<"You can win"<<endl;
    return 0;
}