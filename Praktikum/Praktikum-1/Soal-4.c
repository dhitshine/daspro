#include <stdio.h>
int main(){
    int dd1, hh1, mm1, dd2, hh2, mm2;
    char chr1, chr2, jenis, bayar;
    scanf("%d %d%c%d %d %d%c%d %c %c", &dd1, &hh1, &chr1, &mm1, &dd2, &hh2, &chr2, &mm2, &jenis, &bayar);
    if(dd2 < dd1 || (dd2 == dd1 && hh2 < hh1) || (dd2 == dd1 && hh2 == hh1 && mm2 < mm1)){
        printf("Tidak mungkin");
        return 0;
    }
    int jumlah_hari = dd2 - dd1;
    int jumlah_jam = hh2 - hh1;
    int jumlah_menit = mm2 - mm1;
    
    if(jumlah_menit < 0){
        jumlah_jam -= 1;
        jumlah_menit += 60;
    }
    
    if(jumlah_jam < 0){
        jumlah_hari -= 1;
        jumlah_jam += 24;
    }
    
    int display_hari = jumlah_hari;
    int display_jam = jumlah_jam;
    int display_menit = jumlah_menit;
    
    int billing_jam = jumlah_jam;
    if(jumlah_menit > 0){
        billing_jam += 1;
    }
    
    int ans = 0;
    
    if(jenis == 'M'){
        if(jumlah_hari == 0){
            if(billing_jam <= 3){
                ans += 10000;
            } else {
                ans += 10000 + 2000 * (billing_jam - 3);
            }
        }else{
            ans += 10000 + jumlah_hari * 150000 + 2000 * billing_jam;
        }
    } else if(jenis == 'S'){
        if(jumlah_hari == 0){
            if(billing_jam > 0){
                ans += 3000;
            }
        }else{ 
            ans += jumlah_hari * 50000;
            if(billing_jam > 0){
                ans += 3000;
            }
        }
    }
    
    if(bayar == 'b'){
        int diskon = ans * 20 / 100;
        if(diskon > 10000){
            diskon = 10000;
        }
        ans -= diskon;
    } else if(bayar == 'c'){
        int diskon = ans * 10 / 100;
        if(diskon > 20000){
            diskon = 20000;
        }
        ans -= diskon;
    }
    
    printf("Anda telah berada di sini selama %d hari, %d jam, dan %d menit. Anda harus membayar sebesar %d rupiah", display_hari, display_jam, display_menit, ans);
    
    return 0;
}