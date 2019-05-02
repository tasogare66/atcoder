//ABC019 A - 高橋くんと年齢
#include <bits/stdc++.h>
using namespace std;
int main() {
    int a,b,c;
    vector<int> tb(3);
    cin>>tb[0]>>tb[1]>>tb[2];
    sort(tb.begin(),tb.end());
    cout<<tb[1]<<endl;
    return 0;
}