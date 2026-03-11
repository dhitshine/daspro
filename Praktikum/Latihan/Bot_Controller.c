#include <stdio.h>

int main(){
	int x, y, w, a, s, d;
	scanf("%d %d %d %d %d %d", &x, &y, &w, &a, &s, &d);
	int x_akhir = x + d - a;
	int y_akhir = y + w - s;
	if(x_akhir <= 100 && y_akhir <= 100 && x_akhir >= -100 && y_akhir >= -100){
		if(x_akhir == 0 && y_akhir == 0){
			printf("Bot Mr. Biti berada di tengah arena\n");	
		}else if(x_akhir > 0 && y_akhir > 0){
			printf("Bot Mr. Biti berada di kuadran 1\n");
		}else if(x_akhir > 0 && y_akhir < 0){
			printf("Bot Mr. Biti berada di kuadran 4\n");	
		}else if(x_akhir < 0 && y_akhir > 0){
			printf("Bot Mr. Biti berada di kuadran 2\n");
		}else if(x_akhir < 0 && y_akhir < 0){
			printf("Bot Mr. Biti berada di kuadran 3\n");	
		}else if(x_akhir == 0){
			printf("Bot Mr. Biti berada di sumbu Y!\n");
		}else if(y_akhir == 0){
			printf("Bot Mr. Biti berada di sumbu X!\n");
		}
	}else{
		printf("Bot Mr. Biti keluar arena\n");
	}
}
