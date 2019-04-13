#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main(){
    string s;
    cin>>s;
    int tbl[3];
    for (int i = 0; i < 3;++i) {
        tbl[i] = s[i] - '0';
    }
    cout<<(tbl[0]+tbl[1]+tbl[2])<<endl;
    return 0;
}