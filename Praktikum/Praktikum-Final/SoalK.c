#include <stdio.h>

int is_valid(int x, int y, int n){
  return x >= 1 && x <= n && y >= 1 && y <= n;
}

void change(int *dim){
  if(*dim == 1){
    *dim = 2;
  }else{
    *dim = 1;
  }
}

int main(){
  int n, t, hp_now, warp, d_realm, d_sword;
  scanf("%d %d", &n, &t);
  scanf("%d %d", &hp_now, &warp);
  scanf("%d %d", &d_realm, &d_sword);
  char fisik[n + 1][n + 1], astral[n + 1][n + 1];
  for(int i = 1; i <= n; i++){
    char temp[n + 1];
    scanf("%s", temp);
    for(int j = 1; j <= n; j++){
      fisik[i][j] = temp[j];
      astral[i][j] = fisik[i][j];
    }
  }
  int bisa = 1;
  int x_now = 1, y_now = 1;
  int dim_now = 1;            // 1 untuk fisik dan 2 untuk 
  for(int i = 1; i <= t; i++){
    int tipe;
    scanf("%d", &tipe);
    if(tipe == 1){    // serang semua baris dan co, pada dimensi fisik -> 
      if(d_realm < warp){   // gausa warp
        hp_now -= d_realm;
      }else{    // warp aja
        hp_now -= warp;
        change(&dim_now);
      }
    }else if(tipe == 2){    // serang semua baris dan col pada dimensi astral
      if(d_realm < warp){
        hp_now -= d_realm;
      }else{
        hp_now -= warp;
        change(&dim_now);
      }
    }else if(tipe == 3){    // serang baris ke R
      int row;
      scanf("%d", &row);
    
      if(row == x_now && fisik[x_now + 1][y_now] != '#' && is_valid(x_now + 1, y_now, n)){ // bawah
        x_now++;
      }
      if(row == x_now && fisik[x_now + 1][y_now + 1] != '#' && is_valid(x_now + 1, y_now + 1, n)){ // kanan bawah
        x_now++;
        y_now++;
      }
      if(row == x_now && fisik[x_now + 1][y_now - 1] != '#' && is_valid(x_now + 1, y_now - 1, n)){ // kiri bawah
        x_now++;
        y_now--;
      }
      if(row == x_now && fisik[x_now - 1][y_now + 1] != '#' && is_valid(x_now - 1, y_now + 1, n)){ // kanan atas
        x_now--;
        y_now++;
      }
      if(row == x_now && fisik[x_now - 1][y_now - 1] != '#' && is_valid(x_now - 1, y_now - 1, n)){ // kiri atas
        x_now--;
        y_now--;
      }
      if(row == x_now && fisik[x_now - 1][y_now] != '#' && is_valid(x_now - 1, y_now, n)){ // atas
        x_now--;
      }
      if(row == x_now){   // gabisa gerak kemana mana 
        if(d_sword < warp){
          hp_now -= d_sword;
        }else{
          hp_now -= warp;
          change(&dim_now);
        }   
      }
    }else{
      int col;
      scanf("%d", &col);    // serang kolom ke C 
      if(col == y_now && fisik[x_now + 1][y_now + 1] != '#' && is_valid(x_now + 1, y_now + 1, n)){ // kanan bawah
        x_now++;
        y_now++;
      }
      if(col == y_now && fisik[x_now + 1][y_now - 1] != '#' && is_valid(x_now + 1, y_now - 1, n)){ // kiri bawah
        x_now++;
        y_now--;
      }
      if(col == y_now && fisik[x_now - 1][y_now + 1] != '#' && is_valid(x_now - 1, y_now + 1, n)){ // kanan atas
        x_now--;
        y_now++;
      }
      if(col == y_now && fisik[x_now - 1][y_now - 1] != '#' && is_valid(x_now - 1, y_now - 1, n)){ // kiri atas
        x_now--;
        y_now--;
      }
      if(col == y_now && fisik[x_now][y_now + 1] != '#' && is_valid(x_now, y_now + 1, n)){
        y_now++;
      }
      if(col == y_now && fisik[x_now][y_now - 1] != '#' && is_valid(x_now, y_now - 1, n)){
        y_now--;
      }
      if(col == y_now){   // gabisa gerak kemana mana 
        if(d_sword < warp){
          hp_now -= d_sword;
        }else{
          hp_now -= warp;
          change(&dim_now);
        }   
      }
    }
    if(hp_now <= 0){
      bisa = 0;
      break;
    }
  }
  if(bisa){
    printf("The barrier is down and I still hold %d HP. Your reign ends this instant.", hp_now);
  }else{
    printf("Insignificant... You were never a threat to my eternity.");
  }
  return 0;
}
