#include <stdio.h>

long long gcd(long long a, long long b){
	if(b == 0){
		return a;
	}
	return gcd(b, a % b);
}

long long lcm(long long a, long long b){
	return a / (gcd(a,b)) * b;
}

int main(){
	long long a, b;
	scanf("%lld %lld", &a, &b);
	long long ans = lcm(a,b);
	printf("%lld", ans);
}
