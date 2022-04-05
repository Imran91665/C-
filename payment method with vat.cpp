#include <iostream>
using namespace std;

class Bike
{
  public:
    double price;
    string model, company;
    int miles;
    // bike constructor
    Bike(string company, string model, int miles, double price)
    {
        this->model = model;
        this->miles = miles;
        this->company = company;
        this->price = price;
    }
    // show bike info
    void showInfo()
    {
        cout << "Bike Details:" << endl;
        cout << "Model: " << this->model << endl;
        cout << "Miles: " << this->miles << endl;
        cout << "Manufactured by: " << this->company << endl;
        cout << "Only at (TK): " << this->price << endl;
    }
};

class MyProfile
{
  private:
    int age;
  protected:
    string username, password;
  public:
    string email, phone, hometown;
    MyProfile(string username, string password)
    {
        this->username = username;
        this->password = password;
    }
    void setInfo(string email, string phone, string hometown)
    {
        this->email = email;
        this->phone = phone;
        this->hometown = hometown;
    }
    void accessPoint(int s_id)
    {
        int last_digit = s_id % 100;
        // check for access points
        if      (last_digit >= 0 && last_digit <= 3)
                cout << "You can buy this bike from amazon.com\n";
        else if (last_digit >= 4 && last_digit <= 6)
                cout << "You can buy this bike from daraz.com\n";
        else if (last_digit >= 0 && last_digit <= 3)
                cout << "You can buy this bike from evally.com\n";
        else {
            cout << "Student ID Error!";
            exit(1);
        }
        cout << endl;
    }
    void confirm(Bike *your_bike);
};

void MyProfile::confirm(Bike *your_bike)
{
    int choice;
    cout << "Confirm your purchase: \n";
    cout << "1. Confirm\n";
    cout << "2. Cancel\n";
    cout << "Input: ";
    cin >> choice;
    // check for the choice
    switch(choice)
    {
      case 1:
        cout << "Congratulations You've bought " << your_bike->company << " " << your_bike->model << "!\n";
        break;
      case 2:
        cout << "You've canceled your purchase.\n";
        break;
      default:
        cout << "Something went wrong\n";
        break;
    }
}



class Payment
{
  private:
    int method;
  public:
    int choosePaymentMethod()
    {
        cout << "Please choose your payment method:\n";
        cout << "1. Bkash / Nogod\n";
        cout << "2. Debit Card / Credit Card\n";
        cout << "3. Bank Deposit\n";
        cout << "Input: ";
        cin >> method;
        // recurse in-case of wrong input
        if (!method || method < 1 || method > 3)
            choosePaymentMethod();
        // return method number
        return method;
    }
    void calculateCost(double price, int method)
    {
        double cost, vat, transaction;
        switch(method) {
          case 1:
            vat = (price / 100) * 12;
            transaction = (price / 100) * 1.5;
            cost = price + vat + transaction;
            break;
          case 2:
            vat = (price / 100) * 12;
            transaction = (price / 100) * 1;
            cost = price + vat + transaction;
            break;
          case 3:
            vat = (price / 100) * 12;
            transaction = (price / 100) * 0.05;
            cost = price + vat + transaction;
            break;
          default:
            cout << "Wrong method\n";
            exit(1);
        }
        cout << "You have to pay total of " << cost << " TK to buy this bike.\n\n";
    }
};



int main()
{
    // variables
    Bike *my_bike = new Bike("Yamaha", "Mx800v-Efi", 320, 200000);
    Payment *pay_system = new Payment();
    MyProfile *user;
    int id = 305;
    
    // temp variables to take user inputs
    string strA, strB, strC;
    // ask for login info
    cout << "Enter login credentials: \n";
    cout << "Enter your Username: ";
    cin >> strA;
    cout << "Enter your Password: ";
    cin >> strB;
    // store login info
    user = new MyProfile(strA, strB);
    //status
    cout << "Login successful\n\n";
    
    // ask for basic info 
    cout << "Enter your basic information: \n";
    cout << "Enter your Email: ";
    cin >> strA;
    cout << "Enter your Phone: ";
    cin >> strB;
    cout << "Enter your Hometown: ";
    cin >> strC;
    // store basic info 
    user->setInfo(strA, strB, strC);
    //status
    cout << "Information accepted\n\n";
    
    // show bike info 
    my_bike->showInfo();
    
    // show buying site 
    user->accessPoint(id);
    
    // prompt for calculate total payable cost
    pay_system->calculateCost(my_bike->price, pay_system->choosePaymentMethod());
    
    // confirm purchase
    user->confirm(my_bike);
    
    
    return 0;
}