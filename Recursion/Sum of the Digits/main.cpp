#include <iostream>

using namespace std;

int sumOfDigits(int n){
    while(n != 0){
        return ( (n%10) + sumOfDigits(n / 10) );
    }
}

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;
    cout << sumOfDigits(n);
    return 0;
}
