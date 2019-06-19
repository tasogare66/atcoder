//AtCoder ABC057 A - Remaining Time
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
    int A,B;
    cin>>A>>B;
    int ans=(A+B)%24;
    cout<<ans<<endl;
    return 0;
}