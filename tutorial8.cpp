//ABC085B - Kagami Mochi
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main(){
    int x;
    set<int> dtbl;
    cin >>x;
    int din;
    for(int i=0;i<x;++i){
        cin >> din;
        dtbl.emplace(din);
    }
    cout<<dtbl.size()<<endl;
    return 0;
}