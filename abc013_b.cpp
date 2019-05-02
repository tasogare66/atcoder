//ABC013 B - 錠
#include <bits/stdc++.h>
using namespace std;
int main() {
    int a,b;
    cin>>a>>b;
    int ans = abs(b-a);
    int ans2 = 10-max(a,b)+min(a,b);
    cout<<(ans>ans2?ans2:ans)<<endl;
    return 0;
}