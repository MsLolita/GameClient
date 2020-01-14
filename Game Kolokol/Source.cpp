#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>

// ////////////////////

using namespace std;

int id = 1;
int o = 10;
string j;
class Player_Manager;

vector<string>	vPlayer = { "Denys", "Maks", "Anton", "Nazar", "Andrei", "Danya", "Yra", "Vanya", "Andrey", "Losha" };
vector <int> Rank = { 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000 };


vector<string> vHero = { "mag", "luchnik", "bomber", "loser", "pitardomen", "luntik", "batman", "poseidon", "programissst", "kekster" };

vector<int> HP = { 120, 120, 125, 90, 95, 70, 250, 100, 90, 130 };
vector<int> damage = { 12,20,7,16,20,13,20,18,19,10 };


int plus_red_rank[5];
int plus_blue_rank[10];


int red_HP, red_damage;
int  blue_HP, blue_damage;

vector<int> Rand;
/////////////
#include "Player.h"
#include "Hero.h"
#include "Team_part.h"
#include "Session.h"
#include "Game_Manager.h"
#include "Player_Manager.h"
#include "Hero_Manager.h"
//////////////
class Player;
int main() {


	Player name;
	Player_Manager get_name;
	Hero_Manager yourheroes;
	Session team;
	Game_Manager win;

	int a;

	cout << "!=================================================!" << endl << "**********************Kolokol**********************" << endl;

	while (true) {
		cout << "Enter your id: ";
		cin >> id;
		if (id > 0 && id < vPlayer.size()) {
			break;
		}
		cout << "No such id" << endl;
		
	}
	cout << "\nTo see the statistic - 1\nTo change a name - 2\nTo see your hero - 3\nTo find by name/id - 4\nTo add a player - 5\nTo play a game - 7" << endl;
	cout << "--------------------------------------" << endl;



	cout << "What do you want, " << vPlayer[id - 1] << "?\n";

	do {

		cin >> a;
		cout << endl;
		switch (a) {
		case 1:
			name.infoPlayer();
			break;
		case 2:

			name.changename();
			break;
		case 3:
			yourheroes.infohero();
			break;
		case 4:
			cout << "To find by name - 1\nTo find by id - 2\n";
			cin >> a;
			cout << endl;
			if (a == 1) {
				get_name.get_player_by_name();
				break;
			}
			else if (a == 2) {
				get_name.get_player_by_id();
				break;
			}
		case 5:
			cout << "To add player - 1\nTo remove player - 2\n";
			cin >> a;
			cout << endl;
			if (a == 1) {
				get_name.get_player();
				yourheroes.pasthero_newplayer();
				break;
			}
			else if (a == 2) {
				get_name.remove_player();
				break;
			}

		case 6:
			name.ListPlayers();
			break;
		case 7:
			team.team_separate();
			win.winner_teams();
			break;
		};

		cout << endl << "--------------------------------------" << endl;
		cout << "To see the statistic - 1\nTo change a name - 2\nTo see your hero - 3\nTo find by name/id - 4\nTo add/remove a player - 5\nTo see all players - 6\nTo play a game - 7" << endl;
		cout << "--------------------------------------" << endl;
	} while (true);

	return 0;
}
