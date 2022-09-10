#include <iostream>
using namespace std;

char findFirstNoReapitingElement(char arr[], int size)
{
    int counter = 0;
    for (int i = 0; i < size; i++) {
        counter = 0;
        for (int j = 0; j < size; j++) {
            if (arr[i] == arr[j] && i != j) {
                counter++;
            }
        }
        if (counter == 0) {
            return arr[i];
        }
    }
    return '-';
}

int main()
{
    int size = 9;
    char arr[] = "vayimarev";
    cout << findFirstNoReapitingElement(arr, size);
    return 0;
}