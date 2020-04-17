#ifndef _RECORD_H_
#define _RECORD_H_

// type defition
typedef struct{
  char name[30];
  int year;
  int rating;
  int used; // 0 if available
} Record;

#endif
