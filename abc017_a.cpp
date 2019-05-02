//ABC017 A - プロコン
#include <bits/stdc++.h>
using namespace std;
int main() {
    int s,e;
    int ans=0;
    for (int i=0;i<3;++i){
        cin>>s>>e;
        ans+=s*e/10;
    }
    cout<<ans<<endl;
    return 0;
}