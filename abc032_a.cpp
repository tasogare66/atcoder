//AtCoder ABC032 A - 高橋君と青木君の好きな数
#include <bits/stdc++.h>
using namespace std;
using li=int64_t;

int main() {
#if LOCAL&0
  	std::ifstream in("input.txt");
  	std::cin.rdbuf(in.rdbuf());
#endif
    int a,b,n;
    cin>>a>>b>>n;
    while(true){
        if(n%a==0&&n%b==0){
            cout<<n<<endl;
            break;
        }
        ++n;
    }
    return 0;
}