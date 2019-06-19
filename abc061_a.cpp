//AtCoder ABC061 A - Between Two Integers
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
    int A,B,C;
    cin>>A>>B>>C;
    cout<<(C>=A&&C<=B?"Yes":"No")<<endl;
    return 0;
}