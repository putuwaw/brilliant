#include "delete.h"

char deleteTarget[100];

void hapus_data(){
    if (totalBook == 0){
        printf("ERROR! Belum ada buku!\n");
    }
    else if (totalBook == 1){
        printf("Masukkan nama buku yang akan dihapus: ");
        gets(deleteTarget);
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
            printf("Buku berhasil dihapus!\n");
        }
        else{
            printf("Buku yang akan dihapus tidak ditemukan!\n");
        }
    }
    else{
        // LL OPERATION
        printf("Masukkan nama buku yang akan dihapus: ");
        gets(deleteTarget);
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
            printf("Buku berhasil dihapus!\n");
        }
        else{
            printf("Buku yang akan dihapus tidak ditemukan!\n");
        }
    }
}
