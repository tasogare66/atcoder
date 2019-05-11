// AGC020 A - Move and Win
#include <bits/stdc++.h>
using namespace std;
int main() {
    int a,b,n;
    cin>>n>>a>>b;
    while(true){
        if (a+1!=b) {
			++a;
		}else{
			cout << "Borys" << endl;
			break;
		}
        if (a!=b-1) {
            --b;
        } else{
            cout<<"Alice"<<endl;
            break;
        }
    }
    return 0;
}