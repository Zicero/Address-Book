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
   // FILE: getaddress.c
   //
   // DESCRIPTION: This file contains the getaddress function for project1.
   //
 ****************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern int debugmode;

/*****************************************************************
   //
   // Function name: getaddress
   //
   // DESCRIPTION: Takes in the user input as an address
   //
   // Parameters: address (char []): the place to store the address
   //             charCount (int): The limit of the user input
   //
   // Return values: void
   //
 ****************************************************************/

void getaddress(char address[], int charCount)
{
        char buffer[80];
        int finished = 0;
        if (debugmode == 1)
        {
                printf("\n################################################\n");
                printf("################## DEBUGGER ####################\n");
                printf("Entering getaddress...\n");
                printf("> Address: %s\n", address);
                printf("################################################\n\n");
        }
        while (finished == 0)
        {
                fgets(buffer, charCount, stdin);
                if (buffer[0] != '\n')
                {
                        buffer[strlen(buffer) - 1] = ' ';
                        strcat(address, buffer);
                }
                else if (buffer[0] == '\n')
                {
                        finished = 1;
                }
        }
}

