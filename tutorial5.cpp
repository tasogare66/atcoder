//ABC087B - Coins
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main(){
    int a500,b100,c50;
    int xsum;
    cin>>a500;
    cin>>b100;
    cin>>c50;
    cin>>xsum;
    int ans = 0;
    for (int a = 0; a <= a500; ++a)
    {
        for (int b = 0; b <= b100; ++b)
        {
            for (int c = 0; c <= c50; ++c)
            {
                auto val = a * 500 + b * 100 + c * 50;
                if (val == xsum) ++ans;
            }
        }
    }
    cout << ans << endl;
    return 0;
}