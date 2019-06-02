//AtCoder ABC127 
#include <bits/stdc++.h>
using namespace std;
using lli=int64_t;

int main() {
    int A,B;
    cin>>A>>B;
    int ans;
    if(A>=13){
		ans = B;
	} else if (A>=6&&A<=12){
        ans = B/2;
    } else {
        ans=0;
    }
    cout<<ans<<endl;
    return 0;
}