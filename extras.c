#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "extras.h"
#include "record.h"
#include "base.h"

// Function: optimize() //extra1
// Input: record
// Output: none
// data defragmentation
void optimize(Record records[]){
  Record temp[1000] = {"", 0, 0, 0};  //temp array
  int tempIdx = 0;  // temp Idx
  for(int i = 0; i < 1000; i++){
    if(records[i].used == 1){
      strcpy(temp[tempIdx].name, records[i].name);
      temp[tempIdx].year = records[i].year;
      temp[tempIdx].rating = records[i].rating;
      temp[tempIdx].used = 1;
      tempIdx++;
    }
  }

  init(records);  //initialzing the original array

  for(int i = 0; i < tempIdx; i++){  //recopying
      strcpy(records[i].name, temp[i].name);
      records[i].year = temp[i].year; 
      records[i].rating = temp[i].rating;
      records[i].used = 1;
  }

  /*
  // Testing loop
  for(int i = 0; records[i].year != 0; i++){
    printf("index: %d %s\n", i, records[i].name);
  }
  */
}

// Function: sort() //extra2
// Input: record
// Output: none
// sort the records in certain orders with quickSort
void sort(Record records[]){
  printf("\nHow do you want to sort?\n");
  printf("1.Name(alphabatic)\n2.Year\n3.Rating\n\n");
  int choice = 0;
  scanf("%d", &choice);
  while (getchar() != '\n');  //fflush 

  if(choice == 1) {
    optimize(records);  //need to optimize first
    sort_name(0, count(records)-1, records);  //using count return value
  }
  else if(choice == 2) {
    optimize(records);
    sort_year(0, count(records)-1, records);
  }
  else if(choice == 3) {
    optimize(records);
    sort_rating(0, count(records)-1, records);
  }
  else {
    printf("\nPlease choose the valid option!\n\n");
    return;
  }

  printf("\n:::::Succesully sorted!:::::\n\n");
}

// Function: sort_name
// Input: left, right, records
// Output: none
// quickSort by the name(alphabatic)
void sort_name(int left, int right, Record records[]){  //sort by name
  int pivot = left;
  int j = pivot;
  int i = left + 1;

  if(left < right){
    for(; i <=right; i++){
      if(records[i].name[0] < records[pivot].name[0]){
        j++;
        swap(&records[j], &records[i]);
      }
    }
    swap(&records[left], &records[j]);
    pivot = j;

    sort_name(left, pivot-1, records);
    sort_name(pivot+1, right, records);
  }
}

// Function: sort_year
// Input: left, right, records
// Output: none
// quickSort by the year
void sort_year(int left, int right, Record records[]){  //sort by name
  int pivot = left;
  int j = pivot;
  int i = left + 1;

  if(left < right){
    for(; i <=right; i++){
      if(records[i].year < records[pivot].year){
        j++;
        swap(&records[j], &records[i]);
      }
    }
    swap(&records[left], &records[j]);
    pivot = j;

    sort_year(left, pivot-1, records);
    sort_year(pivot+1, right, records);
  }
}

// Function: sort_rating
// Input: left, right, records
// Output: none
// quickSort by the rating
void sort_rating(int left, int right, Record records[]){  //sort by name
  int pivot = left;
  int j = pivot;
  int i = left + 1;

  if(left < right){
    for(; i <=right; i++){
      if(records[i].rating < records[pivot].rating){
        j++;
        swap(&records[j], &records[i]);
      }
    }
    swap(&records[left], &records[j]);
    pivot = j;

    sort_rating(left, pivot-1, records);
    sort_rating(pivot+1, right, records);
  }
}

// Function: swap 
// Input: record1, record2
// Output: none
// swap the content
void swap(Record* r1, Record* r2){
     Record r3;
     r3 = *r1;
     *r1 = *r2;
     *r2 = r3;
}

// Function: random() //extra3
// Input: record
// Output: none
// randomly recommend one movie for the user to watch!
void random_selection(Record records[]){
  srand(time(NULL));
  int randIdx = 0;
  while(1){
    randIdx = rand() % 1000;
    if(records[randIdx].used == 1) break;
  }
  printf("\nThe movie of the day!: \n[%s %d %d]\n\n", records[randIdx].name, records[randIdx].year, records[randIdx].rating);
}

// Function: count() //extra4
// Input: record
// Output: count numbers
// count the number of entries
int count(Record records[]){
  int cnt = 0;
  for(int i = 0; i < 1000; i++){
    if(records[i].used == 1) cnt++;
  }
  return cnt;
}

// Function: init() //extra5
// Input: record
// Output: none
// initialize every element
void init(Record records[]){
  for(int i = 0; i < 1000; i++){
    records[i].name[0] = '\0';
    records[i].year = 0;
    records[i].rating = 0;
    records[i].used = 0;  //initializing 
  }
}
