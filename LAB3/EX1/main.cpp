#include <iostream>
#include "Math.h"

using namespace std;
int main() {
    Math m;
    cout<<m.Add(12,3)<<endl;
    cout<<m.Add(1,2,3)<<endl;
    cout<<m.Mul(2,8)<<endl;
    cout<<m.Add(1.4,1.2)<<endl;
    cout<<m.Add(4, 1, 1, 1, 1)<<endl;
    cout<<m.Add("123", "45");
    return 0;
}
