#ifndef A3_H
#define A3_H

#include "room.h"

class Builder{
protected:
	Room* room;
public:
	virtual void setChairs(int num){}
	virtual void setTables(int num){}
	virtual void setComputers(int num){}

	Room* getRoom() {
		return room;
	}
};
class Director{
	Builder* builder;
public:
	virtual void setBuilder(Builder& choice);
	virtual Room* buildRoom(int num);
};
class ALCBuilder:public Builder {
public:
	ALCBuilder();
	virtual void setChairs(int num);
	virtual void setTables(int num);
};
class LabBuilder:public Builder {
public:
	LabBuilder();
	virtual void setChairs(int num);
	virtual void setTables(int num);
	virtual void setComputers(int num);
};
class StepRoomBuilder:public Builder {
public:
	StepRoomBuilder();
	virtual void setChairs(int num);
	virtual void setTables(int num);
};

#endif
