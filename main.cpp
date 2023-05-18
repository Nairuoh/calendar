#include<stdio.h>
#include<iostream>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 1e3 + 5, M = 2e8 + 5, inf = 0x3f3f3f3f, mod = 1e9 + 7;
const int hashmod[8] = { 802653189,805306857,1610612781,998288353 };
#define mst(a,b) memset(a,b,sizeof a)
#define db double
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define x first
#define y second
#define pb emplace_back
#define SZ(a) (int)a.size()
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
#define IOS ios::sync_with_stdio(false),cin.tie(nullptr) 

int number=0;
void Print(int* a, int n) {
	for (int i = 1; i < n; i++)
		printf("%d ", a[i]);
	printf("%d\n", a[n]);
}
template <typename T>		//x=max(x,y)  x=min(x,y)
void cmx(T& x, T y) {
	if (x < y) x = y;
}
template <typename T>
void cmn(T& x, T y) {
	if (x > y) x = y;
}
char a[10][6][6] = {
	{{'.','.','.','.','.'},
	{'.','.','.','.','.'},
	{'.','.','.','.','.'},
	{'.','.','.','.','.'},
	{'.','.','.','.','.'}},

	{{'1','1','1','.','.'},
	{'1','.','.','.','.'},
	{'1','.','.','.','.'},
	{'1','.','.','.','.'},
	{'.','.','.','.','.'}},

	{{'2','2','2','.','.'},
	{'2','2','.','.','.'},
	{'.','.','.','.','.'},
	{'.','.','.','.','.'},
	{'.','.','.','.','.'}},

	{{'3','3','.','.','.'},
	{'.','3','3','3','.'},
	{'.','.','.','.','.'},
	{'.','.','.','.','.'},
	{'.','.','.','.','.'}},

	{{'4','4','.','.','.'},
	{'.','4','4','4','.'},
	{'.','4','.','.','.'},
	{'.','.','.','.','.'},
	{'.','.','.','.','.'}},

	{{'5','5','5','5','.'},
	{'5','.','.','.','.'},
	{'.','.','.','.','.'},
	{'.','.','.','.','.'},
	{'.','.','.','.','.'}},

	{{'6','6','6','6','6'},
	{'.','6','.','.','.'},
	{'.','.','.','.','.'},
	{'.','.','.','.','.'},
	{'.','.','.','.','.'}},

	{{'7','7','7','7','.'},
	{'.','7','.','.','.'},
	{'.','7','.','.','.'},
	{'.','.','.','.','.'},
	{'.','.','.','.','.'}},

	{{'8','.','8','.','.'},
	{'8','8','8','.','.'},
	{'8','.','.','.','.'},
	{'.','.','.','.','.'},
	{'.','.','.','.','.'}},

	{{'9','9','9','9','9'},
	{'9','.','.','.','.'},
	{'.','.','.','.','.'},
	{'.','.','.','.','.'},
	{'.','.','.','.','.'}} };

char b[10][9][6][6];
void filp(char a[6][6]) {
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 2; j++) {
			swap(a[i][j], a[i][4 - j]);
		}
}
void pr(char a[6][6]) {
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++) {
			putchar(a[i][j]);
		}
		putchar('\n');
	}
}
void rot(char a[6][6]) {
	char b[6][6];
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++)
			b[i][j] = a[4 - j][i];
	}
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++) a[i][j] = b[i][j];
}
char mp[10][7] = {
	"......",
	"......",
	"......",
	"......",
	"......",
	"......",
	"......",
	"......",
	"......",
};

void cp(char a[6][6], char b[6][6]) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++)
			a[i][j] = b[i][j];
		a[i][5] = '\0';
	}
}
int vis[10];
bool candown(int x, int y, int i, int j) {
	int sx = -1, sy = -1;
	for (int xx = 0; xx < 5; xx++)
		for (int yy = 0; yy < 5; yy++) {
			if (b[i][j][xx][yy] != '.') {
				sx = xx;
				sy = yy;
				int kx = sx, ky = sy;
				while (kx < 5 && ky < 5) {
					int nx = x + kx - sx;
					int ny = y + ky - sy;
					//如果要覆盖
					if (b[i][j][kx][ky] != '.') {
						if (nx < 0 || ny < 0) return false;
						if (mp[nx][ny] != '.') return false;
						//	mp[nx][ny] = b[i][j][kx][ky];
					}
					if (ky == 4) {
						kx++, ky = 0;
					}
					else ky++;
				}
				return true;
			}
		}
	return false;
}
void down(int x, int y, int i, int j) {
	for (int xx = 0; xx < 5; xx++)
		for (int yy = 0; yy < 5; yy++) {
			if (b[i][j][xx][yy] != '.') {
				int kx = xx, ky = yy;
				while (kx < 5 && ky < 5) {
					int nx = x + kx - xx;
					int ny = y + ky - yy;
					if (b[i][j][kx][ky] != '.') {
						mp[nx][ny] = b[i][j][kx][ky];
					}
					if (ky == 4) {
						kx++, ky = 0;
					}
					else ky++;
				}
				return;
			}
		}
}
void undown(int x, int y, int i, int j) {
	for (int xx = 0; xx < 5; xx++)
		for (int yy = 0; yy < 5; yy++) {
			if (b[i][j][xx][yy] != '.') {
				int kx = xx, ky = yy;
				while (kx < 5 && ky < 5) {
					int nx = x + kx - xx;
					int ny = y + ky - yy;
					if (b[i][j][kx][ky] != '.') {
						mp[nx][ny] = '.';
					}
					if (ky == 4) {
						kx++, ky = 0;
					}
					else ky++;
				}
				return;
			}
		}
}
void dfs(int id) {
	int x = id / 6;
	int y = id % 6;
	if (x == 8 && y == 5) {
		printf("Success!\n");
		number++;
		printf("第%d种解法：\n", number);
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 6; j++) {
				if (mp[i][j] == '.') continue;
				putchar(mp[i][j]);
			}
			putchar('\n');
		}
		putchar('\n');
		//exit(0);
	}
	if (mp[x][y] != '.') dfs(id + 1);
	for (int i = 1; i <= 9; i++) {
		if (!vis[i]) {
			for (int j = 1; j <= 8; j++) {
				if (candown(x, y, i, j)) {
					down(x, y, i, j);
					vis[i] = 1;
					dfs(id + 1);
					undown(x, y, i, j);
					vis[i] = 0;
				}
			}
		}
	}
}
int main() {
	int m, d, w;
	scanf_s("%d%d%d", &m, &d, &w);
	//初始化
	mp[m > 6][(m - 1) % 6] = '0';
	mp[((d - 1) / 6) + 2][(d - 1) % 6] = '0';
	if (w <= 3) {
		mp[7][w+3] = '0';
	}
	else {
		mp[8][w-2] = '0';
	}
	

	//得到每个拼图的所有情况
	for (int i = 1; i <= 9; i++) {
		cp(b[i][1], a[i]); filp(a[i]);
		cp(b[i][2], a[i]); filp(a[i]); rot(a[i]);
		cp(b[i][3], a[i]); filp(a[i]);
		cp(b[i][4], a[i]); filp(a[i]); rot(a[i]);
		cp(b[i][5], a[i]); filp(a[i]);
		cp(b[i][6], a[i]); filp(a[i]); rot(a[i]);
		cp(b[i][7], a[i]); filp(a[i]);
		cp(b[i][8], a[i]);
	}
	dfs(0);
	return 0;
}
