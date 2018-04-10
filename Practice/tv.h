#pragma once
#include<iostream>

//在第二次修改时为了使用前向声明的方法同时又不想因此将枚举类的位置强行
//从一个类移到另一个类中，不惜采用新建一自己的名称空间interactive，同时试验效果
//结果成功，相关经验为:名称空间可用于封装（我自己目前这么理解）自己创建的类，我这里将需要的枚举也
//一同放入名称空间，使用作用域解析运算符或相关using声明即可使用。
//放入名称空间后不同的一点是如果要在外边定义里边的类，需要using声明或像现在这样表明作用域（Interactive：：）
//否则声明的类仍为全局空间的类，并不是自创名称空间里的类。
//使用作用域解析运算符之后，类和函数的定义相当于在名称空间内定义了，代码块内使用名称空间内的变量和函数不必再次使用：：
//但是在函数声明时的形参的类型必须使用：：，如tv.cpp第10行。
//如果不使用一个名称空间，则必须调整枚举类定义的位置以配合编译器的读取顺序，麻烦而且无聊


namespace interactive {
	enum State
	{
		On,
		Off
	};
	enum VolumnRange
	{
		MinVol,
		MaxVol = 20
	};
	enum Mode
	{
		Antenna,
		Cable
	};
	enum Input
	{
		Tv,
		DVD
	};
	class tv;
	class remote;
}



class interactive::remote
{
public:
	remote(Input mod = interactive::Tv) :_CtrlMode(mod) {}
	inline void VolUp(tv & t);
	inline void VolDown(tv & t);
	inline void ChannelUp(tv & t);
	inline void ChannelDown(tv & t);
	inline void OnOff(tv & t);
	inline void Set_Mode(tv & t);
	inline void Set_Input(tv & t);
	inline void Set_Channel(tv & t, int chal);


private:
	Input  _CtrlMode;   //controls TV or DVD
};

class interactive::tv
{
public:
	//friend class remote;        //remote is tv's friend,but tv is not remote's.
	friend void remote::Set_Channel(tv & t, int chal);
	
public:
	tv(State s=Off,int MaxChannel=120);
	~tv();

public:
	void OnOff();
	bool IsOn() const;
	void VolUp();
	void VolDown();
	void ChannelUp();
	void	ChannelDown();
	void Set_Mode();
	void Set_Input();
	void DispSettings();

private:
	State _sta;
	int _volumn;
	int _maxChannel;
	int _channel;
	Mode _mod;
	Input _inpt;

};

inline void interactive::remote::VolUp(tv & t) { t.VolUp(); }
inline void interactive::remote::VolDown(tv & t) { t.VolDown(); }
inline void interactive::remote::ChannelUp(tv & t) { t.ChannelUp(); }
inline void interactive::remote::ChannelDown(tv & t) { t.ChannelDown(); }
inline void interactive::remote::OnOff(tv & t) { t.OnOff(); }
inline void interactive::remote::Set_Mode(tv & t) { t.Set_Mode(); }
inline void interactive::remote::Set_Input(tv & t) { t.Set_Input(); }
inline void interactive::remote::Set_Channel(tv & t, int chal)
{
	if ((chal <= t._maxChannel) && (chal >= 0))
		t._channel = chal;
	else if (chal < 0)
		t._channel = 0;
	else if (chal > t._maxChannel)
		t._channel = t._maxChannel;
}


