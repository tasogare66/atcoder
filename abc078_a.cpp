//AtCoder ABC078 A - HEX
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
    string a,b;
    cin>>a>>b;    
    if (a[0]==b[0]) cout<<"="<<endl;
    else if(a[0]>b[0]) cout<<">"<<endl;
    else cout<<"<"<<endl;
    return 0;
}