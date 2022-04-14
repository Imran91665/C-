#include <iostream>
using namespace std;
#define TOTAL_RES 4
#define TOTAL_DIV 8
#define TOTAL_FOOD 10
#define VAT 10


int find_minimum(float row[]) {
    
    int index = 0;
    float min = row[0];
    
    for (int i = 1; i < TOTAL_RES; i++) {
        if (row[i] < min)
        {
          index = i;
          min = row[i];
        } 
    }
    return index;
}

class Efood {
  private:
    float distance[TOTAL_DIV][TOTAL_RES] = 
    {
        {236.7, 237.4, 237,239},    // Chattogram
        {125, 123, 251, 406},  // Rajshahi
        {220, 266, 265, 265.5},  // Khulna
        {171, 141, 178, 116},  // Barishal
        {247, 242, 245, 295},  // Sylhet
        {4.9, 4.8, 3.6, 5.8}, // Dhaka
        {306.1, 306, 307, 305.8},  // Rangpur
        {117, 117, 118, 120}   // Mymensingh
    };
    string divisions[TOTAL_DIV] = {
        "Chattogram",
        "Rajshahi",
        "Khulna",
        "Barishal",
        "Sylhet",
        "Dhaka",
        "Rangpur",
        "Mymensingh"
    };
  public:
    int nearest;
    string restaurents[TOTAL_RES] = {
        "Pizza Hut",
        "KFC",
        "Star Kabab",
        "Nando's"
    };
    void find_nearest(int division)
    {
        division--;
        nearest = find_minimum(distance[division]);
        cout << "\nYour Division: " << divisions[division] << endl;
        for (int i = 0; i < TOTAL_RES; i++)
        {
            cout << restaurents[i] << " is " << distance[division][i] << " KM away.\n";
        }
        cout << "You can buy food from the nearest " << restaurents[nearest] << endl;
    }
    
    int show_divisions()
    {
        int div;
        
        cout << "Choose your division:\n";
        for(int i = 0; i < TOTAL_DIV; i++)
        {
            cout << i + 1 << ")" << divisions[i] << endl;
        }
        cout << ">>>>> Select (1-8): ";
        cin >> div;
        return div;
    }
    
    void show_menu();
};

class FoodMenu : public Efood {
  private:
    float prices[TOTAL_FOOD] = {
        450,
        800,
        150,
        250,
        150,
        180,
        600,
        100,
        185,
        480
    };
    string food_menu[TOTAL_FOOD] = {
        "Burger",
        "Pizza",
        "Chow mein",
        "Fried Chicken",
        "Soup",
        "Fried Rice",
        "Peri Peri Chicken",
        "Grill Chicken",
        "Tandori",
        "Lemonade Grilled Chicken"
    };
  public:
    void show_menu() 
    {
        cout << endl << "Food Menu:\n";
        for(int i = 0; i < TOTAL_FOOD; i++)
        {
            cout << i + 1 <<  ")" << food_menu[i] << "(" << prices[i] << "/-)" << endl;
        }
    }
    void calculate_bill()
    {
        int item = 1;
        float raw = 0;
        float total = 0;
        
        cout << "\nPlease select food item by index number.\n";
        cout << "Enter 0 when done.\n";
        
        while (item != 0)
        {
            cout << ">>>>> Select (0-10): ";
            cin >> item;
            
            if (item == 0)
            {
                cout << "Calculating Bill...\n";
                break;
            } else 
            {
                raw = prices[item - 1];
                total += raw + (raw/100) * VAT;
                cout << "Selected 1 " << food_menu[item - 1] << endl;
            }   
        }
        
        if (total <= 0)
        {
            cout << "No food was selected.\n";
            exit(0);
        }
        
        cout << "Your order will cost: " << total << "/-" << endl;
    }
    
    void take_order() 
    {
        int order = 0;
        cout << "\nConfirm your order:\n";
        cout << "1)Confirm\n0)Cancel\n";
        cout << "Enter: ";
        cin >> order;
        if (order)
        {
            cout << "Order completed. Thanks for buying from us.\n";
        } else {
            cout << "Your order has been canceled.\n";
        }
    }
};

int main()
{
    Efood *mySite = new Efood;
    FoodMenu *myMenu = new FoodMenu;
    
    int div;
    
    div = mySite->show_divisions();
    mySite->find_nearest(div);
    myMenu->show_menu();
    myMenu->calculate_bill();
    myMenu->take_order();
    
    return 0;
}