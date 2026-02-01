#include "cardType.h"
void cardType::setCard(string f, int b)
{
	face = f;
	back = b;
}
string cardType::getFace() const
{
	return face;
}
int cardType::getBack() const
{
	return back;
}
void cardType:: printCard() const
{
	cout << face << " " << back << endl;
}
bool cardType::operator==(const cardType& card) const
{
	return(face==card.face && back==card.back);
}
bool cardType::operator!=(const cardType& card)const
{
	return (face != card.face && back == card.back || face == card.face && back != card.back || face!=card.face && back!=card.back);
}
bool cardType::checkFace(string f) const
{
	return face == f;
}
bool cardType::checkBack(int b) const
{
	return back == b;
}