#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

int id = 1;
int o = 10;
string j;
class Player_Manager;

vector<string>	vPlayer = { "kek", "no", "hub", "glu", "rom", "qqq", "mik", "opp", "fox", "ten" };

vector <int> Rank = { 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000 };

class Player  {
	friend class Player_Manager;
private:

public:
	
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




class Hero {
public:


	vector<string> vHero = { "mag", "luchnik", "bomber", "loser", "pitardomen", "luntik", "batman", "poseidon", "programissst", "kekster" }; 
	
	vector<int> HP = { 100, 120, 125, 90, 95, 70, 250, 100, 90, 130 };
	vector<int> damage = {15,20,7,16,25,13,24,18,19,10 };
	vector<int> speed = { 6,5,3,6,2,7,5,9,7,10 };

	

};



class Session : Player,Hero {

public:
	string team_red[5];
	string team_blue[10];
	
	int red_rank;
	int blue_rank;

	int plus_red_rank[5];
	int plus_blue_rank[10];

	
	int red_HP, red_damage;
	int  blue_HP, blue_damage;
	


	bool winner;

	void team_separate() {
		
		vector<int> rand(vPlayer.size());
		
		for (int i = 0; i < vPlayer.size() ; i++) {
			rand[i] = i;
			
		}
		byrank_badteams:
		srand((time(0)));
		random_shuffle(rand.begin(), rand.end());
		
		
		for (int i = 0;i < 5; i++) {
			team_red[i] = vPlayer[rand[i]];
			red_rank += Rank[rand[i]];
			plus_red_rank[i] = rand[i];

		}

		for (int i = 5;i < 10;i++) {
			team_blue[i] = vPlayer[rand[i]];
			blue_rank += Rank[rand[i]];
			plus_blue_rank[i] = rand[i];
		}
		cout << " | " <<red_rank << " | "<< blue_rank << " | "<< endl;
		if (unsigned(red_rank - blue_rank) > 200)
			goto byrank_badteams;

		//////////////////////
		int zero = 0;
		do {
			for (int i = 0;i < 5; i++) {
				if ( zero == 0)						// щоб при повторному ударі не добавлялося здоровя а тільки урон 
				red_HP += HP[rand[i]];

				red_damage += damage[rand[i]];

			}
			cout << red_HP << " - HP red damage - " << red_damage << endl;

			for (int i = 5;i < 10;i++) {
				if (zero == 0)
				blue_HP += HP[rand[i]];

				blue_damage += damage[rand[i]];

			}
			cout << blue_HP << "  - HP blue damage -" << blue_damage << endl;
			++zero;
		} while (zero < 2);
	};
	

	void winner_team() 
	{

		if (red_HP - blue_damage > blue_HP - blue_damage)
		{
			winner = true;
		}

		if (winner == true)
		{
			cout << endl << "Red team wins" << endl;
			for (int i = 0;i < 5; i++) {
				
				Rank[plus_red_rank[i]] += 25;

				Rank[plus_blue_rank[i]] -= 25;
			}
			
		}
		else if (winner == false)
		{
			if (red_HP - blue_damage < blue_HP - blue_damage) {
				cout << endl << "Blue team wins" << endl;
				for (int i = 5;i < 10; i++) {

					Rank[plus_blue_rank[i]] += 25;

					Rank[plus_red_rank[i]] -= 25;
				}
			}
			else 
				cout << endl << "Friendship is a winner" << endl;
		}
		for (int i = 0;i < 10; i++) {

			cout << endl <<Rank[i] << " | ";

		}
	}
	
};

class Team_part : Player, Hero {

public:


	/*void teamhero() {
		vHero[] = ;
	}*/
};

class Player_Manager {	
	friend class Hero_Manager;
public:

	void get_player_by_name() {

		string j;
		cout << "Enter a name of player: ";
		cin >> j;
		cout << endl;
		
		for (int i = 0; i <= vPlayer.size() ; i++) {
			
			if (vPlayer[i] == j) {
				cout << "Player's id is " << i + 1 << endl;

				cout << "Player's nickname is " << vPlayer[i] << endl;

				cout << "Player's rank is " << Rank[i] << endl;
				goto yesname;
			}
			
				
		}
		cout << "No such name" << endl;
	yesname:
		cout << endl;
	}

	void get_player_by_id() {

	id:
		cout << "To start enter your id: ";
		cin >> id;
		if (id < 0 || id > vPlayer.size()) {
			cout << "No such id" << endl;
			goto id;
		}
		else {
			cout << "Player's id is " << id << endl;

			cout << "Player's nickname is " << vPlayer[id-1] << endl;

			cout << "Player's rank is " << Rank[id -1] << endl;
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
		
	wrongid:

		cout << "Enter id of player: ";
		
		cin >> id;

		

			if (id > vPlayer.size() || id < 0) {
				cout << "\nWrong id\n";
				goto wrongid;
			}
			else {
				vPlayer.erase(vPlayer.begin() + id - 1);

				
			}
	}


};
	


class Hero_Manager : Hero{
	friend class Player_Manager;
public :
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

		for (int i = 0; i <= vPlayer.size(); i++) {

			if (vHero[i] == j) {
				cout << "Heroe's id is " << i + 1 << endl;

				cout << "Heroe's name is " << vHero[i] << endl;

				cout << "Heroe's rank is " << Rank[i] << endl;
				goto yeshero;
			}
			
		}
		cout << "No such hero" << endl;
	yeshero:
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

int main() {
	

	Player name;
	Player_Manager get_name;
	Hero_Manager yourheroes;
	
	int a;
	cout << "!================================================!" << endl << "**********************Gamers**********************" << endl;
	cout << "To see the statistic - 1\nTo change a name - 2\nTo see your hero - 3\nTo find by name/id - 4\nTo add a player - 5" << endl;
	cout << "--------------------------------------" << endl;

	cout << "What do you want?\n";

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
			
			break;
		case 6:
			name.ListPlayers();
		};
		
		
		
	
		
		Session team;
		team.team_separate();
		team.winner_team();

		
		cout << endl << "--------------------------------------" << endl;
		cout << "To see the statistic - 1\nTo change a name - 2\nTo see your hero - 3\nTo find by name/id - 4\nTo add/remove a player - 5\nTo see all players - 6" << endl;
		cout << "--------------------------------------" << endl;
	} while (true);



	
	return 0;
}
