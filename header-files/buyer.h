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

//Fatima Babar
// 22i-1565
//CY-B
//Final Project


using namespace std;
#include"user.h"

class buyer : public user
{
public:

	buyer();
	~buyer();
	void Login() override;
	void Register(string fileName) override;
	void AddID(string fileName) override;
	void ViewNotification() override;
	void Logout() override;
	void Display() override;
	void AddComment(string fileName) override;
	void ContactSeller(string fileName) override;
};