//AtCoder ABC056 A - HonestOrDishonest
#include <bits/stdc++.h>
using namespace std;
using ll=int64_t;

int main() {
    char a,b;
    cin>>a>>b;
    if (a=='H') cout<<(char)b<<endl;
    else cout<<(b=='H'?"D":"H")<<endl;
    return 0;
}