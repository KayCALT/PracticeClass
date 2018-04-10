//Practice1 友元类，友元成员函数名称空间

#include<iostream>
#include<string>
#include"tv.h"

using std::cout;
using std::endl;
using interactive::tv;
using interactive::remote;

int main()
{
	tv skyworth(interactive::On, 350);
	tv hisense(interactive::On, 500);
	skyworth.DispSettings();
	hisense.DispSettings();
	//dsfa
	skyworth.ChannelUp();
	hisense.ChannelDown();
	skyworth.VolDown();
	hisense.VolUp();
	skyworth.DispSettings();
	hisense.DispSettings();

	remote controller;
	controller.Set_Input(skyworth);
	controller.Set_Channel(skyworth, 369);
	controller.Set_Mode(hisense);
	controller.Set_Channel(hisense, 89);
	skyworth.DispSettings();
	hisense.DispSettings();

	std::cin.get();
}




