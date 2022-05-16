#include "delete.h"

char deleteTarget[100];

COORD pos;

void hapus_data(){
    if (totalBook == 0){
        printf("|                                                                   |\n");
        printf("|  Belum ada buku!                                                  |\n");
        printf("|                                                                   |\n");
        printf("|-------------------------------------------------------------------|\n");
    }
    else if (totalBook == 1){
        clearScreen();
        printf("|-------------------------------------------------------------------|\n");
        printf("|                                                                   |\n");
        printf("|                         HAPUS BUKU                                |\n");
        printf("|                                                                   |\n");
        printf("|-------------------------------------------------------------------|\n");
        printf("|                                                                   |\n");
        printf("|  Nama Buku Yang Akan Dihapus:                                     |\n");
        printf("|                                                                   |\n");
        printf("---------------------------------------------------------------------\n");
        pos.X = 32;
        pos.Y = 6;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
        gets(deleteTarget);
        pos.X = 0;
        pos.Y = 9;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
        fflush(stdin);
        book *curr;
        bool isFound = false;
        curr = head;
        while(curr != NULL){
            if (strcmp(curr->name, deleteTarget) == 0){
                isFound = true;
                break;
            }
            curr = curr->next;
        }
        if (isFound){
            // LL OPERATION
            head = NULL;
            free(curr);
            curr = NULL;
            totalBook--;
            // FILE OPERATION
            FILE *f;
            f = fopen("data/book.txt", "w");
            fclose(f);
            printf("|                                                                   |\n");
            printf("|  Buku Berhasil Dihapus!                                           |\n");
            printf("|                                                                   |\n");
            printf("---------------------------------------------------------------------\n");
        }
        else{
            printf("|                                                                   |\n");
            printf("|  Buku Tidak Ditemukan!                                            |\n");
            printf("|                                                                   |\n");
            printf("---------------------------------------------------------------------\n");
        }
    }
    else{
        clearScreen();
        // LL OPERATION
        printf("|-------------------------------------------------------------------|\n");
        printf("|                                                                   |\n");
        printf("|                         HAPUS BUKU                                |\n");
        printf("|                                                                   |\n");
        printf("|-------------------------------------------------------------------|\n");
        printf("|                                                                   |\n");
        printf("|  Nama Buku Yang Akan Dihapus:                                     |\n");
        printf("|                                                                   |\n");
        printf("---------------------------------------------------------------------\n");
        pos.X = 32;
        pos.Y = 6;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
        gets(deleteTarget);
        pos.X = 0;
        pos.Y = 9;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
        fflush(stdin);
        book *curr;
        bool isFound = false;
        curr = head;
        while(curr != NULL){
            if (strcmp(curr->name, deleteTarget) == 0){
                isFound = true;
                break;
            }
            curr = curr->next;
        }
        if (isFound){
            if (curr == head){ // head
                head = curr->next;
                free(curr);
                curr = NULL;
            }
            else if (curr->next == NULL){ // tail
                book *prev;
                prev = head;
                while(prev->next != curr){
                    prev = prev->next;
                }
                prev->next = NULL;
                free(curr);
                curr = NULL;
            }
            else{ // middle
                book *prev;
                prev = head;
                while(prev->next != curr){
                    prev = prev->next;
                }
                prev->next = curr->next;
                free(curr);
                curr = NULL;
            }
            totalBook--;
            // FILE OPERATION
            FILE *f;
            f = fopen("data/book.txt", "w");
            book *temp;
            temp = head;
            while(temp != NULL){
                fprintf(f, "%s|%s|%d|%s|%s|%s\n", temp->name, temp->author, temp->year, temp->category, temp->created, temp->modified);
                temp = temp->next;
            }
            fclose(f);
            printf("|                                                                   |\n");
            printf("|  Buku Berhasil Dihapus!                                           |\n");
            printf("|                                                                   |\n");
            printf("---------------------------------------------------------------------\n");
        }
        else{
            printf("|                                                                   |\n");
            printf("|  Buku Tidak Ditemukan!                                            |\n");
            printf("|                                                                   |\n");
            printf("---------------------------------------------------------------------\n");
        }
    }
}
