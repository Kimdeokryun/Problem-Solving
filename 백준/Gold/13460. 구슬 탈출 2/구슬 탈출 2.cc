#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class info {
public:
    int rx, ry, bx, by, count;
};

info start;
bool visited[11][11][11][11];
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1 ,1 };
int min_result;

void solve(vector<string> board) {
    
    queue<info> q;
    q.push(start);
    visited[start.rx][start.ry][start.bx][start.by] = true;

    while (!q.empty()) {
        info cursor = q.front(); q.pop();
        if (cursor.count > 10) { continue; }
        if (board[cursor.rx][cursor.ry] == 'O' && board[cursor.bx][cursor.by] != 'O')   // 빨간공만 들어간 경우.
        { 
            if (min_result > cursor.count) { min_result = cursor.count; continue; }
        }
        else if (board[cursor.bx][cursor.by] == 'O') { continue; }  // 파란색 공이 들어간 경우 (빨간색 공도 들어간 경우도 포함된다.)

        for (int dir = 0; dir < 4; dir++) 
        {
            int nrx = cursor.rx, nry = cursor.ry, nbx = cursor.bx, nby = cursor.by;

            while (true) 
            {
                nrx += dx[dir]; 
                nry += dy[dir];
                if (board[nrx][nry] == '#') { nrx -= dx[dir]; nry -= dy[dir]; break; } // 벽에 닿았다면 한칸 물러나고 break;
                else if (board[nrx][nry] == 'O') break; // 구멍에 들어가면 break;
            }
            while (true) {
                nbx += dx[dir]; nby += dy[dir];
                if (board[nbx][nby] == '#') { nbx -= dx[dir]; nby -= dy[dir]; break; } // 벽에 닿았다면 한칸 물러나고 break;
                else if (board[nbx][nby] == 'O') break; // 구멍에 들어가면 break;
            }

            if (nrx == nbx && nry == nby) {
                if (board[nrx][nry] != 'O') {
                    int rdist = abs(nrx - cursor.rx) + abs(nry - cursor.ry);
                    int bdist = abs(nbx - cursor.bx) + abs(nby - cursor.by);
                    if (rdist > bdist) {
                        nrx -= dx[dir];
                        nry -= dy[dir];
                    }
                    else {
                        nbx -= dx[dir];
                        nby -= dy[dir];
                    }
                }
            }

            // Check visit
            if (visited[nrx][nry][nbx][nby]) continue;
            visited[nrx][nry][nbx][nby] = true;
            info next; 
            next.rx = nrx; 
            next.ry = nry; 
            next.bx = nbx; 
            next.by = nby; 
            next.count = cursor.count + 1;
            q.push(next);
        }
    }

}

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> board(n);

    for (int i = 0; i < n; ++i) {
        cin >> board[i];
        for (int j = 0; j < m; ++j) {
            if (board[i][j] == 'R') { start.rx = i, start.ry = j, board[i][j] = '.'; }
            else if (board[i][j] == 'B') { start.bx = i, start.by = j, board[i][j] = '.'; }
        }
    }

    min_result = 11;
    solve(board);
    if (min_result == 11) { min_result = -1; }
    cout << min_result;

    return 0;
}
