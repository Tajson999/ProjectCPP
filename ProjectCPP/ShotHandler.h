#ifndef SHOTHANDLER_H
#define SHOTHANDLER_H
#include "Shot.h"
class ShotHandler {
private:
	Shot* *shots;
	int nrOfShots;
	int capacity;
	int shotCD;
	void expand();
public:
	ShotHandler();
	~ShotHandler();
	int getNrOfShots();
	void setNrOfShots(int s);
	int getCapacity();
	void setCapacity(int c);
	void setShotCD(int i);
	int getShotCD();
	void addShot(Vector2f v);
	void removeShot(int i);
	void updateShots(Sprite arr[]);

};
#endif // !SHOTHANDLER_H

