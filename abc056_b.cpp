//AtCoder ABC056 B - NarrowRectanglesEasy
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
    int W,a,b;
    cin>>W>>a>>b;
    int tmp0 = max(b-(a+W),0);
    int tmp1 = max(a-(b+W),0);
    cout<<max(tmp0,tmp1)<<endl;
    return 0;
}