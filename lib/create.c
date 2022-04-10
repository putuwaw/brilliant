#include "create.h"

void tambah_data(book *b){
    // FILE OPERATION
    FILE *f;
    f = fopen("data/book.txt", "a");
    // GET INPUT FROM  USER
    printf("Masukkan nama buku: ");
    gets(b->name);
    fflush(stdin);
    printf("Masukkan nama pengarang: ");
    gets(b->author);
    fflush(stdin);
    printf("Masukkan tahun terbit: ");
    scanf("%d", &b->year);
    fflush(stdin);
    printf("Masukkan kategori buku: ");
    gets(b->category);
    if (head == NULL)
    {
        head = b;
        b->next = NULL;
    }
    else
    {
        book *curr;
        curr = head;
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = b;
        b->next = NULL;
    }
    // TIME OPERATION
    time(&rawtime);
    timeInfo = localtime(&rawtime);
    strcpy(b->created, timeToStr(timeInfo));
    strcpy(b->modified, timeToStr(timeInfo));
    // OUTPUT (OPTIONAL)
    printf("Buku berhasil ditambahkan!\nDetail:\n");
    printf("%-35s|%-20s|%-5d|%-15s|%15s|%15s\n", b->name, b->author, b->year, b->category, b->created, b->modified);
    // ... FILE OPERATION
    fprintf(f, "%-35s|%-20s|%-5d|%-15s|%15s|%15s\n", b->name, b->author, b->year, b->category, b->created, b->modified);
    fclose(f);
}
