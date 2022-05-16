#include "edit.h"

char edit_target[100];

COORD pos;

void edit_data(){
    if(totalBook==0){
        printf("|                                                                   |\n");
        printf("|  Belum ada buku!                                                  |\n");
        printf("|                                                                   |\n");
        printf("|-------------------------------------------------------------------|\n");
    }
    else{
        clearScreen();
        printf("|-------------------------------------------------------------------|\n");
        printf("|                                                                   |\n");
        printf("|                          EDIT BUKU                                |\n");
        printf("|                                                                   |\n");
        printf("|-------------------------------------------------------------------|\n");
        printf("|                                                                   |\n");
        printf("|  Nama Buku Yang Akan Diedit:                                      |\n");
        printf("|                                                                   |\n");
        printf("---------------------------------------------------------------------\n");
        pos.X = 31;
        pos.Y = 6;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
        gets(edit_target);
        pos.X = 0;
        pos.Y = 9;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
        fflush(stdin);
        bool isFound=false;
        book *curr=head;
        char nk[100],ak[100],ctk[100],crk[100],cmk[100],nkk[100],akk[100],ctkk[100],crkk[100],cmkk[100];
        int yk,ykk;
        while(curr!=NULL){
            if(strcmp(curr->name,edit_target)==0){
                strcpy(nk, curr->name);
                strcpy(ak, curr->author);
                yk = curr->year;
                strcpy(ctk, curr->category);
                strcpy(crk, curr->created);
                strcpy(cmk, curr->modified);
                isFound=true;
                break;
            }
            curr=curr->next;
        }
        if(isFound==true){
            printf("|                                                                   |\n");
            printf("|  Nama Buku Yang Baru          :                                   |\n");
            printf("|  Nama Penulis Yang Baru       :                                   |\n");
            printf("|  Tahun Terbit Buku Yang Baru  :                                   |\n");
            printf("|  Kategori Buku Yang Baru      :                                   |\n");
            printf("|                                                                   |\n");
            printf("---------------------------------------------------------------------\n");
            pos.X = 34;
            pos.Y = 10;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
            gets(curr->name);
            fflush(stdin);
            pos.X = 34;
            pos.Y = 11;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
            gets(curr->author);
            fflush(stdin);
            pos.X = 34;
            pos.Y = 12;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
            scanf("%d", &curr->year);
            fflush(stdin);
            pos.X = 34;
            pos.Y = 13;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
            gets(curr->category);
            pos.X = 0;
            pos.Y = 16;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
            //Time Calculation
            time(&rawtime);
            timeInfo = localtime(&rawtime);
            strcpy(curr->modified, timeToStr(timeInfo));
            strcpy(nkk, curr->name);
            strcpy(akk, curr->author);
            ykk = curr->year;
            strcpy(ctkk, curr->category);
            strcpy(crkk, curr->created);
            strcpy(cmkk, curr->modified);
            //File Operation
            FILE *f;
            f = fopen("data/book.txt", "w");
            curr = head;
            while(curr!=NULL){
                fprintf(f, "%s|%s|%d|%s|%s|%s\n", curr->name, curr->author, curr->year, curr->category, curr->created, curr->modified);
                curr=curr->next;
            }
            fclose(f);
            printf("|                                                                   |\n");
            printf("|  Buku Berhasil Diedit!                                            |\n");
            printf("|                                                                   |\n");
            printf("---------------------------------------------------------------------\n");
            printf("|                                                                   |\n");
            printf("|  Data Buku Sebelum Diedit :                                       |\n");
            printf("|                                                                   |\n");
            printf("|  Nama               :                                             |\n"); //23
            printf("|  Penulis            :                                             |\n");
            printf("|  Tahun Terbit       :                                             |\n");
            printf("|  Kategori           :                                             |\n");
            printf("|  Waktu Dibuat       :                                             |\n");
            printf("|  Waktu Dimodifikasi :                                             |\n");
            printf("|                                                                   |\n");
            printf("---------------------------------------------------------------------\n");
            printf("|                                                                   |\n");
            printf("|  Data Buku Setelah Diedit :                                       |\n");
            printf("|                                                                   |\n");
            printf("|  Nama               :                                             |\n"); //34
            printf("|  Penulis            :                                             |\n");
            printf("|  Tahun Terbit       :                                             |\n");
            printf("|  Kategori           :                                             |\n");
            printf("|  Waktu Dibuat       :                                             |\n");
            printf("|  Waktu Dimodifikasi :                                             |\n");
            printf("|                                                                   |\n");
            printf("---------------------------------------------------------------------\n");
            //DATA BEFORE
            pos.X = 24;
            pos.Y = 23;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
            printf("%s",nk);
            pos.X = 24;
            pos.Y = 24;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
            printf("%s",ak);
            pos.X = 24;
            pos.Y = 25;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
            printf("%d",yk);
            pos.X = 24;
            pos.Y = 26;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
            printf("%s",ctk);
            pos.X = 24;
            pos.Y = 27;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
            printf("%s",crk);
            pos.X = 24;
            pos.Y = 28;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
            printf("%s",cmk);

            //DATA AFTER
            pos.X = 24;
            pos.Y = 34;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
            printf("%s",nkk);
            pos.X = 24;
            pos.Y = 35;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
            printf("%s",akk);
            pos.X = 24;
            pos.Y = 36;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
            printf("%d",ykk);
            pos.X = 24;
            pos.Y = 37;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
            printf("%s",ctkk);
            pos.X = 24;
            pos.Y = 38;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
            printf("%s",crkk);
            pos.X = 24;
            pos.Y = 39;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
            printf("%s",cmkk);
            pos.X = 0;
            pos.Y = 42;
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
        }
        else{
            printf("|                                                                   |\n");
            printf("|  Buku Tidak Ditemukan!                                            |\n");
            printf("|                                                                   |\n");
            printf("---------------------------------------------------------------------\n");
        }
    }
}
