//AtCoder ABC063 A - Restricted
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
    ll A,B;
    cin>>A>>B;
    cout<<(A+B>=10?"error":to_string(A+B))<<endl;
    return 0;
}