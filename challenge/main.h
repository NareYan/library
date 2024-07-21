#ifndef MAIN_H
 #define MAIN_H
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <stdbool.h>

 typedef struct book
{
   int id;
   char *title;
   char *author;
   bool is_borrowed; 
   int borrowed_by;
   struct book *next; 
} Book; 

typedef struct user
{
   int id; 
   char *name;
   char *mail;
   struct user *next; 
} User; 

typedef struct list
{
   unsigned int len;
   void*        head;
} List; 



List *createList();
List *createList1();
void add_book(List *library, char *author, char *title, int id);
Book * search_book(List *library, char *author, char *title, int id, bool print);
void remove_book(List *library, char *author, char *title, int id); 
void register_user(List *userlist, char *name, char *mail, int id);
bool does_user_exist(List *userlist, char *name, char *mail, int id);
void borrow_book(List *library, List *userlist, int userid, char *name, char *mail, char *title, char *author, int bookid);
void return_book(List *library,List *userlist,  int bookid, int userid, char *title, char *author);

#endif