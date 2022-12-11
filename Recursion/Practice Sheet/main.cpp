#include <iostream>

using namespace std;

int findMin(int a[], int size){
    if(size == 1){
        return a[0];
    }else{
        if(a[size] < findMin(a, size-1)){
            return a[size];
        }else{
            return findMin(a, size-1);
        }
    }
}

int main()
{
    int size;
    cout << "Enter Array size: ";
    cin >> size;
    int a[size];
    cout << "Enter Array Elements: ";
    for(int i=0;i<size;i++){
        cin >> a[i];
    }
    cout << "Minimum is : " << findMin(a, size - 1 );
    return 0;
}
