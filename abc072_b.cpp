//AtCoder B - OddString
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
    string s;
    string ans;
    cin>>s;
    for(ll i=0;i<s.size();++i){
        if (i%2==0) ans.push_back(s[i]);
    }
    cout<<ans<<endl;
    return 0;
}