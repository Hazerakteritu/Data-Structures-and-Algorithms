//Lazy Propagation in Segment Tree
//Given an array arr[] of size N. There are two types of operations:
//Update(l, r, x) : Increment the a[i] (l <= i <= r) with value x.
//Query(l, r) : Find the sum value in the array in a range l to r (both are included).

#include <iostream>
using namespace std;
#define MAX 1000

int tree[MAX] = {0}; // To store segment tree
int lazy[MAX] = {0}; // To store pending updates

void updateRangeUtil(int si, int ss, int se, int us, int ue, int diff)
{
    if (lazy[si] != 0)
    {
        tree[si] += (se-ss+1)*lazy[si];

        if (ss != se)
        {
            // We can postpone updating children we don't need their new values now.
            // Since we are not yet updating children of si,
            // we need to set lazy flags for the children
            lazy[si*2 + 1] += lazy[si];
            lazy[si*2 + 2] += lazy[si];
        }
        lazy[si] = 0;
    }

    // out of range
    if (ss>se || ss>ue || se<us)
        return ;

    // Current segment is fully in range
    if (ss>=us && se<=ue)
    {
        // Add the difference to current node
        tree[si] += (se-ss+1)*diff;

        if (ss != se)
        {
            lazy[si*2 + 1] += diff;
            lazy[si*2 + 2] += diff;
        }
        return;
    }

    int mid = (ss+se)/2;
    updateRangeUtil(si*2+1, ss, mid, us, ue, diff);
    updateRangeUtil(si*2+2, mid+1, se, us, ue, diff);

    tree[si] = tree[si*2+1] + tree[si*2+2];
}

void updateRange(int n, int us, int ue, int diff)
{
    updateRangeUtil(0, 0, n-1, us, ue, diff);
}

int getSumUtil(int ss, int se, int qs, int qe, int si)
{
    // If lazy flag is set for current node of segment tree, then there are some pending updates. So we need to make sure that the pending updates are done before
    // processing the sub sum query
    if (lazy[si] != 0)
    {
        tree[si] += (se-ss+1)*lazy[si];

        if (ss != se)
        {
            lazy[si*2+1] += lazy[si];
            lazy[si*2+2] += lazy[si];
        }
        lazy[si] = 0;
    }

    // Out of range
    if (ss>se || ss>qe || se<qs)
        return 0;

    // If this segment lies in range
    if (ss>=qs && se<=qe)
        return tree[si];

    int mid = (ss + se)/2;
    return getSumUtil(ss, mid, qs, qe, 2*si+1) +
           getSumUtil(mid+1, se, qs, qe, 2*si+2);
}

int getSum(int n, int qs, int qe)
{
    // Check for erroneous input values
    if (qs < 0 || qe > n-1 || qs > qe)
    {
        cout <<"Invalid Input";
        return -1;
    }

    return getSumUtil(0, n-1, qs, qe, 0);
}

void constructSTUtil(int arr[], int ss, int se, int si)
{
    // out of range as ss can never be greater than se
    if (ss > se)
        return ;

    // If there is one element in array, store it in
    // current node of segment tree and return
    if (ss == se)
    {
        tree[si] = arr[ss];
        return;
    }

    int mid = (ss + se)/2;
    constructSTUtil(arr, ss, mid, si*2+1);
    constructSTUtil(arr, mid+1, se, si*2+2);

    tree[si] = tree[si*2 + 1] + tree[si*2 + 2];
}

void constructST(int arr[], int n)
{
    constructSTUtil(arr, 0, n-1, 0);
}


int main()
{
    int arr[] = {1, 3, 5, 7, 9, 11};
    int n = sizeof(arr)/sizeof(arr[0]);

    // Build segment tree from given array
    constructST(arr, n);

    // Print sum of values in array from index 1 to 3
    cout <<"Sum of values in given range = "<<
         getSum(n, 1, 3);

    // Add 10 to all nodes at indexes from 1 to 5.
    updateRange(n, 1, 5, 10);

    // Find sum after the value is updated
    cout <<"\nUpdated sum of values in given range = "<<
         getSum( n, 1, 3);

    return 0;
}

