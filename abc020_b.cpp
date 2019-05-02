//ABC020 B - 足し算
#include <bits/stdc++.h>
using namespace std;
int main() {
    string a,b;
    cin>>a>>b;
    a=a+b;
    int ans = stoi(a);
	cout << ans*2 << endl;
	return 0;
}