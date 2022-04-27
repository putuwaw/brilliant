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
    static const char weekDay[][10] = {
        "Minggu", "Senin", "Selasa", "Rabu", "Kamis", "Jumat", "Sabtu"};
    static const char monthDay[][15] = {
        "Januari", "Februari", "Maret", "April", "Mei", "Juni",
        "Juli", "Agustus", "September", "Oktober", "November", "Desember"};
    static char timeResult[50];
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
char *yearToStr(int year){
    static char yearResult[7];
    sprintf(yearResult, "- %d", year);
    return yearResult;
}
char *numToStr(int num){
    static char strResult[7];
    sprintf(strResult, "%d", num);
    return strResult;
}
void resetString(char *str, int len){
    int idx;
    for (idx = 0; idx < len; idx++){
        str[idx] = '\0';
    }
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
            resetString(tempName,100);
            resetString(tempAuthor,100);
            resetString(tempCategory,100);
            resetString(tempCreated,100);
            resetString(tempModified,100);
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
