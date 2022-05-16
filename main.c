#include "crud.h"

int main(){
    getDataFromFile();
    int pilihan, p2, p3;
    bool repeat, r1, r2;
    COORD pos;
    do{
        repeat = true;
        clearScreen();
        printf("|-------------------------------------------------------------------|\n");
        printf("|                       * BRILLIANT *                               |\n");
        printf("|        Brilliant adalah aplikasi berbasis console dengan          |\n");
        printf("|           fitur GUI yang mampu mengolah data buku                 |\n");
        printf("|-------------------------------------------------------------------|\n");
        printf("|                                                                   |\n");
        printf("|                                                                   |\n");
        printf("|                     0. About                                      |\n");
        printf("|                     1. Tambah Data                                |\n");
        printf("|                     2. Edit Data Buku                             |\n");
        printf("|                     3. Hapus Data                                 |\n");
        printf("|                     4. Lihat Data                                 |\n");
        printf("|                     5. Keluar Program                             |\n");
        printf("|                                                                   |\n");
        printf("|                     [PILIHAN ANDA] :                              |\n");
        printf("|                                                                   |\n");
        printf("|                                                                   |\n");
        printf("|                                                                   |\n");
        printf("|                                                                   |\n");
        printf("---------------------------------------------------------------------\n");
        printf("|                       Created by: Kelompok 1                      |\n");
        // Time Calc
        time(&rawtime);
        timeInfo = localtime(&rawtime);
        printf("| Date: %.2d/%.2d/%d                                      Time: %.2d.%.2d |\n",
        timeInfo->tm_mday, timeInfo->tm_mon+1, timeInfo->tm_year+1900, timeInfo->tm_hour, timeInfo->tm_min);
        printf("=====================================================================\n");
        // Cursor Position
        pos.X = 39;
        pos.Y = 14;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
        scanf("%d", &pilihan);
        fflush(stdin);
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

                    printf("|-------------------------------------------------------------------|\n");
                    printf("|                                                                   |\n");
                    printf("|                      Ingin tambah buku?                           |\n");
                    printf("|                                                                   |\n");
                    printf("|-------------------------------------------------------------------|\n");
                    printf("|                                                                   |\n");
                    printf("|                                                                   |\n");
                    printf("|                     0. Tidak! (Kembali)                           |\n");
                    printf("|                     1. Ya!    (Lanjut)                            |\n");
                    printf("|                                                                   |\n");
                    printf("|                     [PILIHAN ANDA] :                              |\n");
                    printf("|                                                                   |\n");
                    printf("|                                                                   |\n");
                    printf("|                                                                   |\n");
                    printf("|                                                                   |\n");
                    printf("---------------------------------------------------------------------\n");

                    pos.X = 39;
                    pos.Y = 10;
                    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
                    scanf("%d", &p2);
                    pos.X = 0;
                    pos.Y = 16;
                    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
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
                            printf("\a|                                                                   |\n");
                            printf("|                     \033[0;31mInput harus 0-1!\033[0m                              |\n");
                            printf("|                                                                   |\n");
                            printf("---------------------------------------------------------------------\n");
                            pauseScreen();
                    }
                } while (r1);
                break;
            case 2:
                do{
                    r1 = true;
                    clearScreen();

                    printf("|-------------------------------------------------------------------|\n");
                    printf("|                                                                   |\n");
                    printf("|                        Ingin edit buku?                           |\n");
                    printf("|                                                                   |\n");
                    printf("|-------------------------------------------------------------------|\n");
                    printf("|                                                                   |\n");
                    printf("|                                                                   |\n");
                    printf("|                     0. Tidak! (Kembali)                           |\n");
                    printf("|                     1. Ya!    (Lanjut)                            |\n");
                    printf("|                                                                   |\n");
                    printf("|                     [PILIHAN ANDA] :                              |\n");
                    printf("|                                                                   |\n");
                    printf("|                                                                   |\n");
                    printf("|                                                                   |\n");
                    printf("|                                                                   |\n");
                    printf("---------------------------------------------------------------------\n");

                    pos.X = 39;
                    pos.Y = 10;
                    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
                    scanf("%d", &p2);
                    pos.X = 0;
                    pos.Y = 16;
                    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
                    fflush(stdin);
                    switch (p2){
                        case 0:
                            r1 = false;
                            break;
                        case 1:
                            edit_data();
                            pauseScreen();
                            break;
                        default:
                            printf("\a|                                                                   |\n");
                            printf("|                     \033[0;31mInput harus 0-1!\033[0m                              |\n");
                            printf("|                                                                   |\n");
                            printf("---------------------------------------------------------------------\n");
                            pauseScreen();
                    }
                } while (r1);
                break;
            case 3:
                do{
                    r1 = true;
                    clearScreen();

                    printf("|-------------------------------------------------------------------|\n");
                    printf("|                                                                   |\n");
                    printf("|                       Ingin hapus buku?                           |\n");
                    printf("|                                                                   |\n");
                    printf("|-------------------------------------------------------------------|\n");
                    printf("|                                                                   |\n");
                    printf("|                                                                   |\n");
                    printf("|                     0. Tidak! (Kembali)                           |\n");
                    printf("|                     1. Ya!    (Lanjut)                            |\n");
                    printf("|                                                                   |\n");
                    printf("|                     [PILIHAN ANDA] :                              |\n");
                    printf("|                                                                   |\n");
                    printf("|                                                                   |\n");
                    printf("|                                                                   |\n");
                    printf("|                                                                   |\n");
                    printf("---------------------------------------------------------------------\n");

                    pos.X = 39;
                    pos.Y = 10;
                    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
                    scanf("%d", &p2);
                    pos.X = 0;
                    pos.Y = 16;
                    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
                    fflush(stdin);
                    switch (p2){
                        case 0:
                            r1 = false;
                            break;
                        case 1:
                            hapus_data();
                            pauseScreen();
                            break;
                        default:
                            printf("\a|                                                                   |\n");
                            printf("|                     \033[0;31mInput harus 0-1!\033[0m                              |\n");
                            printf("|                                                                   |\n");
                            printf("---------------------------------------------------------------------\n");
                            pauseScreen();
                    }
                } while (r1);
                break;
            case 4:
                do{
                    r1 = true;
                    clearScreen();

                    printf("|-------------------------------------------------------------------|\n");
                    printf("|                                                                   |\n");
                    printf("|                        Ingin lihat apa?                           |\n");
                    printf("|                                                                   |\n");
                    printf("|-------------------------------------------------------------------|\n");
                    printf("|                                                                   |\n");
                    printf("|                                                                   |\n");
                    printf("|                     0. Kembali                                    |\n");
                    printf("|                     1. Lihat Biasa                                |\n");
                    printf("|                     2. Lihat Secara Urut                          |\n");
                    printf("|                     3. Cari Buku                                  |\n");
                    printf("|                                                                   |\n");
                    printf("|                     [PILIHAN ANDA] :                              |\n");
                    printf("|                                                                   |\n");
                    printf("|                                                                   |\n");
                    printf("|                                                                   |\n");
                    printf("|                                                                   |\n");
                    printf("---------------------------------------------------------------------\n");

                    pos.X = 39;
                    pos.Y = 12;
                    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
                    scanf("%d", &p2);
                    pos.X = 0;
                    pos.Y = 18;
                    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
                    fflush(stdin);
                    switch (p2){
                        case 0:
                            r1 = false;
                            break;
                        case 1:
                            lihat_data_normal();
                            pauseScreen();
                            break;
                        case 2:
                            do{
                                r2 = true;
                                system("cls");

                                printf("|-------------------------------------------------------------------|\n");
                                printf("|                                                                   |\n");
                                printf("|                Ingin urutkan berdasarkan apa?                     |\n");
                                printf("|                                                                   |\n");
                                printf("|-------------------------------------------------------------------|\n");
                                printf("|                                                                   |\n");
                                printf("|                                                                   |\n");
                                printf("|                     0. Kembali                                    |\n");
                                printf("|                     1. Urutkan Berdasarkan Nama Buku              |\n");
                                printf("|                     2. Urutkan Berdasarkan Nama Penulis           |\n");
                                printf("|                     3. Urutkan Berdasarkan Tahun Terbit           |\n");
                                printf("|                     4. Urutkan Berdasarkan Kategori               |\n");
                                printf("|                                                                   |\n");
                                printf("|                     [PILIHAN ANDA] :                              |\n");
                                printf("|                                                                   |\n");
                                printf("|                                                                   |\n");
                                printf("|                                                                   |\n");
                                printf("|                                                                   |\n");
                                printf("---------------------------------------------------------------------\n");
                                pos.X = 39;
                                pos.Y = 13;
                                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
                                scanf("%d", &p3);
                                fflush(stdin);
                                pos.X = 0;
                                pos.Y = 19;
                                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
                                switch (p3){
                                    case 0:
                                        r2 = false;
                                        break;
                                    case 1:
                                        lihat_sort_nama();
                                        pauseScreen();
                                        break;
                                    case 2:
                                        // AUTHOR SORTING
                                        lihat_sort_author();
                                        pauseScreen();
                                        break;
                                    case 3:
                                        // PUBLICATION DATE SORTING
                                        lihat_sort_year();
                                        pauseScreen();
                                        break;
                                    case 4:
                                        // CATEGORY SORTING
                                        lihat_sort_cat();
                                        pauseScreen();
                                        break;
                                    default:
                                        printf("\a|                                                                   |\n");
                                        printf("|                     \033[0;31mInput harus 0-4!\033[0m                              |\n");
                                        printf("|                                                                   |\n");
                                        printf("---------------------------------------------------------------------\n");
                                        pauseScreen();
                                }
                            } while (r2);
                            break;
                        case 3:
                            do{
                                r2 = true;
                                clearScreen();

                                printf("|-------------------------------------------------------------------|\n");
                                printf("|                                                                   |\n");
                                printf("|                Buku apa yang ingin anda cari?                     |\n");
                                printf("|                                                                   |\n");
                                printf("|-------------------------------------------------------------------|\n");
                                printf("|                                                                   |\n");
                                printf("|                                                                   |\n");
                                printf("|                     0. Kembali                                    |\n");
                                printf("|                     1. Cari Nama Buku                             |\n");
                                printf("|                     2. Cari Nama Penulis                          |\n");
                                printf("|                     3. Cari Tahun Terbit                          |\n");
                                printf("|                     4. Cari Kategori                              |\n");
                                printf("|                                                                   |\n");
                                printf("|                     [PILIHAN ANDA] :                              |\n");
                                printf("|                                                                   |\n");
                                printf("|                                                                   |\n");
                                printf("|                                                                   |\n");
                                printf("|                                                                   |\n");
                                printf("---------------------------------------------------------------------\n");
                                pos.X = 39;
                                pos.Y = 13;
                                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
                                scanf("%d", &p3);
                                fflush(stdin);
                                pos.X = 0;
                                pos.Y = 19;
                                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
                                switch (p3){
                                    case 0:
                                        r2 = false;
                                        break;
                                    case 1:
                                        lihat_cari_nama();
                                        pauseScreen();
                                        break;
                                    case 2:
                                        // AUTHOR SEARCH
                                        lihat_cari_author();
                                        pauseScreen();
                                        break;
                                    case 3:
                                        // PUBLICATION DATE SEARCH
                                        lihat_cari_year();
                                        pauseScreen();
                                        break;
                                    case 4:
                                        // CATEGORY SEARCH
                                        lihat_cari_cat();
                                        pauseScreen();
                                        break;
                                    default:
                                        printf("\a|                                                                   |\n");
                                        printf("|                     \033[0;31mInput harus 0-4!\033[0m                              |\n");
                                        printf("|                                                                   |\n");
                                        printf("---------------------------------------------------------------------\n");
                                        pauseScreen();
                                }
                            } while (r2);
                            break;
                        default:
                            printf("\a|                                                                   |\n");
                            printf("|                     \033[0;31mInput harus 0-3!\033[0m                              |\n");
                            printf("|                                                                   |\n");
                            printf("---------------------------------------------------------------------\n");
                            pauseScreen();
                    }
                } while (r1);
                break;
            case 5:
                pos.X = 0;
                pos.Y = 23;
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
                repeat = false;
                break;
            default:
                pos.X = 0;
                pos.Y = 23;
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
                printf("\a|                                                                   |\n");
                printf("|                     \033[0;31mInput harus 0-5!\033[0m                              |\n");
                printf("|                                                                   |\n");
                printf("---------------------------------------------------------------------\n");
                pauseScreen();
        }
    } while (repeat);
    return 0;
}
