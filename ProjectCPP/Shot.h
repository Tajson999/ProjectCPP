#ifndef SHOT_H
#define SHOT_H
#include "Entity.h"
class Shot:public Entity{
private:
	int active;
	double lifeSpan;
public:
	Shot();
	Shot(double lifespan);
	~Shot();
	int getLifeSpan() const;
	void setLifeSpan(int l);

	int getActive() const;
	void setActive(int a);

};
#endif // !SHOT_H
