#include <cstring>
#include <iostream>
using namespace std;



char line[]="";
int main(void)
{
    int n;
    cin>>n;
    cin.ignore();

    while(n--)
    {
//        scanf("%s", line);

        //cin>>line;
        getline(cin, line);
        printf("%d %d\n",sizeof(line),strlen(line));

    }
    return 0;
}
