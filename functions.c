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
   // FILE: functions.c
   //
   // DESCRIPTION: This file contains the functions for project1.
   //
 ****************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "record.h"

extern int debugmode;

/*****************************************************************
   //
   // Function name: addRecord
   //
   // DESCRIPTION: Adds a record to the database
   //
   // Parameters: start (struct record **): a reference to the database
   //             accountno (int): The account number to be added
   //             name (char []): The name to be added
   //             address (char []): The address to be added
   //
   // Return values: 0: success
   //                1: failure (invalid account number)
   //
 ****************************************************************/

int addRecord(struct record ** start, int accountno, char name[], char address[])
{
        struct record *temp;
        int retVal = 0;

        if (debugmode == 1)
        {
                printf("################## DEBUGGER ####################\n");
                printf("Entering addRecord...\n");
                printf("> Account Number: %i\n", accountno);
                printf("> Name: %s\n", name);
                printf("> Address: %s\n", address);
                printf("################################################\n\n");
        }

        temp = malloc(sizeof(struct record));

        temp->accountno = accountno;
        strcpy(temp->name, name);
        strcpy(temp->address, address);
        temp->next = NULL;

        if (accountno <= 0)
        {
                printf("Account number must be greater than 0\n");
                retVal = 1;
        }
        else
        {
                if (start == NULL)
                {
                        *start = temp;
                }
                else
                {
                        struct record *lpointer;
                        lpointer = *start;

                        if (lpointer == NULL)
                        {
                                *start = temp;
                        }
                        else
                        {

                                while (lpointer->next != NULL)
                                {
                                        lpointer = lpointer->next;
                                }

                                lpointer->next = temp;
                        }
                }

                printf("Successfully added a new account record.\n");
        }

        return retVal;
}

/*****************************************************************
   //
   // Function name: modifyRecord
   //
   // DESCRIPTION: Modifies a record from the database
   //
   // Parameters: start (struct record *): a reference to the database
   //             accountno (int): The number of the account to be modified
   //             address (char []): The address to be modified
   //
   // Return values: 0: success
   //
 ****************************************************************/

int modifyRecord(struct record * start, int accountno, char address[] )
{
        struct record *temp;
        int modified = 0;

        if (debugmode == 1)
        {
                printf("################## DEBUGGER ####################\n");
                printf("Entering modifyRecord\n");
                printf("> Account Number: %i\n", accountno);
                printf("> Address: %s\n", address);
                printf("################################################\n\n");
        }

        temp = start;

        if (start == NULL)
        {
                printf("The database is empty. If you wish to add a new record please use option 1.\n");
        }
        else
        {
                while (temp != NULL)
                {
                        if (temp->accountno == accountno)
                        {
                                strcpy(temp->address, address);
                                modified = 1;
                        }

                        temp = temp->next;
                }

                if (modified == 1)
                {
                        printf("All records matching account number: %i have been updated.\n", accountno);
                }
                else
                {
                        printf("No records were found matching the account number:%i\n", accountno);
                }
        }

        return 0;
}

/*****************************************************************
   //
   // Function name: printRecord
   //
   // DESCRIPTION: Prints a record from the database
   //
   // Parameters: start (struct record *): a reference to the database
   //             accountno (int): The account number to be printed
   //
   // Return values: 0: success
   //
 ****************************************************************/

int printRecord(struct record * start, int accountno)
{
        struct record *temp;
        int printed = 0;

        if (debugmode == 1)
        {
                printf("################## DEBUGGER ####################\n");
                printf("Entering printRecord...\n");
                printf("> Account Number: %i\n", accountno);
                printf("################################################\n\n");
        }

        temp = start;

        if (temp == NULL)
        {
                printf("There are no records in the database.\n");
        }
        else
        {
                while(temp != NULL)
                {
                        if (temp->accountno == accountno)
                        {
                                printf("Record for account number %d:\n", accountno);
                                printf("Acc Number: %d\n", temp->accountno);
                                printf("Name: %s\n", temp->name);
                                printf("Address: %s\n\n", temp->address);
                                printed = 1;
                        }

                        temp = temp->next;
                }
        }

        if (printed == 0)
        {
                printf("No records were found matching the account number:%i\n", accountno);
        }

        return 0;
}

/*****************************************************************
   //
   // Function name: printAllRecord
   //
   // DESCRIPTION: Prints all the records from the database.
   //
   // Parameters: start (struct record *): a reference to the database
   //
   // Return values: void
   //
 ****************************************************************/

void printAllRecords(struct record * start)
{
        struct record * temp;

        if (debugmode == 1)
        {
                printf("################## DEBUGGER ####################\n");
                printf("Entering printAllRecords...\n");
                printf("################################################\n\n");
        }

        temp = start;

        if (temp == NULL)
        {
                printf("There are no records in the database.\n");
        }
        else
        {
                while(temp != NULL)
                {
                        printf("Record for account number %d:\n", temp->accountno);
                        printf("Acc Number: %d\n", temp->accountno);
                        printf("Name: %s\n", temp->name);
                        printf("Address: %s\n\n", temp->address);

                        temp = temp->next;
                }
        }
}

/*****************************************************************
   //
   // Function name: deleteRecord
   //
   // DESCRIPTION: Deletes a record from the database
   //
   // Parameters: start (struct record **): a reference to the database
   //             accountno (int): The account number to be deleted
   //
   // Return values: 0: success
   //
 ****************************************************************/

int deleteRecord(struct record ** start, int accountno)
{
        struct record * prev;
        struct record * curr;
        int deleted = 0;

        if (debugmode == 1)
        {
                printf("################## DEBUGGER ####################\n");
                printf("Entering deleteRecord...\n");
                printf("> Account Number: %i\n", accountno);
                printf("################################################\n\n");
        }

        prev = *start;

        if(prev == NULL)
        {
                printf("There are no records in the database.\n");
        }
        else
        {
                if(prev != NULL)
                {
                        while(prev != NULL && prev->accountno == accountno)
                        {
                                curr = prev->next;
                                free(prev);
                                *start = curr;
                                prev = *start;
                                deleted = 1;
                        }
                }
                if(prev != NULL)
                {
                        curr = prev->next;
                        prev = *start;

                        while(curr != NULL)
                        {
                                if(curr->accountno == accountno)
                                {
                                        prev->next = curr->next;
                                        free(curr);
                                        curr = prev->next;
                                        deleted = 1;
                                }
                                else
                                {
                                        prev = prev->next;
                                        curr = prev->next;
                                }
                        }
                }

                if (deleted == 1)
                {
                        printf("All records matching account number: %i have been deleted.\n", accountno);
                }
                else
                {
                        printf("No records were found matching the account number: %i\n", accountno);
                }
        }

        return 0;
}

