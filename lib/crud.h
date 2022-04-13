#ifndef CRUD_H_INCLUDED
#define CRUD_H_INCLUDED

// C STANDARD LIBRARY
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

// GLOBAL VARIABLE
typedef struct book{
    char name[100];
    char author[100];
    int year;
    char category[100];
    char created[100];
    char modified[100];
    struct book *next;
} book;

book *b, *head;

int totalBook;

time_t rawtime;
struct tm *timeInfo;

// SFML
#include "SFML/Graphics.h"
#include "SFML/Window.h"

// LOCAL HEADER
#include "create.h"
#include "edit.h"
#include "delete.h"

// FUNCTIONS
void clearScreen();
void pauseScreen();
char *timeToStr(struct tm *timeInfo);
void getDataFromFile();

#endif // CRUD_H_INCLUDED
