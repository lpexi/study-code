#include <iostream>
#include <string>
#include <iomanip>
using namespace std;        // "using" is bad sytax, wirte std:: before every argument

class Article {
public:         // everything is public? Check whar can be private do limit accessability form other functions
    string name;
    double price;
    int stock;
    string* category;       // Why "string*" (pointer) ??
    int id;

    Article(string name, double price, int stock, string category, int id) {        // Dont declare all the params in the bodey, use this sytax insted: name{name}, price{price}, ...,
        name = name;                        // use this-> as same name              // This prevents a double declare / lookup from the Constructor
        price = price;                                                              // No validation of any function (if input or outpit makes sense)
        stock = stock;
        this->id = id;                      // no checking for duplicate id's
        this->category = new string;
        *this->category = category;         // this->category = category; "this" is alrady a pointer
    }

    void setPrice(double price) {
        price = price;                      // use "this"
    }

    void sell(int amount) {
        stock = stock - amount;             // use "this"
    }

    void restock(int amount) {
        this->stock += amount;              // unify syntax (=+ to + ore - to =-)
    }

    double applyDiscount(double percent) {
        price = price - price * percent / 100;
        return price;
    }

    double getPrice() {
        return price;
    }

    bool isAvailable() {        // change to const function as it dose not change a value
        if (stock > 0)          // change to <= 0
            return true;
        else
            return false;
    }

    void printInfo() {          // Code the method in a function not in the constructor
        cout << "Article: " << name << endl;
        cout << "Category: " << *category << endl;
        cout << "Price: " << price << endl;
        cout << "Stock: " << stock << endl;
        cout << "ID: " << id << endl;
    }
};

int main() {// bad naming "a" use someting more fitting, which describes the article
    Article a("Laptop", 999.99, 10, "Electronics", 101);        // Throughout the main function, magic numbers are used and difficult to change afterwords
                                                                // Change for example the Discount to a Param like "APPLY_DISCOUNT = 20", ...,
    a.sell(15);
    a.restock(-5);                                              // Restock removes 5 insted of adding 5
    a.price = -100;                                             // no direct access, we have a funcrion 
    a.applyDiscount(150);

    if (a.isAvailable()) cout << "Article available" << endl;

    a.printInfo();
}