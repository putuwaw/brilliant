#include "crud.h"

char tempName[100], tempAuthor[100], tempCategory[100], tempCreated[100], tempModified[100], tempChYear;

void clearScreen(){
    system("cls");
}
void pauseScreen(){
    printf("Silakan tekan ENTER untuk melanjutkan...\n");
    getchar();
}
char *timeToStr(struct tm *timeInfo){
    static const char weekDay[][7] = {
        "Minggu", "Senin", "Selasa", "Rabu", "Kamis", "Jumat", "Sabtu"};
    static const char monthDay[][10] = {
        "Januari", "Februari", "Maret", "April", "Mei", "Juni",
        "Juli", "Agustus", "September", "Oktober", "November", "Desember"};
    static char timeResult[38];
    sprintf(timeResult, "%.2d:%.2d:%.2d - %s, %d %s %d",
            timeInfo->tm_hour,
            timeInfo->tm_min,
            timeInfo->tm_sec,
            weekDay[timeInfo->tm_wday],
            timeInfo->tm_mday,
            monthDay[timeInfo->tm_mon],
            1900 + timeInfo->tm_year);
    return timeResult;
}
void getDataFromFile(){

    int tempYear = 0, counter = 0, section = 0;

    head = NULL;
    totalBook = 0;

    FILE *f;
    f = fopen("data/book.txt", "r");
    char currentCh;

    while(!feof(f)){
        currentCh = fgetc(f);
        if (currentCh == '|'){
            section++;
            counter = 0;
        }
        else if (currentCh == '\n'){
            // ADD NEW NODE
            b = (book*)malloc(sizeof(book));
            strcpy(b->name, tempName);
            strcpy(b->author, tempAuthor);
            b->year = tempYear;
            strcpy(b->category, tempCategory);
            strcpy(b->created, tempCreated);
            strcpy(b->modified, tempModified);
            b->next = NULL;
            if (head == NULL){
                head = b;
            }
            else{
                book *curr;
                curr = head;
                while(curr->next != NULL){
                    curr = curr->next;
                }
                curr->next = b;
            }
            totalBook++;
            // RESET
            counter = section = tempYear = 0;
            memset(tempName, 0, sizeof(tempName));
            memset(tempAuthor, 0, sizeof(tempAuthor));
            memset(tempCategory, 0, sizeof(tempCategory));
            memset(tempCreated, 0, sizeof(tempCreated));
            memset(tempModified, 0, sizeof(tempModified));
        }
        else{
            if (section == 0){
                tempName[counter] = currentCh;
            }
            else if (section == 1){
                tempAuthor[counter] = currentCh;
            }
            else if (section == 2){
                tempChYear = currentCh;
                int tempIYear = tempChYear - '0';
                tempYear = (tempYear * 10) + tempIYear;
            }
            else if (section == 3){
                tempCategory[counter] = currentCh;
            }
            else if (section == 4){
                tempCreated[counter] = currentCh;
            }
            else if (section == 5){
                tempModified[counter] = currentCh;
            }
            counter++;
        }
    }
}

