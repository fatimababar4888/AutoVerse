//Fatima Babar
// 22i-1565
//CY-B
//Final Project

#pragma once
#include <iostream>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <conio.h>

using namespace std;
int const MAX_USERS = 100;

class user 
{
protected:
    string username;
    string password;
    int menu_choice;
    int condition_choice;
    int rating_condition_choice;
    int rating_car_choice;
    int first_choice;

public:
    user();
    virtual ~user();
    virtual void Login();
    virtual void Display();
    virtual void Register(string fileName);
    virtual void AddID(string filename);
    virtual void AddVehicle(string fileName);
    virtual void ViewNotification();
    virtual void AddNotification(string fileName);
    virtual void RateVehicle(string fileName);
    virtual void ContactSeller(string fileName);
    virtual void AddComment(string fileName);
    virtual void Logout();
};
