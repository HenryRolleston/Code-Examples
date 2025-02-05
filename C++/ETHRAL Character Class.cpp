#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

class RPGCharacter {
private:
    std::string name;
    int level;
    int experience;
    
    // Core Stats
    int might; // Determines a character's physical acuity - how much raw power their body can dish out, and take in.
    int talent; // Determines a character's reflexes, precision, and speed.
    int mind; // Determines a character's intellect, logical reasoning, and capacity to learn.
    int heart; // Determines a character's personal conviction in their own beliefs, and force of personality.

    //Derived Attributes
    // Survival & Resource Attributes
    int maxHealth; // A representation of a character's physical, mental, and spiritual health - how much damage the character can take before death.
    int currentHealth; // Cannot be greater than the character's maxHealth. Depleted when damage is dealt to the character.
    int maxStamina; // A representation of the character's energy, used to perform physically strenuous tasks such as sprinting.
    int currentStamina; // Cannot be greater than the character's maxStamina.
    //Utility Attributes
    int knowledge; // Modifies the rate at which resources are consumed, for everything from building supplies to stamina costs.
    int speed; // Modifies the character's rate of movement.
    //Defensive Attributes
    int defiance; // Modifies a character's resistance to non-physical damage, and effects that attempt to persuade the character - physically or otherwise.
    int evasion; // A higher evasion score increases the chance of dodging physical damage, and avoiding detection by others.
    int armour; // Base armour (will be modified based on equipment later)
    //Offensive Attributes
    int potency; // The effectiveness of a character's Intelligence on their outgoing damage.
    int force; // The effectiveness of a character's Physicality on their outgoing damage.
    int rupture; // Represents the ability to bypass enemy resistances with outgoing damage.

    void updateAttributes() {
        maxHealth = 10 + (might * 3) + (heart * 2);
        maxStamina = 10 + (heart * 3) + (might * 2);
        knowledge = (mind * 2) + talent;
        speed = talent * 2;
        defiance = heart * 2;
        evasion = talent * 2; // Adjusted if armour is equipped
        potency = (mind + heart) * 2;
        force = might * 2;
        rupture = talent * 2;
        armour = 0; // To be modified if equipped with gear
        
        // Restore health and stamina on update
        currentHealth = maxHealth;
        currentStamina = maxStamina;
    }

    void levelUp() {
        experience = experience % (100 * level); // Carry over excess XP
        level++;
        std::cout << name << " has leveled up to Level " << level << "!\n";

        // Distribute stat points randomly
        might += rand() % 2;
        talent += rand() % 2;
        mind += rand() % 2;
        heart += rand() % 2;

        updateAttributes();

        std::cout << "New stats: [Might: " << might << "] [Talent: " << talent 
                  << "] [Mind: " << mind << "] [Heart: " << heart << "]\n";
    }

public:
    RPGCharacter(std::string characterName, int m, int t, int mi, int h)
        : name(characterName), level(1), experience(0),
          might(m), talent(t), mind(mi), heart(h) {
        updateAttributes();
    }

    void gainExperience(int exp) {
        experience += exp;
        std::cout << name << " gained " << exp << " EXP!\n";
        while (experience >= (100 * level)) {
            levelUp();
        }
    }

    void displayStats() const {
        std::cout << "=== " << name << " ===\n"
                  << "Level: " << level << "\n"
                  << "EXP: " << experience << "/" << (100 * level) << "\n"
                  << "Might: " << might << "\n"
                  << "Talent: " << talent << "\n"
                  << "Mind: " << mind << "\n"
                  << "Heart: " << heart << "\n"
                  << "--- Attributes ---\n"
                  << "Health: " << currentHealth << "/" << maxHealth << "\n"
                  << "Stamina: " << currentStamina << "/" << maxStamina << "\n"
                  << "Knowledge: " << knowledge << "\n"
                  << "Speed: " << speed << "\n"
                  << "Defiance: " << defiance << "\n"
                  << "Evasion: " << evasion << "\n"
                  << "Potency: " << potency << "\n"
                  << "Force: " << force << "\n"
                  << "Rupture: " << rupture << "\n"
                  << "Armour: " << armour << "\n";
    }
};

// Example usage
int main() {
    srand(time(0)); // Seed RNG for stat increases

    RPGCharacter hero("Artemis", 5, 6, 7, 8);
    hero.displayStats();
    
    hero.gainExperience(150); // Gain enough XP to level up
    hero.displayStats();

    return 0;
}
