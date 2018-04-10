#pragma once
#include<iostream>

//�ڵڶ����޸�ʱΪ��ʹ��ǰ�������ķ���ͬʱ�ֲ�����˽�ö�����λ��ǿ��
//��һ�����Ƶ���һ�����У���ϧ�����½�һ�Լ������ƿռ�interactive��ͬʱ����Ч��
//����ɹ�����ؾ���Ϊ:���ƿռ�����ڷ�װ�����Լ�Ŀǰ��ô��⣩�Լ��������࣬�����ｫ��Ҫ��ö��Ҳ
//һͬ�������ƿռ䣬ʹ���������������������using��������ʹ�á�
//�������ƿռ��ͬ��һ�������Ҫ����߶�����ߵ��࣬��Ҫusing��������������������������Interactive������
//��������������Ϊȫ�ֿռ���࣬�������Դ����ƿռ�����ࡣ
//ʹ����������������֮����ͺ����Ķ����൱�������ƿռ��ڶ����ˣ��������ʹ�����ƿռ��ڵı����ͺ��������ٴ�ʹ�ã���
//�����ں�������ʱ���βε����ͱ���ʹ�ã�������tv.cpp��10�С�
//�����ʹ��һ�����ƿռ䣬��������ö���ඨ���λ������ϱ������Ķ�ȡ˳���鷳��������


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


