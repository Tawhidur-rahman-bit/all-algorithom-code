#include <bits/stdc++.h>
using namespace std;

int maxSubarray(int a[], int low, int high, int &start, int &end)
{
    // Base case
    if(low == high)
    {
        start = low;
        end = high;

        return a[low];
    }

    // Middle
    int mid = (low + high) / 2;

    // Left maximum
    int leftStart, leftEnd;
    int left = maxSubarray(a, low, mid, leftStart, leftEnd);

    // Right maximum
    int rightStart, rightEnd;
    int right = maxSubarray(a, mid + 1, high, rightStart, rightEnd);

    // Maximum suffix of left part
    int sum = 0;
    int leftSum = INT_MIN;
    int crossStart = mid;

    for(int i = mid; i >= low; i--)
    {
        sum += a[i];

        if(sum > leftSum)
        {
            leftSum = sum;
            crossStart = i;
        }
    }

    // Maximum prefix of right part
    sum = 0;
    int rightSum = INT_MIN;
    int crossEnd = mid + 1;

    for(int i = mid + 1; i <= high; i++)
    {
        sum += a[i];

        if(sum > rightSum)
        {
            rightSum = sum;
            crossEnd = i;
        }
    }

    // Crossing sum
    int cross = leftSum + rightSum;

    // Best of three
    if(left >= right && left >= cross)
    {
        start = leftStart;
        end = leftEnd;

        return left;
    }
    else if(right >= left && right >= cross)
    {
        start = rightStart;
        end = rightEnd;

        return right;
    }
    else
    {
        start = crossStart;
        end = crossEnd;

        return cross;
    }
}

int main()
{
    int a[] = {-2, 5, -1, 3, -4, 6, 2, -5};

    int n = 8;

    int start, end;

    int maximumSum = maxSubarray(a, 0, n - 1, start, end);

    cout << "Maximum Sum = " << maximumSum << endl;

    cout << "Maximum Sum Subarray = ";

    for(int i = start; i <= end; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}