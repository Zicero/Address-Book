/*****************************************************************
   //
   // NAME: Trevin Tejero
   //
   // HOMEWORK: project1
   //
   // CLASS: ICS 212
   //
   // INSTRUCTOR: Ravi Narayan
   //
   // DATE: July 9, 2017
   //
   // FILE: main.c
   //
   // DESCRIPTION: This file contains the user-interface for project1.
   //
 ****************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "record.h"

int debugmode = 0;

int addRecord (struct record **, int, char [],char [] );
int printRecord (struct record *, int);
int modifyRecord (struct record *, int, char [] );
void printAllRecords(struct record *);
int deleteRecord(struct record **, int);
int readfile(struct record **, char []);
void writefile(struct record *, char []);
void getaddress(char [], int);

/*****************************************************************
   //
   // Function name: main
   //
   // DESCRIPTION: The main function for project1.
   //
   // Parameters: argc (int): The number of arguments passed into the program.
   //             argv (char* []): The arguments passed into the program.
   //
   // Return values: 0: success
   //
 ****************************************************************/

int main(int argc, char* argv[])
{
        int quit = 0;
        char input[20];
        int choice;
        struct record * start = NULL;

        if ((argc >= 2) && ((strcmp(argv[1], "debug") == 0)))
        {
                if (argc > 2)
                {
                        printf("debug usage: ./hw3 [debug]\n");
                        quit = 1;
                }
                else
                {
                        debugmode = 1;
                        printf("\n##############################\n");
                        printf("\n  ### ENTERING DEBUG MODE ###  \n");
                        printf("\n##############################\n\n");
                }
        }
        else
        {
                debugmode = 0;
        }

        readfile(&start, "database.txt");

        if (quit != 1)
        {
                do
                {
                        char buffer[150];
                        int accountnum;
                        char name[25];
                        char address[80] = {'\0'};

                        printf("\n|---------- Option Menu ----------|\n\n");
                        printf("[1] - Add new record to database\n");
                        printf("[2] - Modify an existing record\n");
                        printf("[3] - Print a record\n");
                        printf("[4] - Print all records in the database\n");
                        printf("[5] - Delete an existing record \n");
                        printf("[6] - Exit the program\n");
                        printf("|---------------------------------|\n\n");

                        printf("Please select an option: ");
                        fgets(input, 5, stdin);
                        choice = atoi(input);

                        switch (choice)
                        {
                        case 1:
                                printf("\n--- Adding a new record. ---\n\n");
                                printf("Enter new account number: ");
                                scanf("%i", &accountnum);
                                scanf("%c", buffer);

                                printf("\nEnter name of the account holder: ");
                                fgets(name, 25, stdin);
                                name[strlen(name) - 1] = '\0';

                                printf("Please enter account holder's address below:\n");
                                printf("Hit enter twice when finished.\n");

                                getaddress(address, 80);
                                addRecord(&start, accountnum, name, address);
                                break;
                        case 2:
                                printf("\n--- Modifying a record. ---\n\n");
                                printf("Enter number of the account you wish to make changes to: ");
                                scanf("%i", &accountnum);
                                scanf("%c", buffer);

                                printf("Please enter account holder's address below:\n");
                                printf("Hit enter twice when finished.\n");

                                getaddress(address, 80);
                                modifyRecord(&*start, accountnum, address);
                                break;
                        case 3:
                                printf("\n--- Printing a record. ---\n\n");
                                printf("Enter account number of the record you wish to print: ");
                                scanf("%i", &accountnum);
                                scanf("%c", buffer);

                                printRecord(start, accountnum);
                                break;
                        case 4:
                                printf("\n--- Printing the database. ---\n\n");

                                printAllRecords(start);
                                break;
                        case 5:
                                printf("\n--- Deleting a record. ---\n\n");
                                printf("Enter account number of the record you wish to delete: ");
                                scanf("%i", &accountnum);
                                scanf("%c", buffer);

                                deleteRecord(&start, accountnum);
                                break;
                        case 6:
                                quit = 1;
                        default:
                                break;
                        }
                } while (quit != 1);
        }
        writefile(start, "database.txt");
        printf("\n--- Exiting database. Goodbye. ---\n");
        return 0;
}

