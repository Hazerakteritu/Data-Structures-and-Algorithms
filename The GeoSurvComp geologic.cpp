#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mx 102

char grid[mx][mx];
int n,m;

int dx[8] = {0, 0, -1, -1, -1, 1, 1, 1};
int dy[8] = {1, -1, -1, 0, 1, -1, 0, 1};

void dfs(int i, int j){
    if(i<0 || i>=n || j<0 || j>=m || grid[i][j]!='@') return;

    grid[i][j] = '*';
    for(int k = 0; k<8; k++){
        int ni = i + dx[k];
        int nj = j + dy[k];
        dfs(ni, nj);
    }
}

int32_t main()
{
    while(cin>>n>>m && n!=0){
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>grid[i][j];
            }
        }
        int cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]=='@'){
                        cnt++;
                    dfs(i, j);
                }
            }
        }
        cout<<cnt<<endl;
    }

}
