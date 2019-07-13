//AtCoder ABC111 A - AtCoder Beginner Contest 999
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
int main() {
    string n; cin>>n;
    for(auto&& c:n){
        if(c=='9') c='1';
        else if(c=='1') c='9';
    }
    cout<<n<<endl;
    return 0;
}