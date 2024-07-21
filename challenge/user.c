#include "main.h"

User *createUser(int id, char *name, char *mail)
{
    User *user;
    user = (User *)malloc(sizeof(User)); 
    if (!user)
    {
        printf("Error with mem malloc in Book.");
        exit (1);
    }
    user->id = id; 
    user->name = name; 
    user->mail = mail; 
    user->next = NULL; 
    return(user); 
} 
List *createList1()
{
    List *userlist;
    userlist = (List *)malloc(sizeof(List));
    if (!userlist)
    {
        printf("Error with mem alloc in List.");
        exit(1);
    }
    userlist->len = 0;
    userlist->head = NULL;
    return(userlist);
}

void register_user(List *userlist, char *name, char *mail, int id)
{
    User *user = createUser(id, name, mail);
    userlist->len++; 
    if (!userlist->head)
    {
        userlist->head = user;
        return;
    }
    User *temp = userlist->head;
    while(temp->next)
    {
        temp = temp->next;
    }
    temp->next = user; 
}

bool does_user_exist(List *userlist, char *name, char *mail, int id)
{
    if(!userlist)
    {
        return false;
    }

    User *temp = userlist->head;
    while(temp)
    {
        if (!strcmp(temp->name, name) && !strcmp(temp->mail, mail) && temp->id == id)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void borrow_book(List *library, List *userlist, int userid, char *name, char *mail, char *title, char *author, int bookid)
{
    if (!does_user_exist(userlist, name, mail, userid))
    {
        printf("You cannot borrow, beacause %d user doesn't exist. \n", userid);
        return;
    }
    
    Book *booktemp = search_book(library, author, title, bookid, false);
    if (!booktemp)
    {
        printf("No book found with %s by %s.\n", title, author);
        return;
    }
    if (booktemp->is_borrowed)
    {
        printf("%s by %s is already borrowed. \n", title, author);
        return;
    }

    booktemp->is_borrowed = true;
    booktemp->borrowed_by = userid;
    printf("%s by %s is borrowed by %s. \n", title, author, name);
}


void return_book(List *library, List *userlist, int bookid, int userid, char *title, char *author)
{
    Book *booktemp = search_book(library, author, title, bookid, false);
    if (!booktemp)
    {
        printf("No book found.\n");
        return;
    }

    if (!booktemp->is_borrowed)
    {
        printf("%s by %s isn't borrowed.\n", title, author);
        return;
    }

    if (booktemp->borrowed_by != userid)
    {
        printf("%s by %s isn't borrowed by %d user.\n", title, author, userid);
        return;
    }

    booktemp->is_borrowed = false;
    booktemp->borrowed_by = -1;
    printf("%s by %s is successfully returned.\n", title, author);
}