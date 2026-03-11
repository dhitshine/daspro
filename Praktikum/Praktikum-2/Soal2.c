#include <stdio.h>
int main(){
	long long m, h;
	scanf("%lld %lld", &m, &h);
	long long arr[m];
	for(long long i = 0; i < m; i++){
		scanf("%lld", &arr[i]);
	}
	long long ans[100];
	long long idx = 0, sum = 0, bisa = 0;
	for(long long i = 0; i < m; i++){
    long long num = arr[i];
    int is_prime = 1;
    if(num < 2){
      is_prime = 0;
    }else if(num == 2 || num == 3){
      is_prime = 1;
    }else if(num % 2 == 0 || num % 3 == 0){
      is_prime = 0;
    }else{
      for(long long j = 5; j*j <= num; j+=2){
        if(num % j == 0){
          is_prime = 0;
          break;
        }
      }
    }
		if(is_prime){
			sum += num;
			ans[idx] = num;
			idx++;
			bisa = 1;
		}
    if(sum >= h){
			break;
		}
	}
	if(bisa){
    if(sum >= h){
		  printf("Wah angkanya cocok nih! Angkanya adalah ");
		  for(int i = 0; i < idx; i++){
			  printf("%lld ", ans[i]);
		  }
    }else{
      printf("Waduh angkanya kurang nih, minta Bedul dulu deh!\n");
    }
	}else{
		printf("Wah angkanya ngga cocok nih!");
	}	
}

/*
analisis:
untuk n = 10^10 dan m = 50
hanya m*sqrt(n) = 50 * 10^5 = 5 * 10^6 (masih bisa < 1 second)

*/
