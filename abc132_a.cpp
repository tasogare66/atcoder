//AtCoder ABC132 A - Fifty-Fifty
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
int main() {
    string S;
    cin>>S;
    sort(S.begin(),S.end());
    bool ans=false;
    if(S[0]==S[1]&&S[2]==S[3]&&S[1]!=S[2]) ans=true;
    cout<<(ans?"Yes":"No")<<endl;    
    return 0;
}