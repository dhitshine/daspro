#include <stdio.h>

int memo[31][31];

int comb(int n, int k){
  if(n == k || k == 0){
    return 1;
  }
  if(n < k){
    return 0;
  }
	if(memo[n][k] != 0){
		return memo[n][k];
	}
	memo[n][k] = comb(n - 1, k - 1) + comb(n - 1, k);
	return comb(n - 1, k - 1) + comb(n - 1, k);
}

int main(){
	int n, k;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < k; j++){
			memo[i][j] = 0;
		}
	}
	scanf("%d %d", &n, &k);
	if(n < k){
		printf("No fair way to share the candies tonight... A truly spooky Halloween!");
		return 0;
	}
	int ans = comb(n - 1, k - 1);
	if(ans & 1){
		printf("There are %d ways to share the candies, A magical Halloween night!", ans);
	}else{
		printf("There are %d ways to share the candies, A spooky Halloween night!", ans);
	}
}
