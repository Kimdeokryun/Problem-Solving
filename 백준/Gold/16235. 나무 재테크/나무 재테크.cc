#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>

using namespace std;

int n, m, k;

class tree
{
public:
	int x;
	int y;
	int age;
	void init(int x, int y, int age)
	{
		this->x = x;
		this->y = y;
		this->age = age;
	}
};

vector<vector<int>> ground(11, vector<int>(11));
vector<vector<int>> add_point(11, vector<int>(11));

vector<vector<vector<int>>> live_trees(11, vector<vector<int>>(11));

//map<int, int> live_trees;
queue<tree> dead_trees;

int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

int live_tree_result;

int main() 
{
	cin >> n >> m >> k;
	live_tree_result = 0;

	for (int i = 1; i <= n; i++) 
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> add_point[i][j];
			ground[i][j] = 5;
		}
	}

	int x, y, z;
	for (int i = 0; i < m; i++) 
	{
		cin >> x >> y >> z;
		live_trees[x][y].push_back(z);
	}

	while (k-- > 0)		// 년도.
	{
		// 봄		
		for (int tx = 1; tx <= n; tx++)
		{
			for (int ty = 1; ty <= n; ty++)
			{
				int tree_num = live_trees[tx][ty].size();
				if (tree_num > 0)
				{
					sort(live_trees[tx][ty].begin(), live_trees[tx][ty].end());		// 나이순 대로 정렬

					int check_tree_idx = -1;
					for (int tree_idx = 0; tree_idx < tree_num; tree_idx++)
					{
						ground[tx][ty] -= live_trees[tx][ty][tree_idx];	// 나이만큼 양분 흡수 후 나이 1 증가
						if (ground[tx][ty] < 0)			// 양분 부족하다면?		그 뒤부터는 모두 다 부족할 텐데....
						{
							ground[tx][ty] += live_trees[tx][ty][tree_idx];	// 다시 늘리기.
							check_tree_idx = tree_idx;
							break;
						}
						live_trees[tx][ty][tree_idx]++;
					}

					if (check_tree_idx != -1) 
					{
						int check_tree_len = tree_num - check_tree_idx;
						while (check_tree_len-- > 0) 
						{
							tree die_tree;																	// 먼저 죽은 나무 저장 후
							die_tree.init(tx, ty, live_trees[tx][ty][check_tree_idx]);
							dead_trees.push(die_tree);

							live_trees[tx][ty].erase(live_trees[tx][ty].begin() + check_tree_idx);		// live_trees에서 삭제.
						}
						

					}
				}
			}
		}

		// 여름		죽은 나무 양분으로 추가 후 삭제
		while (!dead_trees.empty()) 
		{
			tree temp_tree = dead_trees.front();
			dead_trees.pop();

			int d_tree_x = temp_tree.x;
			int d_tree_y = temp_tree.y;
			int d_tree_age = temp_tree.age;

			ground[d_tree_x][d_tree_y] += (d_tree_age / 2);  // 소수점 아래는 버린채로 양분으로 추가
		}

		// 가을		나무 번식
		for (int tx = 1; tx <= n; tx++)
		{
			for (int ty= 1; ty <= n; ty++)
			{
				int tree_num = live_trees[tx][ty].size();
				if (tree_num > 0)
				{
					//sort(live_trees[tx][ty].begin(), live_trees[tx][ty].end());		// 나이순 대로 정렬을 할 필요 없음.
					for (int tree_idx = 0; tree_idx < tree_num; tree_idx++) 
					{
						if (live_trees[tx][ty][tree_idx] % 5 == 0)	// 현재 나무가 5의 배수라면
						{
							for (int dir = 0; dir < 8; dir++)			// 인접한 8개의 땅 확인
							{
								int nx = tx + dx[dir];
								int ny = ty + dy[dir];

								if (nx <= 0 || ny <= 0 || nx > n || ny > n) { continue; }	// 좌표 초과시 생성 X
								live_trees[nx][ny].push_back(1);	// 나이가 1인 나무 생성
							}
						}
					}
				}
			}
		}

		// 겨울     양분 추가
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				ground[i][j] += add_point[i][j];
			}
		}
	}

	for (int tx = 1; tx <= n; tx++)
	{
		for (int ty = 1; ty <= n; ty++)
		{
			int tree_num = live_trees[tx][ty].size();
			live_tree_result += tree_num;
		}
	}

	cout << live_tree_result << "\n";

	return 0;
}