#pragma once
#ifndef H_CARDTYPE
#define H_CARDTYPE
#include <iostream>
using namespace std;


class cardType
{
public:
	cardType():face(""), back(0){}
	cardType(string f, int n): face(f), back(n){}
	void setCard(string, int);
	void setFace(string f) { face = f; }
	void setBack(int b) { back = b; }
	string getFace() const;
	int getBack() const;
	void printCard() const;
	bool operator==(const cardType&) const;
	bool operator!=(const cardType&) const;
	bool checkFace(string f) const;
	bool checkBack(int b) const;
	cardType& operator=(const cardType& other);
private:
	string face;
	int back;

};

#endif // !H_CARDTYPE