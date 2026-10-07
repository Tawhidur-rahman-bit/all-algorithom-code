#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;

    cin >> n;

    int price[n];

    for(int i = 0; i < n; i++)
    {
        cin >> price[i];
    }

    int dp[n + 1][n + 1];

    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            // No piece or rod length 0
            if(i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }

            // Current piece length is bigger than rod length
            else if(i > j)
            {
                dp[i][j] = dp[i - 1][j];
            }

            else
            {
                dp[i][j] = max(
                    dp[i - 1][j],
                    price[i - 1] + dp[i][j - i]
                );
            }
        }
    }

    cout << dp[n][n];

    return 0;
}