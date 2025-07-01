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
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <conio.h>

using namespace std;
#include"user.h"

class seller : public user
{
public:

	seller();
	~seller();
	void Login() override;
	void Register(string fileName) override;
	void AddID(string fileName) override;
	void ViewNotification() override;
	void AddVehicle(string fileName) override;
	void Logout() override;
	void Display() override;
};