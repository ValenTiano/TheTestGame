#include <iostream>
#include <random>
#include <ctime>
#include <string>

using namespace std;

int main()
{
    //random generators
    mt19937 randomGenerator(time(0));
    uniform_real_distribution<float> RandomModifier(-10.0f, 10.0f);
    uniform_real_distribution<float> ZombieDamageModifier(-5.0f, 10.0f);

    bool isBattle = true;
    bool nextHuman = true;
    bool nextZombie = true;

    //human vars
    int humanCount;
    float humanDefaultHealth = 100.0f;
    float humanHealth;
    float humanDamage = 10.0f;

    //zombie vars
    int zombieCount;
    float zombieDefaultHealth = 20.0f;
    float zombieHealth;    
    float zombieDamage = 5.0f;


    cout << "Enter Humans Count:";
    cin >> humanCount;
    cout << "Enter Zombies Count:";
    cin >> zombieCount;

    //battle simulation
    float zombieModifier;
    float humanModifier;
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

        humanModifier = RandomModifier(randomGenerator);
        cout << "Human punches zombie";
        if (humanModifier == -10.0f) {
            cout << ", but misses.\n";
        } else if (humanModifier < -2) {
            cout << "in legs. It's not very effective.\n";
        } else if (humanModifier < 6) {
            cout << "in chest.\n";
        } else if (humanModifier < 9) {
            cout << "in head. it's very effective!\n";
        } else {
            cout << "in head, dealing crittical damage!\n";
        }
        zombieHealth -= (humanDamage + humanModifier);
        if (zombieHealth > 1) {
            cout << "Zombie is still Alive, and punches back. \n";
            zombieModifier = ZombieDamageModifier(randomGenerator);
            cout << "Zombie ";
            if (zombieModifier == -5.0f) {
                cout << "misses human.\n";
            } else if (zombieModifier < -2) {
                cout << "punches human. It's not wery effective\n";
            } else if (zombieModifier < 6) {
                cout << "scratches human.\n";
            } else if (zombieModifier < 9) {
                cout << "bites human in arm. it's very effective!\n";
            } else {
                cout << "bites human in heck, blood is all around the place! human is dead...\n";
                humanCount--;
                nextHuman = true;
            }
            if (!nextHuman) {
                humanHealth -= (zombieDamage + zombieModifier);
                if (humanHealth > 0) {
                    cout << "Human is still Alive.";
                } else if (humanCount > 0) {
                    cout << "Human is dead. but there is more ..." << endl;
                    nextHuman = true;
                } else {
                    cout << "All Humans is dead. Zombies Win!" << endl;
                    isBattle = false;
                }
            }
        } else if (zombieCount > 1) {
            cout << "Zombie is dead. but there is more ..." << endl;
            zombieCount--;
            nextZombie = true;
        } else {
            cout << "All Zombies is dead. Humans Win!" << endl;
            isBattle = false;
        }
        cout << endl;
        system("PAUSE");
    }

    system("PAUSE");
    return 0;
}
