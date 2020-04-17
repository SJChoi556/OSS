#ifndef _EXTRAS_H_
#define _EXTRAS_H_

#include "record.h"
#include "base.h"

// function prototypes
void optimize(Record[]);  //extra1
void sort(Record[]);  //extra2
void sort_name(int, int, Record[]);  //extra2-1
void sort_year(int, int, Record[]);  //extra2-2
void sort_rating(int, int, Record[]);  //extra2-3
void swap(Record*, Record*); // swap
void random_selection(Record[]); //extra3
int count(Record[]); //extra4
void init(Record[]);  //extra5

#endif
