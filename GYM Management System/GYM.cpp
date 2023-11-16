#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <cstdlib>
#include <string>

using namespace std;

class alogin {
        string admin;

public:
    int adlogin() {
        cout << "Enter the admin code" << endl;
        cin >> admin;
        if (admin == "adminA1" || admin == "adminA2" || admin == "adminA3") {
            int p = getadpassword();
            if (p == 1) {
                cout << "Login successful" << endl;
                return 1;
            }
        } else {
            cout << "User name not found" << endl;
            adlogin();
            cout << "Login failed" << endl;
            return 0;
        }
    }

    int getadpassword();
};

int alogin::getadpassword() {
    string pw;
    cout << "Enter the password" << endl;
    cin >> pw;
    if (pw == "gymadmin123") {
        cout << "WELCOME!!" << endl;
        return 1;
    } else {
        cout << "Entered password is incorrect" << endl;
        getadpassword();
        return 0;
    }
}

void allotment_gold(int gc, int sc) {
    if (gc != 0) {
        cout << gc << endl;
        cout << "Trainer allotted\n";
    } else {
        cout << "No trainer available\n";
    }
}

void allotment_silver(int gc, int sc) {
    if (sc != 0) {
        cout << sc << endl;
        cout << "Trainer allotted\n";
    } else {
        cout << "\nNo trainer available\n";
        if (gc != 0) {
            cout << "Enter another class\n";
            allotment_gold(gc, sc);
        }
    }
}

int trainee_allotment(char* c) {
    char class_type[10];
    int i, gold_class = 3, silver_class = 5;
    strcpy(class_type, c);

    if ((gold_class != 0) || (silver_class) != 0) {
        if (strcmp(class_type, "gold") == 0) {
            gold_class--;
            allotment_gold(gold_class, silver_class);
        } else if (strcmp(class_type, "silver") == 0) {
            silver_class--;
            allotment_silver(gold_class, silver_class);
        }
    } else {
        cout << "No trainer available\n";
        return 1;
    }
};

class Finance {
public:
    void calculateExpenses() {
        // Add logic to calculate expenses
        // For simplicity, let's assume some fixed expenses
        float rent = 5000.0;
        float utilities = 1000.0;
        float salaries = 3000.0;

        float totalExpenses = rent + utilities + salaries;

        cout << "Total Expenses: $" << totalExpenses << endl;
    }

    void displayFinancialInfo() {
        // Display financial information to the admin
        cout << "Financial Information:\n";
        calculateExpenses();
        // Add more financial information if needed
    }

    void displayMembershipInfo(float fee, int daysRemaining) {
        // Display membership-related details to members
        cout << "Membership Information:\n";
        cout << "Membership Fee: $" << fee << endl;
        cout << "Days Remaining to Submit Fee: " << daysRemaining << " days" << endl;
    }
};

class member {
    int member_number;
    char mem_name[50];
    char classs[50];
    char timings[50];
    float fee;
    long int contact;

public:
    int time_slots() {
        int k;

        cout << "Please select your preferred timings" << endl;
        cout << "1. Morning 6-7" << endl;
        cout << "2. Morning 7-8" << endl;
        cout << "3. Morning 8-9" << endl;
        cout << "4. Evening 4-5" << endl;
        cout << "5. Evening 5-6" << endl;
        cout << "6. Evening 6-7" << endl;
        cin >> k;
        switch (k) {
            case 1:
                strcpy(timings, "6AM-7AM");
                break;
            case 2:
                strcpy(timings, "7AM-8AM");
                break;
            case 3:
                strcpy(timings, "8AM-9AM");
                break;
            case 4:
                strcpy(timings, "4PM-5PM");
                break;
            case 5:
                strcpy(timings, "5PM-6PM");
                break;
            case 6:
                strcpy(timings, "6PM-7PM");
                break;
        }
    }

    void create_mem() {
        int k, l, j;
        cout << "Please Enter The member Number: ";
        cin >> member_number;
        cout << "Please Enter The Name of The member: ";
        getchar();
        cin.getline(mem_name, 50);
        cout << "Please Enter the contact number: ";
        cin >> contact;
        cout << "1.Gold class\n 2.Silver class\n";
        cout << "Enter the choice: ";
        cin >> k;
        switch (k) {
            case 1:
                {
                    strcpy(classs, "Gold");
                    fee = 2500;
                    cout << "Your monthly fee would be: " << fee << endl;
                    l = trainee_allotment(classs);
                }
                break;
            case 2:
                {
                    strcpy(classs, "Silver");
                    fee = 2000;
                    cout << "Your monthly fee would be: " << fee << endl;
                    l = trainee_allotment(classs);
                }
                break;
        }
        time_slots();
    }

    void show_mem() {
        cout << "Member code: " << member_number << endl;
        cout << "Name: " << mem_name << endl;
        cout << "Category: " << classs << endl;
        cout << "Fee: " << fee << endl;
        cout << "Contact: " << contact << endl;
        cout << "Timings: " << timings << endl;
    }

    int getmem() {
        return member_number;
    }

    float getfee() {
        return fee;
    }

    char* getName() {
        return mem_name;
    }

    float getcontact() {
        return contact;
    }
    
    int adlogin() {
        cout << "Admin login not allowed for members" << endl;
        return 0;
    }
    
    int getadpassword() {
        cout << "Admin password not allowed for members" << endl;
        return 0;
    }

    // Membership-related details
    void displayMembershipDetails(Finance& finance) {
        finance.displayMembershipInfo(getfee(), 30);  // Assuming 30 days for simplicity
    }
};

fstream fp;
member m1;

void save_member() {
    fp.open("newdata2.dat", ios::out | ios::app);
    m1.create_mem();
    fp.write((char*)&m1, sizeof(m1));
    fp.close();
    cout << "The member has been successfully added." << endl;
    getchar();
}

void show_all() {
    system("cls");
    cout << "\t\tRECORDS..." << endl;
    fp.open("newdata2.dat", ios::in);
    while (fp.read((char*)&m1, sizeof(m1))) {
        m1.show_mem();
        getchar();
    }
    fp.close();
}

void display_record(int num) {
    bool found = false;
    fp.open("newdata2.dat", ios::in);
    while (fp.read((char*)&m1, sizeof(m1))) {
        if (m1.getmem() == num) {
            system("cls");
            m1.show_mem();
            found = true;
        }
    }

    fp.close();
    if (found == true)
        cout << "No record found" << endl;
    getchar();
}

void edit_member() {
    int num;
    bool found = false;
    system("cls");
    cout << "Please Enter The member number: ";
    cin >> num;

    fp.open("newdata2.dat", ios::in | ios::out);
    while (fp.read((char*)&m1, sizeof(m1)) && found == false) {
        if (m1.getmem() == num) {
            m1.show_mem();
            cout << "Please Enter The New details of the member: " << endl;
            m1.create_mem();
            int pos = 1 * sizeof(m1);
            fp.seekp(pos, ios::cur);
            fp.write((char*)&m1, sizeof(m1));
            cout << "Record Successfully Updated." << endl;
            found = true;
        }
    }
    fp.close();
    if (found == false)
        cout << "Record Not Found." << endl;
    getchar();
}

void delete_member() {
    int num;
    system("cls");
    cout << "Please Enter The member number: ";
    cin >> num;
    fp.open("newdata2.dat", ios::in | ios::out);
    fstream fp2;
    fp2.open("Temp2.dat", ios::out);
    fp.seekg(0, ios::beg);
    while (fp.read((char*)&m1, sizeof(m1))) {
        if (m1.getmem() != num) {
            fp2.write((char*)&m1, sizeof(m1));
        }
    }
    fp2.close();
    fp.close();
    remove("newdata2.dat");
    rename("Temp2.dat", "newdata2.dat");
    cout << "Record Deleted." << endl;
    getchar();
}

void fnmanage() {
    // ... (unchanged fnmanage function)

    Finance finance;  // Create an instance of the Finance class

    for (;;) {
        system("cls");
        int option;
        cout << "\t***********************************************" << endl;
        cout << "\tPress 1 to CREATE MEMBER" << endl;
        cout << "\tPress 2 to DISPLAY ALL RECORDS" << endl;
        cout << "\tPress 3 to SEARCH FOR A PARTICULAR RECORD " << endl;
        cout << "\tPress 4 to EDIT MEMBER DETAILS" << endl;
        cout << "\tPress 5 to DELETE MEMBER" << endl;
        cout << "\tPress 6 to GO BACK TO MAIN MENU" << endl;
        cout << "\tPress 7 to DISPLAY FINANCIAL INFORMATION" << endl; // Added option for financial info
        cout << "\t***********************************************" << endl;

        cout << "\n\n\tOption: ";
        cin >> option;

        switch (option) {
            // ... (unchanged cases)
            case 1:
                system("cls");
                save_member();
                break;

            case 2:
                show_all();
                break;

            case 3:
                int num;
                system("cls");
                cout << "\n\n\tPlease Enter The member Number: ";
                cin >> num;
                display_record(num);
                break;

            case 4:
                edit_member();
                break;

            case 5:
                delete_member();
                break;

            case 6:
                system("cls");
                break;

            case 7:
                system("cls");
                finance.displayFinancialInfo();
                break;

            default:
                fnmanage();
                break;  // Add break statement for each case
        }
    }
}
void fitness() {
    cout << "displaying fitness tips..." << endl;
    std::ifstream f("tips.txt");

    if (f.is_open()) {
        std::cout << f.rdbuf();
    }
}

void fnuser() {
    for (;;) {
        int m;
        cout << "1.Join Gym\n2.Quit Gym\n3.Edit your profile\n";
        cin >> m;
        switch (m) {
            case 1:
                system("cls");
                save_member();
                break;
            case 2:
                delete_member();
                break;
            case 3:
                edit_member();
                break;
        }
    }
}

int main() {
    // ... (unchanged main function)
    int i, k;
    string name, code;
    cout << "SELECT MODE" << endl;
    cout << "1. USER" << endl;
    cout << "2. ADMIN" << endl;
    cin >> i;

    if (i == 1) {
        cout << "You're in user mode" << endl;
        fnuser();
    }

    if (i == 2) {
        cout << "You're in admin mode" << endl;

        alogin ad;
        k = ad.adlogin();
        if (k == 1) {
            fnmanage();
        } else {
            cout << "You cannot access managerial details!" << endl;
        }
    }
    return 0;
}
