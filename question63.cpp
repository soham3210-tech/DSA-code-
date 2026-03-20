#include <iostream>
using namespace std;

int main()
{
    int arr[] = {5, 9, 2, 11, 3};
    int n = 5;

    int maxVal = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > maxVal)
        {
            maxVal = arr[i];
        }
    }

    cout << "Largest element: " << maxVal;

    return 0;
}