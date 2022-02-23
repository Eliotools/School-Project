/*
** EPITECH PROJECT, 2021
** B-OOP-400-LIL-4-1-arcade-thomas.gillet
** File description:
** centipede
*/

#include "centipede.hpp"

/**
* \file
* \brief Function for Centipede Game
*/

/**
* \brief set lock to false for good restart of centipede
*/
void Centipede::setLock()
{
   lock = false;
}

/**
* \brief create Centipede
*/
void Centipede::createCentipede()
{
   for (int i = 0; i < 5; i++) {
       if (i == 0)
         snakes.clear();
      snakes.push_front(Centipede(0 + i, 0));
      xcoords.push_back(3 + i);
      ycoords.push_back((3));
   }
}

/**
* \brief relaunch correctly game
*/
void Centipede::relaunch()
{
   snakes.clear();
   xcoords.clear();
   ycoords.clear();
}

/**
* \brief change Direction of centipede
* \param[in] logic for position  of centipede
* \param[in] direction of centipde
* \return 1 or 0
*/
int Centipede::changeDir(Centipede logic, int dir)
{
   x = logic.getXpos();
   y = logic.getYpos();
   if (dir == 3 && food_x != 0) 
      food_x -= 1;
   else if (dir == 2 && food_x != 31) 
      food_x += 1;
   else if (dir == 5) 
      return (1);
   else if (dir == 6 && bullet_x == -1) {
       bullet_x = food_x;
       bullet_y = 20;
   } 
   if (bullet_y != -1)
       bullet_y--;
   if (bullet_y < 0) {
       bullet_y = -1;
       bullet_x = -1;
   }
   return (0);
}

/**
* \brief action if wall hited
*/
void Centipede::hitWall()
{
   if (x > 31) {
      y += 1;
      wall = -1;
   }
   if (x < 0) {
      y += 1;
      wall = 1;
   }
   x += wall;
}

/**
* \brief checkCollision bullet / centipede
* \param[in] xx 
*/
void Centipede::checkCollision(int xx)
{
   std::list<Centipede>::iterator it;
   for (it = snakes.begin(); it != snakes.end(); it++) {
      if ((*it).getXpos() == bullet_x && (*it).getYpos() == bullet_y) {
          hit_counter++;
          std::cout << "You hit " << hit_counter << " centipedes!" << std::endl;
          xcoords.clear();
          ycoords.clear();
          lock = false;
      }
   xcoords[xx] = (*it).getXpos();
   ycoords[xx] = (*it).getYpos();
   xx++;
   }
}

/**
* \brief reset dir of centipede when touched
* \param[in] dir -> direction of centipede
* \return 0 or 2 for good exit
*/
int Centipede::checkInputs(int dir)
{
   int xx = 0;

   if (lock == false)
      this->createCentipede();
   lock = true;
   Centipede logic = snakes.front();
   if (this->changeDir(logic, dir) == 1)
      return (2);
   if (x == food_x and y == food_y) // Si collision avec centipede
      return (2);
   else
      snakes.pop_back();

   this->hitWall();
   snakes.push_front(Centipede(x, y));
   this->checkCollision(xx);
   if (hit_counter == 20) {
       std::cout << "You win !" << std::endl;
       return (2);
   }
   return (0);
}

/**
* \brief return score
* \return hit_counter -> score of centipede
*/
int Centipede::getScore()
{
   return hit_counter;
}

void __attribute__((constructor)) calledFirst(); 
void __attribute__((destructor)) calledLast(); 

/**
* \brief entryPoint -> for dynamic lib
* \return nib -> Instance of IGame who is Centipede
*/
extern "C" IGame *entryPoint() 
{
   IGame *nib = new Centipede(3, 3);
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
* \brief function call during desctruction
*/
void calledLast()
{ 
   printf("I am called last (NIB)\n"); 
}