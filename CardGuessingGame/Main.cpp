
#include <vector>
#include <algorithm>
#include "cardType.h"
void print(vector<cardType> cardList);
void displayMenu();
bool comp1(cardType card1, cardType card2);
bool comp2(cardType card1, cardType card2);
bool comp3(cardType card1, cardType card2);
int main()
{
	vector<cardType> cardList = { cardType("Ace", 1), cardType("King", 13), cardType("Queen", 12) };
	cardType card;
	int choice;
	int back;
	int location;
	int index;
	string face;
	bool found, found2;
	random_shuffle(cardList.begin(), cardList.end());
	displayMenu();
	cout << "Your choice:";
	cin >> choice;
	while (choice != -9)
	{
		switch (choice)
		{
		case 1:
		{
			cout << "Face:";
			cin >> face;
			card.setCard(face, 0);
			cout << "What location do you think it is:";
			cin >> location;
			vector<cardType> originalList = cardList;
			for (auto& c : originalList) 
				c.setBack(0);

				auto it = find(originalList.begin(), originalList.end(), card);
				if (it != originalList.end())
				{
					index = distance(originalList.begin(), it);
					cout << "Index:" << index;
					found = it->checkFace(face);
					if (found && location == index)
						cout << "You have succesfully found the face" << endl;
					else
						cout << "Face doesn't exists" << endl;
				}
				else
					cout << "Card unavailable" << endl;
				
			
			break;
		}
		case 2:
		{
			cout << "back:";
			cin >> back;
			card.setCard("", back);
			cout << "What location do you think it is:";
			cin >> location;
			vector<cardType> originalList = cardList;
			for (auto &c : originalList) 
				c.setFace("");

				auto it = find(originalList.begin(), originalList.end(), card);
				if (it != originalList.end())
				{
					index = distance(originalList.begin(), it);
					found = it->checkBack(back);
					if (found && location == index)
						cout << "You have succesfully found the back" << endl;
					else
						cout << "Back doesn't exists" << endl;
				}
				else
					cout << "Card unavailable" << endl;
				
			
			break;
		}
		case 3:
		{
			cout << "Face:";
			cin >> face;
			cout << "back:";
			cin >> back;
			card.setCard(face, back);
			cout << "What location do you think it is:";
			cin >> location;
			auto it = find(cardList.begin(), cardList.end(), card);
			if (it != cardList.end())
			{
				index = distance(cardList.begin(), it);
				found = it->checkBack(back);
				found2 = it->checkFace(face);
				if (found && found2 && location==index)
					cout << "You have succesfully found the face and back" << endl;
				else
					cout << "You have wrong one of them" << endl;
			}
			else
				cout << "Card unavailable" << endl;
			break;
			
		}
		case 4:
			print(cardList);
		

		default:
			break;
		}
		
		random_shuffle(cardList.begin(), cardList.end());
		displayMenu(); //display menu
		cout << "Enter your choice: ";
		cin >> choice; //get the next request
		cout << endl;

	}
	



}
void print(vector<cardType> cardList)
{
	for (auto card : cardList)
		card.printCard();
}
void displayMenu()
{
	cout << endl;
	cout << "Select one of the following:" << endl;
	cout << "Select 1 if you want  to guess only want to guess face value of the card" << endl;
	cout << "Select 2 if you want to guess only the value of a back of the card" << endl;
	cout << "Select 3 if you want to guess both back and face value of the card" << endl;
	cout << "Select 4 to see the cards" << endl;
	cout << "Select -9 to stop the game" << endl;
}
bool comp1(cardType card1, cardType card2)
{
	return (card1.getFace() == card2.getFace());
}
bool comp2(cardType card1, cardType card2)
{
	return (card1.getBack() == card2.getBack());
}
bool comp3(cardType card1, cardType card2)
{
	return (card1.getBack() == card2.getBack() && card1.getFace() == card2.getFace());
}

