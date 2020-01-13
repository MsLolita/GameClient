#include <iostream>
#include <string>
#include <vector>

#pragma once
class Game_Manager :Session {
public:

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
					if (id - 1 == plus_blue_rank[i])
						win = 1;
				}
				cout << endl;
				for (int i = 0;i < 5; i++) {

					Rank[plus_red_rank[i]] -= 25;
					//cout << endl << "-25" << endl << Rank[plus_red_rank[i]]  << " | ";///////////////
				}

				if (win == 1)
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
			cout << endl << vPlayer[plus_red_rank[i]] << ":  " << Rank[plus_red_rank[i]];

		}
		for (int i = 5;i < 10; i++) {
			cout << endl << vPlayer[plus_blue_rank[i]] << ":  " << Rank[plus_blue_rank[i]];

		}
	}
};