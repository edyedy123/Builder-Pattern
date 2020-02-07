#ifndef A3_CPP
#define A3_CPP
#include "a3.h"

ALCBuilder::ALCBuilder() {
	room = new Room();
}

void ALCBuilder::setChairs(int num) {
	for (int i = 0; i < num; i++) {
		room->addChair("Low Back Plastic with Wheels", 100);
	}
}
void ALCBuilder::setTables(int num) {
	double t = num;
	int tables = ceil(t / 3);;
	if (tables % 2 != 0) {
		tables++;
	}
	for (int i = 0; i < tables; i++) {
		room->addTable("Half Hex", 600);
	}
}

LabBuilder::LabBuilder() {
	room = new Room();
}
void LabBuilder::setChairs(int num) {
	for (int i = 0; i < num; i++) {
		room->addChair("Student Desk Chair", 130);
	}
	room->addChair("instructor stool", 80);
}
void LabBuilder::setTables(int num) {
	double t = num;
	int tables = ceil(t / 2);
	for (int i = 0; i < tables; i++) {
		room->addTable("2 station desk", 500);
	}
}
void LabBuilder::setComputers(int num) {
	int tNum = 0;
	for (int i = 0; i < num; i++) {
		if (i % 2 != 0) {
			tNum++;
		}
		room->addComputer("mac mini", 1000, tNum);
	}
}

StepRoomBuilder::StepRoomBuilder() {
	room = new Room();
}
void StepRoomBuilder::setChairs(int num) {
	room->addChair("instructor stool", 80);
	room->addChair("Regular Chair", 70);

	int tables = ceil(num / 8);
	for (int i = 0; i < tables*8-1; i++) {
		room->addChair("padded lecture theater chairs", 150);
	}
}

void StepRoomBuilder::setTables(int num) {
	room->addTable("instructor table", 200);

	int tables = ceil(num / 8);
	for (int i = 0; i < tables; i++) {
		room->addTable("8 student long tables", 1000);
	}
}

void Director::setBuilder(Builder& choice) {
	builder = &choice;
}
Room* Director::buildRoom(int num) {
	builder->setChairs(num);
	builder->setTables(num);
	builder->setComputers(num);
	
	return builder->getRoom();
}

#endif