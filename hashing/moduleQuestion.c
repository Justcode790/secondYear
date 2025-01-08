#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100
#define AVAILABLE 1
#define CHECKED_OUT 0

typedef struct Book {
    char isbn[20];
    char title[100];
    char author[100];
    char genre[50];
    int isAvailable;
} Book;

Book hashTable[TABLE_SIZE];
int occupied[TABLE_SIZE] = {0};

unsigned int hashFunction(char *key) {
    unsigned long hash = 0;
    const int prime = 31;

    while (*key) {
        hash = (hash * prime) + *key;
        key++;
    }

    return hash % TABLE_SIZE;
}

int findSlot(char *key) {
    int index = hashFunction(key);
    int originalIndex = index;
    while (occupied[index] && strcmp(hashTable[index].isbn, key) != 0) {
        index = (index + 1) % TABLE_SIZE;
        if (index == originalIndex) {
            printf("Hash table is full\n");
            return -1;
        }
    }
    return index;
}

void addBook(char *isbn, char *title, char *author, char *genre) {
    int index = findSlot(isbn);
    if (index != -1) {
        strcpy(hashTable[index].isbn, isbn);
        strcpy(hashTable[index].title, title);
        strcpy(hashTable[index].author, author);
        strcpy(hashTable[index].genre, genre);
        hashTable[index].isAvailable = AVAILABLE;
        occupied[index] = 1;
        printf("Book '%s' added to the library\n", title);
    }
}

Book* searchByISBN(char *isbn) {
    int index = hashFunction(isbn);
    int originalIndex = index;
    while (occupied[index]) {
        if (strcmp(hashTable[index].isbn, isbn) == 0) {
            return &hashTable[index];
        }
        index = (index + 1) % TABLE_SIZE;
        if (index == originalIndex) break;
    }
    return NULL;
}

void updateAvailability(char *isbn, int status) {
    Book *book = searchByISBN(isbn);
    if (book) {
        book->isAvailable = status;
        printf("Book '%s' availability updated to %s\n", book->title, status ? "Available" : "Checked Out");
    } else {
        printf("Book with ISBN %s not found\n", isbn);
    }
}

void removeBook(char *isbn) {
    int index = hashFunction(isbn);
    int originalIndex = index;
    while (occupied[index]) {
        if (strcmp(hashTable[index].isbn, isbn) == 0) {
            occupied[index] = 0;
            printf("Book '%s' removed from library\n", hashTable[index].title);
            return;
        }
        index = (index + 1) % TABLE_SIZE;
        if (index == originalIndex) break;
    }
    printf("Book with ISBN %s not found\n", isbn);
}

void borrowBook(char *isbn) {
    Book *book = searchByISBN(isbn);
    if (book) {
        if (book->isAvailable == AVAILABLE) {
            book->isAvailable = CHECKED_OUT;
            printf("Book '%s' has been borrowed.\n", book->title);
        } else {
            printf("Book '%s' is already checked out.\n", book->title);
        }
    } else {
        printf("Book with ISBN %s not found.\n", isbn);
    }
}

void returnBook(char *isbn) {
    Book *book = searchByISBN(isbn);
    if (book) {
        if (book->isAvailable == CHECKED_OUT) {
            book->isAvailable = AVAILABLE;
            printf("Book '%s' has been returned.\n", book->title);
        } else {
            printf("Book '%s' was not checked out.\n", book->title);
        }
    } else {
        printf("Book with ISBN %s not found.\n", isbn);
    }
}

void displayBook(Book *book) {
    if (book) {
        printf("ISBN: %s\nTitle: %s\nAuthor: %s\nGenre: %s\nAvailability: %s\n",
               book->isbn, book->title, book->author, book->genre,
               book->isAvailable ? "Available" : "Checked Out");
    } else {
        printf("Book not found.\n");
    }
}

void menu() {
    int choice;
    char isbn[20], title[100], author[100], genre[50];

    do {
        printf("\nLibrary System Menu:\n");
        printf("1. Add Book\n");
        printf("2. Search Book by ISBN\n");
        printf("3. Borrow Book\n");
        printf("4. Return Book\n");
        printf("5. Remove Book\n");
        printf("6. Display Book Details\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("Enter ISBN: ");
                fgets(isbn, 20, stdin);
                isbn[strcspn(isbn, "\n")] = '\0';

                printf("Enter Title: ");
                fgets(title, 100, stdin);
                title[strcspn(title, "\n")] = '\0';

                printf("Enter Author: ");
                fgets(author, 100, stdin);
                author[strcspn(author, "\n")] = '\0';

                printf("Enter Genre: ");
                fgets(genre, 50, stdin);
                genre[strcspn(genre, "\n")] = '\0';

                addBook(isbn, title, author, genre);
                break;
            case 2:
                printf("Enter ISBN to search: ");
                fgets(isbn, 20, stdin);
                isbn[strcspn(isbn, "\n")] = '\0';
                displayBook(searchByISBN(isbn));
                break;
            case 3:
                printf("Enter ISBN to borrow: ");
                fgets(isbn, 20, stdin);
                isbn[strcspn(isbn, "\n")] = '\0';
                borrowBook(isbn);
                break;
            case 4:
                printf("Enter ISBN to return: ");
                fgets(isbn, 20, stdin);
                isbn[strcspn(isbn, "\n")] = '\0';
                returnBook(isbn);
                break;
            case 5:
                printf("Enter ISBN to remove: ");
                fgets(isbn, 20, stdin);
                isbn[strcspn(isbn, "\n")] = '\0';
                removeBook(isbn);
                break;
            case 6:
                printf("Enter ISBN to display details: ");
                fgets(isbn, 20, stdin);
                isbn[strcspn(isbn, "\n")] = '\0';
                displayBook(searchByISBN(isbn));
                break;
            case 7:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 7);
}

int main() {
    menu();
    return 0;
}
