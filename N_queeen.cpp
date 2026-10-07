#include <bits/stdc++.h>
using namespace std;

int n;
int board[20][20];

bool isSafe(int row, int col)
{
    // Same column
    for(int i = 0; i < row; i++)
    {
        if(board[i][col] == 1)
            return false;
    }

    // Upper-left diagonal
    for(int i = row - 1, j = col - 1;
        i >= 0 && j >= 0;
        i--, j--)
    {
        if(board[i][j] == 1)
            return false;
    }

    // Upper-right diagonal
    for(int i = row - 1, j = col + 1;
        i >= 0 && j < n;
        i--, j++)
    {
        if(board[i][j] == 1)
            return false;
    }

    return true;
}

bool solve(int row)
{
    // সব Queen বসানো হয়ে গেছে
    if(row == n)
        return true;

    // Current row-এর প্রতিটি column চেষ্টা করি
    for(int col = 0; col < n; col++)
    {
        if(isSafe(row, col))
        {
            // Queen বসাই
            board[row][col] = 1;

            // পরের row-তে যাই
            if(solve(row + 1))
                return true;

            // কাজ না হলে Queen সরিয়ে দিই
            board[row][col] = 0;
        }
    }

    return false;
}

int main()
{
    cin >> n;

    if(solve(0))
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cout << board[i][j] << " ";
            }

            cout << endl;
        }
    }
    else
    {
        cout << "No solution";
    }

    return 0;
}