#include <iostream>

using namespace std;

class Student {
    
 private:
    string id;
    string pass;
    
 public:
    Student (string id, string pwd) {
        this->id = id;
        this->pass = pwd;
    }
    void login(string id, string pass);
    void display()
    {
        string garbage;
        
        cout << "1. Payment" << endl;
        cout << "2. Result" << endl;
        cout << "3. Class Routine" << endl;
        cout << "4. Course list" << endl;
        cout << "5. Student profile" << endl;
        cout << "6. Grade" << endl;
        
        cout << "Choose Options: " << endl;
        cin >> garbage;
        cout << "No service available." << endl;
    }
};

void Student::login(string id, string pwd) {
    
    if (id == this->id && pwd == this->pass) {
            this->display();
    }
    else {
        cout << "Incorrect Password of ID";
    }
}


int main()
{
    Student imran("imran", "1234");
    
    string s_id;
    string s_pass;
    
    cout << "Student Id: ";
    cin >> s_id;
    cout << "Password: ";
    cin >> s_pass;
    
    imran.login(s_id, s_pass);
    
    return 0;
}