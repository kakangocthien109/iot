#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct item //DuongTran
{
    char *itemName; //DuongTran
    int quantity;
    float price;
    float amount;
};

void readItem(struct item *i)
{
    printf("Please enter item name: ");
    scanf("%s", i->itemName);

    printf("Please enter item price: ");
    scanf("%f", &(i->price)); //DuongTran

    printf("Please enter item quantity: ");
    scanf("%d", &(i->quantity)); //DuongTran
    i->amount = (float)i->quantity * i->price;
}

void printItem(struct item *i)
{

    printf("P R O D U C T   I N F O :");

    printf("\nName: %s", i->itemName);
    printf("\nPrice: %f", i->price);
    printf("\nQuantity: %d", i->quantity);
    printf("\nTotal amount: %f", i->amount);
}

int main()
{
    struct item item;
    struct item *pItem;

    pItem = &item;
    pItem->itemName = (char *)malloc(30 * sizeof(char));

    if (pItem == NULL)
        exit(-1);

    readItem(pItem);
    printItem(pItem);

    free(pItem->itemName);

    return 0;
}