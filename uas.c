#include <stdio.h>
#include <string.h>

struct Buku
{
    char judul[50];
    char pengarang[50];
    char penerbit[50];
    int tahunTerbit;
    int halaman;
    int dipinjam;
};

int main()
{
    struct Buku daftarBuku[100];
    int jumlahBuku = 0;
    int pilihan;

    while (1)
    {
        printf("---Manajemen Perpustakaan---\n");
        printf("|1. Tambah Buku             |\n");
        printf("|2. Cari Buku               |\n");
        printf("|3. Pinjam Buku             |\n");
        printf("|4. Kembalikan Buku         |\n");
        printf("|5. Keluar                  |\n");
        printf("-----------------------------\n");
        printf("Pilihan : ");
        scanf("%d", &pilihan);
