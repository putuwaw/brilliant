#include "create.h"

COORD pos;

void tambah_data(book *b){
    // FILE OPERATION
    FILE *f;
    f = fopen("data/book.txt", "a");
    // GET INPUT FROM  USER
    clearScreen();
    printf("|-------------------------------------------------------------------|\n");
    printf("|                                                                   |\n");
    printf("|                          TAMBAH BUKU                              |\n");
    printf("|                                                                   |\n");
    printf("|-------------------------------------------------------------------|\n");
    printf("|                                                                   |\n");
    printf("|  Nama Buku          :                                             |\n");
    printf("|  Nama Penulis       :                                             |\n");
    printf("|  Tahun Terbit Buku  :                                             |\n");
    printf("|  Kategori Buku      :                                             |\n");
    printf("|                                                                   |\n");
    printf("---------------------------------------------------------------------\n");
    pos.X = 24;
    pos.Y = 6;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
    gets(b->name);
    fflush(stdin);
    pos.X = 24;
    pos.Y = 7;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
    gets(b->author);
    fflush(stdin);
    pos.X = 24;
    pos.Y = 8;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
    scanf("%d", &b->year);
    fflush(stdin);
    pos.X = 24;
    pos.Y = 9;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
    gets(b->category);
    pos.X = 0;
    pos.Y = 12;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
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
    totalBook++;
    // TIME OPERATION
    time(&rawtime);
    timeInfo = localtime(&rawtime);
    strcpy(b->created, timeToStr(timeInfo));
    strcpy(b->modified, timeToStr(timeInfo));
    // OUTPUT (OPTIONAL)

    printf("|                                                                   |\n");
    printf("|  Buku Berhasil Ditambahkan!                                       |\n");
    printf("|                                                                   |\n");
    printf("---------------------------------------------------------------------\n");
    printf("|                                                                   |\n");
    printf("|  Detail:                                                          |\n");
    printf("|                                                                   |\n");
    printf("|  Nama               :                                             |\n"); //19
    printf("|  Penulis            :                                             |\n");
    printf("|  Tahun Terbit       :                                             |\n");
    printf("|  Kategori           :                                             |\n");
    printf("|  Waktu Dibuat       :                                             |\n");
    printf("|  Waktu Dimodifikasi :                                             |\n");
    printf("|                                                                   |\n");
    printf("---------------------------------------------------------------------\n");

    pos.X = 24;
    pos.Y = 19;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
    printf("%s",b->name);
    pos.X = 24;
    pos.Y = 20;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
    printf("%s",b->author);
    pos.X = 24;
    pos.Y = 21;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
    printf("%d",b->year);
    pos.X = 24;
    pos.Y = 22;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
    printf("%s",b->category);
    pos.X = 24;
    pos.Y = 23;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
    printf("%s",b->created);
    pos.X = 24;
    pos.Y = 24;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
    printf("%s",b->modified);
    pos.X = 0;
    pos.Y = 27;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
    // ... FILE OPERATION
    fprintf(f, "%s|%s|%d|%s|%s|%s\n", b->name, b->author, b->year, b->category, b->created, b->modified);
    fclose(f);
}
