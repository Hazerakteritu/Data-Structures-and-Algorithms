#include<bits/stdc++.h>
using namespace std;

int n,m;
bool vis[100][100];

bool isvalid(int x,int y)
{
    if(x<0 || x>=n || y<0 || y>=m)
        return false;
    if(vis[x][y]== true)
        return false;

    return true;
}

void dfs(int x,int y)
{
    vis[x][y]=1;
    cout<<x<<" "<<y<<endl;

    if(isvalid(x-1,y)) //up
        dfs(x-1,y);

    if(isvalid(x+1,y))  //down
        dfs(x+1,y);

    if(isvalid(x,y+1)) //right
        dfs(x,y+1);

    if(isvalid(x,y-1)) //left
        dfs(x,y-1);

}

int main()
{
    cin>>n>>m;
    dfs(0,0);

    return 0;
}
