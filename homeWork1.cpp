#include <iostream>
using namespace std;

// char findFirstNoReapitingElement(char arr[], int size)
// {
//     int counter = 0;
//     for (int i = 0; i < size; i++) {
//         counter = 0;
//         for (int j = 0; j < size; j++) {
//             if (arr[i] == arr[j] && i != j) {
//                 counter++;
//             }
//         }
//         if (counter == 0) {
//             return arr[i];
//         }
//     }
//     return '-';
// }

char findFirstNoReapitingElement(char arr[], int size)
{
    unsigned int indexArr[127] = {0};

    for (int i = 0; i < size; i++)
    {
        indexArr[(unsigned int)arr[i]]++;
    }
    for (int i = 0; i < size; i++)
    {
        if (indexArr[(unsigned int)arr[i]] == 1)
        {
            return arr[i];
        }
    }
    return '-';
}

int main()
{
    int size = 10;
    char arr[] = "helloworld";
    cout << findFirstNoReapitingElement(arr, size);
    return 0;
}