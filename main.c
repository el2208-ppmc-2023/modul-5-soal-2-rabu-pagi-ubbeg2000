/** EL2208 Praktikum Pemecahan Masalah dengan C 2022/2023
 *   Modul               : 
 *   Hari dan Tanggal    :
 *   Nama (NIM)          :
 *   Nama File           : main.c
 *   Deskripsi           :
 */

#include <stdio.h>
#include <stdlib.h>

// Fungsi display memindahkan donat dari tiang awal ke tiang tujuan
void printOutPerpindahan(int n, char awal, char tujuan, int *sum) {
    printf("Noor memindahkan donat %d dari tiang %c ke tiang %c\n", n, awal, tujuan);
    (*sum)++;
}

// Fungsi rekursif untuk menyelesaikan masalah hanoi tower
void pindahkanDonat(int n, char awal, char tujuan, char bantu, int *sum) {
    if (n == 1) {
        printOutPerpindahan(n, awal, tujuan, sum);
        return;
    }
    pindahkanDonat(n-1, awal, bantu, tujuan, sum);
    printOutPerpindahan(n, awal, tujuan, sum);
    pindahkanDonat(n-1, bantu, tujuan, awal, sum);
}

int main() {
    int n;
    int sum = 0;
    printf("Masukkan jumlah donat (minimal 3): ");
    scanf("%d", &n);
    if (n<0) {
        printf("Jumlah donat harus positif!");
        return 0;
    }
    if (n<3) {
        printf("Jumlah donat minimal 3 yaa!\n");
        return 0;
    }

    printf("Langkah untuk menyelesaikan masalah menara donat dengan %d donat:\n", n);
    pindahkanDonat(n, 'A', 'C', 'B', &sum);
    printf("Jumlah langkah minimal yang diperlukan Noor untuk memindahkan menara donat dari tiang A ke tiang C : %d\n",sum);
    return 0;
}
