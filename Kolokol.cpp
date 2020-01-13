#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>


using namespace std;

int id = 1;
int o = 10;
string j;
class Player_Manager;



class Player  {
	friend class Player_Manager;
private:

public:
	
	vector<string>	vPlayer = { "kek", "no", "hub", "glu", "rom", "qqq", "mik", "opp", "fox", "ten" };
    

	vector <int> Rank = { 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000 };


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


vector<string> vHero = { "mag", "luchnik", "bomber", "loser", "pitardomen", "luntik", "batman", "poseidon", "programissst", "kekster" };

vector<int> HP = { 110, 120, 125, 90, 95, 70, 250, 100, 90, 130 };
vector<int> damage = { 12,20,7,16,20,13,20,18,19,10 };

class Hero {
public:

	vector<string> vHero = { "mag", "luchnik", "bomber", "loser", "pitardomen", "luntik", "batman", "poseidon", "programissst", "kekster" };

	vector<int> HP = { 110, 120, 125, 90, 95, 70, 250, 100, 90, 130 };
	vector<int> damage = { 12,20,7,16,20,13,20,18,19,10 };

	string Hero;
	int hp;
	int Hdamage;
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
	
	int red_rank_between[5];
	int blue_rank_between[10];

	int max_rank;
	int min_rank;


	int a,win = 0;

	bool winner_team = 0;
	

	void team_separate() {
		
		vector<int> rand(vPlayer.size());
	byrank_badteams:

		for (int i = 0; i < vPlayer.size() ; i++) {
			rand[i] = i;			
		}
		win = a = 0;
		red_rank = blue_rank = 0;

		srand((time(0)));
		random_shuffle(rand.begin(), rand.end());
		
		
		for (int i = 0;i < 5; i++) {
			team_red[i] = vPlayer[rand[i]];
			red_rank += Rank[rand[i]];
			plus_red_rank[i] = rand[i];

			red_rank_between[i] = Rank[rand[i]];
		}
		/////

		for (int i = 0;i < 5; i++) {
			if (a < 1)
			{
				max_rank = red_rank_between[i];
				min_rank = red_rank_between[i];
				a++;
			}
			if (max_rank < red_rank_between[i])
				max_rank = red_rank_between[i];
			if (min_rank > red_rank_between[i])
				min_rank = red_rank_between[i];
		}

		/////перевірка в команді шоб не більше 200 рангів між учасниками red
		//cout  << endl << " | " << max_rank << " | " << min_rank<< " maxmin" << endl;///////////
		if (max_rank - min_rank > 200)
			goto byrank_badteams;
		/////
		for (int i = 5;i < 10;i++) {
			team_blue[i] = vPlayer[rand[i]];
			blue_rank += Rank[rand[i]];
			plus_blue_rank[i] = rand[i];

			blue_rank_between[i] = Rank[rand[i]];			
		}
		a = 0;
		for (int i = 5;i < 10;i++) {
			if (a < 1)
			{
				max_rank = blue_rank_between[i];
				min_rank = blue_rank_between[i];
				a++;
			}
			if (max_rank < blue_rank_between[i])
				max_rank = blue_rank_between[i];
			if (min_rank > blue_rank_between[i])
				min_rank = blue_rank_between[i];
		}

		
		
		//cout << endl <<" | " << max_rank << " | " << min_rank << " maxmin" << endl;

		/////перевірка в команді шоб не більше 200 рангів між учасниками blue
		if (max_rank-min_rank > 200)
			goto byrank_badteams;
		/////перевірка щоб між командами не було більше 100 рангу
		if ((red_rank - blue_rank) > 100 || (blue_rank - red_rank) > 100)
	goto byrank_badteams;

		//////////////////////
		int zero = 0;
		do {
			for (int i = 0;i < 5; i++) {
				if ( zero == 0)						// щоб при повторному ударі не добавлялося здоровя а тільки урон 
				red_HP += HP[rand[i]];

				red_damage += damage[rand[i]];

			}
			//cout << red_HP << " - HP red damage - " << red_damage << endl;///////

			for (int i = 5;i < 10;i++) {
				if (zero == 0)						// щоб при повторному ударі не добавлялося здоровя а тільки урон 
				blue_HP += HP[rand[i]];

				blue_damage += damage[rand[i]];

			}
			//cout << blue_HP << "  - HP blue damage -" << blue_damage << endl;//////////////
			++zero;
		} while (zero = 0);
	};
	

	void winner_teams() 
	{

		if (red_HP - blue_damage > blue_HP - blue_damage)
		{
			winner_team = true;
		}

		if (winner_team == true)
		{
			cout << endl << "Red team wins" << endl;
			
			for (int i = 0;i < 5; i++) {
				
				Rank[plus_red_rank[i]] += 25;
				if (id - 1 == plus_red_rank[i])
					win = 1;
				
				
			}
			for (int i = 5;i < 10; i++) {

				Rank[plus_blue_rank[i]] -= 25;
			}
			if (win == 1) 
				cout << "Congratulations! You win!" << endl;
			
			else
				cout << "Sorry but you lose" << endl;
		}
		else if (winner_team == false)
		{
			if (red_HP - blue_damage < blue_HP - blue_damage) {
				cout << endl << "Blue team wins" << endl;
				for (int i = 5;i < 10; i++) {
					//cout << plus_blue_rank[i] << " |gg " << endl;///////////
					//cout << endl << "+25" << endl << Rank[plus_blue_rank[i]] << " | ";/////////////
					Rank[plus_blue_rank[i]] += 25;
					//cout << " | " << plus_blue_rank[i] << " | ";///////////////
					if (id -1== plus_blue_rank[i])
						win=1;
				}
				cout << endl;
				for (int i = 0;i < 5; i++) {

					Rank[plus_red_rank[i]] -= 25;
					//cout << endl << "-25" << endl << Rank[plus_red_rank[i]]  << " | ";///////////////
				}
				
				if (win==1)
					cout << "Congratulations! You win!" << endl;
				else
					cout << "Sorry but you lose" << endl;
			}
			else 
				cout << endl << "Friendship is a winner" << endl;
		}
		cout << endl << "Your rank is " << Rank[id - 1];
		cout << endl << "Ranks of others participants:";
		for (int i = 0;i < 5; i++) {
			cout << endl << vPlayer[plus_red_rank[i]] << ":  "<<Rank[plus_red_rank[i]];

		}
		for (int i = 5;i < 10; i++) {
			cout << endl << vPlayer[plus_blue_rank[i]] << ":  " << Rank[plus_blue_rank[i]];

		}
	}
	
};

class Team_part : Player, Hero {

public:


	/*void teamhero() {
		vHero[] = ;
	}*/
};

class Player_Manager : Player{	
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
		cout << "Enter  id: ";
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
	


class Hero_Manager : Hero,Player{
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
	Session team;

	int a;
	cout << "!================================================!" << endl << "**********************Gamers**********************" << endl;
	cout << "To see the statistic - 1\nTo change a name - 2\nTo see your hero - 3\nTo find by name/id - 4\nTo add a player - 5\nTo play a game - 7" << endl;
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
			
		case 6:
			name.ListPlayers();
			break;
		case 7:
			team.team_separate();
			team.winner_teams();
			break;
		};

		cout << endl << "--------------------------------------" << endl;
		cout << "To see the statistic - 1\nTo change a name - 2\nTo see your hero - 3\nTo find by name/id - 4\nTo add/remove a player - 5\nTo see all players - 6\nTo play a game - 7" << endl;
		cout << "--------------------------------------" << endl;
	} while (true);
	
	return 0;
}
