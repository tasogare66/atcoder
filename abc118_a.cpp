//AtCoder A - B +/- A
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;
int main() {
    ll A,B; cin>>A>>B;
    cout<<(B%A==0?A+B:B-A)<<endl;
    return 0;
}