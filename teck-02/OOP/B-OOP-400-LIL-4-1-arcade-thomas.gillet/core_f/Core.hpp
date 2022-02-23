/*
** EPITECH PROJECT, 2021
** B-OOP-400-LIL-4-1-arcade-thomas.gillet [WSL: Ubuntu]
** File description:
** Core
*/

#ifndef CORE_HPP_
#define CORE_HPP_
#include <iostream>
#include "../game/igame.hpp"
#include "../graphic/igraphic.hpp"
#include "DLLoader.hpp"

/**
* \class Core
* \brief Core create bridge between game and graphic also do main menu
*/
class Core {
    public:
        Core();
        ~Core();
        void pActual();
        void pCommand();
        void pNotHandle(std::string error);
        bool getPlay();
        int startOrExit();
        int lib(DLLoader loader);
        int gamePrint(DLLoader loader);
        void getInput(int input, DLLoader loader);
        void printLib(std::vector<std::string> libs);

        void setGame(IGame *game);
        void setGraphic(IGraphic *graphic);
        void setNextGame(DLLoader loader);
        void setNextGraphic(DLLoader loader);
        void setPrevGame(DLLoader loader);
        void setPrevGraphic(DLLoader loader);
        void setPosGraph(int i);
        void setPosGame(int i);
        std::string getGraphName(int nb);
        std::string getGameName(int nb);
        IGame *getGame();
        IGraphic *getGraphic();
        int gameLoop(DLLoader loader);
        int inGamesName(std::string name);
        int inGraphicsName(std::string name);
        void setFirstGame(DLLoader loader);
        void setFirstGraph(DLLoader loader, std::string name);
        std::string _actualGame;
        std::string _actualLib;
        int menu(DLLoader loader);
        void addPlayerName(void);



    protected:
    private:
        IGame *_game;
        IGraphic *_graphic;
        std::vector<std::string> _gamesName;
        std::vector<std::string> _graphName;
        bool _play;
        int _posGame;
        int _posGraph;
        int _maxGraph;
        int _maxGame;
        std::string _command;
        std::string _playerName;
};

std::vector<std::string> get_lib(int i);
int gameLoop(DLLoader loader, Core core);
#endif /* !CORE_HPP_ */
