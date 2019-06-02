//AtCoder ABC127 B - Algae  
#include <bits/stdc++.h>
using namespace std;
using lli=int64_t;

int main() {
    int r,D,x2k;
    cin>>r>>D>>x2k;
    lli x=x2k;
    for(int i=0;i<10;++i){
        x=r*x-D;
        cout<<x<<endl;
    }
    return 0;
}