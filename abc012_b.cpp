//ABC012 B - 入浴時間
#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin>>N;
    int s = N%60;
    int m = N/60;
    int h = m/60; 
    cout<<setw(2)<<setfill('0')<<h<<":"<<setw(2)<<setfill('0')<<m%60<<":"<<setw(2)<<setfill('0')<<s<<endl;
    return 0;
}