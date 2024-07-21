#include "main.h"

Book *createBook(char *author, char *title, int id)
{
    Book *book;
    book = (Book *)malloc(sizeof(Book)); 
    if (!book)
    {
        printf("Error with mem malloc in Book.");
        exit (1);
    }
    book->author = author; 
    book->title = title; 
    book->id = id; 
    book->is_borrowed = false;
    book->borrowed_by = -1;
    book->next = NULL; 
    return(book); 
} 

List *createList()
{
    List *library;
    library = (List *)malloc(sizeof(List));
    if (!library)
    {
        printf("Error with mem alloc in List.");
        exit(1);
    }
    library->len = 0;
    library->head = NULL;
    return(library);
}

void add_book(List *library, char *author, char *title, int id)
{
    Book *book = createBook(author, title, id);
    library->len++; 
    if (!library->head)
    {
        library->head = book;
        return;
    }
    Book *temp = library->head;
    while(temp->next)
    {
        temp = temp->next;
    }
    printf("%s by %s, %d was successfully added.\n", temp->title, temp->author, temp->id);
    temp->next = book; 
}

Book * search_book(List *library, char *author, char *title, int id, bool print)
{
    if(!library)
    {
        if (print)
        {   printf("No book found. \n");
        }
        return NULL;
    }

    Book *temp = library->head;
    while(temp)
    {
        if (!strcmp(temp->author, author) && !strcmp(temp->title, title) && temp->id == id)
        {
            if (print)
            {
                printf("The book is found. \n");
            }
            return temp;
        }
        temp = temp->next;
    }
    if (print)
    {
        printf("No book found. \n");
    }
    return NULL;
}

void remove_book(List *library, char *author, char *title, int id) 
{
    if (!library) {
        printf("The library is empty.\n");
        return;
    }


    Book *temp = search_book(library, author, title, id, false);
    Book *previous = NULL; 

    if (!temp) {
        printf("The book was not found.\n");
        return;
    }

    if (!previous) {
        library->head = temp->next; 
    } else {
        previous->next = temp->next; 
    }

    free(temp);
    library->len--;
    printf("%s by %s, %d was removed.\n", title, author, id);

}

