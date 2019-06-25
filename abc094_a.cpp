//AtCoder ABC094 A - Cats and Dogs
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
    ll A,B,X;
    cin>>A>>B>>X;
    bool ans=(A<=X&&A+B>=X);
    cout<<(ans?"YES":"NO")<<endl;
    return 0;
}