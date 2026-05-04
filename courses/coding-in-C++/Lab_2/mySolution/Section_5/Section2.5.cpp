#include <iostream>
#include <string>
#include <iomanip>
// using namespace std;        // "using" is bad sytax, wirte std:: before every argument

class Article {
public:         // everything is public? Check whar can be private do limit accessability form other functions
    std::string name;
    double price;
    int stock;
    std::string category;       // Why "string*" (pointer) ??
    int id;

    Article(std::string name, double price, int stock, std::string category, int id) {        // Dont declare all the params in the bodey, use this sytax insted: name{name}, price{price}, ...,
        this->name = name;                        // use this-> as same name              // This prevents a double declare / lookup from the Constructor
        price = price;                                                              // No validation of any function (if input or outpit makes sense)
        stock = stock;
        this->id = id;                      // no checking for duplicate id's
        this->category = new std::string;
        this->category = category;         // this->category = category; "this" is alrady a pointer
    }

    void setPrice(double price) {
        this->price = price;                      // use "this"
    }

    void sell(int amount) {
        this->stock = stock - amount;             // use "this"
    }

    void restock(int amount) {
        this->stock =+ amount;              // unify syntax (=+ to + ore - to =-)
    }

    double applyDiscount(double percent) {
        price = price - price * percent / 100;
        return price;
    }

    double getPrice() {
        return price;
    }

    const bool isAvailable() {        // change to const function as it dose not change a value
        if (stock >= 0)          // change to <= 0
        {
            return true;
        } 
        else
        {
            return false;
        }
    }

    void printInfo() {          // Code the method in a function not in the constructor
        std::cout << "Article: " << name << std::endl;
        std::cout << "Category: " << category << std::endl;
        std::cout << "Price: " << price << std::endl;
        std::cout << "Stock: " << stock << std::endl;
        std::cout << "ID: " << id << std::endl;
    }
};

int main() {// bad naming "a" use someting more fitting, which describes the article
    Article a("Laptop", 999.99, 10, "Electronics", 101);        // Throughout the main function, magic numbers are used and difficult to change afterwords
                                                                // Change for example the Discount to a Param like "APPLY_DISCOUNT = 20", ...,
    a.sell(15);
    a.restock(-5);                                              // Restock removes 5 insted of adding 5
    a.price = -100;                                             // no direct access, we have a funcrion 
    a.applyDiscount(150);

    if (a.isAvailable()) std::cout << "Article available" << std::endl;

    a.printInfo();
}