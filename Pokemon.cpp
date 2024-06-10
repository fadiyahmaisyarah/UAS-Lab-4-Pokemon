#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

// Pilihan Pokemon
void selectpokemon(string pokemonuser, string& selectedpokemon, int& HP, string& attack) {
    if (pokemonuser=="Pikachu"||pokemonuser=="1") {
        selectedpokemon="Pikachu"; HP=100;
        attack="\n1. Thunderbolt (40 DMG)\n2. Quick Attack (20 DMG)\n3. Iron Tail (30 DMG)";
        }
    else if (pokemonuser=="Charmander"||pokemonuser=="2") {
        selectedpokemon="Charmander"; HP=100;
        attack="\n1. Flamethrower (40 DMG)\n2. Scratch (20 DMG)\n3. Ember (30 DMG)";
    }
    else if (pokemonuser=="Bulbasaur"||pokemonuser=="3") {
        selectedpokemon="Bulbasaur"; HP=100;
        attack="\n1. Vine Whip (40 DMG)\n2. Tackle (20 DMG)\n3. Bubble (30 DMG)";
    }
    else if (pokemonuser=="Squirtle"||pokemonuser=="4") {
        selectedpokemon="Squirtle"; HP=100;
        attack="\n1. Water Gun (40 DMG)\n2. Tackle (20 DMG)\n3. Bubble (30 DMG)";
    }
    else if (pokemonuser=="Mewtwo"||pokemonuser=="5") {
        selectedpokemon="Mewtwo"; HP=100;
        attack="\n1. Psystrike (80 DMG)\n2. Confusion (20 DMG)\n3. Psycho Cut (30 DMG)";
    }
    else if (pokemonuser=="Snorlax"||pokemonuser=="6") {
        selectedpokemon="Snorlax"; HP=100;
        attack="\n1. Hyper beam (50 DMG)\n2. Tackle (30 DMG)\n3. Rest (0 DMG)";
    }
    else if (pokemonuser=="Lucario"||pokemonuser=="7") {
        selectedpokemon="Lucario"; HP=100;
        attack="\n1. Dragon pulse (50 DMG)\n2. Bone rush (30 DMG)\n3. Quick attack (20 DMG)";
    }
    else if (pokemonuser=="Rayquaza"||pokemonuser=="8") {
        selectedpokemon="Rayquaza"; HP=100;
        attack="\n1. Dragon ascent (40 DMG)\n2. Twister (40 DMG)\n3. Ice beam (30 DMG)";
    }
    else if (pokemonuser=="Arceus"||pokemonuser=="9") {
        selectedpokemon="Arceus"; HP=100;
        attack="\n1. Judgement (80 DMG)\n2. Earth power (40 DMG)\n3. Hypervoice (30 DMG)";
    }
    else if (pokemonuser=="Lugia"||pokemonuser=="10") {
        selectedpokemon="Lugia"; HP=100;
        attack="\n1. Aeroblast (80 DMG)\n2. Hydro pump (40 DMG)\n3. Whirlpool (30 DMG)";
    }
    else {
        selectedpokemon=="???"; HP=0; attack="\n???";
    }
}

// Info attack
struct Attack {
    string name;
    int damage;

    Attack(string n, int d) : name(n), damage(d) {}
};

// Class Pokemon
class Pokemon {
public:
    string name;
    int hp;
    int maxHp;
    int defense;
    vector<Attack> attacks;
    int catchRate;

    Pokemon(string n, int h, int d, vector<Attack> a, int rate)
        : name(n), hp(h), defense(d), attacks(a), catchRate(rate) {}

    // Attack Pokemon
    void attackPokemon(Pokemon &target, int attackIndex) {
        if (attackIndex < 0 || attackIndex >= attacks.size()) {
            cout << "Attack tidak valid!\n";
            return;
        }
        Attack selectedAttack = attacks[attackIndex];
        int damage = selectedAttack.damage - target.defense;
        if (damage < 0) damage = 0;
        target.hp -= damage;
        cout <<"\n"<< this->name << " menggunakan " << selectedAttack.name << " pada " << target.name << " sebesar " << damage << " damage!\n";
        if (target.hp < 0) target.hp = 0;
    }
    
    // Memeriksa apakah pokemon pingsan atau tidak
    bool isFainted() {
        return hp <= 0;
    }

    void printAttacks() {
        for (int i = 0; i < attacks.size(); i++) {
            cout << i + 1 << ". " << attacks[i].name << " (Damage: " << attacks[i].damage << ")\n";
        }
    }

    void printInfo() {
        cout << "Pokemon: " << name << ", HP: " << hp << ", Defense: " << defense << "\n";
    }
    
     void restoreHealth() {
        hp = 100;
    }
    
};
