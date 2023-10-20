#include<vector>
#include<queue>

using namespace std;

int dx[] = {1,0,-1,0};      // 하 우 상 좌 순으로.
int dy[] = {0,1,0,-1};
bool visited[101][101];
int leastmap[101][101];
int solution(vector<vector<int> > maps)
{
    int n = maps.size();
    int m = maps[0].size();
    
    int answer = n*m;
    queue<pair<int,int>> q;
    q.push(make_pair(0,0));
    visited[0][0] = true;
    leastmap[0][0] = 1;
    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop(); 
        
        for(int i = 0; i< 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || ny < 0 || nx >= n || ny >= m)  // map을 넘어선다면
            {
                continue;
            }
            if(visited[nx][ny] != 1 && maps[nx][ny] != 0)   // 지나왔던 길이나  벽이 아니라면   
            {
                q.push(make_pair(nx,ny));
                visited[nx][ny] = true;
                leastmap[nx][ny] = leastmap[x][y] + 1;
            }
        }
    }
    if(visited[n-1][m-1] == 0){ answer = -1; }
    else{ answer = leastmap[n-1][m-1]; }
    return answer;
}