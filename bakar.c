#include<stdio.h>


int main()
{
    //int arr[5] = {90, 80, 70,60, 50};

    float arr[5];
    for(int i=0; i<5; i++) scanf("%f",&arr[i]);

    float mx = arr[0];
    for(int i=1 ; i<5; i++)
    {
        if(arr[i]> mx) mx = arr[i];
    }
    printf("%f\n",mx);

    return 0;
}
