#include <stdio.h>

int main()
{
    int n, i, min, max;
    long long sum = 0;
    scanf("%d", &n);
    int a[n];
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    min = a[0];
    max = a[0];

    for (i=0; i<n; i++)
    {
        if (a[i]<min)
        {
            min=a[i];
        }
        if (a[i]>max)
        {
            max=a[i];
        }
        sum+=a[i];
    }
    printf("%d %d %lld\n", min, max, sum);
    return 0;
}
