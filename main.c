//#include "lib/sample_header.h"
#include <stdio.h>

int main(){
   int pilihan,p2,p3;
    do{
        system("clear");
        printf("Main Menu\n");
        printf("0. About\n");
        printf("1. Tambah Data Buku\n");
        printf("2. Edit Data Buku\n");
        printf("3. Hapus Data\n");
        printf("4. Lihat Data\n");
        printf("5. Keluar Program\n");
        printf("Pilihan Anda: ");
        scanf("%d",&pilihan);
        switch(pilihan){
        case 0:
            system("clear");
            // ABOUT US HERE!!!
        break;
              
        case 1:
            system("clear");
            printf("0. Kembali\n");
            printf("1. Lanjutkan Menambah Buku?\n");
            printf("Pilihan Anda: ");
            scanf("%d",&p2);
            switch(p2){
                case 0:
                // BACK
                break;

                case 1:
                // ADDING BOOK FUNCTION
                break;
            }
            break;

        case 2:
            system("clear");
            printf("0. Kembali\n");
            printf("1. Lanjutkan Edit Buku?\n");
            printf("Pilihan Anda: ");
            scanf("%d",&p2);
            switch(p2){
                case 0:
                // BACK
                break;

                case 1:
                // EDIT BOOK FUNCTION
                break;
            }
        break;

            case 3:
            system("clear");
            printf("0. Kembali\n");
            printf("1. Lanjutkan Hapus Buku?\n");
            printf("Pilihan Anda: ");
            scanf("%d",&p2);
            switch(p2){
                case 0:
                // BACK
                break;

                case 1:
                // DELETE BOOK FUNCTION
                break;
            }
        break;

        case 4:
            system("clear");
            printf("0. Kembali\n");
            printf("1. Lihat Biasa\n");
            printf("2. Lihat Data Terurut\n");
            printf("3. Cari Buku\n");
            printf("Pilihan Anda: ");
            scanf("%d",&p2);
            switch(p2){
                case 0:
                // BACK
                break;

                case 1:
                // NORMAL VIEW
            break;

                case 2:
                    system("clear");
                    printf("0. Kembali\n");
                    printf("1. Urutkan Berdasarkan Nama Buku\n");
                    printf("2. Urutkan Berdasarkan Nama Penulis\n");
                    printf("3. Urutkan Berdasarkan Tahun Terbit\n");
                    printf("4. Urutkan Berdasarkan Kategori\n");
                    printf("Pilihan Anda: ");
                    scanf("%d",&p3);
                    switch(p3){
                        case 0:
                        // BACK
                        break;

                        case 1:
                        // NAME SORTING
                        break;

                        case 2:
                        // AUTHOR SORTING
                        break;

                        case 3:
                        // PUBLICATION DATE SORTING
                        break;

                        case 4:
                        // CATEGORY SORTING
                        break;

                    }
                break;

                case 3:
                    system("clear");
                    printf("0. Kembali\n");
                    printf("1. Cari Nama Buku\n");
                    printf("2. Cari Nama Penulis\n");
                    printf("3. Cari Berdasarkan Tahun Terbit\n");
                    printf("4. Cari Kategori\n");
                    printf("Pilihan Anda: ");
                    scanf("%d",&p3);
                    switch(p3){
                        case 0:
                        // BACK
                        break;

                        case 1:
                        // NAME SEARCH
                        break;

                        case 2:
                        // AUTHOR SEARCH
                        break;

                        case 3:
                        // PUBLICATION DATE SEARCH
                        break;

                        case 4:
                        // CATEGORY SEARCH
                        break;

                    }
                break;
            }
        break;
        }
    }
    while (0);
    return 0;
}
