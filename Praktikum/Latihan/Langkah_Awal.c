#include <stdio.h>
#include <math.h>

int main(){
	int x, f, n;
	scanf("%d %d %d", &x, &f, &n);
	int dist = abs(x - f);
	int count = ceil((double)dist / n);
	printf("%d", count);
}
