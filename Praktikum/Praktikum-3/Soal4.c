#include <stdio.h>

double fun(long long b, long long n){
	if(n == 0){
		return b;
	}
	return b + (b * 1.0) / (fun(b, n - 1));
}

int main(){
	long long b, n;
	scanf("%lld %lld", &b, &n);
  /*
  for(long long i = 0; i <= b; i++){
    for(long long j = 0; j <= n; j++){
      printf("i = %lld, j = %lld dan ans = %.8lf\n", i, j, fun(i, j));
    }
  }
  */
	double ans;
  if(n >= 20){
    ans = fun(b, 20);
  }else{
    ans = fun(b, n);
  }
  printf("%.8f", ans);
}
