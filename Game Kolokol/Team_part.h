#include <iostream>
#include <string>
#include <vector> 
#include <algorithm>
#pragma once

class Team_part : Hero {
	friend class Session;
private:

public:
	void random_teams() {
		Rand.erase(Rand.begin(), Rand.end());
		for (int i = 0; i < vPlayer.size(); i++) {
			Rand.push_back(i);
		}


		srand((time(0)));
		random_shuffle(Rand.begin(), Rand.end());
	}

};