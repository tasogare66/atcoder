//AtCoder ABC036 A - お茶
#include <bits/stdc++.h>
using namespace std;
using lli=int64_t;

int main() {
    int A,B;
    cin>>A>>B;
    auto ans = B/A;
    if (ans*A<B)++ans;
    cout<<ans<<endl;
    return 0;
}