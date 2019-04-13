//ABC085C - Otoshidama
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main(){
    int n, y;
    cin>>n;
    cin>>y;
    y/=1000;
    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= n-i; ++j)
        {
            int k=n-i-j;
            {
                if (i * 10 + j * 5 + k * 1 == y)
                {
                    cout << i << " " << j << " " << k <<endl;
                    return 0;
                }
            }
        }
    }
    cout << "-1 -1 -1" << endl;
    return 0;
}