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
   // FILE: iofunctions.c
   //
   // DESCRIPTION: This file contains the readfile and writefile functions for project1.
   //
 ****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "record.h"

int addRecord (struct record **, int, char [],char [] );

extern int debugmode;

/*****************************************************************
   //
   // Function name: readfile
   //
   // DESCRIPTION: Reads the data from a text file and stores it in accarray.
   //
   // Parameters: accarray (struct record []): place to store customer's bank info
   //             filename (char []): name of file to read
   //
   // Return values: 0: success
   //                1: failure (file does not exist)
   //
 ****************************************************************/

int readfile( struct record **accarray, char filename[]  )
{
        FILE *inf;
        int retVal = 0;
        int currentField = 0;
        char buff[100];
        int accountno;
        char name[26];
        char address[81] = {'\0'};

        if (debugmode == 1)
        {
                printf("################## DEBUGGER ####################\n");
                printf("Getting database with readfile...\n");
                printf("> File: %s\n", filename);
                printf("################################################\n\n");
        }

        inf = fopen(filename, "r");

        if (inf == NULL)
        {
                retVal = 1;
        }
        else {

                while ( fgets(buff, 81, inf) )
                {
                        if (currentField == 0)
                        {
                                accountno = atoi(buff);

                        }
                        else if (currentField == 1)
                        {
                                if ( strlen(buff) > 0 && buff[strlen(buff) - 1] == '\n' )
                                {
                                        buff[strlen(buff) - 1] = '\0';
                                }
                                strcpy(name, buff);

                        }
                        else if ( currentField == 2)
                        {
                                if ( strlen(buff) > 0 && buff[strlen(buff) - 1] == '\n' )
                                {
                                        buff[strlen(buff) - 1] = '\0';
                                }
                                strcpy(address, buff);
                        }

                        if ( buff[0] == '\n' && buff[1] == '\0' )
                        {
                                currentField = 0;
                                addRecord(accarray, accountno, name, address);
                                accountno = 0;
                                address[0] = '\0';

                        }
                        else
                        {
                                currentField++;
                        }
                }
                addRecord(accarray, accountno, name, address);
                fclose(inf);
        }

        return retVal;
}

/*****************************************************************
   //
   // Function name: writefile
   //
   // DESCRIPTION: Writes data stores in the accarray into a text file.
   //
   // Parameters: accarray (struct record []): place that stores the cust record data
   //             filename (char []): name of output file
   //
   // Return values: void
   //
 ****************************************************************/

void writefile( struct record * accarray, char filename[]  )
{
        FILE *ouf;
        struct record * currAcc;

        if (debugmode == 1)
        {
                printf("################## DEBUGGER ####################\n");
                printf("Getting database with writefile...\n");
                printf("> File: %s\n", filename);
                printf("################################################\n\n");
        }

        currAcc = accarray;

        ouf = fopen(filename, "w+");

        if (ouf != NULL)
        {
                while ( currAcc != NULL )
                {
                        fprintf(ouf, "%d\n", currAcc->accountno);
                        fprintf(ouf, "%s\n", currAcc->name);
                        fprintf(ouf, "%s\n\n", currAcc->address);

                        currAcc = currAcc->next;
                }
        }

        fclose(ouf);
}

