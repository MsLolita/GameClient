#include <iostream>
#include <string>
#include <vector>

#pragma once
class Player_Manager : Player {
	friend class Hero_Manager;
public:

	void get_player_by_name() {

		string j;
		cout << "Enter your name : ";
		cin >> j;
		cout << endl;

		for (int i = 0; i <= vPlayer.size(); i++) {

			if (vPlayer[i] == j) {
				cout << "Player's id is " << i + 1 << endl;

				cout << "Player's nickname is " << vPlayer[i] << endl;

				cout << "Player's rank is " << Rank[i] << endl;
				break;
			}

			if (i == vPlayer.size())
			{
				cout << "No such player" << endl;
			}
		}
		
		cout << endl;
	}

	void get_player_by_id() {

		while (true) {
			cout << "Enter  id: ";
			cin >> id;
			if (id > 0 && id <= vPlayer.size()) {
				
				cout << "Player's id is " << id << endl;

				cout << "Player's nickname is " << vPlayer[id - 1] << endl;

				cout << "Player's rank is " << Rank[id - 1] << endl;

				break;
			}
			else {
				cout << "No such id" << endl;
			}
		}
	}

	void get_player() {

		o++;
		id = o;

		cout << "Enter nickname of player: ";

		cin >> j;

		vPlayer.push_back(j);

		Rank.push_back(1000);



	}



	void remove_player() {

		while (true) {

			cout << "Enter id of player: ";

			cin >> id;
			if (id <= vPlayer.size() && id > 0) {
				vPlayer.erase(vPlayer.begin() + id - 1);
				break;
			}
			else {
				cout << "\nWrong id\n";
			}
		}
		id = 1;
	}


};