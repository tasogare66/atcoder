//AtCoder 
#include <bits/stdc++.h>
using namespace std;
using lli=int64_t;
template<size_t SIZE, class T> inline size_t array_size(T (&arr)[SIZE]) {
    return SIZE;
}

bool month(int v) { return (v >= 1 && v <= 12); }

int main() {
#if LOCAL&0
  	std::ifstream in("input.txt");
  	std::cin.rdbuf(in.rdbuf());
#endif
    string S;
    cin>>S;
    int val = std::stoi(S);
    int h = val / 100;
    int f = val % 100;

    if (month(f) && month(h)) {
        cout<<"AMBIGUOUS"<<endl;
    } else if(month(h)) {
        cout<<"MMYY"<<endl;
    } else if(month(f)) {
        cout<<"YYMM"<<endl;
    } else {
        cout<<"NA"<<endl;
    }
    return 0;
}