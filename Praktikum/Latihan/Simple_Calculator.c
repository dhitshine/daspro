#include <stdio.h>

int main(){
	int x, y;
	char op;
	scanf("%d %c %d", &x, &op, &y);
	if(op == '^'){
		printf("%d", (x ^ y) % 2);
	}else if(op == '&'){
		printf("%d", (x & y) % 2);
	}else if(op == '|'){
		printf("%d", (x | y) % 2);
	}
}
