//AtCoder ABC050 A - Addition and Subtraction Easy
#include <bits/stdc++.h>
using namespace std;
using lli=int64_t;

int main() {
    int A,B;
    string op;
    cin>>A>>op>>B;
    int ans= (op[0]=='+')?A+B:A-B;
    cout<<ans<<endl;
    return 0;
}