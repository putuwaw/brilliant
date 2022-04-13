#include "edit.h"

char edit_target[100];

void edit_data(){
    if(totalBook==0){
        printf("ERROR BELUM ADA BUKU!!!");
    }
    else{
        printf("Masukkan Nama Buku Yang Akan Diedit: ");
        gets(edit_target);
        bool isFound=false;
        book *curr=head;
        while(curr!=NULL){
            if(strcmp(curr->name,edit_target)==0){
                isFound=true;
                break;
            }
            curr=curr->next;
        }
        if(isFound==true){
            printf("Masukkan nama buku baru: ");
            gets(curr->name);
            fflush(stdin);
            printf("Masukkan nama pengarang baru: ");
            gets(curr->author);
            fflush(stdin);
            printf("Masukkan tahun terbit baru: ");
            scanf("%d", &curr->year);
            fflush(stdin);
            printf("Masukkan kategori buku baru: ");
            gets(curr->category);
            //Time Calculation
            time(&rawtime);
            timeInfo = localtime(&rawtime);
            strcpy(curr->modified, timeToStr(timeInfo));
            //File Operation
            FILE *f;
            f = fopen("data/book.txt", "w");
            curr = head;
            while(curr!=NULL){
                fprintf(f, "%s|%s|%d|%s|%s|%s\n", curr->name, curr->author, curr->year, curr->category, curr->created, curr->modified);
                curr=curr->next;
            }
            fclose(f);
            printf("Data Berhasil Diedit!");
        }
        else{
            printf("Buku Tidak Ditemukan!");
        }
    }
}
