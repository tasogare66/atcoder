//AtCoder ABC053 B - A to Z String
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
    string s;
    cin>>s;
    int st,ed;
    for(st=0;st<s.size();++st){
        if(s[st]=='A') break;
    }
    for(ed=s.size()-1;ed>=0;--ed){
        if(s[ed]=='Z') break;
    }
    cout<<ed-st+1<<endl;    
    return 0;
}