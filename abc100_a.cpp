//AtCoder ABC100 A - Happy Birthday!
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
    ll A,B; cin>>A>>B;
    bool ans=(A<=8&&B<=8);
    cout<<(ans?"Yay!":":(")<<endl;
    return 0;
}