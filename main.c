#include "crud.h"

int main(){
    int pilihan, p2, p3;
    bool repeat, r1, r2;
    do{
        repeat = true;
        system("cls");
        printf("||====================================================================||\n");
        printf("||============================ Main Menu =============================||\n");
        printf("||====================================================================||\n");
        printf("|| Pilihan Menu :                                                     ||\n");
        printf("||====================================================================||\n");
        printf("|| 0. About                                                           ||\n");
        printf("|| 1. Tambah Data Buku                                                ||\n");
        printf("|| 2. Edit Data Buku                                                  ||\n");
        printf("|| 3. Hapus Data                                                      ||\n");
        printf("|| 4. Lihat Data                                                      ||\n");
        printf("|| 5. Keluar Progam                                                   ||\n");
        printf("||====================================================================||\n");
        scanf("%d", &pilihan);
        switch (pilihan){
            case 0:
                system("cls");
                // ABOUT US HERE!!!
                printf("about us\n");
                system("pause");
                break;
            case 1:
                do{
                    r1 = true;
                    clearScreen();
                    printf("0. Kembali\n");
                    printf("1. Lanjutkan Menambah Buku?\n");
                    printf("Pilihan Anda: ");
                    scanf("%d", &p2);
                    fflush(stdin);
                    switch (p2){
                        case 0:
                            // BACK
                            r1 = false;
                            break;
                        case 1:
                            // ADDING BOOK FUNCTION
                            b = malloc(sizeof(book));
                            tambah_data(b);
                            pauseScreen();
                            break;
                        default:
                            printf("Input harus 0-1!\n");
                            pauseScreen();
                    }
                } while (r1);
                break;
            case 2:
                do{
                    r1 = true;
                    system("cls");
                    printf("0. Kembali\n");
                    printf("1. Lanjutkan Edit Buku?\n");
                    printf("Pilihan Anda: ");
                    scanf("%d", &p2);
                    switch (p2){
                        case 0:
                            // BACK
                            r1 = false;
                            break;
                        case 1:
                            // EDIT BOOK FUNCTION
                            printf("edit book\n");
                            system("pause");
                            break;
                        default:
                            printf("Input harus 0-1!\n");
                            system("pause");
                    }
                } while (r1);
                break;
            case 3:
                do{
                    r1 = true;
                    system("cls");
                    printf("0. Kembali\n");
                    printf("1. Lanjutkan Hapus Buku?\n");
                    printf("Pilihan Anda: ");
                    scanf("%d", &p2);
                    switch (p2){
                        case 0:
                            // BACK
                            r1 = false;
                            break;
                        case 1:
                            // DELETE BOOK FUNCTION
                            printf("delete book\n");
                            system("pause");
                            break;
                        default:
                            printf("Input harus 0-1!\n");
                            system("pause");
                    }
                } while (r1);
                break;
            case 4:
                do{
                    r1 = true;
                    system("cls");
                    printf("0. Kembali\n");
                    printf("1. Lihat Biasa\n");
                    printf("2. Lihat Data Terurut\n");
                    printf("3. Cari Buku\n");
                    printf("Pilihan Anda: ");
                    scanf("%d", &p2);
                    switch (p2){
                        case 0:
                            // BACK
                            r1 = false;
                            break;
                        case 1:
                            // NORMAL VIEW
                            printf("normal view\n");
                            system("pause");
                            break;
                        case 2:
                            do{
                                r2 = true;
                                system("cls");
                                printf("0. Kembali\n");
                                printf("1. Urutkan Berdasarkan Nama Buku\n");
                                printf("2. Urutkan Berdasarkan Nama Penulis\n");
                                printf("3. Urutkan Berdasarkan Tahun Terbit\n");
                                printf("4. Urutkan Berdasarkan Kategori\n");
                                printf("Pilihan Anda: ");
                                scanf("%d", &p3);
                                switch (p3){
                                    case 0:
                                        // BACK
                                        r2 = false;
                                        break;
                                    case 1:
                                        // NAME SORTING
                                        printf("sort name\n");
                                        system("pause");
                                        break;
                                    case 2:
                                        // AUTHOR SORTING
                                        printf("sort author\n");
                                        system("pause");
                                        break;
                                    case 3:
                                        // PUBLICATION DATE SORTING
                                        printf("sort year\n");
                                        system("pause");
                                        break;
                                    case 4:
                                        // CATEGORY SORTING
                                        printf("sort category\n");
                                        system("pause");
                                        break;
                                    default:
                                        printf("Input harus 0-4!\n");
                                        system("pause");
                                }
                            } while (r2);
                            break;
                        case 3:
                            do{
                                r2 = true;
                                system("cls");
                                printf("0. Kembali\n");
                                printf("1. Cari Nama Buku\n");
                                printf("2. Cari Nama Penulis\n");
                                printf("3. Cari Berdasarkan Tahun Terbit\n");
                                printf("4. Cari Kategori\n");
                                printf("Pilihan Anda: ");
                                scanf("%d", &p3);
                                switch (p3){
                                    case 0:
                                        // BACK
                                        r2 = false;
                                        break;
                                    case 1:
                                        // NAME SEARCH
                                        printf("name search\n");
                                        system("pause");
                                        break;
                                    case 2:
                                        // AUTHOR SEARCH
                                        printf("name search\n");
                                        system("pause");
                                        break;
                                    case 3:
                                        // PUBLICATION DATE SEARCH
                                        printf("name search\n");
                                        system("pause");
                                        break;
                                    case 4:
                                        // CATEGORY SEARCH
                                        printf("name search\n");
                                        system("pause");
                                        break;
                                    default:
                                        printf("Input harus 0-4!\n");
                                        system("pause");
                                }
                            } while (r2);
                            break;
                        default:
                            printf("Input harus 0-3!\n");
                            system("pause");
                    }
                } while (r1);
                break;
            case 5:
                repeat = false;
                break;
            default:
                printf("Input harus 0-5!\n");
                system("pause");
        }
    } while (repeat);
    return 0;
}
