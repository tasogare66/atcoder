//
#include <bits/stdc++.h>
using namespace std;
int main() {
    int a,b;
    cin>>a>>b;
    int sum = 0;
    //1
    if (a > b)
    {
        sum += a;
        --a;
    }
    else
    {
        sum += b;
        --b;
    }
    //2
    if (a > b)
    {
        sum += a;
        --a;
    }
    else
    {
        sum += b;
        --b;
    }
    cout<<sum<<endl;
    return 0;
}