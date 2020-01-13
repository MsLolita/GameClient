#include <iostream>
#include <string>
#include <vector>

#pragma once

class Session : Team_part, Hero {

public:
	string team_red[5];
	string team_blue[10];

	int red_rank;
	int blue_rank;

	int red_rank_between[5];
	int blue_rank_between[10];

	int max_rank;
	int min_rank;

	int a, win = 0;

	bool winner_team = 0;


	void team_separate() {



	byrank_badteams:

		random_teams();

		win = a = 0;
		red_rank = blue_rank = 0;
		for (int i = 0;i < 5; i++) {
			team_red[i] = vPlayer[Rand[i]];
			red_rank += Rank[Rand[i]];
			plus_red_rank[i] = Rand[i];

			red_rank_between[i] = Rank[Rand[i]];
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
			team_blue[i] = vPlayer[Rand[i]];
			blue_rank += Rank[Rand[i]];
			plus_blue_rank[i] = Rand[i];

			blue_rank_between[i] = Rank[Rand[i]];
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
		if (max_rank - min_rank > 200)
			goto byrank_badteams;
		/////перевірка щоб між командами не було більше 100 рангу
		if ((red_rank - blue_rank) > 100 || (blue_rank - red_rank) > 100)
			goto byrank_badteams;

		//////////////////////

		int times = 0;
		do {
			for (int i = 0;i < 5; i++) {
				if (times == 0)						// щоб при повторному ударі не добавлялося здоровя а тільки урон 
					red_HP += HP[Rand[i]];

				red_damage += damage[Rand[i]];

			}
			//cout << red_HP << " - HP red damage - " << red_damage << endl;///////

			for (int i = 5;i < 10;i++) {
				if (times == 0)						// щоб при повторному ударі не добавлялося здоровя а тільки урон 
					blue_HP += HP[Rand[i]];

				blue_damage += damage[Rand[i]];

			}
			//cout << blue_HP << "  - HP blue damage -" << blue_damage << endl;//////////////
			++times;
		} while (times = 0);

	};





};