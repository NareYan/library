#include "main.h"

int main(){
    List *library = createList();
    List *userlist = createList();
    register_user(userlist, "Bob", "Bob@mail.ru", 151);
    register_user(userlist, "Jane", "jane@gmail.com", 525);
    register_user(userlist, "Jack", "Jack@mail.ru", 621);
    add_book(library, "F Scott Fitzgerald","The Great Gatsby", 101);
    add_book(library, "Jane Austen","Pride and Prejudice", 98);
    add_book(library, "Charlotte Bronte","Jane Eyre", 5);
    add_book(library, "John Ronald Reuel Tolkien","The Lord Of The Rings", 15);
    add_book(library, "Harper Lee","To Kill A Mockingbird", 1205);
    add_book(library, "George Orwell","1984", 181);
    add_book(library, "Lousia May Alcott","Little Women", 101);
    // search_book(library, "Harper Lee","lalala Mockingbird", 1205, true);
    // remove_book(library, "John Ronald Reuel Tolkien","The Lord Of The Rings", 15);
    // borrow_book(library, userlist, 151, "Bob", "Bob@mail.ru", "To Kill A Mockingbird", "Harper Lee", 1205);
    // return_book(library, userlist, 1205, 151, "To Kill A Mockingbird", "Harper Lee");
    // borrow_book(library, userlist, 525, "Jane", "jane@gmail.com", "To Kill A Mockingbird", "Harper Lee", 1205);
    borrow_book(library, userlist, 525, "Jane", "jane@gmail.com", "The Lord Of The Rings", "John Ronald Reuel Tolkien", 15);

    return 0;
}