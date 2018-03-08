#ifndef Blink_H
#define Blink_H

class Blink {
private: 
	int pinNumber;

public:
	Blink(int input);

	void on(int onTime);
	void off(int outTime);
};

#endif
