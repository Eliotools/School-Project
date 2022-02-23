/*
** EPITECH PROJECT, 2021
** B-OOP-400-LIL-4-1-arcade-thomas.gillet
** File description:
** core
*/
/**
* \file
* \brief File for core Function : change Game or Lib
*/

#include "../graphic/sfml/sfmldraw.hpp"
#include "../game/nibbler/nibbler.hpp"
#include "../game/centipede/centipede.hpp"
#include "DLLoader.hpp"
#include "Core.hpp"
#include <thread>
#include <chrono>
#include <dlfcn.h>
#include <stdio.h>
#include <ncurses.h>

/**
* \brief Core constructor -> Get Lib of lib/ folder
*/
Core::Core() 
{
    _play = false;
    _gamesName = get_lib(1);
    _graphName = get_lib(2);
    _maxGame = _gamesName.size();
    _maxGraph = _graphName.size();
}

/**
* \brief Core Deconstructor
*/
Core::~Core()
{
}

/**
* \brief Print for NotHandle menu print
* \param[in] String for type of not handle type
*/
void Core::pNotHandle(std::string error)
{
    std::cout << "Sorry, unknown " << error << std::endl;
}

/**
* \brief Print avaible graphics lib in menu
* \param[in] vector of libs name
*/
void Core::printLib(std::vector<std::string> libs)
{
    std::string name;
    std::cout << "[ ";
    for (std::vector<std::string>::const_iterator i = libs.begin(); i != libs.end(); ++i) {
        name = *i;
        name = name.substr(name.find('_')+1, name.length());
        name = name.substr(0, name.find('.'));
        std::cout << name << " ";
    }
    std::cout <<"]";        
}

/**
* \brief Print of avaible command in menu
*/
void Core::pCommand()
{ 
    std::cout << "Actual Game load : " << _actualGame << std::endl;
    std::cout << "Actual Graph load : " << _actualLib << std::endl;
    std::cout << "Score : " << getGame()->getScore() << std::endl;
    std::cout << "Command :\tstart -> start the game with actual lib" << std::endl <<
                     "\t\tlib + ";
                     printLib(_graphName);
                     std::cout << " -> change Actual lib" << std::endl <<
                     "\t\tgame + ";
                     printLib(_gamesName);
                     std::cout << " -> change Actual lib" << std::endl <<                     
                     "\t\texit -> quit interface without launch game" << std::endl <<
                     "\t\treload -> reload Games and Graphics library" << std::endl;
                     std::cout << std::endl <<"\t\t" <<_maxGame << " game(s) load" << std::endl;
                     std::cout << "\t\t" <<_maxGraph << " Graphic(s) load" << std::endl;
    std::cout << std::endl << std::endl << "Command : ";
    std::getline(std::cin, _command);
}

/**
* \brief Handle start and exit command of menu
* \return -1 if exit 2 if reload and 0 for other case
*/
int Core::startOrExit()
{
    if (_command == "start" || _command == "")
        _play = true;
    else if (_command == "exit")
        return -1;
    else if (_command == "reload") {
        _gamesName = get_lib(1);
        _graphName = get_lib(2);
        _maxGame = _gamesName.size();
        _maxGraph = _graphName.size();
        return (2);
    }
    return 0;
}

/**
* \brief Handle change of game in menu
* \param[in] loader (DLLoader) need for getInstance of Graph or Game
* \return 1 or 0
*/
int Core::gamePrint(DLLoader loader)
{
    std::vector<std::string> games {"nibbler", "centipede", "pacman", "qix", "solarfox"};

    for (int i = 0; i < games.size(); i++){
        if (_command.find(games[i]) != std::string::npos) {
            if (inGamesName("arcade_" + games[i] + ".so") != -1) {
                _game = loader.getInstanceOfGame("lib/arcade_" + games[i] + ".so");
                _posGame = inGamesName("arcade_" + games[i] + ".so");
                _actualGame = "arcade_" + games[i] + ".so";
                return 1;
            }
        }
    }
    return 0;
}

/**
* \brief Handle change of lib in menu
* \param[in] loader (DLLoader) need for getInstance of Graph or Game
* \return 1 or 0
*/
int Core::lib(DLLoader loader)
{
    std::vector<std::string> libs{"ncurses", "sdl2", "sfml", "ndk++", "aallib", "libcaca", "allegro5", "xlib", "gtk+", "irrlicht", "opengl", "vulkan", "qt5"};

    for (int i = 0; i < libs.size(); i++){
        if (_command.find(libs[i]) != std::string::npos) {
            if (inGraphicsName("arcade_" + libs[i] + ".so") != -1) {
                _graphic = loader.getInstanceOfGraph("lib/arcade_" + libs[i] + ".so");
                _posGraph = inGraphicsName("arcade_" + libs[i] + ".so");
                _actualLib = "arcade_" + libs[i] + ".so";
                return 1;
            }
        }
    }
    return 0;
}

/**
* \brief check if given name is in vector _gamesName
* \param[in] name -> given name
* \return -1 if not found position of name in vector if found
*/
int Core::inGamesName(std::string name)
{
    for (int i = 0; i < _gamesName.size(); i++) {
        if (_gamesName[i] == name)
            return i;
    }
    return -1;
}

/**
* \brief check if given name is in vector _graphName
* \param[in] name -> given name
* \return -1 if not found position of name in vector if found
*/
int Core::inGraphicsName(std::string name)
{
    for (int i = 0; i < _graphName.size(); i++) {
        if (_graphName[i] == name)
            return i;
    }
    return -1;
}

/**
* \brief set _game with a new IGame instance
* \param[in] game -> new Instance of IGame
*/
void Core::setGame(IGame *game)
{
    _game = game;
}

/**
* \brief set _graphic with a new Igraph instance
* \param[in] graphic -> new Instance of Igraph
*/
void Core::setGraphic(IGraphic *graphic)
{
    _graphic = graphic;
}

/**
* \brief Return _game
* \return _game -> Igame of Core
*/
IGame *Core::getGame()
{
    return _game;
}

/**
* \brief return _graphic
* \return _graphic -> IGraph of Core
*/
IGraphic *Core::getGraphic()
{
    return _graphic;
}

/**
* \brief Test input for changing lib of game
* \param[in] input -> value of input return by _graphic
* \param[in] loader -> Need for get new Instance
*/
void Core::getInput(int input, DLLoader loader)
{
    if (input == 100)
        setNextGame(loader);
    if (input == 101)
        setPrevGame(loader);
    if (input == 102)
        setPrevGraphic(loader);
    if (input == 103)
        setNextGraphic(loader);
}

/**
* \brief return name of graphic vector of given nb element
* \param[in] nb -> element of vector we want
* \return _graphName[nb] -> nb element of vector of graph names
*/
std::string Core::getGraphName(int nb)
{
    return _graphName[nb];
}

/**
* \brief return name of game vector of given nb element
* \param[in] nb -> element of vector we want
* \return _gamesName[nb] -> nb element of vector of games names
*/
std::string Core::getGameName(int nb)
{
    std::cout << _gamesName[nb] << std::endl;
    return _gamesName[nb];
}

/**
* \brief set _graphic to next _graphName (vector containing name of all graphics lib we use). If actual _graphic is last of vector, first one is set
* \param[in] loader -> need to create new Instance of lib
*/
void Core::setNextGraphic(DLLoader loader)
{
    _graphic->stop();
    if (_posGraph == _maxGraph - 1){
        _graphic = loader.getInstanceOfGraph("lib/" + _graphName[0]);
        _actualLib = "lib/" + _graphName[0];
        _posGraph = 0;
    }
    else {
        _graphic = loader.getInstanceOfGraph("lib/" + _graphName[_posGraph + 1]);
        _actualLib = "lib/" + _graphName[_posGraph + 1];
        _posGraph += 1;
    }
    _graphic->launch();
}

/**
* \brief set _graphic to previous _graphName (vector containing name of all graphics lib we use). If actual _graphic is first of vector, last one is set
* \param[in] loader -> need to create new Instance of lib
*/
void Core::setPrevGraphic(DLLoader loader)
{
    _graphic->stop();
    if (_posGraph == 0){
        _graphic = loader.getInstanceOfGraph("lib/" + _graphName[_maxGraph - 1]);
        _actualLib = "lib/" + _graphName[_maxGraph - 1];
        _posGraph = _maxGraph - 1;
    }
    else {
        _graphic = loader.getInstanceOfGraph("lib/" + _graphName[_posGraph - 1]);
        _actualLib = "lib/" + _graphName[_posGraph - 1];
        _posGraph -= 1;
    }
    _graphic->launch();
}

/**
* \brief set _game to next _gamesName (vector containing name of all games lib we use). If actual _game is last of vector, first one is set
* \param[in] loader -> need to create new Instance of lib
*/
void Core::setNextGame(DLLoader loader)
{
    if (_posGame == _maxGame - 1){
        std::cout << "Last game" << std::endl;
        _game = loader.getInstanceOfGame("lib/" + _gamesName[0]);
        _actualGame = "lib/" + _gamesName[0];
        _posGame = 0;
    }
    else {
        _game = loader.getInstanceOfGame("lib/" + _gamesName[_posGame + 1]);
        _actualGame = "lib/" + _gamesName[_posGame + 1];
        _posGame += 1;
    }
    _game->setLock();
    _game->relaunch();
    _graphic->settingInput(2);
}

/**
* \brief set _game to previous _gamesName (vector containing name of all games lib we use). If actual _game is first of vector, last one is set
* \param[in] loader -> need to create new Instance of lib
*/
void Core::setPrevGame(DLLoader loader)
{
    if (_posGame == 0){
        std::cout << "Last game" << std::endl;
        _game = loader.getInstanceOfGame("lib/" + _gamesName[_maxGame - 1]);
        _actualGame = "lib/" + _gamesName[_maxGame - 1];
        _posGame = _maxGame - 1;
    }
    else {
        _game = loader.getInstanceOfGame("lib/" + _gamesName[_posGame - 1]);
        _actualGame = "lib/" + _gamesName[_posGame - 1];
        _posGame -= 1;
    }
    _game->setLock();
    _game->relaunch();
    _graphic->settingInput(2);
}

/**
* \brief set _posGraph to i value
* \param[in] i -> new value we want to set
*/
void Core::setPosGraph(int i)
{
    _posGraph = i;
}

/**
* \brief set _posGame to i value
* \param[in] i -> new value we want to set
*/
void Core::setPosGame(int i)
{
    _posGame = i;
}

/**
* \brief Return _play
* \return _play 
*/
bool Core::getPlay()
{
    return _play;
}

/**
* \brief set _game to first game found in /lib dir
* \param[in] loader -> use to get instance of game
*/
void Core::setFirstGame(DLLoader loader)
{
    if (_maxGame == 0) {
        std::cout << "Sorry no game to load..." << std::endl;
        exit (0);
    }
    setGame(loader.getInstanceOfGame("lib/" + _gamesName[0]));
    _actualGame = _gamesName[0];
    setPosGame(0);
}

/**
* \brief set _game to first graph found in /lib dir
* \param[in] loader -> use to get instance of graph
*/
void Core::setFirstGraph(DLLoader loader, std::string name)
{
    std::vector<std::string> libs{"ncurses", "sdl2", "sfml", "ndk++", "aallib", "libcaca", "allegro5", "xlib", "gtk+", "irrlicht", "opengl", "vulkan", "qt5"};

    if (_maxGraph == 0) {
        std::cout << "Sorry no graph to load..." << std::endl;
        exit (0);
    }
    if (name.find("lib/arcade_") != std::string::npos && name.find(".so") != std::string::npos) {
        name = name.substr(name.find('_')+1, name.length());
        name = name.substr(0, name.find('.'));
        std::cout << name << std::endl;
        for (int i = 0; i < libs.size(); i++){
            if (name == libs[i]) {
                if (inGraphicsName("arcade_" + name + ".so") != -1) {
                    _graphic = loader.getInstanceOfGraph("lib/arcade_" + name + ".so");
                    _posGraph = inGraphicsName("arcade_" + name + ".so");
                    _actualLib = "arcade_" + name + ".so";
                    return ;
                }
            }
        }
    }
    std::cout << name << " is not valid" << std::endl;
    exit(84);
}

/**
* \brief all function for restart game and do game loop
* \param[in] loader -> get Input -> change lib and game during game
* \return 1 if gq,e quit
*/
int Core::gameLoop(DLLoader loader)
{
    getGame()->setLock();
    getGame()->relaunch();
    getGraphic()->launch();
    while (1) {
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        getInput(getGraphic()->getInput(), loader);
        if (getGame()->checkInputs(getGraphic()->getInput()) == 2) {
            getGraphic()->stop();
            return (1);
        }
        getGraphic()->drawobj(getGame()->getSnakeXpos(),
                              getGame()->getSnakeYpos(),
                              getGame()->getFoodX(),
                              getGame()->getFoodY(),
                              getGame()->getBulletX(),
                              getGame()->getBulletY());
    }
}

/**
* \brief get player name
*/
void Core::addPlayerName()
{
    std::cout << "Enter your name : ";
    std::getline(std::cin, _playerName);
}

/**
* \brief menu loop
* \param[in] loader -> get new Instance of game or graph
* \return 0 or 1
*/
int Core::menu(DLLoader loader)
{
    _play = false;
    while (getPlay() == false) {
        pCommand();
        if (startOrExit() == -1)
            return 0;
        if (getPlay() == true)
            return 1;
        else if (lib(loader) == 0)
            if (gamePrint(loader) == 0)
                pNotHandle("Command");
    }
    return 0;
}