#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int maxProfit(vector<int> &prices)
{
    int minPrice = INT_MAX;
    int maxProfit = 0;

    for (int price : prices)
    {
        if (price < minPrice)
        {
            minPrice = price;
        }
        else
        {
            maxProfit = max(maxProfit, price - minPrice);
        }
    }

    return maxProfit;
}

int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << maxProfit(prices);
    return 0;
}
