//AtCoder ABC059 A - Three-letter acronym
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
    string s1,s2,s3;
    cin>>s1>>s2>>s3;
    string ans;
    ans.push_back(s1[0]);
    ans.push_back(s2[0]);
    ans.push_back(s3[0]);
    transform(ans.begin(), ans.end(), ans.begin(), ::toupper);
    cout<<ans<<endl;
    return 0;
}