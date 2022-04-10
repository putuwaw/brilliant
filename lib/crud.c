#include "crud.h"

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
