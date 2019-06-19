//AtCoder ABC060 A - Shiritori
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
    string A,B,C;
    cin>>A>>B>>C;
    cout<<((A.back()==B[0] && B.back()==C[0])?"YES":"NO")<<endl;
    return 0;
}