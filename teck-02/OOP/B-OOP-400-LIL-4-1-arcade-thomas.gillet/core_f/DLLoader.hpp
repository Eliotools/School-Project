/*
** EPITECH PROJECT, 2021
** B-OOP-400-LIL-4-1-arcade-thomas.gillet [WSL: Ubuntu]
** File description:
** DLLoader
*/

#ifndef DLLOADER_HPP_
#define DLLOADER_HPP_

#include "../game/igame.hpp"
#include "../graphic/igraphic.hpp"
#include <map>

/**
* \class DLLoader
* \brief Load .so and create Instance of Interface
*/
class DLLoader {
    public:
        DLLoader();
        ~DLLoader();
        IGame *getInstanceOfGame(std::string name);
        IGraphic *getInstanceOfGraph(std::string name);
        void closeAllHandles();
        std::string getGraphInstanceName(int nb);
        std::string getGameInstanceName(int nb);
        IGraphic *getGraphInstance(int nb);
        IGame *getGameInstance(int nb);
        int getGamesNb();
        int getGraphicsNb();
        void insideOfGames();

    protected:
        std::vector<IGraphic *> _graphics;
        std::vector<std::string> _graphicsName;
        int _graphicsNb;
        std::vector<IGame *> _games;
        std::vector<std::string> _gamesName;
        int _gamesNb;
        std::vector<void *> _handles;
};

#endif /* !DLLOADER_HPP_ */
