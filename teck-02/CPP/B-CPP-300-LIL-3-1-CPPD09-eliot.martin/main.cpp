/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPD09-thomas.gillet
** File description:
** main
*/
#include "Character.hpp"
#include "Warrior.hpp"
#include "Mage.hpp"
#include "Priest.hpp"
#include "Paladin.hpp"
#include "Hunter.hpp"

int main(void)
{
    Character ch("bite", 42);
    ch.CloseAttack();
    ch.RangeAttack();
    // ******************* MAGE *******************//
    std::cout << "\033[34mMessage de constructor ....\033[0m" << std::endl;
    Mage c("MageNumero", 2);
    std::cout << "\033[35m************** ALL **********************\033[0m" << std::endl;
    //c.PrintAll();
    std::cout << "\033[35m************** PV ***********************\033[0m" << std::endl;
    std::cout << "Life : " << c.getPv() << "\t\t\t\t\033[35m*\033[0m" << std::endl;
    c.TakeDamage(50);
    std::cout << "Life : " << c.getPv() << "\t\t\t\t\033[35m*\033[0m" << std::endl;
    c.Heal();
    std::cout << "Life : " << c.getPv() << "\t\t\t\t\033[35m*\033[0m" << std::endl;
    std::cout << "\033[35m************** POWER *******************\033[0m" << std::endl;
    std::cout << "Energy : " << c.getPower() << "\t\t\t\t\033[35m*\033[0m" << std::endl;
    c.RangeAttack();
    std::cout << "Energy : " << c.getPower() << "\t\t\t\t\033[35m*\033[0m" << std::endl;
    c.RestorePower();
    std::cout << "Energy : " << c.getPower() << "\t\t\t\t\033[35m*\033[0m" << std::endl;
    
    std::cout << "\033[35m************** RANGE *******************\033[0m" << std::endl;
    std::cout << "Range : ";
    if (c.getRange() == Character::CLOSE)
        std::cout << "CLOSE\t\t\t\t\033[35m*\033[0m" << std::endl;
    if (c.getRange() == Character::RANGE)
        std::cout << "RANGE\t\t\t\t\033[35m*\033[0m" << std::endl;
    c.CloseAttack();
    std::cout << "Range : ";
    if (c.getRange() == Character::CLOSE)
        std::cout << "CLOSE\t\t\t\t\033[35m*\033[0m" << std::endl;
    if (c.getRange() == Character::RANGE)
        std::cout << "RANGE\t\t\t\t\033[35m*\033[0m" << std::endl;
    std::cout << "Use Range Attack !\t\t\t\033[35m*\033[0m" << std::endl;
    c.RangeAttack();
    std::cout << "Range : ";
    if (c.getRange() == Character::CLOSE)
        std::cout << "CLOSE\t\t\t\t\033[35m*\033[0m" << std::endl;
    if (c.getRange() == Character::RANGE)
        std::cout << "RANGE\t\t\t\t\033[35m*\033[0m" << std::endl;
    c.CloseAttack();
    std::cout << "\033[35m*************** END *********************\033[0m" << std::endl << std::endl;

    // ******************* PRIEST *******************//
    std::cout << "\033[34mMessage de constructor ....\033[0m" << std::endl;
    Priest p("MageNumero", 2);
    std::cout << "\033[35m************** ALL **********************\033[0m" << std::endl;
    //p.PrintAll();
    std::cout << "\033[35m************** PV ***********************\033[0m" << std::endl;
    std::cout << "Life : " << p.getPv() << "\t\t\t\t\033[35m*\033[0m" << std::endl;
    p.TakeDamage(50);
    std::cout << "Life : " << p.getPv() << "\t\t\t\t\033[35m*\033[0m" << std::endl;
    p.Heal();
    std::cout << "Life : " << p.getPv() << "\t\t\t\t\033[35m*\033[0m" << std::endl;
    std::cout << "\033[35m************** POWER *******************\033[0m" << std::endl;
    std::cout << "Energy : " << p.getPower() << "\t\t\t\t\033[35m*\033[0m" << std::endl;
    p.RangeAttack();
    std::cout << "Energy : " << p.getPower() << "\t\t\t\t\033[35m*\033[0m" << std::endl;
    p.RestorePower();
    std::cout << "Energy : " << p.getPower() << "\t\t\t\t\033[35m*\033[0m" << std::endl;
    
    std::cout << "\033[35m************** RANGE *******************\033[0m" << std::endl;
    std::cout << "Range : ";
    if (p.getRange() == Character::CLOSE)
        std::cout << "CLOSE\t\t\t\t\033[35m*\033[0m" << std::endl;
    if (p.getRange() == Character::RANGE)
        std::cout << "RANGE\t\t\t\t\033[35m*\033[0m" << std::endl;
    p.CloseAttack();
    std::cout << "Range : ";
    if (p.getRange() == Character::CLOSE)
        std::cout << "CLOSE\t\t\t\t\033[35m*\033[0m" << std::endl;
    if (p.getRange() == Character::RANGE)
        std::cout << "RANGE\t\t\t\t\033[35m*\033[0m" << std::endl;
    std::cout << "Use Range Attack !\t\t\t\033[35m*\033[0m" << std::endl;
    p.RangeAttack();
    std::cout << "Range : ";
    if (p.getRange() == Character::CLOSE)
        std::cout << "CLOSE\t\t\t\t\033[35m*\033[0m" << std::endl;
    if (p.getRange() == Character::RANGE)
        std::cout << "RANGE\t\t\t\t\033[35m*\033[0m" << std::endl;
    p.CloseAttack();
    std::cout << "\033[35m*************** END *********************\033[0m" << std::endl << std::endl;
    // *************************** PALADIN ***************//
    std::cout << "\033[34mMessage de constructor ....\033[0m" << std::endl;
    Paladin pa("MageNumero", 2);
    std::cout << "\033[35m************** ALL **********************\033[0m" << std::endl;
    //pa.PrintAll();
    std::cout << "\033[35m************** PV ***********************\033[0m" << std::endl;
    std::cout << "Life : " << pa.getPv() << "\t\t\t\t\033[35m*\033[0m" << std::endl;
    pa.TakeDamage(50);
    std::cout << "Life : " << pa.getPv() << "\t\t\t\t\033[35m*\033[0m" << std::endl;
    pa.Heal();
    std::cout << "Life : " << pa.getPv() << "\t\t\t\t\033[35m*\033[0m" << std::endl;
    std::cout << "\033[35m************** POWER *******************\033[0m" << std::endl;
    std::cout << "Energy : " << pa.getPower() << "\t\t\t\t\033[35m*\033[0m" << std::endl;
    pa.RangeAttack();
    std::cout << "Energy : " << pa.getPower() << "\t\t\t\t\033[35m*\033[0m" << std::endl;
    pa.RestorePower();
    std::cout << "Energy : " << pa.getPower() << "\t\t\t\t\033[35m*\033[0m" << std::endl;
    
    std::cout << "\033[35m************** RANGE *******************\033[0m" << std::endl;
    std::cout << "Range : ";
    if (pa.getRange() == Character::CLOSE)
        std::cout << "CLOSE\t\t\t\t\033[35m*\033[0m" << std::endl;
    if (pa.getRange() == Character::RANGE)
        std::cout << "RANGE\t\t\t\t\033[35m*\033[0m" << std::endl;
    pa.CloseAttack();
    std::cout << "Range : ";
    if (pa.getRange() == Character::CLOSE)
        std::cout << "CLOSE\t\t\t\t\033[35m*\033[0m" << std::endl;
    if (pa.getRange() == Character::RANGE)
        std::cout << "RANGE\t\t\t\t\033[35m*\033[0m" << std::endl;
    std::cout << "Use Range Attack !\t\t\t\033[35m*\033[0m" << std::endl;
    pa.RangeAttack();
    std::cout << "Range : ";
    if (pa.getRange() == Character::CLOSE)
        std::cout << "CLOSE\t\t\t\t\033[35m*\033[0m" << std::endl;
    if (pa.getRange() == Character::RANGE)
        std::cout << "RANGE\t\t\t\t\033[35m*\033[0m" << std::endl;
    pa.CloseAttack();
    std::cout << "\033[35m*************** END *********************\033[0m" << std::endl;
}