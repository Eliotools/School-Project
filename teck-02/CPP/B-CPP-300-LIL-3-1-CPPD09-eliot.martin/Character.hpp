/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPD09-eliot.martin
** File description:
** Character
*/

#ifndef CHARACTER_HPP_
#define CHARACTER_HPP_
#include <string>
#include <iostream>
class Character{
    public:
        enum AttackRange {CLOSE, RANGE};
        explicit Character(const  std:: string &name , int level);
        ~Character();
        const std::string &getName () const;
        const std::string &getClass () const;
        const std::string &getRace () const;
        int getLvl ()  const;
        int getPv()  const;
        int getPower ()  const;
        int getStrength()  const;
        int getStamina()  const;
        int getIntelligence()  const;
        int getSpirit() const;
        int getAgility()  const;
        int CloseAttack();
        void Heal();
        void RestorePower();
        void TakeDamage(int damage);
        //void PrintAll();
        void setRange(AttackRange Range);
        int RangeAttack ();
        void setRace(std::string race);
        std::string getClasse();
        AttackRange getRange() const;
        AttackRange Range;

    protected:
        std::string *_name;
        std::string *_class;
        std::string *_race;
        int _level;
        int _power;
        int _strength;
        int _stamina;
        int _intelligence;
        int _spirit;
        int _agitily;
        int _pv;
    private:
};

#endif /* !CHARACTER_HPP_ */
