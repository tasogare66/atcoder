//AtCoder ABC067 A - Sharing Cookies
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
    ll A,B;
    cin>>A>>B;
    cout<<((A%3==0 || B%3==0 || (A+B)%3==0)?"Possible":"Impossible")<<endl;
    return 0;
}