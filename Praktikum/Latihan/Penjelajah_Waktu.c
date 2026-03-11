#include <stdio.h>

int main(){
	int y;
	scanf("%d", &y);
	if(y % 400 == 0){
		if(y % 4 == 0){
			printf("Perjalanan waktu telah dimulai! Selamat mengeksplorasi tahun %d.", y);
		}else{
			printf("Tahun %d bukan tahun kabisat. Coba tahun lain.", y);
		}
	}else{
		printf("Tahun %d bukan tahun kabisat. Coba tahun lain.", y);
	}
}
