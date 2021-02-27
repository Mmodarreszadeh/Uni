#include <iostream>
#include <string>
#include <list>

using namespace std;

struct Address
{
    int id;
    string address;
    string postalCode;
    string city;
    string province;
    string country;
};

struct File
{
    int id;
    string fileName;
    string imageUrl;
    int size;
};

struct Role
{
    int id;
    string title;
    string description;
};

struct Order
{
    int id;
    string serial;
    int productCount;
    int totalPrice;
    bool isPayed;
    time_t paymentDate;
};

struct User
{
    int id;
    string fullName;
    string phoneNumber;
    string email;
    string password;
    Role role;
    File profileImage;
    list<Order> orders;
    list<Address> addresses;
};

struct Admin
{
    int id;
    string username;
    string password;
    Role role;
};

struct Category
{
    int id;
    string title;
    string description;
    list<Category> childs;
};

struct Attribute
{
    int id;
    string title;
    string unit;
};

struct ProductAttribute
{
    Attribute attribute;
    string value;
};

struct Product
{
    int id;
    string title;
    string description;
    int price;
    int count;
    int discount;
    int rating;
    File file;
    Category category;
    list<ProductAttribute> attributes;
};

int main()
{
    File file1;
    file1.fileName = "laptop.png";

    Category category1;
    category1.title = "digital";
    Category category2;
    category2.title = "laptop";
    category1.childs.push_back(category2);

    Attribute attr1;
    attr1.title = "ram";
    Attribute attr2;
    attr2.title = "cpu";

    list<ProductAttribute> attributes;
    ProductAttribute pa;
    pa.attribute = attr1;
    pa.value = 16;
    ProductAttribute pa2;
    pa2.attribute = attr2;
    pa2.value = "core i7";
    attributes.push_back(pa);
    attributes.push_back(pa2);

    Product products[5];
    products[0].id = 1;
    products[0].title = "laptop lenovo";
    products[0].price = 12000000;
    products[0].count = 10;
    products[0].discount = 20;
    products[0].file = file1;
    products[0].category = category2;
    products[0].attributes = attributes;

    products[1].id = 2;
    products[1].title = "laptop asus";
    products[1].price = 15000000;
    products[1].count = 5;
    products[1].discount = 5;
    products[1].file = file1;
    products[1].category = category2;
    products[1].attributes = attributes;

    products[2].id = 3;
    products[2].title = "laptop apple";
    products[2].price = 50000000;
    products[2].count = 3;
    products[2].discount = 2;
    products[2].file = file1;
    products[2].category = category2;
    products[2].attributes = attributes;

    products[3].id = 4;
    products[3].title = "laptop hp";
    products[3].price = 17000000;
    products[3].count = 15;
    products[3].discount = 6;
    products[3].file = file1;
    products[3].category = category2;
    products[3].attributes = attributes;

    products[4].id = 5;
    products[4].title = "laptop acer";
    products[4].price = 16000000;
    products[4].count = 7;
    products[4].discount = 2;
    products[4].file = file1;
    products[4].category = category2;
    products[4].attributes = attributes;

    for (Product p : products)
    {
        cout << p.title << " ";
        cout << p.price << " ";
        cout << p.count << " ";
        cout << p.discount << " ";
        cout << p.file.fileName << " ";
        cout << p.category.title << "\n";
    }
}
