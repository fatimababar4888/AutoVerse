//Fatima Babar
// 22i-1565
//CY-B
//Final Project


#pragma once
#include <iostream>
#include <cstdio>
#include <cmath>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include <conio.h>

using namespace std;
#include"user.h"

class admin : public user
{
public:

	admin();
	~admin();
	void Login() override;
	void Logout() override;
	void AddVehicle(string fileName) override;
	void RateVehicle(string fileName) override;
	void AddNotification(string fileName) override;
	void Display() override;
};
