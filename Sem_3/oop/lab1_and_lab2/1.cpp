#include <iostream>

using namespace std;

int main(){
    int a,b,c;
    int large;
    cin >> a >> b >> c;
    large = ((a>b && b>c) || (a>c && c>b)) ? a : ((b>c && c>a) || (b>a && a>c)) ? b : c;
    cout << large << endl;
    return 0;
}