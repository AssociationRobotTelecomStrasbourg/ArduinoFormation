#ifndef ULTRASON_H
#define ULTRASON_H

class Ultrason{
public:
	Ultrason(int pinTrig, int pinEcho);
	int distance() const;
	
private:
	int _pinTrig;
	int _pinEcho;
};

#endif
