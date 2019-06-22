//AtCoder ABC093 A - abc of ABC
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
    string S;
    cin>>S;    
    sort(S.begin(),S.end());
    cout<<(S=="abc"?"Yes":"No")<<endl;
    return 0;
}