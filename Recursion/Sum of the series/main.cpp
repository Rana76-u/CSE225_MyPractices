#include <iostream>
#include <math.h>

using namespace std;

double sumOfTheSeries(int n){
    if(n == 0){
        return 1;
    }
    else{
        return ( (1/pow(2, n)) + sumOfTheSeries(n-1));
    }
}

int main()
{
    int n;
    cout << "Input n: ";
    cin >> n;
    cout << sumOfTheSeries(n-1);
    return 0;
}
