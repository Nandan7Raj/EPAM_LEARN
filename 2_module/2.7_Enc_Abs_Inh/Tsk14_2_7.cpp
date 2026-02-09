#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Abstract Base Class
class Character {

    int health;
    int mana;
    static constexpr int MAX_HEALTH = 100;
    static constexpr int MAX_MANA   = 100;

protected:
    // Validated setters
    bool setHealth(int h) {
        if (h < 0 || h > MAX_HEALTH) {
            cout << "Invalid health! (must be 0.." << MAX_HEALTH << ")\n";
            return false;
        }
        health = h;
        return true;
    }

    bool setMana(int m) {
        if (m < 0 || m > MAX_MANA) {
            cout << "Invalid mana! (must be 0.." << MAX_MANA << ")\n";
            return false;
        }
        mana = m;
        return true;
    }

public:
    Character(int h, int m) : health(0), mana(0) {  // safe defaults
        setHealth(h);
        setMana(m);
    }

    // Public getters
    int getHealth() const { return health; }
    int getMana() const { return mana; }

    // Public validated updates
    bool updateHealth(int h) { return setHealth(h); }
    bool updateMana(int m) { return setMana(m); }

    // Must be implemented by derived classes
    virtual void attack() = 0;

    virtual ~Character() = default;
};

// Derived: Warrior
class Warrior : public Character {
public:
    Warrior(int h, int m) : Character(h, m) {}

    void attack() override {
        if (getHealth() <= 0) {
            cout << "[Warrior] Can't attack: I'm defeated!\n";
            return;
        }
        cout << "[Warrior] Dum haii to aaja! (melee attack)\n";
    }
};

// Derived: Mage
class Mage : public Character {
public:
    Mage(int h, int m) : Character(h, m) {}

    void attack() override {
        if (getHealth() <= 0) {
            cout << "[Mage] Can't attack: I'm defeated!\n";
            return;
        }
        if (getMana() <= 0) {
            cout << "[Mage] Not enough mana to cast a spell!\n";
            return;
        }
        cout << "[Mage] casts Fireball! (magic attack, mana -10)\n";

        // Reduce mana safely using validated setter via public updater
        int newMana = getMana() - 10;
        if (newMana < 0) newMana = 0;
        updateMana(newMana);
    }
};


int main() {
    Warrior w(80, 20);
    Mage m(60, 15);

    vector<Character*> party;
    party.push_back(&w);
    party.push_back(&m);

    cout << "Party Attacks (Polymorphism)\n";
    for (Character* c : party) {
        c->attack();
        cout << "Health: " << c->getHealth() << ", Mana: " << c->getMana() << "\n\n";
    }

    cout << "Validation Tests\n";
    w.updateHealth(-5);    // invalid
    w.updateMana(200);     // invalid
    m.updateMana(-10);     // invalid
    m.updateHealth(150);   // invalid

    w.updateHealth(50);    //valid
    w.updateMana(70);     // valid
    m.updateMana(60);     // valid
    m.updateHealth(100);   // valid

    cout << "\nAfter Invalid Attempts \n";
    cout << "Warrior -> Health: " << w.getHealth() << ", Mana: " << w.getMana() << "\n";
    cout << "Mage    -> Health: " << m.getHealth() << ", Mana: " << m.getMana() << "\n\n";

    cout << "Mage Mana Drain Demo\n";
    // Keep attacking until mana reaches 0
    for (int i = 0; i < 5; i++) {
        m.attack();
        cout << "Mage Mana: " << m.getMana() << "\n";
    }

    return 0;
}
