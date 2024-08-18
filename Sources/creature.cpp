#include "creature.h"


//==================================================================================================
//         NAME:    --------
//  DESCRIPTION:    Create specified creature
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
Creature::Creature(Creature::Type type, int level) :
    mb_type {type}, mb_level {level}
{
    // Nothing to do
}


//==================================================================================================
//         NAME:    --------
//  DESCRIPTION:    --------
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
int Creature::getLevel() const
{
    return mb_level;
}


//==================================================================================================
//         NAME:    --------
//  DESCRIPTION:    --------
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
int Creature::getCurrentHealth() const
{
    return mb_curHealth;
}


//==================================================================================================
//         NAME:    --------
//  DESCRIPTION:    --------
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
int Creature::getCurrentStamina() const
{
    return mb_curStamina;
}


//==================================================================================================
//         NAME:    --------
//  DESCRIPTION:    Function changes health of creature by specified value @health. This value can
//                  be negative!
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    Virtual function - it has a little more options in derived classes
//==================================================================================================
void Creature::changeHealth(int health)
{
    assert(mb_curHealth >= 0 && "Negative health means inactive characteristic, but creatures always have hp!");

    int newHealth = mb_curHealth + health;
    if (newHealth > mb_maxHealth) {
        mb_curHealth = mb_maxHealth;
    }
    else if (newHealth < 0) {
        mb_curHealth = 0;
    }
    else {
        mb_curHealth = newHealth;
    }

}


//==================================================================================================
//         NAME:    --------
//  DESCRIPTION:    Function changes stamina of creature by specified value @stamina. If creature's
//                  @mb_curStamina == -1, it means that this characteristic is inactive for
//                  instance of the class, derived from <Creature>
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
void Creature::changeStamina(int stamina)
{
    if (mb_curStamina == -1) {
        std::cout << "Stamina is inactive for this creature. Nothing to do" << std::endl;
        return;
    }
    else {} // Nothing to do


    int newStamina = mb_curStamina + stamina;
    if (newStamina > mb_maxStamina) {
        mb_curStamina = mb_maxStamina;
    }
    else if (newStamina < 0) {
        mb_curStamina = 0;
    }
    else {
        mb_curStamina = newStamina;
    }
}



//==================================================================================================
//         NAME:    --------
//  DESCRIPTION:    --------
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
void Creature::changeStrength(int strength)
{
    if (mb_curStrength == -1) {
        std::cout << "Strength is inactive for this creature. Nothing to do" << std::endl;
        return;
    }
    else {} // Nothing to do


    int newStrength = mb_curStrength + strength;
    if (newStrength > mb_maxStrength) {
        mb_curStrength = mb_maxStrength;
    }
    else if (newStrength < 0) {
        mb_curStrength = 0;
    }
    else {
        mb_curStrength = newStrength;
    }
}




//==================================================================================================
//         NAME:    --------
//  DESCRIPTION:    --------
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
bool Creature::isDead() const
{
    return (mb_curHealth == 0);
}


//==================================================================================================
//         NAME:    --------
//  DESCRIPTION:    --------
//   PARAMETERS:    --------
// RETURN VALUE:    --------
//     COMMENTS:    --------
//==================================================================================================
void Creature::commitSuicide() {

}
