#include <stdio.h>
int main(){
  long long x, y;
  scanf("%lld %lld", &x, &y);
  long long ans = 0;
  while(x > 1){
    if(y > 0 && x % 2 == 0){
      x >>= 1;
      y--;
      ans++;
    }else if(y == 0){
      ans += (x - 1);
      break;
    }else{
      x--;
      ans++;
    }
  }
  printf("%lld", ans);
}
/*
ada 3 kemungkinan
- bisa make lompatan kalo y nya masih > 0 dan x nya bisa dibagi 2 (ans++)
- ga make lompatan (x nya ganjil) (ans++)
- kalo y nya 0 kurangi sisa ans += (x - 1)






3 - 2 
128 -> 64 -> 32 -> 16
50 -> 25 -> 12 -> 6 -> 3 -> 2 
38 -> 19 -> 9 -> 4 

4 + 1 + 1 + 3



12
1
2
3
4
8
16
17
18
19

19 -> 9 -> 4
3 + 1 + 1 + 1 + 1




128 -> 64 -> 32 -> 16

+16
+32
+64

15 + 3

127 4
127 -> 63 -> 31 -> 15 -> 7 

6 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1


5 1 
5 -> 2 
ans += 1 + 1 + (2 - 1);

*/

