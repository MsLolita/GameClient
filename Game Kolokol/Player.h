#include <iostream>
#include <string>
#include <vector>
#pragma once

class Player {
	friend class Player_Manager;
private:

public:

	string Player;
	int rank;

	void infoPlayer() {

		cout << "Your id is " << id << endl;

		cout << "Your nickname is " << vPlayer[id - 1] << endl;

		cout << "Your rank is " << Rank[id - 1] << endl;

	};

	void ListPlayers() {
		cout << "List of Players: " << endl;
		for (int i = 0; i < vPlayer.size();i++) {
			cout << vPlayer[i] << " | ";
		}

	}

	char iff;

	void changename() {
	again:
		cout << "Do you really want to change nickname?(Put N(NO) or Y(Yes))" << endl;
		cin >> iff;
		if ((iff == 'Y') || (iff == 'y')) {
			cout << "Enter your new nickname: ";
			cin >> vPlayer[id - 1];
			cout << "Your nickname is " << vPlayer[id - 1] << endl;
		}
		else if ((iff == 'N') || (iff == 'n')) {
			cout << "Your nickname is " << vPlayer[id - 1] << endl;
		}
		else {
			cout << "You write wrong(Only N(NO) or Y(Yes))" << endl;
			goto again;
		}
	};

};
