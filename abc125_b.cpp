//ABC125 B - Resale
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    vector<int> vt(n,0);
    vector<int> ct(n,0);
    for (auto& v:vt){
        cin>>v;
    }
    for (auto& c:ct){
        cin>>c;
    }
    int ans=0;
    for (int i= 0;i<n;++i){
        if(vt[i]-ct[i] > 0){
            ans += (vt[i]-ct[i]);
        }
    }
    cout<<ans<<endl;
    return 0;
}