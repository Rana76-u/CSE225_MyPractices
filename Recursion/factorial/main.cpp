#include <iostream>

using namespace std;

int fact(int n){
    while(n != 1){
        return n * fact(n - 1);
    }
}

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;
    cout << fact(n);
    return 0;
}
