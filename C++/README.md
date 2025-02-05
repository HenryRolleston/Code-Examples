RPG Character Class (C++)

A structured, expandable RPG character system in C++, featuring a dynamic stat progression system with scaling experience requirements and derived attributes.  
The character creation system is meant for an in-depth, highly customizable RPG videogame - where character's personalities and aptitudes are intrinsically linked, but are not locked to one particular playstyle. Being strong can lend itself to either more punishing weapon attacks, or a greater amount of control over the elements, for example.

🛠 Features  

✔ Simple Character class with private attributes and public methods.  
✔ Core Stats:  

    🏋 Might (Physical strength)
    🎭 Talent (Agility, finesse, and precision)
    🧠 Mind (Intelligence and magical aptitude)
    ❤️ Heart (Resilience, endurance, and willpower)
    ✔ Derived Attributes:
    💖 Health (Max & Current) – Based on Might & Heart
    ⚡ Stamina (Max & Current) – Based on Heart & Might
    📖 Knowledge – Based on Mind & Talent
    🏃 Speed – Based on Talent
    🛡 Defiance – Based on Heart
    🌀 Evasion – Based on Talent (reduced by equipped armor)
    🔥 Potency – Based on Mind & Heart
    💪 Force – Based on Might
    ⚔️ Rupture – Based on Talent
    🏰 Armor – Based on equipped gear
    ✔ Dynamic Level System – XP required scales as 100 * level.
    ✔ XP Carryover – Excess XP after leveling is retained.
    ✔ Randomized Stat Growth – Each stat has a chance to increase per level-up.
    ✔ Clear, modular design – Easy to extend for combat, inventory, and abilities.

📌 How It Works  

    Create an RPG character with a name and starting stats.
    Gain experience via the gainExperience(int exp) method.
    Level up when XP exceeds 100 * level, with stats increasing randomly.
    Character attributes update dynamically based on core stat changes.
    Display character stats using displayStats().

📦 Installation & Usage  

Clone the repository:  

    git clone https://github.com/yourusername/RPGCharacterClass.git
    cd RPGCharacterClass

Compile the program:

g++ RPGCharacter.cpp -o RPGCharacter

Run the program:

    ./RPGCharacter

📜 Example Output

=== Aldric ===
Level: 1
EXP: 0/100
Might: 5
Talent: 6
Mind: 7
Heart: 8
--- Attributes ---
Health: 34/34
Stamina: 34/34
Knowledge: 20
Speed: 12
Defiance: 16
Evasion: 12
Potency: 30
Force: 10
Rupture: 12
Armour: 0

Aldric gained 150 EXP!
Aldric has leveled up to Level 2!
New stats: [Might: 6] [Talent: 6] [Mind: 7] [Heart: 9]

=== Aldric ===
Level: 2
EXP: 50/200
Might: 6
Talent: 6
Mind: 7
Heart: 9
--- Attributes ---
Health: 37/37
Stamina: 38/38
Knowledge: 20
Speed: 12
Defiance: 18
Evasion: 12
Potency: 32
Force: 12
Rupture: 12
Armour: 0
