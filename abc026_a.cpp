//ABC026 A - 掛け算の最大値
#include <bits/stdc++.h>
using namespace std;
using lli=int64_t;
int main() {
    int A;
    cin>>A;
    int a = A/2;
    cout<<a*(A-a)<<endl;
    return 0;
}