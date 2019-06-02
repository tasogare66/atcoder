//AtCoder ABC037 A - 饅頭
#include <bits/stdc++.h>
using namespace std;
using lli=int64_t;

int main() {
    int A,B,C;
    cin>>A>>B>>C;
    int v=min(A,B);
    cout<<C/v<<endl;
    return 0;
}