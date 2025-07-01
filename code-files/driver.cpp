//Fatima Babar
// 22i-1565
//CY-B
//Final Project


#include<iostream>
#include"user.h"
#include"admin.h"
#include "buyer.h"
#include "seller.h"

int main()
{
    user* users[3];

    int choice;

    cout << "\033[1;33m_________________________________________________________________________________________\033[0m" << endl;
    cout << "\033[1;33m|(_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_)|\033[0m" << endl;
    cout << "\033[1;33m|(/                                                                                   /)|\033[0m" << endl;
    cout << "\033[1;33m|(\\                          \033[1;3;4;31m                                  \033[0m                       \033[1;33m\\)|\033[0m" << endl;
    cout << "\033[1;33m|(" << "/                          \033[1;3;4;31m|WELCOME TO CAR MANAGEMENT SYSTEM|\033[0m                       " << "\033[0m" << "\033[1;33m/)|\033[0m" << endl;
    cout << "\033[1;33m|(\\                                                                                   \\)|\033[0m" << endl;
    cout << "\033[1;33m|(_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_)|\033[0m" << endl;
    cout << "\033[1;33m|(_____________________________________________________________________________________)|\033[0m" << endl;
    cout << endl << endl << "\033[1;31mPress enter to proceed...\033[0m" << endl;
    getchar();

#ifdef _WIN32
    system("cls"); 
#endif


    menu:
    cout << "\033[1;31mWELCOME TO USER MENU:\033[0m" << endl;
    cout << "\033[1;33m[1] Admin\033[0m" << endl;
    cout << "\033[1;33m[2] Buyer\033[0m" << endl;
    cout << "\033[1;33m[3] Seller\033[0m" << endl << endl;
    cout << "\033[1;31mEnter the number of your choice:\033[0m" << endl;
    cin >> choice;

   

    if (choice != 1 && choice != 2 && choice != 3)
    {
        cout << "Enter valid choice." << endl << endl;
        goto menu;
    }


    users[0] = new admin;
    users[1] = new buyer;
    users[2] = new seller;

    switch (choice)
    {
        case 1:
            users[0]->Login();
            break;

        case 2:
            users[1]->Login();
            break;

        case 3:
            users[2]->Login();
            break;
    }

   for (int i = 0; i < 3; i++)
   {
       delete users[i];
   }

    return 0;
}
