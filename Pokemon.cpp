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

// Class Player
class Player {
public:
    string name;
    int level;
    int coins = 0;
    int expp = 0;
    vector<Pokemon> ownedPokemons;

    Player(string n, int l) : name(n), level(l) {}

    void printInfo() {
        cout << "Player: " << name << endl << "Level: " << level << endl;
    }

    void printOwnedPokemons() {
        cout << "Pokemon yang dimiliki: " << endl;
        for (int i = 0; i < ownedPokemons.size(); ++i) {
            cout << i + 1 << ". " << ownedPokemons[i].name << "\n";
        }
    }

    void addPokemon(const Pokemon &pokemon) {
        ownedPokemons.push_back(pokemon);
    }

    void reward(int coinsReward, int expReward) {
        coins += coinsReward;
        level += expReward;
        expp  += expReward;
        cout << "Kamu mendapat " << coinsReward << " coins dan " << expReward << " exp!\n";
    }

    bool tryToCatch(Pokemon &pokemon) {
        int roll = rand() % 100 + 1;
        if (coins >= 10)
        {   
            coins -= 10;
            cout << pokemon.name << " liar muncul!" << endl;
            if (roll <= pokemon.catchRate) 
            {
                cout << "Selamat! Kamu berhasil menangkap " << pokemon.name << "!\n";
                addPokemon(pokemon);
                return true;
            }   
            else 
            {
                cout << "Oh tidak! " << pokemon.name << " melarikan diri!\n";
                return false;
            }
        }
        else 
        {
            cout << "Koin tidak cukup" << endl;
            return false;
        }
    }
};
// Battle pokemon player dan musuh
void battle(Pokemon &pokemon1, Pokemon &pokemon2, Player &player) {
    srand(static_cast<unsigned int>(time(0)));

    cout << "\nBattle dimulai: " << pokemon1.name << " vs " << pokemon2.name << "!\n\n";
    while (!pokemon1.isFainted() && !pokemon2.isFainted()) {
        int attackChoice;

        // Giliran player
        cout << "Giliran " << pokemon1.name << " Pilih attack : " << endl;
        pokemon1.printAttacks();
        cout << "Masukkan serangan pilihanmu di sini (1/2/3): ";
        cin >> attackChoice;
        pokemon1.attackPokemon(pokemon2, attackChoice - 1);
        if (pokemon2.isFainted()) {
            cout << pokemon2.name << " telah pingsan! " << pokemon1.name << " menang!\n";
            player.reward(20, 1); // Hadiah koin dan exp dari battle
            pokemon1.restoreHealth();
            pokemon2.restoreHealth();
            break;
        }

        // Giliran musuh (random)
        attackChoice = rand() % pokemon2.attacks.size();
        pokemon2.attackPokemon(pokemon1, attackChoice);
        if (pokemon1.isFainted()) {
            cout << pokemon1.name << " telah pingsan! " << pokemon2.name << " menang!\n";
            pokemon1.restoreHealth();
            pokemon2.restoreHealth();
            break;
        }

        cout << pokemon1.name << " HP: " << pokemon1.hp << " | " << pokemon2.name << " HP: " << pokemon2.hp << "\n\n";
    }
}

int main()
{
    srand(static_cast<unsigned int>(time(0)));

    system("CLS");
    string pokemon[] = {"Pikachu", "Charmander", "Bulbasaur", "Squirtle", "Mewtwo", "Snorlax", "Lucario", "Rayquaza", "Arceus", "Lugia"};
    string pokemonuser, selectedpokemon, attack;
    int HP, pilihanmenu, count, coins, coinsReward, expReward;
    char name[50], yn;

    vector<Attack> pikachuAttacks = {
        Attack("Thunderbolt", 40),
        Attack("Quick attack", 20),
        Attack("Iron tail", 30)
    };
    vector<Attack> charmanderAttacks = {
        Attack("Flamethrower", 40),
        Attack("Scratch", 20),
        Attack("Ember", 30)
    };
    vector<Attack> bulbasaurAttacks = {
        Attack("Vine whip", 40),
        Attack("Tackle", 20),
        Attack("Bubble", 30)
    };
    vector<Attack> squirtleAttacks = {
        Attack("Water gun", 40),
        Attack("Tackle", 20),
        Attack("Bubble", 30)
    };
    vector<Attack> mewtwoAttacks = {
        Attack("Psystrike", 80),
        Attack("Confusion", 40),
        Attack("Psycho cut", 30)
    };
    
    vector<Attack> snorlaxAttacks = {
        Attack("Hyper beam", 50),
        Attack("Tackle", 30),
        Attack("Rest", 0)
    };
    
    vector<Attack> lucarioAttacks = {
        Attack("Dragon pulse", 50),
        Attack("Bone rush", 30),
        Attack("Quick attack", 20)
    };
    
    vector<Attack> rayquazaAttacks = {
        Attack("Dragon Ascent", 80),
        Attack("Twister", 40),
        Attack("Ice beam", 30)
    };
    
    vector<Attack> arceusAttacks = {
        Attack("Judgement", 80),
        Attack("Earth power", 40),
        Attack("Hyper voice", 30)
    };
    
    vector<Attack> lugiaAttacks = {
        Attack("Aeroblast", 80),
        Attack("Hydro Pump", 40),
        Attack("Whirlpool", 30)
    };
    vector<Pokemon> availablePokemons = {
        Pokemon("Pikachu", 100, 10, pikachuAttacks, 50),
        Pokemon("Charmander", 100, 10, charmanderAttacks, 30),
        Pokemon("Bulbasaur", 100, 10, bulbasaurAttacks, 40),
        Pokemon("Squirtle", 100, 10, squirtleAttacks, 35),
        Pokemon("Mewtwo", 100, 10, mewtwoAttacks, 10),
        Pokemon("Snorlax", 100, 10, snorlaxAttacks, 30),
        Pokemon("Lucario", 100, 10, lucarioAttacks, 30),
        Pokemon("Rayquaza", 100, 10, rayquazaAttacks, 10),
        Pokemon("Arceus", 100, 10, arceusAttacks, 10),
        Pokemon("Lugia", 100, 10, lugiaAttacks, 10)
    };

    cout << "Nama pemain: ";
    cin >> name;
    Player player(name, 1);
    player.addPokemon(Pokemon("Pikachu", 100, 10, pikachuAttacks, 50));

    mn: cout<<"\nMenu"<<endl;
    cout<<"1. Info Player\n2. Inventory\n3. Pokedex\n4. Catch Pokemon (10 coins)\n5. Battle";
    cout<<"\nMasukkan pilihanmu di sini (1/2/3/4/5): "; cin>>pilihanmenu;


        switch (pilihanmenu) {
            case 1:
                player.printInfo();
                break;

            case 2:
                cout << "\nKoin Anda: " << player.coins << endl;
                cout << "EXP Anda: " << player.expp << endl;
                break;

            case 3: cout<<"\nPokemon mana yang ingin Anda lihat?"<<endl;
            cout<<"1. Pikachu\n2. Charmander\n3. Bulbasaur\n4. Squirtle\n5. Mewtwo\n6. Snorlax\n7. Lucario\n8. Rayquaza\n9. Arceus\n10. Lugia";
            cout<<"\nMasukkan pilihanmu di sini: "; cin>>pokemonuser;
            
            selectpokemon(pokemonuser, selectedpokemon, HP, attack);

            cout<<"\nKamu telah memilih "<<selectedpokemon<<"! ("<<HP<<" HP)"<<endl;
            cout<<"Attacks: "<<attack<<endl; break;

            case 4: {
                Pokemon &wildPokemon = availablePokemons[rand() % availablePokemons.size()];
                player.tryToCatch(wildPokemon);
                break;
            }

            case 5: count++;
            player.printOwnedPokemons();
            cout<<"Masukkan Pokemon pilihanmu di sini (1/2/3/4/5): ";
            int index; cin>>index;
            Pokemon &chosenPokemon = player.ownedPokemons[index - 1];
            
            srand(static_cast<unsigned int>(time(0)));
            Pokemon &opponentPokemon = availablePokemons[rand() % availablePokemons.size()];
            battle(chosenPokemon, opponentPokemon, player);
            chosenPokemon.restoreHealth();
            break;

    }

    cout<<"\nKembali ke menu? (Y/N): "; cin>>yn;
    if ((yn=='Y') || (yn=='y')) {goto mn;}
    else { cout<<"Terima kasih sudah bermain!"; }
    return 0;
}
