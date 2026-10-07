#include <bits/stdc++.h>
using namespace std;

int a[100];
int tree[400];

// Build Segment Tree
void build(int node, int start, int end)
{
    // যদি শুধু একটি element থাকে
    if(start == end)
    {
        tree[node] = a[start];
        return;
    }

    int mid = (start + end) / 2;

    // Left child
    build(node * 2, start, mid);

    // Right child
    build(node * 2 + 1, mid + 1, end);

    // Parent = Left + Right
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}


// Update
void update(int node, int start, int end, int index, int value)
{
    // Target index-এ পৌঁছে গেছি
    if(start == end)
    {
        a[index] = value;
        tree[node] = value;
        return;
    }

    int mid = (start + end) / 2;

    // Left side-এ থাকলে
    if(index <= mid)
    {
        update(node * 2, start, mid, index, value);
    }
    // Right side-এ থাকলে
    else
    {
        update(node * 2 + 1, mid + 1, end, index, value);
    }

    // Child update হওয়ার পর parent update
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}


// Range Query
int query(int node, int start, int end, int l, int r)
{
    // Range-এর বাইরে
    if(r < start || end < l)
    {
        return 0;
    }

    // পুরো range-এর ভিতরে
    if(l <= start && end <= r)
    {
        return tree[node];
    }

    int mid = (start + end) / 2;

    int left = query(node * 2, start, mid, l, r);

    int right = query(node * 2 + 1, mid + 1, end, l, r);

    return left + right;
}


int main()
{
    int n;

    cin >> n;

    // Array input
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // Build
    build(1, 0, n - 1);

    // Query
    int l, r;

    cin >> l >> r;

    cout << "Sum = " << query(1, 0, n - 1, l, r) << endl;

    // Update
    int index, value;

    cin >> index >> value;

    update(1, 0, n - 1, index, value);

    // Query again after update
    cout << "After Update = "
         << query(1, 0, n - 1, l, r) << endl;

    return 0;
}