//AtCoder ABC077 A - Rotation
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
    string c1,c2;
    cin>>c1>>c2;
    string n1=c2;
    reverse(n1.begin(),n1.end());
    string n2=c1;    
    reverse(n2.begin(),n2.end());
    cout<<(c1==n1&&c2==n2?"YES":"NO")<<endl;
    return 0;
}