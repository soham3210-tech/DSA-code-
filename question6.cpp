#include <iostream>
using namespace std;

int main()
{
    int arr[] = {1, 2, 2, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    bool sorted = true;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            sorted = false;
            break;
        }
    }

    if (sorted)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
