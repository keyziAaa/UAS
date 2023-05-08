#include <stdio.h>
#include <string.h>

struct Buku{
    char judul[50];
    char pengarang[50];
    char penerbit[50];
    int tahunTerbit;
    int halaman;
    int dipinjam;
};

int main(){
    struct Buku daftarBuku[100];
    int jumlahBuku = 0;
    int pilihan;

    while (1){
        printf("---Manajemen Perpustakaan---\n");
        printf("|1. Tambah Buku             |\n");
        printf("|2. Cari Buku               |\n");
        printf("|3. Pinjam Buku             |\n");
        printf("|4. Kembalikan Buku         |\n");
        printf("|5. Keluar                  |\n");
        printf("-----------------------------\n");
        printf("Pilihan : ");
        scanf("%d", &pilihan);

        switch (pilihan){
        case 1:
            if (jumlahBuku < 50){
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
                if (file){
                    for (int i = 0; i < jumlahBuku; i++){
                        fprintf(file, "%s|%s|%s|%d|%d|%s\n", daftarBuku[i].judul, daftarBuku[i].pengarang,
                                daftarBuku[i].penerbit, daftarBuku[i].tahunTerbit, daftarBuku[i].halaman,
                                daftarBuku[i].dipinjam ? "Dipinjam" : "Tersedia");
                    }
                    fclose(file);
                }
                printf("\nBuku berhasil ditambahkan.\n\n");
            }
            else{
                printf("\nGagal menambahkan buku karena telah penuh.\n\n");
            }
            break;

        case 2:
            if (jumlahBuku > 0){
                char judulBuku[50];
                int ditemukan = 0;
                printf("\nCari Buku");
                printf("\nKetikkan Judul Buku : ");
                scanf(" %[^\n]s", judulBuku);

                for (int i = 0; i < jumlahBuku; i++){
                    if (strcmp(daftarBuku[i].judul, judulBuku) == 0){
                        printf("\nJudul buku          : %s\n", daftarBuku[i].judul);
                        printf("Pengarang           : %s\n", daftarBuku[i].pengarang);
                        printf("Penerbit            : %s\n", daftarBuku[i].penerbit);
                        printf("Tahun terbit        : %d\n", daftarBuku[i].tahunTerbit);
                        printf("Jumlah halaman      : %d\n", daftarBuku[i].halaman);
                        printf("Status peminjaman   : %s\n\n", daftarBuku[i].dipinjam ? "Dipinjam" : "Tersedia");
                        ditemukan = 1;
                        break;
                    }
                }

                if (!ditemukan){
                    printf("\nTidak ditemukan buku dengan judul %s.\n\n", judulBuku);
                }
            }
            else{
                printf("\nBelum ada buku yang ditambahkan.\n\n");
            }
            break;

        case 3:
            if (jumlahBuku > 0){
                char judulBuku[50];
                int ditemukan = 0;
                printf("\nPinjam Buku");
                printf("\nKetikkan Judul Buku : ");
                scanf(" %[^\n]s", judulBuku);

                for (int i = 0; i < jumlahBuku; i++){
                    if (strcmp(daftarBuku[i].judul, judulBuku) == 0){
                        if (daftarBuku[i].dipinjam){
                            printf("\nBuku %s sedang dipinjam.\n\n", judulBuku);
                        }
                        else{
                            daftarBuku[i].dipinjam = 1;
                            printf("\nBuku %s berhasil dipinjam.\n\n", daftarBuku[i].judul);
                        }
                        ditemukan = 1;
                        break;
                    }
                }
                if (!ditemukan){
                    printf("\nTidak ditemukan buku dengan judul %s.\n\n", judulBuku);
                }
            }
            else{
                printf("\nBelum ada buku yang ditambahkan.\n\n");
            }
            break;

        case 4:
            if (jumlahBuku > 0){
                char judulBuku[50];
                int ditemukan = 0;
                printf("\nKembalikan Buku");
                printf("\nKetikkan Judul Buku : ");
                scanf(" %[^\n]s", judulBuku);

                for (int i = 0; i < jumlahBuku; i++){
                    if (strcmp(daftarBuku[i].judul, judulBuku) == 0){
                        if (!daftarBuku[i].dipinjam){
                            printf("\nBuku %s belum dipinjam.\n\n", daftarBuku[i].judul);
                        }
                        else{
                            daftarBuku[i].dipinjam = 0;
                            printf("\nBuku %s berhasil dikembalikan.\n\n", daftarBuku[i].judul);
                        }
                        ditemukan = 1;
                        break;
                    }
                }

                if (!ditemukan){
                    printf("\nTidak ditemukan buku dengan judul %s.\n\n", judulBuku);
                }
            }
            else{
                printf("\nBelum ada buku yang ditambahkan.\n\n");
                
        case 5:
            printf("\nTerima kasih telah menggunakan program manajemen perpustakaan.");
            return 0;

        default:
            printf("\nPilihan tidak valid.\n\n");
            break;
        }
            }
            break;
