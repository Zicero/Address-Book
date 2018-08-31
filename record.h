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
   // FILE: record.h
   //
   // DESCRIPTION: This file contains the structure for the bank database.
   //
 ****************************************************************/

struct record
{
        int accountno;
        char name[25];
        char address[80];
        struct record*   next;

};

