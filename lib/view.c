#include "view.h"

void lihat_data_normal(){
    // SFML VARIABLE
    sfRenderWindow *window;
    sfTexture *texture;
    sfSprite *sprite;
    sfFont *font;
    sfText *textNum, *textAuthor, *textName, *textCategory, *textCreated, *textModified, *textYear;
    sfEvent event;
    sfVector2i mousePos;

    // LOCAL VARIABLE
    book *temp;
    int countMaxBook, maxPage, page, maxNum, minNum, counterNum;
    countMaxBook = totalBook;
    maxPage = 0;
    while(countMaxBook > 0){
        countMaxBook -= 5;
        maxPage++;
    }
    page = 1;
    maxNum = page * 5;
    minNum = maxNum - 4;

    // TEXTURE AND SPRITE
    texture = sfTexture_createFromFile("assets/image/View-Blank Design.png", NULL);

    // FONT
    font = sfFont_createFromFile("assets/font/Roboto-Regular.ttf");

    // WINDOW
    sfVideoMode mode = {1280, 720, 30};
    window = sfRenderWindow_create(mode, "Brilliant", sfResize | sfClose, NULL);

    // FRAME LIMIT
    sfRenderWindow_setFramerateLimit(window, 30);

    while (sfRenderWindow_isOpen(window)){
    // SPRITE
    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    // MOUSE POSITION
    mousePos = sfMouse_getPositionRenderWindow(window);
        // EVENT
        while (sfRenderWindow_pollEvent(window, & event)) {
            if (event.type == sfEvtClosed){
                sfRenderWindow_close(window);
            }
            // MOUSE CONTROL
            if (sfMouse_isButtonPressed(sfMouseLeft)){
                // EXIT
                if (mousePos.x > 0 && mousePos.x < 120 && mousePos.y > 0 && mousePos.y < 80){
                    sfRenderWindow_close(window);
                }
                // PREV PAGE
                else if (mousePos.x > 0 && mousePos.x < 60 && mousePos.y > 670 && mousePos.y < 720){
                    if (page > 1){
                        page--;
                    }
                }
                // NEXT PAGE
                else if (mousePos.x > 1220 && mousePos.x < 1280 && mousePos.y > 670 && mousePos.y < 720){
                    if (page < maxPage){
                        page++;
                    }
                }
            }
        }
        maxNum = page * 5;
        minNum = maxNum - 4;
        // CLEAR SCREEN
        sfRenderWindow_clear(window, sfBlack);

        // DRAW SPRITE
        sfRenderWindow_drawSprite(window, sprite, NULL);

        if (totalBook > 0){
            // NUMBERING
            sfVector2f strNumberPos;
            strNumberPos.x = 80;
            strNumberPos.y = 140;
            char *strNumber;
            counterNum = 1;
            while(counterNum < minNum){
                counterNum++;
            }
            while(counterNum <= maxNum){
                strNumber = numToStr(counterNum);
                textNum = sfText_create();
                sfText_setFont(textNum, font);
                sfText_setString(textNum, strNumber);
                sfText_setCharacterSize(textNum, 20);
                sfText_setPosition(textNum, strNumberPos);
                sfText_setColor(textNum, sfBlack);
                strNumberPos.y += 113;
                sfRenderWindow_drawText(window, textNum, NULL);
                sfText_destroy(textNum);
                counterNum++;
            }

            // AUTHOR
            sfVector2f authorPos;
            authorPos.x = 190;
            authorPos.y = 130;
            temp = head;
            counterNum = 1;
            while(counterNum < minNum){
                temp = temp->next;
                counterNum++;
                if (temp == NULL){
                    break;
                }
            }
            while(counterNum <= maxNum){
                textAuthor = sfText_create();
                sfText_setFont(textAuthor, font);
                sfText_setString(textAuthor, temp->author);
                sfText_setCharacterSize(textAuthor, 20);
                sfText_setPosition(textAuthor, authorPos);
                sfText_setColor(textAuthor, sfBlack);
                authorPos.y += 113;
                sfRenderWindow_drawText(window, textAuthor, NULL);
                sfText_destroy(textAuthor);
                temp = temp->next;
                counterNum++;
                if (temp == NULL){
                    break;
                }
            }

            // TITLE
            sfVector2f namePos;
            namePos.x = 190;
            namePos.y = 150;
            temp = head;
            counterNum = 1;
            while(counterNum < minNum){
                temp = temp->next;
                counterNum++;
                if (temp == NULL){
                    break;
                }
            }
            while(counterNum <= maxNum){
                textName = sfText_create();
                sfText_setFont(textName, font);
                sfText_setString(textName, temp->name);
                sfText_setCharacterSize(textName, 20);
                sfText_setPosition(textName, namePos);
                sfText_setColor(textName, sfBlack);
                namePos.y += 113;
                sfRenderWindow_drawText(window, textName, NULL);
                sfText_destroy(textName);
                temp = temp->next;
                counterNum++;
                if (temp == NULL){
                    break;
                }
            }

            // CATEGORY
            sfVector2f categoryPos;
            categoryPos.x = 190;
            categoryPos.y = 170;
            temp = head;
            counterNum = 1;
            while(counterNum < minNum){
                temp = temp->next;
                counterNum++;
                if (temp == NULL){
                    break;
                }
            }
            while(counterNum <= maxNum){
                textCategory = sfText_create();
                sfText_setFont(textCategory, font);
                sfText_setString(textCategory, temp->category);
                sfText_setCharacterSize(textCategory, 20);
                sfText_setPosition(textCategory, categoryPos);
                sfText_setColor(textCategory, sfBlack);
                categoryPos.y += 113;
                sfRenderWindow_drawText(window, textCategory, NULL);
                sfText_destroy(textCategory);
                temp = temp->next;
                counterNum++;
                if (temp == NULL){
                    break;
                }
            }

            // YEAR
            sfVector2f yearPos;
            yearPos.x = 300;
            yearPos.y = 173;
            temp = head;
            counterNum = 1;
            while(counterNum < minNum){
                temp = temp->next;
                counterNum++;
                if (temp == NULL){
                    break;
                }
            }
            while(counterNum <= maxNum){
                textYear = sfText_create();
                sfText_setFont(textYear, font);
                char *strYear = yearToStr(temp->year);
                sfText_setString(textYear, strYear);
                sfText_setCharacterSize(textYear, 20);
                sfText_setPosition(textYear, yearPos);
                sfText_setColor(textYear, sfBlack);
                yearPos.y += 113;
                sfRenderWindow_drawText(window, textYear, NULL);
                sfText_destroy(textYear);
                temp = temp->next;
                counterNum++;
                if (temp == NULL){
                    break;
                }
            }

            // CREATED
            sfVector2f createdPos;
            createdPos.x = 900;
            createdPos.y = 125;
            temp = head;
            counterNum = 1;
            while(counterNum < minNum){
                temp = temp->next;
                counterNum++;
                if (temp == NULL){
                    break;
                }
            }
            while(counterNum <= maxNum){
                textCreated = sfText_create();
                sfText_setFont(textCreated, font);
                sfText_setString(textCreated, temp->created);
                sfText_setCharacterSize(textCreated, 17);
                sfText_setPosition(textCreated, createdPos);
                sfText_setColor(textCreated, sfBlack);
                createdPos.y += 113;
                sfRenderWindow_drawText(window, textCreated, NULL);
                sfText_destroy(textCreated);
                temp = temp->next;
                counterNum++;
                if (temp == NULL){
                    break;
                }
            }

            // MODIFIED
            sfVector2f modifiedPos;
            modifiedPos.x = 900;
            modifiedPos.y = 170;
            temp = head;
            counterNum = 1;
            while(counterNum < minNum){
                temp = temp->next;
                counterNum++;
                if (temp == NULL){
                    break;
                }
            }
            while(counterNum <= maxNum){
                textModified = sfText_create();
                sfText_setFont(textModified, font);
                sfText_setString(textModified, temp->modified);
                sfText_setCharacterSize(textModified, 17);
                sfText_setPosition(textModified, modifiedPos);
                sfText_setColor(textModified, sfBlack);
                modifiedPos.y += 113;
                sfRenderWindow_drawText(window, textModified, NULL);
                sfText_destroy(textModified);
                temp = temp->next;
                counterNum++;
                if (temp == NULL){
                    break;
                }
            }
        }
        // UPDATE WINDOW
        sfRenderWindow_display(window);

        // CLEAN UP
        sfSprite_destroy(sprite);
    }
    // OTHER CLEAN UP
    sfFont_destroy(font);
    sfRenderWindow_destroy(window);
    sfTexture_destroy(texture);
}

void draw_view_search(book *headSearch, int bookFound, int cat){
    // SFML VARIABLE
    sfRenderWindow *window;
    sfTexture *texture;
    sfSprite *sprite;
    sfFont *font;
    sfText *textNum, *textAuthor, *textName, *textCategory, *textCreated, *textModified, *textYear, *textTitle;
    sfEvent event;
    sfVector2i mousePos;

    // LOCAL VARIABLE
    book *temp;
    int countMaxBook, maxPage, page, maxNum, minNum, counterNum;
    countMaxBook = bookFound;
    maxPage = 0;
    while(countMaxBook > 0){
        countMaxBook -= 5;
        maxPage++;
    }
    page = 1;
    maxNum = page * 5;
    minNum = maxNum - 4;

    // TEXTURE AND SPRITE
    texture = sfTexture_createFromFile("assets/image/Search Design.png", NULL);

    // FONT
    font = sfFont_createFromFile("assets/font/Roboto-Regular.ttf");

    // WINDOW
    sfVideoMode mode = {1280, 720, 30};
    window = sfRenderWindow_create(mode, "Brilliant", sfResize | sfClose, NULL);

    // FRAME LIMIT
    sfRenderWindow_setFramerateLimit(window, 30);
    while (sfRenderWindow_isOpen(window)){
    // SPRITE
    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    // MOUSE POSITION
    mousePos = sfMouse_getPositionRenderWindow(window);
        // EVENT
        while (sfRenderWindow_pollEvent(window, & event)) {
            if (event.type == sfEvtClosed){
                sfRenderWindow_close(window);
            }
            // MOUSE CONTROL
            else if (sfMouse_isButtonPressed(sfMouseLeft)){
                // PREV PAGE
                if (mousePos.x > 0 && mousePos.x < 60 && mousePos.y > 670 && mousePos.y < 720){
                    if (page > 1){
                        page--;
                    }
                }
                // NEXT PAGE
                else if (mousePos.x > 1220 && mousePos.x < 1280 && mousePos.y > 670 && mousePos.y < 720){
                    if (page < maxPage){
                        page++;
                    }
                }
            }
        }
        maxNum = page * 5;
        minNum = maxNum - 4;
        // CLEAR SCREEN
        sfRenderWindow_clear(window, sfBlack);

        // DRAW SPRITE
        sfRenderWindow_drawSprite(window, sprite, NULL);

        if (bookFound > 0){
            // TITLE
            sfVector2f titlePos;
            titlePos.x = 188;
            titlePos.y = 4;
            textTitle = sfText_create();
            sfText_setFont(textTitle, font);
            if(cat == 1){
                sfText_setString(textTitle, headSearch->name);
            }
            else if(cat == 2){
                sfText_setString(textTitle, headSearch->author);
            }
            sfText_setCharacterSize(textTitle, 33);
            sfText_setPosition(textTitle, titlePos);
            sfText_setColor(textTitle, sfRed);
            sfRenderWindow_drawText(window, textTitle, NULL);
            sfText_destroy(textTitle);

            // NUMBERING
            sfVector2f strNumberPos;
            strNumberPos.x = 80;
            strNumberPos.y = 140;
            char *strNumber;
            counterNum = 1;
            while(counterNum < minNum){
                counterNum++;
            }
            while(counterNum <= maxNum){
                strNumber = numToStr(counterNum);
                textNum = sfText_create();
                sfText_setFont(textNum, font);
                sfText_setString(textNum, strNumber);
                sfText_setCharacterSize(textNum, 20);
                sfText_setPosition(textNum, strNumberPos);
                sfText_setColor(textNum, sfBlack);
                strNumberPos.y += 113;
                sfRenderWindow_drawText(window, textNum, NULL);
                sfText_destroy(textNum);
                counterNum++;
            }

            // AUTHOR
            sfVector2f authorPos;
            authorPos.x = 190;
            authorPos.y = 130;
            temp = headSearch;
            counterNum = 1;
            while(counterNum < minNum){
                temp = temp->next;
                counterNum++;
                if (temp == NULL){
                    break;
                }
            }
            while(counterNum <= maxNum){
                textAuthor = sfText_create();
                sfText_setFont(textAuthor, font);
                sfText_setString(textAuthor, temp->author);
                sfText_setCharacterSize(textAuthor, 20);
                sfText_setPosition(textAuthor, authorPos);
                sfText_setColor(textAuthor, sfBlack);
                authorPos.y += 113;
                sfRenderWindow_drawText(window, textAuthor, NULL);
                sfText_destroy(textAuthor);
                temp = temp->next;
                counterNum++;
                if (temp == NULL){
                    break;
                }
            }

            // TITLE
            sfVector2f namePos;
            namePos.x = 190;
            namePos.y = 150;
            temp = headSearch;
            counterNum = 1;
            while(counterNum < minNum){
                temp = temp->next;
                counterNum++;
                if (temp == NULL){
                    break;
                }
            }
            while(counterNum <= maxNum){
                textName = sfText_create();
                sfText_setFont(textName, font);
                sfText_setString(textName, temp->name);
                sfText_setCharacterSize(textName, 20);
                sfText_setPosition(textName, namePos);
                sfText_setColor(textName, sfBlack);
                namePos.y += 113;
                sfRenderWindow_drawText(window, textName, NULL);
                sfText_destroy(textName);
                temp = temp->next;
                counterNum++;
                if (temp == NULL){
                    break;
                }
            }

            // CATEGORY
            sfVector2f categoryPos;
            categoryPos.x = 190;
            categoryPos.y = 170;
            temp = headSearch;
            counterNum = 1;
            while(counterNum < minNum){
                temp = temp->next;
                counterNum++;
                if (temp == NULL){
                    break;
                }
            }
            while(counterNum <= maxNum){
                textCategory = sfText_create();
                sfText_setFont(textCategory, font);
                sfText_setString(textCategory, temp->category);
                sfText_setCharacterSize(textCategory, 20);
                sfText_setPosition(textCategory, categoryPos);
                sfText_setColor(textCategory, sfBlack);
                categoryPos.y += 113;
                sfRenderWindow_drawText(window, textCategory, NULL);
                sfText_destroy(textCategory);
                temp = temp->next;
                counterNum++;
                if (temp == NULL){
                    break;
                }
            }

            // YEAR
            sfVector2f yearPos;
            yearPos.x = 300;
            yearPos.y = 173;
            temp = headSearch;
            counterNum = 1;
            while(counterNum < minNum){
                temp = temp->next;
                counterNum++;
                if (temp == NULL){
                    break;
                }
            }
            while(counterNum <= maxNum){
                textYear = sfText_create();
                sfText_setFont(textYear, font);
                char *strYear = yearToStr(temp->year);
                sfText_setString(textYear, strYear);
                sfText_setCharacterSize(textYear, 20);
                sfText_setPosition(textYear, yearPos);
                sfText_setColor(textYear, sfBlack);
                yearPos.y += 113;
                sfRenderWindow_drawText(window, textYear, NULL);
                sfText_destroy(textYear);
                temp = temp->next;
                counterNum++;
                if (temp == NULL){
                    break;
                }
            }

            // CREATED
            sfVector2f createdPos;
            createdPos.x = 900;
            createdPos.y = 125;
            temp = headSearch;
            counterNum = 1;
            while(counterNum < minNum){
                temp = temp->next;
                counterNum++;
                if (temp == NULL){
                    break;
                }
            }
            while(counterNum <= maxNum){
                textCreated = sfText_create();
                sfText_setFont(textCreated, font);
                sfText_setString(textCreated, temp->created);
                sfText_setCharacterSize(textCreated, 17);
                sfText_setPosition(textCreated, createdPos);
                sfText_setColor(textCreated, sfBlack);
                createdPos.y += 113;
                sfRenderWindow_drawText(window, textCreated, NULL);
                sfText_destroy(textCreated);
                temp = temp->next;
                counterNum++;
                if (temp == NULL){
                    break;
                }
            }
            // MODIFIED
            sfVector2f modifiedPos;
            modifiedPos.x = 900;
            modifiedPos.y = 170;
            temp = headSearch;
            counterNum = 1;
            while(counterNum < minNum){
                temp = temp->next;
                counterNum++;
                if (temp == NULL){
                    break;
                }
            }
            while(counterNum <= maxNum){
                textModified = sfText_create();
                sfText_setFont(textModified, font);
                sfText_setString(textModified, temp->modified);
                sfText_setCharacterSize(textModified, 17);
                sfText_setPosition(textModified, modifiedPos);
                sfText_setColor(textModified, sfBlack);
                modifiedPos.y += 113;
                sfRenderWindow_drawText(window, textModified, NULL);
                sfText_destroy(textModified);
                temp = temp->next;
                counterNum++;
                if (temp == NULL){
                    break;
                }
            }
        }
        // UPDATE WINDOW
        sfRenderWindow_display(window);

        // CLEAN UP
        sfSprite_destroy(sprite);
    }
    // OTHER CLEAN UP
    sfFont_destroy(font);
    sfRenderWindow_destroy(window);
    sfTexture_destroy(texture);
    free(temp);
    temp = NULL;
}

void lihat_cari_nama(){
    int cat = 1;
    char nameSearch[100];
    // RESET
    resetString(nameSearch, 100);
    // SEARCH
    int bookFound = 0;
    book *headNameSearch, *curr, *temp;
    bool isFound = false;
    headNameSearch = NULL;
    fflush(stdin);
    printf("Masukkan nama buku yang akan dicari: ");
    gets(nameSearch);
    curr = head;
    while(curr != NULL){
        if (strcmp(nameSearch, curr->name) == 0){
            isFound = true;
            bookFound++;
            // COPY TO TEMP
            temp = (book*)malloc(sizeof(book));
            strcpy(temp->name, curr->name);
            strcpy(temp->author, curr->author);
            temp->year = curr->year;
            strcpy(temp->category, curr->category);
            strcpy(temp->created, curr->created);
            strcpy(temp->modified, curr->modified);
            temp->next = NULL;
            if (headNameSearch == NULL){
                headNameSearch = temp;
            }
            else{
                book *prev;
                prev = headNameSearch;
                while(prev->next != NULL){
                    prev = prev->next;
                }
                prev->next = temp;
            }
        }
        curr = curr->next;
    }
    // GUI - SFML
    if (isFound){
        draw_view_search(headNameSearch, bookFound, cat);
        // DELETE
        book *del;
        del = headNameSearch;
        while(del->next != NULL){
            headNameSearch = del->next;
            free(del);
            del = headNameSearch;
        }
        free(del);
        headNameSearch = NULL;
    }
    else{
        printf("Tidak ada buku dengan nama \"%s\" ditemukan!\n", nameSearch);
    }
}

void lihat_cari_author(){
    int cat = 2;
    char authorSearch[100];
    //RESET
    resetString(authorSearch, 100);
    //SEARCH
    int bookFound = 0;
    book *headAuthorSearch, *curr, *temp;
    bool isFound = false;
    headAuthorSearch = NULL;
    fflush(stdin);
    printf("Masukkan nama author yang akan dicari: ");
    gets(authorSearch);
    curr = head;
    while(curr!=NULL){
        if(strcmp(authorSearch, curr->author) == 0){
            isFound = true;
            bookFound++;
            temp = (book*)malloc(sizeof(book));
            strcpy(temp->name, curr->name);
            strcpy(temp->author, curr->author);
            temp->year = curr->year;
            strcpy(temp->category, curr->category);
            strcpy(temp->created, curr->created);
            strcpy(temp->modified, curr->modified);
            temp->next = NULL;
            if(headAuthorSearch == NULL){
                headAuthorSearch = temp;
            }
            else{
                book *prev;
                prev = headAuthorSearch;
                while(prev->author != NULL){
                    prev = prev->next;
                }
                prev->next = temp;
            }
        }
        curr = curr->next;
    }

    if (isFound){
        draw_view_search(headAuthorSearch, bookFound, cat);
        book *del;
        del = headAuthorSearch;
        while(del->next != NULL){
            headAuthorSearch = del->next;
            free(del);
            del = headAuthorSearch;
        }
        free(del);
        headAuthorSearch = NULL;
    }
    else{
        printf("Tidak ada buku dengan author \"%s\" ditemukan!\n", authorSearch);
    }
}
