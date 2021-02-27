#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define clear() system("")

typedef struct
{
    int id;
    char name[20];
    char family[20];
    char phoneNumber[20];
    char email[50];
    char password[20];
    char address[100];
} User;

typedef struct
{
    int id;
    char title[20];
    char description[100];
    int parentId;
} Category;

typedef struct
{
    int id;
    char title[20];
    char description[100];
    int price;
    int count;
    int categoryId;
} Product;

typedef struct
{
    int id;
    int productId;
    int userId;
    int count;
} Basket;

typedef struct
{
    int id;
    int serial;
    int totalPrice;
    bool isPayed;
    int paymentDate;
    int userId;
    int product_Ids[100];
} Order;

int Random()
{
    int random = (rand() % 100) + 1;
    return random;
}

// initial data of shop
Category categories[] =
    {
        {1, "digital", "this is digital category", 0},
        {2, "food", "this is food category", 0},
        {3, "clothing", "this is clothing category", 0}};

Order orders[100] = {};

User users[100] =
    {
        {1, "mohammad", "moadrreszadeh", "09393639116", "modarres@gmail.com", "123", "kashan"}};

Product products[100] =
    {
        {1, "laptop", "this is laptop", 20000000, 10, 1},
        {2, "cake", "this is cake", 5000, 20, 2},
        {3, "t-shirt", "this is t-shirt", 90000, 15, 3}};

Basket baskets[100] =
    {
        {1, 1, 1, 5},
        {2, 2, 1, 3}};

void addProduct()
{
    clear();
    Product product;
    product.id = Random();
    printf("enter name:");
    scanf("%s", product.title);
    printf("enter description:");
    scanf("%s", product.description);
    printf("enter price:");
    scanf("%d", &product.price);
    printf("enter count:");
    scanf("%d", &product.count);
    printf("list of category\n");
    int len = sizeof(categories) / sizeof(categories[0]);
    for (int i = 0; i < len; i++)
    {
        printf("%d.%s\n", categories[i].id, categories[i].title);
    }
    printf("enter id of category:");
    scanf("%d", &product.categoryId);
    int index = 0;
    int lenProduct = sizeof(products) / sizeof(products[0]);
    for (int i = 0; i < lenProduct; i++)
    {
        index += 1;
        if (products[i].id == 0)
            break;
    }
    int idx = index - 1;
    products[idx] = product;
    printf("successfully added product to shop\n");
}

void addUser()
{
    clear();
    User user;
    user.id = Random();
    printf("enter name:");
    scanf("%s", user.name);
    printf("enter family:");
    scanf("%s", user.family);
    printf("enter phoneNumber:");
    scanf("%s", user.phoneNumber);
    printf("enter email:");
    scanf("%s", user.email);
    printf("enter password:");
    scanf("%s", user.password);
    printf("enter address:");
    scanf("%s", user.address);
    int index = 0;
    int len = sizeof(users) / sizeof(users[0]);
    for (int i = 0; i < len; i++)
    {
        index += 1;
        if (users[i].id == 0)
            break;
    }
    int idx = index - 1;
    users[idx] = user;
    printf("successfully added user to list\n");
}

void showProducts()
{
    clear();
    printf("LIST OF PRODUCT\n----------------\n");
    int len = sizeof(products) / sizeof(products[0]);
    for (int i = 0; i < len; i++)
    {
        if (strcmp(products[i].title, "") <= 0)
            break;
        printf("id:%d\t", products[i].id);
        printf("title:%s\t", products[i].title);
        printf("price:%d\t", products[i].price);
        printf("category name:%s\t", categories[(products[i].categoryId) - 1].title);
        printf("count:%d\n-------------------------------------------------------------------------\n", products[i].count);
    }
}

void showUsers()
{
    clear();
    printf("LIST OF USERS\n----------------\n");
    int len = sizeof(users) / sizeof(users[0]);
    for (int i = 0; i < len; i++)
    {
        if (users[i].id == 0)
            break;
        printf("id:%d\t", users[i].id);
        printf("name:%s\t", users[i].name);
        printf("family:%s\t", users[i].family);
        printf("phoneNumber:%s\t", users[i].phoneNumber);
        printf("email:%s\t", users[i].email);
        printf("address:%s\n--------------------------------------------------------------------------------------------------------\n", users[i].address);
    }
}

void showOrders()
{
    clear();
    printf("LIST OF ORDERS\n----------------\n");
    int len = sizeof(orders) / sizeof(orders[0]);
    for (int i = 0; i < len; i++)
    {
        if (orders[i].id == 0)
            break;
        printf("id:%d\t", orders[i].id);
        printf("serial:%d\t", orders[i].serial);
        printf("totalPrice:%d\t", orders[i].totalPrice);
        printf("isPayed:%s\t", orders[i].isPayed ? "Yes" : "No");
        char name[20];
        char family[20];
        for (int j = 0; j < len; j++)
        {
            if (users[j].id == orders[i].userId)
            {
                strcpy(name, users[j].name);
                strcpy(family, users[j].family);
            }
        }
        printf("user fullname:%s %s\t", name, family);
        printf("List Of Product:");
        for (int i = 0; i < len; i++)
        {
            if (orders[i].product_Ids[i] == products[i].id)
            {
                printf("%s\t", products[i].title);
            }
        }
        printf("\n");
        printf("paymentDate:%d\n", orders[i].paymentDate);
    }
}

void checkOut()
{
    clear();
    int userId;
    printf("enter user id:");
    scanf("%d", &userId);
    int uId = userId;
    printf("[USER BASKET WITH ID %d]\n", userId);
    int len = sizeof(baskets) / sizeof(baskets[0]);
    int lenPro = sizeof(products) / sizeof(products[0]);
    for (int i = 0; i < len; i++)
    {
        if (baskets[i].id == 0)
            break;
        if (baskets[i].userId == uId)
        {
            for (int j = 0; j < lenPro; j++)
            {
                if (baskets[i].productId == products[j].id)
                {
                    printf("title:%s\t count:%d\n", products[j].title, baskets[i].count);
                }
            }
        }
    }
    char response[1];
    printf("Do you want to final your order?[Y/n]");
    scanf("%s", response);
    if (strcmp(response, "Y") == 0)
    {
        Order order;
        order.id = Random();
        order.isPayed = true;
        order.paymentDate = 2021;
        order.serial = Random() + 1000;
        order.userId = uId;
        for (int i = 0; i < len; i++)
        {
            if (baskets[i].id == 0)
                break;
            if (baskets[i].userId == uId)
            {
                order.product_Ids[i] = baskets[i].productId;
            }
        }
        int index = 0;
        int lenOrder = sizeof(orders) / sizeof(orders[0]);
        for (int i = 0; i < lenOrder; i++)
        {
            index += 1;
            if (orders[i].id == 0)
                break;
        }
        int idx = index - 1;
        orders[idx] = order;
        printf("successfully order add\n");
    }
    else
    {
    }
}

void addToBasket()
{
    clear();
    Basket basket;
    basket.id = Random();
    printf("[ADD PRODUCT TO BASKET]\n");
    printf("enter your user id:");
    scanf("%d", &basket.userId);
    int len = sizeof(products) / sizeof(products[0]);
    printf("[LIST OF PRODUCT TO SELECT]\n");
    for (int i = 0; i < len; i++)
    {
        if (products[i].id == 0)
            break;
        printf("%d", products[i].id);
        printf(".title:%s\t", products[i].title);
        printf("price:%d\n--------------------------\n", products[i].price);
    }
    printf("enter id of product for added to basket: ");
    scanf("%d", &basket.productId);
    printf("enter count of product: ");
    int count = 0;
    scanf("%d", &count);
    basket.count = count;
    int index = 0;
    int lenBask = sizeof(baskets) / sizeof(baskets[0]);
    bool isExist = false;
    for (int i = 0; i < lenBask; i++)
    {
        if (baskets[i].productId == basket.productId)
        {
            baskets[i].count += count;
            isExist = true;
        }
        else
        {
            isExist = false;
            index += 1;
            if (baskets[i].id == 0)
                break;
        }
    }
    if (isExist == false)
    {
        int idx = index - 1;
        baskets[idx] = basket;
    }
}

void showBasket()
{
    clear();
    int userId;
    printf("LIST OF BASKET\n----------------\n");
    printf("enter id of user to show baskek:");
    scanf("%d", &userId);
    int len = sizeof(baskets) / sizeof(baskets[0]);
    int lenPro = sizeof(products) / sizeof(products[0]);
    for (int i = 0; i < len; i++)
    {
        if (baskets[i].id == 0)
            break;
        if (baskets[i].userId == userId)
        {
            for (int j = 0; j < lenPro; j++)
            {
                if (baskets[i].productId == products[j].id)
                {
                    printf("title:%s\t count:%d\n", products[j].title, baskets[i].count);
                }
            }
        }
    }
}

void showOrderBySerial()
{
    clear();
    int serial;
    printf("enter serial:");
    scanf("%d", &serial);
    int len = sizeof(orders) / sizeof(orders[0]);
    for (int i = 0; i < len; i++)
    {
        if (orders[i].id == 0)
            break;
        if (orders[i].serial == serial)
        {
            printf("id:%d\t", orders[i].id);
            printf("serial:%d\t", orders[i].serial);
            printf("totalPrice:%d\t", orders[i].totalPrice);
            printf("isPayed:%s\t", orders[i].isPayed ? "Yes" : "No");
            char name[20];
            char family[20];
            for (int j = 0; j < len; j++)
            {
                if (users[j].id == orders[i].userId)
                {
                    strcpy(name, users[j].name);
                    strcpy(family, users[j].family);
                }
            }
            printf("user fullname:%s %s\t", name, family);
            printf("List Of Product:");
            for (int i = 0; i < len; i++)
            {
                if (orders[i].product_Ids[i] == products[i].id)
                {
                    printf("%s\t", products[i].title);
                }
            }
            printf("\n");
            printf("paymentDate:%d\n", orders[i].paymentDate);
        }
    }
}

void showOrderByDate()
{
    clear();
    int date;
    printf("enter date:");
    scanf("%d", &date);
    int len = sizeof(orders) / sizeof(orders[0]);
    for (int i = 0; i < len; i++)
    {
        if (orders[i].id == 0)
            break;
        if (orders[i].paymentDate == date)
        {
            printf("id:%d\t", orders[i].id);
            printf("serial:%d\t", orders[i].serial);
            printf("totalPrice:%d\t", orders[i].totalPrice);
            printf("isPayed:%s\t", orders[i].isPayed ? "Yes" : "No");
            char name[20];
            char family[20];
            for (int j = 0; j < len; j++)
            {
                if (users[j].id == orders[i].userId)
                {
                    strcpy(name, users[j].name);
                    strcpy(family, users[j].family);
                }
            }
            printf("user fullname:%s %s\t", name, family);
            printf("List Of Product:");
            for (int i = 0; i < len; i++)
            {
                if (orders[i].product_Ids[i] == products[i].id)
                {
                    printf("%s\t", products[i].title);
                }
            }
            printf("\n");
            printf("paymentDate:%d\n", orders[i].paymentDate);
        }
    }
}

int main()
{
    while (1)
    {
        clear();
        int input = 0;
        printf("1.Add Product\n");
        printf("2.Add User\n");
        printf("3.Add Product To Basket\n");
        printf("4.Checkout Order\n");
        printf("5.List of Product\n");
        printf("6.List of User\n");
        printf("7.List of Order\n");
        printf("8.Show Order By Serial\n");
        printf("9.Show Order By Date\n");
        printf("10.Show Basket Of User\n");
        printf("-----------------------\nEnter Input Number:");
        scanf("%d", &input);
        if (input == 1)
            addProduct();
        else if (input == 2)
            addUser();
        else if (input == 3)
            addToBasket();
        else if (input == 4)
            checkOut();
        else if (input == 5)
            showProducts();
        else if (input == 6)
            showUsers();
        else if (input == 7)
            showOrders();
        else if (input == 8)
            showOrderBySerial();
        else if (input == 9)
            showOrderByDate();
        else if (input == 10)
            showBasket();
    }
}
