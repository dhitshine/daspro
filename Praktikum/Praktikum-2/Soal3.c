#include <stdio.h>
#include <string.h>
int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		char str[100];
		int cnt = 0;
		int freq[1000];
		scanf("%s", str);
		int len = strlen(str);
		for(int i = 0; i < 1000; i++){
			freq[i] = 0;
		}
		for(int i = 0; i < len; i++){
			freq[str[i]]++;
		}
    int udah[1000] = {0};
		for(int i = 0; i < (len + 1)/2; i++){
			if(freq[str[i]] >= 2 && !udah[str[i]]){
				cnt++;
        udah[str[i]] = 1;
			}
		}
		if(cnt >= 2){
			printf("Perfectly balanced, as all things should be\n");
		}else{
			printf("There was no other way\n");
		}
	}
}
/*

agar palindrom bisa di acak, maka harus ada minimal 2 huruf yang frekuensinya lebih dari 1 
contoh:
aba -> tidak bisa diacak, a memiliki frekuensi 2 dan b hanya 1 
abba -> bisa diacak menjadi baab
ababcbaba -> bisa diacak menjadi aabbbaa, frekuensi a = 4 dan b = 3
*/
