#ifndef _BASE_H_
#define _BASE_H_

#include "record.h"

// function prototypes
void create_file(Record[]); //add()
void create_keyboard(Record[]); //import()
void print_all_records(Record[]); //print_all()
void read_search(Record[]);  //search()
void read_load(Record[]); //load()
void read_save(Record[]); //save()
void read_report(Record[]); //export()
void update(Record[]); // update()
void update_single(Record[]);
void update_multi(Record[]);
void delete_single(Record[]); //delete_siingle()
void delete_multi(Record[]);  //delete_mutil()

void optimize(Record[]);  //extra1
void sort(Record[]);  //extra2
void sort_name(int, int, Record[]);  //extra2-1
void sort_year(int, int, Record[]);  //extra2-2
void sort_rating(int, int, Record[]);  //extra2-3
void swap(Record*, Record*); // swap
void random_selection(Record[]); //extra3
int count(Record[]); //extra4
void init(Record[]);  //extra5

int check(Record[], char[], int, int);

#endif
