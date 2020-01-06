#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <time.h>

using namespace std;


struct movement
{
	string name;
	int damage;
	int accuracy;
	int own_damage = 0;
	bool CD = false;
	bool MS = false;
	bool SW = false;
	bool BW = false;
};

struct player
{
	string name;
	int hp;
	int attack;
	int defense;
	int speed;
	int mind;
	movement one;
	movement two;
	movement three;
	movement four;
};

void CheckCorrect(int x)
{
	if (x == 1)
	{
		cout << "yeet";

	}
	else if (x == 2)
	{
		cout << "yeet2";

	}
	else
	{

		cout << "Incorrect number,  Type '1' to fight or '2' to emulate\n";

	}
}

bool Hit(int accuracy)
{
	int x = rand() % 101;
	if (x <= accuracy)
	{
		return true;
	}
	else return false;
}

void PrintStats(player user, player oponent)
{
	cout << endl;
	cout << user.name << endl;
	cout << "HEALTH: " << user.hp << endl;
	cout << "ATTACK: " << user.attack << endl;
	cout << "DEFENSE: " << user.defense << endl;
	cout << "SPEED: " << user.speed << endl;
	cout << "MIND: " << user.mind << endl;
	cout << endl;
	cout << oponent.name << endl;
	cout << "HEALTH: " << oponent.hp << endl;
	cout << "ATTACK: " << oponent.attack << endl;
	cout << "DEFENSE: " << oponent.defense << endl;
	cout << "SPEED: " << oponent.speed << endl;
	cout << "MIND: " << oponent.mind << endl;
}

void FightBimtiano(player user, player oponent)
{
	cout << user.name << " vs " << oponent.name << endl;
	PrintStats(user, oponent);
	int turn = 0;
	int select;
	int selectIA;
	bool skip_user = false;
	bool skip_oponent = false;
	int round = 0;
	do
	{
		round++;
		cout << endl;
		cout << "ROUND: " << round << endl;

		if (skip_user == false)
		{
			if (turn == 0)
			{
				cout << "Pick an attack: Type the number of the move you want to use '1', '2', '3' or '4'" << endl;
				cout << user.one.name << endl;
				cout << user.two.name << endl;
				cout << user.three.name << endl;
				cout << user.four.name << endl;

				cin >> select;

				switch (select)
				{
				case 1: //fist
					if (Hit(user.one.accuracy) == true)
					{
						cout << "Your fist does " << (user.one.damage + user.attack + rand() % 10) - oponent.defense << " damage." << endl;
						oponent.hp -= (user.one.damage + user.attack) - oponent.defense;
					}
					else cout << "Your fist attack misses..." << endl;
					break;
				case 2: //kick
					if (Hit(user.two.accuracy) == true)
					{
						cout << "Your kick does " << (user.two.damage + user.attack + rand() % 10) - oponent.defense << " damage." << endl;
						oponent.hp -= (user.two.damage + user.attack) - oponent.defense;
					}
					else cout << "Your kick attack misses..." << endl;
					break;
				case 3: //concentrated defense
					if (Hit(user.three.accuracy) == true)
					{
						cout << "Your defense is now higher but you wont be able to move the next turn." << endl;
						user.defense = user.defense + 30;
						skip_user = true;
					}
					else cout << "Your concentrated defense misses..." << endl;
					break;
				case 4: //mind strength
					if (Hit(user.four.accuracy) == true)
					{
						cout << "Your attack is now doubled but you wont be able to move the next turn." << endl;
						user.attack = user.attack * 2;
						skip_user = true;
					}
					else cout << "Your mind strength misses..." << endl;
					break;
				}

			}
		}
		else
		{
			cout << "Your turn is skipped" << endl;
			skip_user = false;
		}

		turn = 1;

		if (skip_oponent == false)
		{
			selectIA = rand() % 3;

			switch (selectIA)
			{
			case 0: //fist
				if (Hit(oponent.one.accuracy) == true)
				{
					if (((oponent.one.damage + oponent.attack + rand() % 10) - user.defense) > 6)
					{
						cout << "Oponent's fist does " << (oponent.one.damage + oponent.attack + rand() % 10) - user.defense << " damage." << endl;
						user.hp -= (oponent.one.damage + oponent.attack) - user.defense;
					}
					else
					{
						cout << "Oponent's fist does 5 damage." << endl;
						user.hp -= 5;
					}
				}
				else cout << "Oponent's fist attack missed..." << endl;
				break;
			case 1: //kick
				if (Hit(oponent.two.accuracy) == true)
				{
					if (((oponent.two.damage + oponent.attack + rand() % 10) - user.defense) > 6)
					{
						cout << "Oponent's kick does " << (oponent.two.damage + oponent.attack + rand() % 10) - user.defense << " damage." << endl;
						user.hp -= (oponent.two.damage + oponent.attack) - user.defense;
					}
					else
					{
						cout << "Oponent's kick does 5 damage." << endl;
						user.hp -= 5;
					}
				}
				else cout << "Oponent's kick attack missed..." << endl;
				break;
			case 2: //sound wave
				if (Hit(oponent.three.accuracy) == true)
				{
					cout << "Oponent has made you fall asleep for 1 turn with his sound wave." << endl;
					skip_user = true;
				}
				else cout << "Oponent's sound wave missed..." << endl;
				break;
			case 3: //concentrated defense
				if (Hit(user.four.accuracy) == true)
				{
					cout << "Your attack is now doubled but you wont be able to move the next turn." << endl;
					user.defense = user.defense + 30;
					skip_oponent = true;
				}
				else cout << "Oponent's concentrated defence missed..." << endl;
				break;
			}
		}
		else
		{
			cout << "Oponent's turn is skipped" << endl;
			skip_oponent = false;
		}
		PrintStats(user, oponent);

		turn = 0;

	} while (user.hp >= 0 && oponent.hp >= 0);

	if (user.hp <= 0)
		cout << "YOU DIED! GAME OVER!" << endl;
	else if (oponent.hp <= 0)
		cout << "Congratulations! You won!" << endl;


}

void FightTorresiano(player user, player oponent)
{
	cout << user.name << " vs " << oponent.name << endl;
	PrintStats(user, oponent);
	int turn = 0;
	int select;
	int selectIA;
	bool skip_user = false;
	bool skip_oponent = false;
	int round = 0;
	do
	{
		round++;
		cout << endl;
		cout << "ROUND: " << round << endl;

		if (skip_user == false)
		{
			if (turn == 0)
			{
				cout << "Pick an attack: Type the number of the move you want to use '1', '2', '3' or '4'" << endl;
				cout << user.one.name << endl;
				cout << user.two.name << endl;
				cout << user.three.name << endl;
				cout << user.four.name << endl;

				cin >> select;

				switch (select)
				{
				case 1: //fist
					if (Hit(user.one.accuracy) == true)
					{
						cout << "Your fist does " << (user.one.damage + user.attack + rand() % 10) - oponent.defense << " damage." << endl;
						oponent.hp -= (user.one.damage + user.attack) - oponent.defense;
					}
					else cout << "Your fist attack misses..." << endl;
					break;
				case 2: //kick
					if (Hit(user.two.accuracy) == true)
					{
						cout << "Your kick does " << (user.two.damage + user.attack + rand() % 10) - oponent.defense << " damage." << endl;
						oponent.hp -= (user.two.damage + user.attack) - oponent.defense;
					}
					else cout << "Your kick attack misses..." << endl;
					break;
				case 3: //concentrated defense
					if (Hit(user.three.accuracy) == true)
					{
						cout << "Your defense is now higher but you wont be able to move the next turn." << endl;
						user.defense = user.defense + 30;
						skip_user = true;
					}
					else cout << "Your concentrated defense misses..." << endl;
					break;
				case 4: //mind strength
					if (Hit(user.four.accuracy) == true)
					{
						cout << "Your attack is now doubled but you wont be able to move the next turn." << endl;
						user.attack = user.attack * 2;
						skip_user = true;
					}
					else cout << "Your mind strength misses..." << endl;
					break;
				}

			}
		}
		else
		{
			cout << "Your turn is skipped" << endl;
			skip_user = false;
		}

		turn = 1;

		if (skip_oponent == false)
		{
			selectIA = rand() % 3;

			switch (selectIA)
			{
			case 0: //fist
				if (Hit(oponent.one.accuracy) == true)
				{
					if (((oponent.one.damage + oponent.attack + rand() % 10) - user.defense) > 6)
					{
						cout << "Oponent's fist does " << (oponent.one.damage + oponent.attack + rand() % 10) - user.defense << " damage." << endl;
						user.hp -= (oponent.one.damage + oponent.attack) - user.defense;
					}
					else
					{
						cout << "Oponent's fist does 5 damage." << endl;
						user.hp -= 5;
					}
				}
				else cout << "Oponent's fist attack missed..." << endl;
				break;
			case 1: //kick
				if (Hit(oponent.two.accuracy) == true)
				{
					if (((oponent.two.damage + oponent.attack + rand() % 10) - user.defense) > 6)
					{
						cout << "Oponent's kick does " << (oponent.two.damage + oponent.attack + rand() % 10) - user.defense << " damage." << endl;
						user.hp -= (oponent.two.damage + oponent.attack) - user.defense;
					}
					else
					{
						cout << "Oponent's kick does 5 damage." << endl;
						user.hp -= 5;
					}
				}
				else cout << "Oponent's kick attack missed..." << endl;
				break;
			case 2: //big wind
				if (Hit(oponent.three.accuracy) == true)
				{
					cout << "Oponent has used his abasfeto to produce a big wind which makes it for player harder to see, all Bandis' accuracy has been lowered by 5." << endl;
					user.one.accuracy -= 5;
					user.two.accuracy -= 5;
					user.three.accuracy -= 5;
					user.four.accuracy -= 5;
				}
				else cout << "Oponent's big wind missed..." << endl;
				break;
			case 3: //mind strength
				if (Hit(oponent.four.accuracy) == true)
				{
					cout << "Oponent's attack is now doubled but wont be able to move the next turn." << endl;
					oponent.attack = oponent.attack * 2;
					skip_oponent = true;
				}
				else cout << "Your mind strength misses..." << endl;
				break;
			}
		}
		else
		{
			cout << "Oponent's turn is skipped" << endl;
			skip_oponent = false;
		}
		PrintStats(user, oponent);

		turn = 0;

	} while (user.hp >= 0 && oponent.hp >= 0);

	if (user.hp <= 0)
		cout << "YOU DIED! GAME OVER!" << endl;
	else if (oponent.hp <= 0)
		cout << "Congratulations! You won!" << endl;
}

void FightTragan(player user, player oponent)
{
	cout << user.name << " vs " << oponent.name << endl;
	PrintStats(user, oponent);
	int turn = 0;
	int select;
	int selectIA;
	bool skip_user = false;
	bool skip_oponent = false;
	int round = 0;
	do
	{
		round++;
		cout << endl;
		cout << "ROUND: " << round << endl;

		if (skip_user == false)
		{
			if (turn == 0)
			{
				cout << "Pick an attack: Type the number of the move you want to use '1', '2', '3' or '4'" << endl;
				cout << user.one.name << endl;
				cout << user.two.name << endl;
				cout << user.three.name << endl;
				cout << user.four.name << endl;

				cin >> select;

				switch (select)
				{
				case 1: //fist
					if (Hit(user.one.accuracy) == true)
					{
						cout << "Your fist does " << (user.one.damage + user.attack + rand() % 10) - oponent.defense << " damage." << endl;
						oponent.hp -= (user.one.damage + user.attack) - oponent.defense;
					}
					else cout << "Your fist attack misses..." << endl;
					break;
				case 2: //kick
					if (Hit(user.two.accuracy) == true)
					{
						cout << "Your kick does " << (user.two.damage + user.attack + rand() % 10) - oponent.defense << " damage." << endl;
						oponent.hp -= (user.two.damage + user.attack) - oponent.defense;
					}
					else cout << "Your kick attack misses..." << endl;
					break;
				case 3: //concentrated defense
					if (Hit(user.three.accuracy) == true)
					{
						cout << "Your defense is now higher but you wont be able to move the next turn." << endl;
						user.defense = user.defense + 30;
						skip_user = true;
					}
					else cout << "Your concentrated defense misses..." << endl;
					break;
				case 4: //mind strength
					if (Hit(user.four.accuracy) == true)
					{
						cout << "Your attack is now doubled." << endl;
						user.attack = user.attack * 2;

					}
					else cout << "Your mind strength misses..." << endl;
					break;
				}

			}
		}
		else
		{
			cout << "Your turn is skipped" << endl;
			skip_user = false;
		}

		turn = 1;

		if (skip_oponent == false)
		{
			selectIA = rand() % 3;

			switch (selectIA)
			{
			case 0: //fist
				if (Hit(oponent.one.accuracy) == true)
				{
					if (((oponent.one.damage + oponent.attack + rand() % 10) - user.defense) > 6)
					{
						cout << "Oponent's fist does " << (oponent.one.damage + oponent.attack + rand() % 10) - user.defense << " damage." << endl;
						user.hp -= (oponent.one.damage + oponent.attack) - user.defense;
					}
					else
					{
						cout << "Oponent's fist does 5 damage." << endl;
						user.hp -= 5;
					}
				}
				else cout << "Oponent's fist attack missed..." << endl;
				break;
			case 1: //kick
				if (Hit(oponent.two.accuracy) == true)
				{
					if (((oponent.two.damage + oponent.attack + rand() % 10) - user.defense) > 6)
					{
						cout << "Oponent's kick does " << (oponent.two.damage + oponent.attack + rand() % 10) - user.defense << " damage." << endl;
						user.hp -= (oponent.two.damage + oponent.attack) - user.defense;
					}
					else
					{
						cout << "Oponent's kick does 5 damage." << endl;
						user.hp -= 5;
					}
				}
				else cout << "Oponent's kick attack missed..." << endl;
				break;
			case 2: //abasfeto
				if (Hit(oponent.three.accuracy) == true)
				{
					cout << "Oponent has used the abasfeto to produce and exploison and damage everyone around" << endl;
					cout << "The explosion does 50 damage and does 50 damage to himself," << endl;
					user.hp -= 50;
					oponent.hp -= 50;
				}
				else cout << "Oponent's abasfeto missed..." << endl;
				break;
			case 3: //big wind
				if (Hit(oponent.four.accuracy) == true)
				{
					cout << "Oponent has used his abasfeto to produce a big wind which makes it for player harder to see, all Bandis' accuracy has been lowered by 5." << endl;
					user.one.accuracy -= 5;
					user.two.accuracy -= 5;
					user.three.accuracy -= 5;
					user.four.accuracy -= 5;
				}
				else cout << "Oponent's big wind missed..." << endl;
				break;
			}
		}
		else
		{
			cout << "Oponent's turn is skipped" << endl;
			skip_oponent = false;
		}
		PrintStats(user, oponent);

		turn = 0;

	} while (user.hp >= 0 && oponent.hp >= 0);

	if (user.hp <= 0)
		cout << "YOU DIED! GAME OVER!" << endl;
	else if (oponent.hp <= 0)
		cout << "Congratulations! You won!" << endl;
}

void FightIABimtiano(player user, player oponent)
{
	cout << user.name << " vs " << oponent.name << endl;
	PrintStats(user, oponent);
	int turn = 0;
	int select;
	int selectIA;
	bool skip_user = false;
	bool skip_oponent = false;
	int round = 0;
	do
	{
		round++;
		cout << endl;
		cout << "ROUND: " << round << endl;

		if (skip_user == false)
		{
			if (turn == 0)
			{
				select = rand() % 3;

				switch (select)
				{
				case 0: //fist
					if (Hit(user.one.accuracy) == true)
					{
						cout << "Your fist does " << (user.one.damage + user.attack + rand() % 10) - oponent.defense << " damage." << endl;
						oponent.hp -= (user.one.damage + user.attack) - oponent.defense;
					}
					else cout << "Your fist attack misses..." << endl;
					break;
				case 1: //kick
					if (Hit(user.two.accuracy) == true)
					{
						cout << "Your kick does " << (user.two.damage + user.attack + rand() % 10) - oponent.defense << " damage." << endl;
						oponent.hp -= (user.two.damage + user.attack) - oponent.defense;
					}
					else cout << "Your kick attack misses..." << endl;
					break;
				case 2: //concentrated defense
					if (Hit(user.three.accuracy) == true)
					{
						cout << "Your defense is now higher but you wont be able to move the next turn." << endl;
						user.defense = user.defense + 30;
						skip_user = true;
					}
					else cout << "Your concentrated defense misses..." << endl;
					break;
				case 3: //mind strength
					if (Hit(user.four.accuracy) == true)
					{
						cout << "Your attack is now doubled but you wont be able to move the next turn." << endl;
						user.attack = user.attack * 2;
						skip_user = true;
					}
					else cout << "Your mind strength misses..." << endl;
					break;
				}

			}
		}
		else
		{
			cout << "Your turn is skipped" << endl;
			skip_user = false;
		}

		turn = 1;

		if (skip_oponent == false)
		{
			selectIA = rand() % 3;

			switch (selectIA)
			{
			case 0: //fist
				if (Hit(oponent.one.accuracy) == true)
				{
					if (((oponent.one.damage + oponent.attack + rand() % 10) - user.defense) > 6)
					{
						cout << "Oponent's fist does " << (oponent.one.damage + oponent.attack + rand() % 10) - user.defense << " damage." << endl;
						user.hp -= (oponent.one.damage + oponent.attack) - user.defense;
					}
					else
					{
						cout << "Oponent's fist does 5 damage." << endl;
						user.hp -= 5;
					}
				}
				else cout << "Oponent's fist attack missed..." << endl;
				break;
			case 1: //kick
				if (Hit(oponent.two.accuracy) == true)
				{
					if (((oponent.two.damage + oponent.attack + rand() % 10) - user.defense) > 6)
					{
						cout << "Oponent's kick does " << (oponent.two.damage + oponent.attack + rand() % 10) - user.defense << " damage." << endl;
						user.hp -= (oponent.two.damage + oponent.attack) - user.defense;
					}
					else
					{
						cout << "Oponent's kick does 5 damage." << endl;
						user.hp -= 5;
					}
				}
				else cout << "Oponent's kick attack missed..." << endl;
				break;
			case 2: //sound wave
				if (Hit(oponent.three.accuracy) == true)
				{
					cout << "Oponent has made you fall asleep for 1 turn with his sound wave." << endl;
					skip_user = true;
				}
				else cout << "Oponent's sound wave missed..." << endl;
				break;
			case 3: //concentrated defense
				if (Hit(user.four.accuracy) == true)
				{
					cout << "Your attack is now doubled but you wont be able to move the next turn." << endl;
					user.defense = user.defense + 30;
					skip_oponent = true;
				}
				else cout << "Oponent's concentrated defence missed..." << endl;
				break;
			}
		}
		else
		{
			cout << "Oponent's turn is skipped" << endl;
			skip_oponent = false;
		}
		PrintStats(user, oponent);

		turn = 0;

	} while (user.hp >= 0 && oponent.hp >= 0);

	if (user.hp <= 0)
		cout << "YOU DIED! GAME OVER!" << endl;
	else if (oponent.hp <= 0)
		cout << "Congratulations! You won!" << endl;


}

void FightIATragan(player user, player oponent)
{
	cout << user.name << " vs " << oponent.name << endl;
	PrintStats(user, oponent);
	int turn = 0;
	int select;
	int selectIA;
	bool skip_user = false;
	bool skip_oponent = false;
	int round = 0;
	do
	{
		round++;
		cout << endl;
		cout << "ROUND: " << round << endl;

		if (skip_user == false)
		{
			if (turn == 0)
			{
				select = rand() % 3;

				switch (select)
				{
				case 0: //fist
					if (Hit(user.one.accuracy) == true)
					{
						cout << "Your fist does " << (user.one.damage + user.attack + rand() % 10) - oponent.defense << " damage." << endl;
						oponent.hp -= (user.one.damage + user.attack) - oponent.defense;
					}
					else cout << "Your fist attack misses..." << endl;
					break;
				case 1: //kick
					if (Hit(user.two.accuracy) == true)
					{
						cout << "Your kick does " << (user.two.damage + user.attack + rand() % 10) - oponent.defense << " damage." << endl;
						oponent.hp -= (user.two.damage + user.attack) - oponent.defense;
					}
					else cout << "Your kick attack misses..." << endl;
					break;
				case 2: //concentrated defense
					if (Hit(user.three.accuracy) == true)
					{
						cout << "Your defense is now higher but you wont be able to move the next turn." << endl;
						user.defense = user.defense + 30;
						skip_user = true;
					}
					else cout << "Your concentrated defense misses..." << endl;
					break;
				case 3: //mind strength
					if (Hit(user.four.accuracy) == true)
					{
						cout << "Your attack is now doubled." << endl;
						user.attack = user.attack * 2;

					}
					else cout << "Your mind strength misses..." << endl;
					break;
				}

			}
		}
		else
		{
			cout << "Your turn is skipped" << endl;
			skip_user = false;
		}

		turn = 1;

		if (skip_oponent == false)
		{
			selectIA = rand() % 3;

			switch (selectIA)
			{
			case 0: //fist
				if (Hit(oponent.one.accuracy) == true)
				{
					if (((oponent.one.damage + oponent.attack + rand() % 10) - user.defense) > 6)
					{
						cout << "Oponent's fist does " << (oponent.one.damage + oponent.attack + rand() % 10) - user.defense << " damage." << endl;
						user.hp -= (oponent.one.damage + oponent.attack) - user.defense;
					}
					else
					{
						cout << "Oponent's fist does 5 damage." << endl;
						user.hp -= 5;
					}
				}
				else cout << "Oponent's fist attack missed..." << endl;
				break;
			case 1: //kick
				if (Hit(oponent.two.accuracy) == true)
				{
					if (((oponent.two.damage + oponent.attack + rand() % 10) - user.defense) > 6)
					{
						cout << "Oponent's kick does " << (oponent.two.damage + oponent.attack + rand() % 10) - user.defense << " damage." << endl;
						user.hp -= (oponent.two.damage + oponent.attack) - user.defense;
					}
					else
					{
						cout << "Oponent's kick does 5 damage." << endl;
						user.hp -= 5;
					}
				}
				else cout << "Oponent's kick attack missed..." << endl;
				break;
			case 2: //abasfeto
				if (Hit(oponent.three.accuracy) == true)
				{
					cout << "Oponent has used the abasfeto to produce and exploison and damage everyone around" << endl;
					cout << "The explosion does 50 damage and does 50 damage to himself," << endl;
					user.hp -= 50;
					oponent.hp -= 50;
				}
				else cout << "Oponent's abasfeto missed..." << endl;
				break;
			case 3: //big wind
				if (Hit(oponent.four.accuracy) == true)
				{
					cout << "Oponent has used his abasfeto to produce a big wind which makes it for player harder to see, all Bandis' accuracy has been lowered by 5." << endl;
					user.one.accuracy -= 5;
					user.two.accuracy -= 5;
					user.three.accuracy -= 5;
					user.four.accuracy -= 5;
				}
				else cout << "Oponent's big wind missed..." << endl;
				break;
			}
		}
		else
		{
			cout << "Oponent's turn is skipped" << endl;
			skip_oponent = false;
		}
		PrintStats(user, oponent);

		turn = 0;

	} while (user.hp >= 0 && oponent.hp >= 0);

	if (user.hp <= 0)
		cout << "YOU DIED! GAME OVER!" << endl;
	else if (oponent.hp <= 0)
		cout << "Congratulations! You won!" << endl;
}


int main()
{
	player Bandis_lvl1;
	player Bandis_lvl2;
	player Bandis_lvl3;
	player Bimtiano;
	player Torresiano;
	player Tragan;

	//bandis lvl1
	Bandis_lvl1.name = "Bandis";
	Bandis_lvl1.hp = 100;
	Bandis_lvl1.attack = 70;
	Bandis_lvl1.defense = 90;
	Bandis_lvl1.speed = 80;
	Bandis_lvl1.mind = 95;
	Bandis_lvl1.one.name = "1. Fist";
	Bandis_lvl1.one.damage = 60;
	Bandis_lvl1.one.accuracy = 100;
	Bandis_lvl1.two.name = "2. Kick";
	Bandis_lvl1.two.damage = 75;
	Bandis_lvl1.two.accuracy = 90;
	Bandis_lvl1.three.name = "3. Concentrated Defense";
	Bandis_lvl1.three.damage = 0;
	Bandis_lvl1.three.accuracy = 95;
	Bandis_lvl1.three.CD = true;
	Bandis_lvl1.four.name = "4. Mind Strength";
	Bandis_lvl1.four.damage = 0;
	Bandis_lvl1.four.accuracy = 95;
	Bandis_lvl1.four.MS = true;

	//bandis lvl2
	Bandis_lvl2.name = "Bandis";
	Bandis_lvl2.hp = 110;
	Bandis_lvl2.attack = 80;
	Bandis_lvl2.defense = 100;
	Bandis_lvl2.speed = 90;
	Bandis_lvl2.mind = 105;
	Bandis_lvl2.one.name = "1. Fist";
	Bandis_lvl2.one.damage = 60;
	Bandis_lvl2.one.accuracy = 100;
	Bandis_lvl2.two.name = "2. Kick";
	Bandis_lvl2.two.damage = 75;
	Bandis_lvl2.two.accuracy = 90;
	Bandis_lvl2.three.name = "3. Concentrated Defense";
	Bandis_lvl2.three.damage = 0;
	Bandis_lvl2.three.accuracy = 100;
	Bandis_lvl2.three.CD = true;
	Bandis_lvl2.four.name = "4. Mind Strength";
	Bandis_lvl2.four.damage = 0;
	Bandis_lvl2.four.accuracy = 100;
	Bandis_lvl2.four.MS = true;

	//bandis lvl3
	Bandis_lvl3.name = "Bandis";
	Bandis_lvl3.hp = 120;
	Bandis_lvl3.attack = 90;
	Bandis_lvl3.defense = 110;
	Bandis_lvl3.speed = 100;
	Bandis_lvl3.mind = 115;
	Bandis_lvl3.one.name = "1. Fist";
	Bandis_lvl3.one.damage = 60;
	Bandis_lvl3.one.accuracy = 100;
	Bandis_lvl3.two.name = "2. Kick";
	Bandis_lvl3.two.damage = 75;
	Bandis_lvl3.two.accuracy = 90;
	Bandis_lvl3.three.name = "3. Concentrated Defense";
	Bandis_lvl3.three.damage = 0;
	Bandis_lvl3.three.accuracy = 100;
	Bandis_lvl3.three.CD = true;
	Bandis_lvl3.four.name = "4. Mind Strength";
	Bandis_lvl3.four.damage = 0;
	Bandis_lvl3.four.accuracy = 100;
	Bandis_lvl3.four.MS = true;

	//bimtiano
	Bimtiano.name = "Bimtiano";
	Bimtiano.hp = 110;
	Bimtiano.attack = 80;
	Bimtiano.defense = 80;
	Bimtiano.speed = 75;
	Bimtiano.mind = 60;
	Bimtiano.one.name = "1. Fist";
	Bimtiano.one.damage = 60;
	Bimtiano.one.accuracy = 85;
	Bimtiano.two.name = "2. Kick";
	Bimtiano.two.damage = 75;
	Bimtiano.two.accuracy = 60;
	Bimtiano.three.name = "3. Sonic Wave";
	Bimtiano.three.damage = 0;
	Bimtiano.three.accuracy = 40;
	Bimtiano.three.SW = true;
	Bimtiano.four.name = "4. Concentrated Defense";
	Bimtiano.four.damage = 0;
	Bimtiano.four.accuracy = 60;
	Bimtiano.four.CD = true;

	//torresiano
	Torresiano.name = "Torresiano";
	Torresiano.hp = 300;
	Torresiano.attack = 85;
	Torresiano.defense = 80;
	Torresiano.speed = 90;
	Torresiano.mind = 65;
	Torresiano.one.name = "1. Fist";
	Torresiano.one.damage = 60;
	Torresiano.one.accuracy = 90;
	Torresiano.two.name = "2. Kick";
	Torresiano.two.damage = 75;
	Torresiano.two.accuracy = 70;
	Torresiano.three.name = "3. Big Wind";
	Torresiano.three.damage = 0;
	Torresiano.three.accuracy = 80;
	Torresiano.three.BW = true;
	Torresiano.four.name = "4. Mind Strength";
	Torresiano.four.damage = 0;
	Torresiano.four.accuracy = 65;
	Torresiano.four.MS = true;

	//Tragan
	Tragan.name = "Tragan";
	Tragan.hp = 500;
	Tragan.attack = 90;
	Tragan.defense = 90;
	Tragan.speed = 95;
	Tragan.mind = 70;
	Tragan.one.name = "1. Fist";
	Tragan.one.damage = 60;
	Tragan.one.accuracy = 90;
	Tragan.two.name = "2. Kick";
	Tragan.two.damage = 75;
	Tragan.two.accuracy = 70;
	Tragan.three.name = "3. Abasfeto";
	Tragan.three.damage = 90;
	Tragan.three.accuracy = 100;
	Tragan.three.own_damage = 50;
	Tragan.four.name = "4. Big Wind";
	Tragan.four.damage = 0;
	Tragan.four.accuracy = 80;
	Tragan.four.BW = true;

	srand(time(NULL));

	int x = 0;
	cout << "Welcome to the battle simulator! Type '1' to fight or '2' to emulate\n";
	//while (x == 1 || x == 2)

	cin >> x;


	if (x == 1)
	{
		int fight;
		cout << "Fight against: Type '1' for bimtiano, '2' for torresiano and '3' for boss Tragan\n";
		cin >> fight;
		if (fight == 1)
		{
			FightBimtiano(Bandis_lvl1, Bimtiano);
		}
		else if (fight == 2)
		{
			FightTorresiano(Bandis_lvl2, Torresiano);
		}
		else if (fight == 3)
		{
			FightTragan(Bandis_lvl3, Tragan);
		}
	}
	else if (x == 2)
	{
		int fightIA;
		cout << "Type '1' for Bandis vs Bimtiano, '2' for Bandis vs boss Tragan" << endl;
		cin >> fightIA;
		if (fightIA == 1)
		{
			FightIABimtiano(Bandis_lvl1, Bimtiano);
		}
		else if (fightIA == 2)
		{
			FightIATragan(Bandis_lvl3, Tragan);
		}
	}
	else
	{
		cout << "Incorrect number.\n";
	}




	system("pause");
	return 0;
}
