#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "base.h"
#include "extras.h"
#include "record.h"

#define MAX_RECORDS 1000

// function prototypes
void input_handler(char[], Record[]);
void display_menu();

// main function
int main(){

	Record records[MAX_RECORDS];  //records(struct array) declaration
  init(records);
	char user_input[64] = "";
	while(strcmp(user_input, "16") != 0){
		display_menu();
		printf("\nSelect a menu> ");
		fgets(user_input, 64, stdin);
		user_input[strlen(user_input)-1] = '\0';
		input_handler(user_input, records);
	}

	return 0;
}


// Function: input_handler()
// Input: record - array of Records; this may contain empty elements in the middle
// Output: none
// - Handles the user input and invokes functions that correspond to the user input
void input_handler(char input[], Record records[]){

	if(!strcmp(input, "1"))
		create_keyboard(records); 
	else if(!strcmp(input, "2"))
		create_file(records);
	else if(!strcmp(input, "3"))
		print_all_records(records);
	else if(!strcmp(input, "4"))
		read_search(records);
  else if(!strcmp(input, "5"))
		read_load(records);
  else if(!strcmp(input, "6"))
		read_save(records);
  else if(!strcmp(input, "7"))
		read_report(records);
  else if(!strcmp(input, "8"))
		update(records);
  else if(!strcmp(input, "9"))
		delete_single(records);
  else if(!strcmp(input, "10"))
		delete_multi(records);
  else if(!strcmp(input, "11"))
		optimize(records);
  else if(!strcmp(input, "12"))
		sort(records);
  else if(!strcmp(input, "13"))
		random_selection(records);
  else if(!strcmp(input, "14"))
		printf("\nNumber of records: %d\n\n", count(records));
  else if(!strcmp(input, "15"))
		init(records);
	else if(!strcmp(input, "16"))
		printf("Terminating... bye!\n\n"); // Quit - no operation (an empty statement with a semi-colon)
	else
		printf("Unknown menu: %s \n\n", input);
}

// Function: display_menu()
// Input: none
// Output: none
// show menu
void display_menu(){

	printf("******************************\nMovie Rating Management System\n******************************\n1.Add a new movie\n2.Import a new movie record\n3.Print all movies\n4.Search Movies\n5.Load a new data file\n6.Save to a data file\n7.Export as a report\n8.Update movie details\n9.Delete a movie\n10.Delete multiple movies (conditional)\n11.Optimize (defrag) the records\n12.Sort\n13.Random selection\n14.Count\n15.Clear\n16.Exit\n");
}
