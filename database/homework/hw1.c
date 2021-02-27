#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define clear() printf("\033[H\033[J")




typedef struct 
{
    int id;
    char serial;
    int productCount;
    int totalPrice;
    bool isPayed;
    char paymentDate[20];
}Order;

typedef struct 
{
    int id;
    char fullName[40];
    char phoneNumber[11];
    char email[50];
    char password[20];
    Order orders[100];
    char addresse[300];
}User;


typedef struct 
{
    int id;
    char title[20];
    char description[100];
    int parentId;
}Category;

typedef struct 
{
    int id;
    char title[20];
    char unit[20];
}Attribute;

typedef struct 
{
    Attribute attribute;
    char value[20];
}ProductAttribute;

typedef struct 
{
    int id;
    char title[20];
    char description[100];
    int price;
    int count;
    Category category;
    ProductAttribute attributes[100];
}Product;

typedef struct {
	int id;
	Product product;
	User user;
	int count;
}Basket;

int Random()
{
   time_t t;
   srand((unsigned) time(&t));
   int random=(rand()%100)+1;
   return random;
}

void addProduct()
{
	clear();
	Product product;
	printf("enter name:");
	scanf("%s",product.title);
	printf("enter description:");
	scanf("%s",product.description);
	printf("enter price");
	scanf("%d",&product.price);
	printf("enter count:");
	scanf("%d",&product.count);
}

void addUser()
{
	clear();
	printf("add user\n");
	for (int i=0;i<2;i++)
	{
		printf(categories[i].title);
	}
}


// initial data of shop
Category categories[2];






int main()
{
	Category c = {1,"digital","this is digital category",0};

	categories[1].id = 2;
	categories[1].title = " food";
	categories[1].description = "this is food category";
	categories[1].parentId = NULL;
	while(1)
	{
		int input = 0;
		printf("1.Add Product\n");
		printf("2.Add User\n");
		printf("3.Checkout Order\n");
		printf("4.List of Product\n");
		printf("5.List of User\n");
		printf("6.Show Order By Serial\n");
		printf("6.Show Order By Date\n");
		printf("Enter Input Number:");
		scanf("%d",&input);
		if (input == 1)
			addProduct();
		else if (input == 2)
			addUser();
	}
}
