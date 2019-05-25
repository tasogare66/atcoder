//AtCoder ABC035 A - テレビ
#include <bits/stdc++.h>
using namespace std;
using lli=int64_t;

int main() {
    int W,H;
    cin>>W>>H;
    cout<<((W/4*3==H)?"4:3":"16:9")<<endl;
    return 0;
}