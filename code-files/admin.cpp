//Fatima Babar
// 22i-1565
//CY-B
//Final Project


#include"admin.h"

admin::admin() : user() 
{}

admin::~admin() 
{}

void admin::Login()
{
    //FILE HANDLING TO VALIDATE CREDENTIALS
    ifstream inputFile("admin.txt");

    string line;
    string usernames[MAX_USERS];
    string passwords[MAX_USERS];
    int userCount = 0;  // To keep track of the number of users

    // Read each line from the file
    while (getline(inputFile, line) && userCount < MAX_USERS)
    {
        istringstream iss(line);

        // Use getline to split the line into username and password
        if (getline(iss, usernames[userCount], ',') && getline(iss, passwords[userCount]))
        {
            userCount++;
        }
    }

    // Close the file
    inputFile.close();

login_page:
    //ENTERING CREDENTIALS
    cout << endl << "\033[1;31mLOGIN PAGE FOR ADMIN\033[0m" << endl;
    cout << "\033[1;33mEnter Username:\033[0m" << endl;
    cin >> username;

    cout << "\033[1;33mPassword:\033[0m" << endl;
    char ch;
    while ((ch = _getch()) != 13)
    {  //13 is the ASCII code for Enter key
        password.push_back(ch);
        cout << '*';  
    }

    if (username == usernames[0] && password == passwords[0])
    {
        Display();
    }
    else //PASSWORD AND USERNAME VALIDATION
    {
        cout << endl << "\033[1;31mUsername or Password is incorrect. Please try again.\033[0m" << endl << endl;
        goto login_page;
    }
}

void admin::Display()
{
admin_menu:
    cout << endl << endl << "\033[1;31mADMIN DISPLAY MENU :\033[0m" << endl;
    cout << "\033[1;33m[1] Add Vehicle\033[0m" << endl;
    cout << "\033[1;33m[2] Remove Vehicle (Unavailable)\033[0m" << endl;
    cout << "\033[1;33m[3] Manage Inspection Requests (Unavailable)\033[0m" << endl;
    cout << "\033[1;33m[4] Add Notification\033[0m" << endl;
    cout << "\033[1;33m[5] Remove Notification and comments (Unavailable)\033[0m" << endl;
    cout << "\033[1;33m[6] Rate a Vehicle\033[0m" << endl;
    cout << "\033[1;33m[7] Clear screen and come back to menu\033[0m" << endl;
    cout << "\033[1;33m[8] Logout\033[0m" << endl;
    cout << "\033[1;31mEnter the number of your choice: \033[0m" << endl;
    cin >> menu_choice;

    if (menu_choice < 1 || menu_choice > 8)
    {
        cout << endl << "\033[1;31mEnter valid number of menu choice.\033[0m" << endl;
        goto admin_menu;
    }

    else if (menu_choice == 1)
    {
        //CHOOSING CONDITION OF VEHICLE
    condition:
        cout << endl << "\033[1;31mCondition of vehicle:\033[0m" << endl;
        cout << "\033[1;33m[1] New\033[0m" << endl;
        cout << "\033[1;33m[2] Used\033[0m" << endl;
        cin >> condition_choice;

        //ENTERING NEW VEHICLE IN TEXT FILE
        if (condition_choice == 1)
        {
            AddVehicle("new_car.txt");
        }
        else if (condition_choice == 2)
        {
            AddVehicle("old_car.txt");
        }
        else
        {
            cout << endl << "\033[1;31mEnter valid number of condition\033[0m" << endl;
            goto condition;
        }
    }

    else if (menu_choice == 2)
    {
        cout << endl << "\033[1;31mService unavailable. Sorry for the inconvenience.\033[0m" << endl;
        goto admin_menu;
    }


    else if (menu_choice == 3)
    {
        cout << endl << "\033[1;31mService unavailable. Sorry for the inconvenience.\033[0m" << endl;
        goto admin_menu;
    }


    else if (menu_choice == 4)
    {
        AddNotification("notifications.txt");
    }

    else if (menu_choice == 5)
    {
        cout << endl << "\033[1;31mService unavailable. Sorry for the inconvenience.\033[0m" << endl;
        goto admin_menu;
    }


    else if (menu_choice == 6)
    {
    r_condition:
        cout << endl << "\033[1;31mCondition of vehicle:\033[0m" << endl;
        cout << "\033[1;33m[1] New\033[0m" << endl;
        cout << "\033[1;33m[2] Used\033[0m" << endl;
        cin >> rating_condition_choice;

        if (rating_condition_choice == 1)
        {
            //TO DISPLAY CARS FIRST AND LET THE USER CHOOSE 
            ifstream inputFile("new_car.txt");

            // Read and display each line in a loop
            string line;
            int i = 1;
            while (getline(inputFile, line))
            {
                cout << "[" << i << "] " << line << endl;
                i++;
            }

            inputFile.close();
            RateVehicle("new_rating.txt");
        }

        else if (rating_condition_choice == 2)
        {
            //TO DISPLAY CARS FIRST AND LET THE USER CHOOSE 
            ifstream inputFile("old_car.txt");

            // Read and display each line in a loop
            string line;
            int i = 1;
            while (getline(inputFile, line))
            {
                cout << "[" << i << "] " << line << endl;
                i++;
            }

            inputFile.close();
            RateVehicle("old_rating.txt");
        }

        else
        {
            cout << endl << "\033[1;31mEnter valid number of condition.\033[0m" << endl;
            goto r_condition;
        }
    }

    else if (menu_choice == 7)
    {
        system("cls");
        goto admin_menu;
    }

    else if (menu_choice == 8)
    {
        Logout();
    }
}
   

void admin::AddVehicle(string fileName)
{
    ofstream outputFile(fileName, ios::app);  // Open file in append mode

    string data;
    cout << endl << "\033[1;31mFORMAT OF DATA(separation of each specification with commas):\033[0m" << endl << endl;
    cout << "\033[1;33mHonda,Accord,1500,Blue,...\033[0m" << endl << endl;
    cout << "\033[1;31mORDER OF SPECIFICATIONS:\033[0m" << endl;
    cout << "\033[1;33m[1] Company\033[0m" << endl;
    cout << "\033[1;33m[2] Name\033[0m" << endl;
    cout << "\033[1;33m[3] Price\033[0m" << endl;
    cout << "\033[1;33m[4] Color\033[0m" << endl;
    cout << "\033[1;33m[5] Model\033[0m" << endl;
    cout << "\033[1;33m[6] Fuel Type\033[0m" << endl << endl;
    cout << "\033[1;31mEnter data for \033[0m" << fileName << " (enter 'ok' to finish):\033[0m" << endl;

    while (true)
    {
        cout << "> ";
        getline(cin, data);

        if (data == "ok")
        {
            break;
        }

        outputFile << data << endl;
    }

    cout << "\033[1;31mData successfully written to " << fileName << "\033[0m" << endl;

    outputFile.close();
    Display();
}

void admin::RateVehicle(string fileName)
{
    ofstream outputFile(fileName, ios::app);  //Open file in append mode

    string data;
    cout << endl << "\033[1;31mEnter data for " << fileName << " (enter 'ok' to finish):\033[0m" << endl;
    cout << "\033[1;33mFirst enter number of vehicle you want to rate and then enter the rating (out of 10).\033[0m" << endl;
    cout << "\033[1;31mFORMAT:\033[0m" << endl;
    cout << "\033[1;33m[car number] rating/10\033[0m" << endl << endl;
    while (true)
    {
        cout << "> ";
        getline(cin, data);

        if (data == "ok")
        {
            break;
        }

        outputFile << data << endl;
    }

    cout << "\033[1;31mData successfully written to " << fileName << "\033[0m" << endl;

    outputFile.close();
    Display();
}

void admin::AddNotification(string fileName)
{
    ofstream outputFile(fileName, ios::app);  //Open file in append mode

    string data;
    cout << endl << "\033[1;31mEnter data for " << fileName << " (enter 'ok' to finish):\033[0m" << endl;

    while (true)
    {
        cout << "> ";
        getline(cin, data);

        if (data == "ok")
        {
            break;
        }

        outputFile << data << endl;
    }

    cout << endl << "\033[1;31mData successfully written to " << fileName << "\033[0m" << endl;

    outputFile.close();
    Display();
}


void admin::Logout() 
{
    system("CLS");
    cout << "\033[1;31mLOGGING OUT...\033[0m" << endl;
}
