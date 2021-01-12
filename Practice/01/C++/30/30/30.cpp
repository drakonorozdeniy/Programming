#include <string>
#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> Lootbox;
struct Item {
    enum  class Itemtype {COIN,RUNE,WEAPON,ARMOR};
    union BG {
        struct Coin {
            int count;
        };
        struct Rune {
            int level;
            enum class Element {FIRE,WATER,EARTH,AIR};

        };
        struct Weapon {
            int damage;
            int critical;
            int durability;
        };
        struct Armor {
            int guard;
            int durability;
        };
    };
};
vector<int> generateLootBox(vector<int>); {

}

int main()
{
    std::cout << "Hello World!\n";
}


