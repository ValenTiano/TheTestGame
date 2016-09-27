#include <iostream>
#include <random>
#include <ctime>

using namespace std;

void main()
{
	mt19937 randomGenerator(time(0));
	uniform_real_distribution<float> RandomModifier(-10.0f, 10.0f);
	bool isBattle = true;
	bool nextHuman = true;
	bool nextZombie = true;

	int humanCount;
	int zombieCount;
	
	float humanDefaultHealth = 100.0f;
	float zombieDefaultHealth = 20.0f;

	float humanHealth;
	float zombieHealth;

	float humanDamage = 10.0f;
	float zombieDamage = 5.0f;

	cout << "Enter Humans Count:";
	cin >> humanCount;
	cout << "Enter Zombies Count:";
	cin >> zombieCount;

	while (isBattle) {
		if (nextHuman) {
			humanHealth = humanDefaultHealth + RandomModifier(randomGenerator);
			nextHuman = false;
		}
		cout << "Human " << humanCount << ". Health: " << humanHealth << endl;
		if (nextZombie) {
			zombieHealth = zombieDefaultHealth + RandomModifier(randomGenerator);
			nextZombie = false;
		}
		cout << "Zombie " << zombieCount << ". Health: " << zombieHealth << endl;
		cout << "Human punches zombie in face" << endl;
		float HumanModifier = RandomModifier(randomGenerator);
		zombieHealth -= humanDamage + HumanModifier;
		if (zombieHealth > 0) {
			cout << "Zombie is still Alive, and punches back";
		} else if(zombieCount > 0) {
			cout << "Zombie is dead. but there is more ..." << endl;
			nextZombie = true;
		} else {
			cout << "All Zombies is dead. Humans Win!" << endl;
			isBattle = false;
		}
	}

	system("PAUSE");
}
