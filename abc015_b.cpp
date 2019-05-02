//ABC015 B - 高橋くんの集計
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    int a;
    int bug=0;
    int num=0;
    for (int i=0;i<n;++i) {
        cin>>a;
        if (a!=0){
            ++num;
            bug+=a;
        }
    }
    int ans = bug/num;
    if(bug%num!=0) ++ans;
    cout<<ans<<endl;
    return 0;
}