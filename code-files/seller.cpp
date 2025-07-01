//Fatima Babar
// 22i-1565
//CY-B
//Final Project


#include "seller.h"

seller::seller() : user()
{}

seller::~seller()
{}

void seller::Login()
{
login_page:
    cout << "\033[1;31mLOGIN PAGE FOR SELLER\033[0m" << endl;
    cout << "\033[1;33m[1] Register/Sign-in\033[0m" << endl;
    cout << "\033[1;33m[2] Login\033[0m" << endl;
    cin >> first_choice;

    if (first_choice == 1)
    {
        Register("seller_info.txt");
        AddID("sellers.txt");
        goto login_page;
    }

    else if (first_choice == 2)
    {
        ifstream inputFile("sellers.txt");

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

    credentials:
        cout << endl << "\033[1;31mLOGIN PAGE\033[0m" << endl;
        cout << "\033[1;33mEnter Username:\033[0m " << endl;
        cin >> username;

        cout << "\033[1;33mPassword: \033[0m" << endl;
        char ch;
        while ((ch = _getch()) != 13)
        {  // 13 is the ASCII code for Enter key
            password.push_back(ch);
            cout << '*';
        }

        for (int i = 0; i < userCount; i++)
        {
            if (username == usernames[i] && password == passwords[i])
            {
                Display();
                break;
            }
            else  //PASSWORD AND USERNAME VALIDATION
            {
                cout << endl << "\033[1;31mUsername or password is incorrect.\033[0m" << endl << endl;
                goto credentials;
            }
        }
    }
}

void seller::Display()
{
seller_menu:
    cout << endl << endl << "\033[1;31mSELLER DISPLAY MENU: \033[0m" << endl;
    cout << "\033[1;33m[1] View Vehicles\033[0m" << endl;
    cout << "\033[1;33m[2] Add Vehicle\033[0m" << endl;
    cout << "\033[1;33m[3] Remove Vehicle (Unavailable)\033[0m" << endl;
    cout << "\033[1;33m[4] Register in Auction (Unavailable)\033[0m" << endl;
    cout << "\033[1;33m[5] View Notifications\033[0m" << endl;
    cout << "\033[1;33m[6] Clear screen and come back\033[0m" << endl;
    cout << "\033[1;33m[7] Logout\033[0m" << endl;
    cout << endl << "\033[1;31mEnter the number of your choice: \033[0m" << endl;
    cin >> menu_choice;

    if (menu_choice < 1 || menu_choice > 7)
    {
        cout << endl << "\033[1;31mEnter valid number of menu choice.\033[0m" << endl;
        goto seller_menu;
    }

    else if (menu_choice == 1)
    {
    condition1:
        cout << endl << "\033[1;31mCondition of vehicle:\033[0m" << endl;
        cout << "\033[1;33m[1] New\033[0m" << endl;
        cout << "\033[1;33m[2] Used\033[0m" << endl;
        cin >> condition_choice;

        //DISPLAY CARS
        if (condition_choice == 1)
        {
            //DISPLAY NEW CARS
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
            goto seller_menu;
        }
        else if (condition_choice == 2)
        {
            //DISPLAY OLD CARS
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
            goto seller_menu;
        }
        else
        {
            cout << endl << "\033[1;31mEnter valid number of condition.\033[0m" << endl;
            goto condition1;
        }
    }

    else if (menu_choice == 2)
    {
        //CHOOSING CONDITION OF VEHICLE
    condition2:
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
            cout << endl << "\033[1;31mEnter valid number of condition.\033[0m" << endl;
            goto condition2;
        }
    }

    else if (menu_choice == 3)
    {
        cout << endl << "\033[1;31mService unavailable. Sorry for the inconvenience.\033[0m" << endl;
        goto seller_menu;
    }

    else if (menu_choice == 4)
    {
        cout << endl << "\033[1;31mService unavailable. Sorry for the inconvenience.\033[0m" << endl;
        goto seller_menu;
    }

    else if (menu_choice == 5)
    {
        ViewNotification();
    }

    else if (menu_choice == 6)
    {
        system("cls");
        goto seller_menu;
    }

    else if (menu_choice == 7)
    {
        Logout();
    }

    else
    {
        cout << endl << "\033[1;31mChoose valid option. Enter again.\033[0m" << endl;
        goto seller_menu;
    }

}

void seller::Register(string fileName)
{
    ofstream outputFile(fileName, ios::app);  // Open file in append mode

    string data;
    cout << endl << "\033[1;31mFORMAT OF DATA(separation of each specification with commas):\033[0m" << endl;
    cout << "\033[1;33mFatima,Babar,Female,...\033[0m" << endl;
    cout << "\033[1;31mORDER OF SPECIFICATIONS:\033[0m" << endl;
    cout << "\033[1;33m[1] First Name\033[0m" << endl;
    cout << "\033[1;33m[2] Last Name\033[0m" << endl;
    cout << "\033[1;33m[3] Gender\033[0m" << endl;
    cout << "\033[1;33m[4] Contact Number\033[0m" << endl;
    cout << "\033[1;33m[5] Password\033[0m" << endl;
    cout << "\033[1;31mEnter data for " << fileName << " (enter 'ok' to finish):\033[0m" << endl << endl;

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
}

void seller::AddID(string fileName)
{
    ofstream outputFile(fileName, ios::app);  // Open file in append mode

    string data;
    cout << "\033[1;31mFORMAT OF DATA(separation of each specification with commas):\033[0m" << endl;
    cout << "\033[1;33mFatima,12345\033[0m" << endl;
    cout << "\033[1;31mORDER OF SPECIFICATIONS:\033[0m" << endl;
    cout << "\033[1;33m[1] ID\033[0m" << endl;
    cout << "\033[1;33m[2] Password\033[0m" << endl;
    cout << "\033[1;31mEnter data for " << fileName << " (enter 'ok' to finish):\033[0m" << endl << endl;

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
}

void seller::ViewNotification()
{
    ifstream inputFile("notification.txt");

    // Read and display each line in a loop
    string line;
    int i = 1;
    cout << endl << "\033[1;31mNOTIFICATIONS:\033[0m" << endl;
    while (getline(inputFile, line))
    {
        cout << "[" << i << "] " << line << endl;
        i++;
    }

    inputFile.close();
    Display();
}


void seller::AddVehicle(string fileName)
{
    ofstream outputFile(fileName, ios::app);  // Open file in append mode

    string data;
    cout << "\033[1;31mFORMAT OF DATA(separation of each specification with commas):\033[0m" << endl;
    cout << "\033[1;33mHonda,1500,Blue,...\033[0m" << endl;
    cout << "\033[1;31mORDER OF SPECIFICATIONS:\033[0m" << endl;
    cout << "\033[1;33m[1] Company\033[0m" << endl;
    cout << "\033[1;33m[2] Name\033[0m" << endl;
    cout << "\033[1;33m[3] Price\033[0m" << endl;
    cout << "\033[1;33m[4] Color\033[0m" << endl;
    cout << "\033[1;33m[5] Model\033[0m" << endl;
    cout << "\033[1;33m[6] Fuel Type\033[0m" << endl;
    cout << "\033[1;31mEnter data for " << fileName << " (enter 'ok' to finish):\033[0m" << endl;

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

    ofstream notificationFile("notification.txt", ios::app);

    notificationFile << "A vehicle was added by the seller" << endl;

    //Close the file using outputFile
    notificationFile.close();

    cout << endl << "\033[1;31mNotification sent to admin.\033[0m" << endl;

    Display();
}

void seller::Logout()
{
    system("CLS");
    cout << "\033[1;31mLOGGING OUT...\033[0m" << endl;
}