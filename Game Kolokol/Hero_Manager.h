#include <iostream>
#include <string>
#include <vector>

#pragma once

class Hero_Manager : Hero, Player {
	friend class Player_Manager;
public:
	void ListHeroes() {
		cout << "List of Heroes: " << endl;
		for (int i = 0; i < vHero.size();i++) {
			cout << vHero[i] << " | ";
		}

	};

	void infohero() {

		cout << "Your hero is " << vHero[id - 1] << endl;

		cout << "Hero's hp is " << HP[id - 1] << endl;

		cout << "Hero's damage is " << damage[id - 1] << endl;

		cout << "Hero's speed is " << speed[id - 1] << endl;

	};

	void get_hero_by_name() {

		string j;
		cout << "Enter a name of hero: ";
		cin >> j;
		cout << endl;

		for (int i = 0; i <= vHero.size(); i++) {

			if (vHero[i] == j) {
				cout << "Heroe's id is " << i + 1 << endl;

				cout << "Heroe's name is " << vHero[i] << endl;

				cout << "Heroe's rank is " << Rank[i] << endl;

				break;
			}
			if (i == vHero.size())
			{
				cout << "No such hero" << endl;
			}
		}
		
	
		cout << endl;
	}

	void pasthero_newplayer()
	{
		srand(time(0));

		id = 1 + rand() % vHero.size();

		vHero.push_back(vHero[id - 1]);
		HP.push_back(HP[id - 1]);
		damage.push_back(damage[id - 1]);
		speed.push_back(speed[id - 1]);


		cout << "Heroe's name is " << vHero[id - 1] << endl;

		cout << "Heroe's HP is " << HP[id - 1] << endl;

		cout << "Heroe's damage is " << damage[id - 1] << endl;

		cout << "Heroe's speed is " << speed[id - 1] << endl;

		id = o;
	}

	void get_hero() {

		o++;

		id = o;

		cout << "Enter nickname of hero ";

		cin >> j;

		vHero.push_back(j);
		HP.push_back(60 + rand() % 122);
		damage.push_back(4 + rand() % 6);
		speed.push_back(10 + rand() % 6);

		cout << "Heroe's name is " << vHero[id - 1] << endl;

		cout << "Heroe's HP is " << HP[id - 1] << endl;

		cout << "Heroe's damage is " << damage[id - 1] << endl;

		cout << "Heroe's speed is " << speed[id - 1] << endl;


	}

	void remove_hero() {
		cout << "Enter id of hero: ";
		cin >> id;


		vHero.erase(vHero.begin() + id - 1);
	}
};