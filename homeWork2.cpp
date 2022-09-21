#include <iostream>

using namespace std;

int* bubbleSort(int arr[], int indexArr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++){
        for (j = 0; j < n - i - 1; j++){
            if (arr[j] > arr[j + 1]){
                swap(indexArr[j], indexArr[j + 1]);
                swap(arr[j], arr[j + 1]);
            }}}
    
    return indexArr;
}



int main()
{
    int size = 5;
    int arr[size] = {5, 4, 3, 2, 1};
    int indexes[size];
    for (int i = 0; i < size; i++) {
        indexes[i] = i;
    }
    
    int *array = bubbleSort(arr, indexes, size);
    for (int i = 0; i < size; i++) {
        cout << indexes[i] << endl;
    }

    return 0;
}
