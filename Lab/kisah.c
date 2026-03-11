#include <stdio.h>
#include <string.h>
int main(){
  int t;
  scanf("%d", &t);
  while(t--){
    int n;
    char str[n];
    scanf("%d %[^\n]s", &n, str);
    long long pref[n];
    for(long long i = 0; i < n; i++){
      pref[i] = 0;
    }
    scanf("%lld", &pref[0]);
    pref[0] %= 26;
    pref[0] += 26;
    for(long long i = 1; i < n; i++){
      long long num;
      scanf("%lld", &num);
      pref[i] = (pref[i - 1] + num) % 26 + 26;
      pref[i] %= 26;
    }
    for(int i = 0; i < n; i++){
      long long shift = (pref[i] % 26);
      if(str[i] >= 'A' && str[i] <= 'Z'){
        char c = ((str[i] - 'A' + shift) % 26 + 'A');
        pri
      }else if(str[i] >= 'a' && str[i] <= 'z'){

      }
    }
  }
}
