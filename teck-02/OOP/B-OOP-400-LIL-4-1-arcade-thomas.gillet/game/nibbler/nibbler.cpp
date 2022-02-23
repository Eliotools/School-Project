/*
** EPITECH PROJECT, 2021
** B-OOP-400-LIL-4-1-arcade-thomas.gillet
** File description:
** nibbler
*/
/**
* \file
* \brief Function for game nibbler
*/

#include <iostream>
#include "nibbler.hpp"

/**
* \brief createSnake set all var
*/
void Nibbler::createSnake()
{
   srand(time(NULL));
   food_x = rand() % 32;
   food_y = rand() % 24;
   for (int i = 0; i < 5; i++) {
      snakes.push_front(Nibbler(12 + i, 11));
      xcoords.push_back(12 + i);
      ycoords.push_back((11));
   }
}

/**
* \brief relaunch correctly game
*/
void Nibbler::relaunch()
{
   snakes.clear();
   xcoords.clear();
   ycoords.clear();
}
      
/**
* \brief change coord of apple by rand
* \param[in] x
* \param[in] y
*/
void Nibbler::changeFoodCoord(int x, int y)
{
   food_x = rand() % 32;
   food_y = rand() % 24;
   std::cout << "Pomme mangé" << std::endl;
   xcoords.push_back(x);
   ycoords.push_back((y));
   score++;
}

/**
* \brief change direction of snake
* \param[in] logic
* \param[in] dir -> direction 
* \return 0 or 1
*/
int Nibbler::changeDir(Nibbler logic, int dir)
{
   x = logic.getXpos();
   y = logic.getYpos();
   if (dir == 3) 
      x -= 1;
   else if (dir == 2) 
      x += 1;
   else if (dir == 4) 
      y -= 1;
   else if (dir == 1) 
      y += 1;
   else if (dir == 5) 
      return (1);
   return (0);
}

/**
* \brief check snake and change food coord
* \param[in] dir for direction of snake
* \param[in] xx ??
* \return 0 or 2
*/
int Nibbler::checkSnake(int dir, int xx)
{
   std::list<Nibbler>::iterator it;

   for (it = snakes.begin(); it != snakes.end(); it++) {
      xcoords[xx] = (*it).getXpos();
      ycoords[xx] = (*it).getYpos();
      xx++;
      if ((*it).getYpos() == y && (*it).getXpos() == x && it != snakes.begin() && dir != 0)// collision avec son corps
          return (2);  
      if ((*it).getYpos() == food_y && (*it).getXpos() == food_x && it != snakes.begin() && dir != 0) {
         food_x = rand() % 32;
         food_y = rand() % 24;
      }
   }
   return (0);
}

/**
* \brief check inputs
* \param[in] direction
* \return 0 or 2
*/
int Nibbler::checkInputs(int dir)
{
   int xx = 0;
   std::list<Nibbler>::iterator it;

   if (lock == false)
      this->createSnake();
   lock = true;
   Nibbler logic = snakes.front();
   if (this->changeDir(logic, dir) == 1)
      return (2);
   snakes.push_front(Nibbler(x, y));
   if (x == food_x and y == food_y) // Si collision avec nouriture
      this->changeFoodCoord(x, y);
   else
      snakes.pop_back();
   if (y > 24 || x > 32 || y < -1 || x < -1) // collision avec les bords
      return (2);
   if (this->checkSnake(dir, xx) == 2)
      return (2);
   return (0);
}

/**
* \brief set lock to false for good restart of game
*/
void Nibbler::setLock()
{
   lock = false;
}

/**
* \brief return score
* \return score
*/
int Nibbler::getScore()
{
   return score;
}

void __attribute__((constructor)) calledFirst(); 
void __attribute__((destructor)) calledLast(); 

/**
* \brief entryPoint -> for dynamic lib
* \return nib -> Instance of IGame who is Nibble
*/
extern "C" IGame *entryPoint() 
{
    IGame *nib = new Nibbler(3, 3);
    
    return nib;
}

/**
* \brief function call during construction
*/
void calledFirst()
{ 
    printf("I am called first (NIB)\n"); 
} 

/**
* \brief function call during deconstruction
*/
void calledLast()
{ 
    printf("I am called last (NIB)\n"); 
}