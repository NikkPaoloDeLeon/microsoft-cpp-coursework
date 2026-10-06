// Task 3: Understand operator precedence
// Demonstrate precedence in arithmethic operation

#include <iostream>

int main () {
    int baseDamge {10};
    int weaponStrenght {5};
    int damageMultiplier {2};
    // Without parentheses - multiplication happens first
    int damage1 {baseDamge + weaponStrenght * damageMultiplier};
    std::cout << "Damage without parentheses: " << damage1 << '\n';
    int damage2 {(baseDamge + weaponStrenght) * damageMultiplier};
    std::cout << "Damage with preantheses: " << damage2 << '\n';
    // Complex expression with multiple operators
    int level {5};
    int experience {100};
    bool isAdvanced = level > 3 && experience >= 50 * 2;
    std::cout << "Advance player: " << (isAdvanced ? "Yes" : "No") << std::endl;


    return 0;
}