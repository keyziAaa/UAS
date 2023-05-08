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
        
        switch (pilihan)
        {
        case 1:
            if (jumlahBuku < 50)
            {
                struct Buku buku;
                printf("\nJudul Buku              : ");
                scanf(" %[^\n]s", buku.judul);
                printf("Pengarang Buku          : ");
                scanf(" %[^\n]s", buku.pengarang);
                printf("Penerbit Buku           : ");
                scanf(" %[^\n]s", buku.penerbit);
                printf("Tahun Terbit Buku       : ");
                scanf("%d", &buku.tahunTerbit);
                printf("Jumlah Halaman Buku     : ");
                scanf("%d", &buku.halaman);
                buku.dipinjam = 0;
                daftarBuku[jumlahBuku] = buku;
                jumlahBuku++;
                FILE *file = fopen("data_perpustakaan.txt", "w");
                if (file)
                {
                    for (int i = 0; i < jumlahBuku; i++)
                    {
                        fprintf(file, "%s|%s|%s|%d|%d|%s\n", daftarBuku[i].judul, daftarBuku[i].pengarang,
                                daftarBuku[i].penerbit, daftarBuku[i].tahunTerbit, daftarBuku[i].halaman,
                                daftarBuku[i].dipinjam ? "Dipinjam" : "Tersedia");
                    }
                    fclose(file);
                }
                printf("\nBuku berhasil ditambahkan.\n\n");
            }
            else
            {
                printf("\nGagal menambahkan buku karena telah penuh.\n\n");
            }
            break;
