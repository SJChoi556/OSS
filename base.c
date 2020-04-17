#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "extras.h"
#include "record.h"
#include "extras.h"

// Function: print_all_records()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: none
// print all the valid records
void print_all_records(Record records[]){
	printf("\n[NAME - YEAR - Rating]\n");
  for(int i = 0; i < 1000; i++){
    if(records[i].used == 1) printf("%s - %d - %d\n", records[i].name, records[i].year, records[i].rating); // checking wether the element is valid
  }
  printf("\n");
}

// Function: add_a_record()
// Input: record
// Output: none
// add a record from the file
void create_file(Record records[]){
  char buffer[40], tempName[30];
  int tempYear = 0, tempRating = 0;
  FILE *fp = fopen("data.txt", "r");
  fgets(buffer, sizeof(buffer), fp);
  sscanf(buffer, "%s %d %d\n", tempName, &tempYear, &tempRating);
  if(check(records, tempName, tempYear, tempRating) == -1) printf(":::::Error!:::::\n\n");
  else printf("\n:::::Sucessfully loaded!:::::\n\n");  
  fclose(fp); 
}

// Function: add_a_record()
// Input: record
// Output: none
// add a record from the keyboard
void create_keyboard(Record records[]){
  char tempName[30];
  int tempYear;
  int tempRating;
  
  printf("\nInput the data in a correct format - (NAME(no space)_YEAR_RATING)\n");
  printf("[Name: less than 30 char | Year: 1900 ~ 2020 | Rating: 0 ~ 10]\n\nYour input: ");
  scanf("%s %d %d", tempName, &tempYear, &tempRating);
  while (getchar() != '\n');  //fflush 

if(check(records, tempName, tempYear, tempRating) == -1) printf(":::::Error!:::::\n\n");
else printf("\n:::::Sucessfully added!:::::\n\n");
}

// Function: check()
// Input: record, inputName, inputYear, inputRating
// Output: -1(if wrong), 1(if correct)
// cehck wether the input is valid or not, if correct, put the value in
int check(Record records[], char tempName[], int tempYear, int tempRating){
  for(int i = 0; i < 1000; i++){  // duplication checking(name, year)
    if(strcmp(records[i].name, tempName) == 0 && records[i].year == tempYear){
      printf("\n:::::Duplications!:::::\n\n");
      return -1;
    }
  }
  
  if(tempYear >= 1900 && tempYear <= 2020 && tempRating >= 0 && tempRating <= 10){
    for(int i = 0; i < 1000; i++){
      if(records[i].used == 0){
        strcpy(records[i].name, tempName);
        records[i].year = tempYear;
        records[i].rating = tempRating;
        records[i].used = 1;
        break;
      }
    }
    printf("\n");
  }
  else{
    printf(":::::Format Incorrect!:::::\n\n");
    return -1;
  }
  return 1;
}

// Function: read_search()
// Input: record
// Output: none
// print the records according to the user's preference
void read_search(Record records[]){
  char tempName[30];
  int tempYear = 0, tempRating = 0;
  printf("\nPlease enter the information.\n");
  printf("Input '0' if it doesn't matter.\n");
  printf("\nMovie Name(no space): ");
  scanf("%s", tempName);
  printf("Production Year: ");
  scanf("%d", &tempYear);
  printf("Rating: ");
  scanf("%d", &tempRating);
  while (getchar() != '\n');  //fflush 

  if(tempName[0] == '0' && tempYear == 0 && tempRating == 0){
    print_all_records(records);
  }
  else if(tempName[0] != '0' && tempYear == 0 && tempRating == 0){
    printf("\n\n[NAME - YEAR - Rating]\n");
    for(int i = 0; i < 1000; i++){
      if(records[i].used == 1 && strcmp(records[i].name, tempName) == 0) printf("%s - %d - %d\n", records[i].name, records[i].year, records[i].rating);
    }
  }
  else if(tempName[0] == '0' && tempYear != 0 && tempRating == 0){
    printf("\n\n[NAME - YEAR - Rating]\n");
    for(int i = 0; i < 1000; i++){
      if(records[i].used == 1 && records[i].year == tempYear) printf("%s - %d - %d\n", records[i].name, records[i].year, records[i].rating);
    }
  }
  else if(tempName[0] == '0' && tempYear == 0 && tempRating != 0){
    printf("\n\n[NAME - YEAR - Rating]\n");
    for(int i = 0; i < 1000; i++){
      if(records[i].used == 1 && records[i].rating == tempRating) printf("%s - %d - %d\n", records[i].name, records[i].year, records[i].rating);
    }
  }
  else if(tempName[0] != '0' && tempYear != 0){
    printf("\n\n[NAME - YEAR - Rating]\n");
    for(int i = 0; i < 1000; i++){
      if(records[i].used == 1 && strcmp(records[i].name, tempName) == 0 && records[i].year == tempYear) printf("%s - %d - %d\n", records[i].name, records[i].year, records[i].rating);
    }
  }
  else if(tempName[0] != '0' && tempYear == 0 && tempRating != 0){
    printf("\n\n[NAME - YEAR - Rating]\n");
    for(int i = 0; i < 1000; i++){
      if(records[i].used == 1 && strcmp(records[i].name, tempName) == 0 && records[i].rating == tempRating) printf("%s - %d - %d\n", records[i].name, records[i].year, records[i].rating);
    }
  }
  else if(tempName[0] == '0' && tempYear != 0 && tempRating != 0){
    printf("\n\n[NAME - YEAR - Rating]\n");
    for(int i = 0; i < 1000; i++){
      if(records[i].used == 1 && records[i].year == tempYear && records[i].rating == tempRating) printf("%s - %d - %d\n", records[i].name, records[i].year, records[i].rating);
    }
  }
}

// Function: read_load()
// Input: record
// Output: none
// load a data file
void read_load(Record records[]){
  char buffer[40];
  int i = 0;
  FILE *fp = fopen("save.txt", "r");
  init(records); // reset the current array

  while(1){
    fgets(buffer, sizeof(buffer), fp);
    if(feof(fp) || i >= 1000) break;
    sscanf(buffer, "%s %d %d\n", records[i].name, &records[i].year, &records[i].rating);
    records[i].used = 1;
    i++;
  }

  printf("\n:::::Succesully loaded!:::::\n\n");
  fclose(fp); 
}

// Function: read_save()
// Input: record
// Output: none
// save the records as a normal data file
void read_save(Record records[]){
  FILE *fp = fopen("save.txt", "w");
  for(int i = 0; i < 1000; i++){
    if(records[i].used == 1){
      fprintf(fp, "%s %d %d\n", records[i].name, records[i].year, records[i].rating);
    }
  }
  printf("\n:::::Succesully saved!:::::\n\n");
  fclose(fp);
}

// Function: read_report()
// Input: record
// Output: none
// save the recrods into the formal report format
void read_report(Record records[]){
  FILE *fp = fopen("report.txt", "w");
  for(int i = 0; i < 1000; i++){
    if(records[i].used == 1){
      fprintf(fp, "==================================\nNAME: %s  |  YEAR : %d\n——————————————————————————————————\nRATING: %d\n==================================\n", records[i].name, records[i].year, records[i].rating);
    }
  }

  printf("\n:::::Succesully exported!:::::\n\n");

  fclose(fp);
}

// Function: update()
// Input: record
// Output: none
// update (conditionally) data records
void update(Record records[]){
  int choice = 0;
  printf("\nDo you want to update a single or mutliple records?\n1.Single\n2.Multiple\n\n");
  scanf("%d", &choice);
  while (getchar() != '\n');  //fflush 

  if(choice == 1) update_single(records);
  else if(choice == 2) update_multi(records);
  else {
    printf("\nPlease choose the valid option!\n\n");
    return;
  }
}

// Function: update_single()
// Input: record
// Output: none
// update a single data record
void update_single(Record records[]){
  char updateName[30] = "";
  int updateYear = 0, updateRating = 0;
  int idx = 0;  //updating data record index
  
  printf("\nSearch Inforamation - (NAME(no space)_YEAR)\n");
  scanf("%s %d", updateName, &updateYear);
  while (getchar() != '\n');  //fflush 
  
  for(int i = 0; i < 1000; i++){
    if(i == 999){
      printf("\nNot found!\n\n");
      return;
    }
    if(records[i].used == 1 && strcmp(records[i].name, updateName) == 0 && records[i].year == updateYear){
      idx = i;
      break;
    }
  }

  printf("\nChange Inforamation - (NAME(no space)_YEAR_RATING)\n\n");
  scanf("%s %d %d", updateName, &updateYear, &updateRating);
  while (getchar() != '\n');  //fflush 

  if(updateYear < 1900 || updateYear > 2020 || updateRating < 0 || updateRating > 10){  // validity checking
    printf("\nInvalid Input!\n\n");
    return;
  }
  
  for(int i = 0; i < 1000; i++){  // duplication checking
    if(records[i].used == 1 && strcmp(records[i].name, updateName) == 0 && records[i].year == updateYear){
      printf("\nDuplication!\n\n");
      return;
    }
  }

  strcpy(records[idx].name, updateName);
  records[idx].year = updateYear;
  records[idx].rating = updateRating;
  printf("\n:::::Succesully updated!:::::\n\n");
}

// Function: update_multi()
// Input: record
// Output: none
// update multiple data records
void update_multi(Record records[]){
  char updateName[30] = "";
  int updateYear = 0, updateRating = 0;
  int choice = 0;

  printf("\n1.Change ratings of Movies with the same name.\n2.Change ratings of Movies released in the same year.\n\n");
  scanf("%d", &choice);
  while (getchar() != '\n');  //fflush 

  if(choice == 1){
    printf("\nMovie Name(no space): ");
    scanf("%s", updateName);
    
    printf("Changing Ratings: ");
    scanf("%d", &updateRating);
    while (getchar() != '\n');  //fflush 

    if(updateRating < 0 || updateRating > 10){  // validity checking
      printf("\nInvalid Input!\n\n");
      return;
    }

    for(int i = 0; i < 1000; i++){
      if(records[i].used == 1 && strcmp(records[i].name, updateName) == 0) records[i].rating = updateRating;
    }
  }
  else if(choice == 2){
    printf("\nYear: ");
    scanf("%d", &updateYear);
    
    printf("Changing Ratings: ");
    scanf("%d", &updateRating);
    while (getchar() != '\n');  //fflush 

    if(updateRating < 0 || updateRating > 10){  // validity checking
      printf("\nInvalid Input!\n\n");
      return;
    }

    for(int i = 0; i < 1000; i++){
      if(records[i].used == 1 && records[i].year == updateYear) records[i].rating = updateRating;
    }
  }
  else printf("\nInvalid option!\n\n");

  printf("\n:::::Succesully updated!:::::\n\n");
}

// Function: delete_single()
// Input: record
// Output: none
// delete a sinlge data record
void delete_single(Record records[]){
  char deleteName[30];
  int deleteYear;
  printf("\nPlease enter the movie info you want to delete.\n");
  printf("\nMovie Name(no space): ");
  scanf("%s", deleteName);
  printf("Production Year: ");
  scanf("%d", &deleteYear);
  while (getchar() != '\n');  //fflush 
  
  for(int i = 0; i <  1000; i++){
    if(i == 999) {
      printf("\n:::::No such data found!:::::\n\n");
      break;
    }
    if(records[i].used == 1 && strcmp(deleteName, records[i].name) == 0 && deleteYear == records[i].year){
      records[i].name[0] = '\0';
      records[i].year = 0;
      records[i].rating = 0;
      records[i].used = 0;
      printf("\n:::::Succesully deleted!:::::\n\n");
      break;
    } 
  }
}


// Function: delete_multi()
// Input: record
// Output: none
// delete multiple records
void delete_multi(Record records[]){
  char deleteName[30];
  int deleteYear = 0;
  printf("\nPlease enter the movie info you want to delete.\n");
  printf("Input '0' if it doesn't matter.\n");
  printf("\nMovie Name(no space): ");
  scanf("%s", deleteName);
  printf("Production Year: ");
  scanf("%d", &deleteYear);
  while (getchar() != '\n');  //fflush 

  if(deleteName[0] == '0' && deleteYear == 0){  //delete all
    init(records);
  }
  else if(deleteName[0] != '0' && deleteYear == 0){ // movie names only
    for(int i = 0; i < 1000; i++){
      if(records[i].used == 1 && strcmp(records[i].name, deleteName) == 0){
      records[i].name[0] = '\0';
      records[i].year = 0;
      records[i].rating = 0;
      records[i].used = 0;
      }
    }
  }
  else if(deleteName[0] == '0' && deleteYear != 0){ // years only
    for(int i = 0; i < 1000; i++){
      if(records[i].used == 1 && records[i].year == deleteYear){
      records[i].name[0] = '\0';
      records[i].year = 0;
      records[i].rating = 0;
      records[i].used = 0;
      }
    }
  }
  else if(deleteName[0] != '0' && deleteYear != 0){ // a certain movie
    for(int i = 0; i < 1000; i++){
      if(records[i].used == 1 && strcmp(records[i].name, deleteName) == 0 &&records[i].year == deleteYear){
      records[i].name[0] = '\0';
      records[i].year = 0;
      records[i].rating = 0;
      records[i].used = 0;
      break;
      }
    }
  }

  printf("\n:::::Succesully deleted!:::::\n\n");
}


