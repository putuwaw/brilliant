#ifndef VIEW_H_INCLUDED
#define VIEW_H_INCLUDED

#include "crud.h"

void lihat_data_normal();

// SEARCH
void draw_view_search(book *headSearch, int bookFound, int cat);
void draw_view_sort(book *headSort, int bookFound, int cat);
void lihat_cari_nama();
void lihat_cari_author();
void lihat_cari_year();
void lihat_cari_cat();
void lihat_sort_nama();
void lihat_sort_author();
void lihat_sort_year();
void lihat_sort_cat();

#endif // VIEW_H_INCLUDED
