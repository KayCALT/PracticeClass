#include "tv.h"



using std::cout;
using std::endl;
using interactive::tv;


tv::tv(interactive::State s, int MaxChannel)
	:_sta(s),_volumn(5),_channel(5),_maxChannel(MaxChannel),_mod(Cable),_inpt(Tv)
{
}

tv::~tv()
{
}

void tv::OnOff()
{
	_sta = (_sta == On) ? Off : On;

}

bool tv::IsOn() const
{
	return On==_sta;
}

void tv::VolUp()
{
	if (_volumn<MaxVol)
	{
		_volumn++;
	}
	else{}
}

void tv::VolDown()
{
	if (_volumn>MinVol)
	{
		_volumn--;
	}
	else{}
}

void tv::ChannelUp()
{
	if (_channel<_maxChannel)
	{
		_channel++;
	}
	else
	{
		_channel = 1;
	}
}

void tv::ChannelDown()
{
	if (_channel>1)
	{
		_channel--;
	}
	else
	{
		_channel = _maxChannel;
	}
}

void tv::Set_Mode()
{
	_mod = (_mod == Cable) ? Antenna : Cable;
}


void tv::Set_Input()
{
	_inpt = (_inpt == Tv) ? DVD : Tv;
}

void tv::DispSettings()
{
	cout << "The current state is " << ((_sta == On) ? "On" : "Off" )<< endl;
	cout << "The volumn is " << _volumn << endl;
	cout << "The current channel is " << _channel << " and the max channel is " << _maxChannel << endl;
	cout << "The current input is " << ((_inpt==Tv)?"Tv":"DVD") << endl;
	cout << "The current mode is " <<( (_mod == Cable) ? "Cable" : "Antenna" )<< endl<<endl;
}
