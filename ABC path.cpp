#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pi pair<int,int>
#define pll pair<ll,ll>
#define mxn 100006

char str[27][27];
int n,m;
  queue<pi>que;

int dx[8] = {0, 0, 1, -1, -1, -1, 1, 1};
int dy[8] = {1, -1, 0, 0, -1, 1, -1,1};

bool isvalid(int x, int y)
{
    if(x<0 || x>= n || y<0 || y>= m) return false;

    return true;
}


int bfs(int sx,int sy)
{

    vector<char>ans;
    char ele = str[sx][sy];
    ans.push_back(ele);

    int vis[27][27] = {0};
    queue<pi>q;
    q.push({sx,sy});
    vis[sx][sy] == 1;

    while(!q.empty()){
        int ux = q.front().first;
        int uy = q.front().second;
        char cur = str[ux][uy];

        for(int i=0; i< 8; i++){
            int newx = ux + dx[i];
            int newy = ux + dy[i];
            char vc = str[newx][newy];

            if(isvalid(newx,newy) && vc == cur + 1){
                q.push({newx,newy});
                ans.push_back(vc);
                vis[sx][sy] = 1;
            }
        }
    }
    return ans.size();
}

int main()
{
    int t = 1;
    while(1){
    int n,m;
    cin>>n>>m;

    if(n ==0 && m==0) break;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>str[i][j];

            if(str[i][j]== 'A')
            {
                que.push({i,j});
            }
        }
    }
    int ans =0;

    while(!que.empty()){
        int i = que.front().first;
        int j = que.front().second;
        int len = bfs(i,j);
        ans = max(ans,len);
    }
    cout<<"Case "<<t<<": "<<ans<<endl;

    t++;
    }

    return 0;
}
