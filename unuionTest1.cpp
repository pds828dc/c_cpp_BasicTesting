// Union word test
#include <stddef.h>
#include <stdio.h>

typedef union amount_t amount_t;

union amount_t {
    unsigned unit;
    float liter;
};

typedef struct item_t item_t;

struct item_t {
    char *name;
    unsigned short amountType;
    amount_t howmuch;
};

int main()
{
    item_t books;
    books.name = "C Programming Tutorial";
    books.amountType = 1;
    books.howmuch.unit = 4;

    item_t apples;
    apples.name = "Apple";
    apples.amountType = 1;
    apples.howmuch.unit = 6;

    item_t juices;
    juices.name = "Orange Juice";
    juices.amountType = 2;
    juices.howmuch.liter = 3.2;
    
    
    item_t items[] = {books, apples, juices};
    
    for (size_t i = 0; i < 3; i++) {
        printf("%s: ", items[i].name);
        
        if (items[i].amountType == 1) {
            printf("%d units", items[i].howmuch.unit);
        } else {
            printf("%.2f liters", items[i].howmuch.liter);
        }
        
        printf("\n"); /* trailing newline. */
    }
    
    return 0;
}