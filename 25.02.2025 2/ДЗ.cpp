#include <iostream>

using namespace std;

class Pudge 
{
private:
    int health; 
    int armour; 

public:

    Pudge(int initialHealth = 100, int initialArmour = 5) : health(initialHealth), armour(initialArmour) {}

    void FreshMeat(int healthBoost = 20, int armourBoost = 3) 
    {
        cout << "Pudge использует Fresh Meat!" << endl;
        health += healthBoost;
        armour += armourBoost;
        cout << "Здоровье увеличено на " << healthBoost << ", броня увеличена на " << armourBoost << "." << endl;
    }

    void PrintStatus() const 
    {
        cout << "Текущее состояние Pudge:" << endl;
        cout << "Здоровье: " << health << endl;
        cout << "Броня: " << armour << endl;
    }

    void TakeDamage(int damage) 
    {
        if (damage <= 0) {
            cout << "Невозможно нанести урон." << endl;
            return;
        }

        cout << "Pudge получает " << damage << " урона!" << endl;

        int effectiveDamage = max(1, damage - armour);
        health -= effectiveDamage;

        if (health <= 0) {
            cout << "Pudge погиб!" << endl;
        }
        else {
            cout << "Эффективный урон: " << effectiveDamage << endl;
        }
    }

    bool IsAlive() const {
        return health > 0;
    }
};

int main() 
{
    
    Pudge myPudge;

    cout << "Начальное состояние:" << endl;
    myPudge.PrintStatus();

    myPudge.FreshMeat();
    cout << "Состояние после использования FreshMeat:" << endl;
    myPudge.PrintStatus();

    cout << "\nНаносим урон Pudge:" << endl;
    myPudge.TakeDamage(30);
    myPudge.PrintStatus();

    if (myPudge.IsAlive()) {
        cout << "\nPudge все еще жив!" << endl;
    }
    else {
        cout << "\nPudge мертв!" << endl;
    }

    if (myPudge.IsAlive()) {
        cout << "\nPudge использует FreshMeat для восстановления!" << endl;
        myPudge.FreshMeat(50, 10);
        myPudge.PrintStatus();
    }

}