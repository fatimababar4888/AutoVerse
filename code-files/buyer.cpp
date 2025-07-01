//Fatima Babar
// 22i-1565
//CY-B
//Final Project


#include "buyer.h"

buyer::buyer() : user()  //CONSTRUCTOR
{}

buyer::~buyer()   //DESTRUCTOR
{}

void buyer::Login()
{
login_page:
    cout << endl <<"\033[1;31mLOGIN PAGE FOR BUYER\033[0m" << endl;
    cout << "\033[1;33m[1] Register/Sign-in\033[0m" << endl;
    cout << "\033[1;33m[2] Login\033[0m" << endl;
    cin >> first_choice;

    if (first_choice == 1)
    {
        Register("buyer_info.txt");  //FOR REGISTERING NEW USER
        AddID("buyers.txt");    //FOR ADDING ID TO THE TXT FILE SO SYSTEM CAN STORE NEW USER ID AND PASSWORD
        goto login_page;
    }
    else if (first_choice == 2)
    {
        //FOR STORING PASSWORDS FROM THE TXT FILE
        ifstream inputFile("buyers.txt");

        string line;
        string usernames[MAX_USERS];
        string passwords[MAX_USERS];
        int userCount = 0;  

        //Read each line from the file
        while (getline(inputFile, line) && userCount < MAX_USERS)
        {
            istringstream iss(line);

            //Use getline to split the line into username and password
            if (getline(iss, usernames[userCount], ',') && getline(iss, passwords[userCount]))
            {
                userCount++;
            }
        }

        //Close the file
        inputFile.close();


    credentials:
        cout <<endl << "\033[1;31mLOGIN PAGE\033[0m" << endl;
        cout << "\033[1;33mEnter Username:\033[0m" << endl;
        cin >> username;

        cout << "\033[1;33mPassword:\033[0m" << endl;
        //TO DISPLAY ASTERISKS INSTEAD OF PASSWORD
        char ch;
        while ((ch = _getch()) != 13)
        {  //13 is the ASCII code for Enter key
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

void buyer::Display()
{
buyer_menu:
    cout << endl << endl << "\033[1;31mBUYER DISPLAY MENU: \033[0m" << endl;
    cout << "\033[1;33m[1] View Vehicles\033[0m" << endl;
    cout << "\033[1;33m[2] View Auction (Unavailable)\033[0m" << endl;
    cout << "\033[1;33m[3] Request Inspection Report (Unavailable)\033[0m" << endl;
    cout << "\033[1;33m[4] Contact Seller\033[0m" << endl;
    cout << "\033[1;33m[5] View Notifications\033[0m" << endl;
    cout << "\033[1;33m[6] Add a comment on car\033[0m" << endl;
    cout << "\033[1;33m[7] Clear screen and come back to menu\033[0m" << endl;
    cout << "\033[1;33m[8] Logout\033[0m" << endl;
    cout << "\033[1;31mEnter the number of your choice:\033[0m" << endl;
    cin >> menu_choice;
    system("cls");

    if (menu_choice < 1 || menu_choice > 8)  //USER CHOICE VALIDATION
    {
        cout << "\033[1;31mEnter valid number of menu choice.\033[0m" << endl;
        goto buyer_menu;
    }

    else if (menu_choice == 1)
    {
    condition:
        cout << "\033[1;31mCondition of vehicle:\033[0m" << endl;
        cout << "\033[1;33m[1] New\033[0m" << endl;
        cout << "\033[1;33m[2] Used\033[0m" << endl;
        cin >> condition_choice;

        //DISPLAY CARS
        if (condition_choice == 1)
        {
            //DISPLAY NEW CARS
            ifstream inputFile("new_car.txt");

            string line;
            int i = 1;
            while (getline(inputFile, line))
            {
                cout << "[" << i << "] " << line << endl;
                i++;
            }

            inputFile.close();
            goto buyer_menu;
        }
        else if (condition_choice == 2)
        {
            //DISPLAY OLD CARS
            ifstream inputFile("old_car.txt");

            string line;
            int i = 1;
            while (getline(inputFile, line))
            {
                cout << "[" << i << "] " << line << endl;
                i++;
            }

            inputFile.close();
            goto buyer_menu;
        }
        else
        {
            cout << "\033[1;31mEnter valid number of condition.\033[0m" << endl;
            goto condition;
        }
    }

    else if (menu_choice == 2)
    {
        cout << "\033[1;31mService unavailable. Sorry for the inconvenience.\033[0m" << endl;
        goto buyer_menu;
    }

    else if (menu_choice == 3)
    {
        cout << "\033[1;31mService unavailable. Sorry for the inconvenience.\033[0m" << endl;
        goto buyer_menu;
    }

    else if (menu_choice == 4)
    {
        ContactSeller("notification.txt");
    }

    else if (menu_choice == 5)
    {
        ViewNotification();
    }

    else if (menu_choice == 6)
    {
    condition1:
        cout << "\033[1;31mCondition of vehicle:\033[0m" << endl;
        cout << "\033[1;33m[1] New\033[0m" << endl;
        cout << "\033[1;33m[2] Used\033[0m" << endl;
        cin >> condition_choice;

        //DISPLAY CARS
        if (condition_choice == 1)
        {
            //DISPLAY NEW CARS
            ifstream inputFile("new_car.txt");

            string line;
            int i = 1;
            while (getline(inputFile, line))
            {
                cout << "[" << i << "] " << line << endl;
                i++;
            }

            inputFile.close();
            AddComment("new_rating.txt");
        }
        else if (condition_choice == 2)
        {
            //DISPLAY OLD CARS
            ifstream inputFile("old_car.txt");

            string line;
            int i = 1;
            while (getline(inputFile, line))
            {
                cout << "[" << i << "] " << line << endl;
                i++;
            }

            inputFile.close();
            AddComment("old_rating.txt");
        }
        else
        {
            cout << endl << "\033[1;31mEnter valid number of condition.\033[0m" << endl;
            goto condition1;
        }
    }

    else if (menu_choice == 7)
    {
        system("cls");
        goto buyer_menu;
    }

    else if (menu_choice == 8)
    {
        Logout();
    }
    
    else
    {
        cout << endl << "\033[1;31mChoose valid option. Enter again.\033[0m" << endl;
        goto buyer_menu;
    }
}

void buyer::Register(string fileName)
{
    ofstream outputFile(fileName, ios::app); 

    string data;
    system("cls");
    cout << "\033[1;31mFORMAT OF DATA(separation of each specification with commas):" << endl << endl;
    cout << "\033[1;33mFatima,Babar,Female,...\033[0m" << endl << endl;
    cout << "\033[1;31mORDER OF SPECIFICATIONS:\033[0m" << endl;
    cout << "\033[1;33m[1] First Name\033[0m" << endl;
    cout << "\033[1;33m[2] Last Name\033[0m" << endl;
    cout << "\033[1;33m[3] Gender\033[0m" << endl;
    cout << "\033[1;33m[4] Contact Number\033[0m" << endl;
    cout << "\033[1;33m[5] Password\033[0m" << endl << endl;
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
}

void buyer::AddID(string fileName)
{
    ofstream outputFile(fileName, ios::app);  // Open file in append mode

    string data;
    system("cls");
    cout << "\033[1;31mEnter ID:\033[0m" << endl;
    cout << "\033[1;31mFORMAT OF DATA(separation of each specification with commas):\033[0m" << endl;
    cout << "\033[1;33mFatima,12345\033[0m" << endl;
    cout << "\033[1;31mORDER OF SPECIFICATIONS:\033[0m" << endl;
    cout << "\033[1;33m[1] ID\033[0m" << endl;
    cout << "\033[1;33m[2] Password\033[0m" << endl;
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

    Display();
}

void buyer::ViewNotification()
{
    system("cls");
    ifstream inputFile("notification.txt");

    string line;
    int i = 1;
    cout << "\033[1;31mNOTIFICATIONS:\033[0m" << endl;

    while (getline(inputFile, line))
    {
        cout << "[" << i << "] " << line << endl;
        i++;
    }

    inputFile.close();

    Display();
}

void buyer::ContactSeller(string fileName)
{
    ofstream outputFile(fileName, ios::app);

    outputFile << "Contact Seller notification: Buyer has requested to contact the seller." << endl;

    //Close the file using outputFile
    outputFile.close();

    cout << endl << "\033[1;31mNotification sent to seller.\033[0m" << endl;

    Display();
}

void buyer::AddComment(string fileName)
{
    ofstream outputFile(fileName, ios::app); 

    string data;
    cout << endl << "\033[1;31mEnter data for " << fileName << " (enter 'ok' to finish):\033[0m" << endl;
    cout << "\033[1;33mEnter car number first and then the comment.\033[0m" << endl;
    cout << "\033[1;31mFORMAT:\033[0m" << endl;
    cout << "\033[1;33m[car number] comment...\033[0m" << endl << endl;
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

    ofstream notificationFile("notification.txt", ios::app);

    notificationFile << "For seller and admin: Comment on car was added by the buyer." << endl;

    //Close the file using outputFile
    notificationFile.close();

    cout << endl << "\033[1;31mNotification sent to seller and admin.\033[0m" << endl;
}

void buyer::Logout()
{
    system("cls");
    cout << "\033[1;31mLOGGING OUT...\033[0m" << endl;
}