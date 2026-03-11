#include <stdio.h>

int visited[101][101];
char grid[101][101];
int sum;

int to_num(char c){
	return (int)(c - 48);	
}

int isvalid(int x, int y, int n, int m){            // Cek masih dalam grid dan cell selanjutnya belum dikunjungi
	return (x >= 0 && y >= 0 && x < n && y < m && !visited[x][y]);	
}

void dfs(int x, int y, int n, int m){
	visited[x][y] = 1;                      // Tandai udah dikunjungi 
	int num = to_num(grid[x][y]);           // Ubah char ke integer
	sum += (num);
	if(grid[x + 1][y] != '.' && isvalid(x + 1, y, n, m)){   // Kanan
		dfs(x + 1, y, n, m);
	}
	if(grid[x - 1][y] != '.' && isvalid(x - 1, y, n, m)){   // Kiri
		dfs(x - 1, y, n, m);
	}
	if(grid[x][y + 1] != '.' && isvalid(x, y + 1, n, m)){   // Bawah
		dfs(x, y + 1, n, m);
	}
	if(grid[x][y - 1] != '.' && isvalid(x, y - 1, n, m)){   // Atas
		dfs(x, y - 1, n, m);
	}
}

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++){
		char temp[101];
		scanf("%s", temp);
		for(int j = 0; j < m; j++){
			visited[i][j] = 0;
			grid[i][j] = temp[j];
		}
	}	
	int mx = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(grid[i][j] != '.' && !visited[i][j]){
				sum = 0;
				dfs(i, j, n, m);
				if(mx < sum){
					mx = sum;
				}
			}
		}
	}
	printf("%d", mx);
}
