/*
** EPITECH PROJECT, 2021
** B-OOP-400-LIL-4-1-arcade-thomas.gillet [WSL: Ubuntu]
** File description:
** DLLoader
*/

#include "DLLoader.hpp"
#include <dlfcn.h>

/**
* \file
* \brief DLLoader function for create Instance of IGame or IGraphic and manage it
*/
/**
* \brief Constructor of DLLoader
*/
DLLoader::DLLoader() : _graphicsNb(0), _gamesNb(0)
{
}

/**
* \brief Deconstructor of DLLoader
*/
DLLoader::~DLLoader()
{
}

/**
* \brief return _gamesNb
* \return _gamesNb -> number of game load
*/
int DLLoader::getGamesNb()
{
    return _gamesNb;
}

/**
* \brief return _graphicsNb
* \return _graphicsNb -> number of graphic load
*/
int DLLoader::getGraphicsNb()
{
    return _graphicsNb;
}

/**
* \brief use dlopen() and dlsym() for create a new Instance of IGraph, put new Instance in vector
* \param[in] name -> path of wanted lib
* \param[in] gname -> name for represents new Instance 
* \return return of entry -> link to function EntryPoint of wanted class
*/
IGraphic *DLLoader::getInstanceOfGraph(std::string name)
{
    IGraphic *(*entry)(void);
    void *handle = dlopen(name.c_str(), RTLD_LAZY);
    *(void **)(&entry) = dlsym(handle, "entryPoint");
    if (!handle) {
        exit(EXIT_FAILURE);
    }
    dlerror();
    return entry();
}

/**
* \brief print all name of games
*/
void DLLoader::insideOfGames()
{
    for (int i = 0; i < getGamesNb(); i++)
        std::cout << i << " Game is " << getGameInstanceName(i) << std::endl;
}

/**
* \brief use dlopen() and dlsym() for create a new Instance of IGame, put new Instance in vector
* \param[in] name -> path of wanted lib
* \param[in] gname -> name for represents new Instance 
* \return return of entry -> link to function EntryPoint of wanted class
*/
IGame *DLLoader::getInstanceOfGame(std::string name)
{
    IGame *(*entry)();
    void *handle = dlopen(name.c_str(), RTLD_LAZY);
    *(void **)(&entry) = dlsym(handle, "entryPoint");
    if (!handle) {
        std::cout << "here" << std::endl;
        exit(EXIT_FAILURE);
    }
    dlerror();
    return entry();
}

/**
* \brief return name of nb element of _graphicsName
* \return _graphicsName[nb] -> nb element of vector of name
*/
std::string DLLoader::getGraphInstanceName(int nb)
{
    return _graphicsName[nb];
}

/**
* \brief return name of nb element of _gamesName
* \param[in] nb -> nth element we wanted
* \return _gamesName[nb] -> nb element of vector of name
*/
std::string DLLoader::getGameInstanceName(int nb)
{
    return _gamesName[nb];
}

/**
* \brief return  IGame instance of nb element of _games
* \param[in] nb -> nth element we wanted
* \return _games[nb] -> Instance IGame of vector _games
*/
IGame *DLLoader::getGameInstance(int nb)
{
    return _games[nb];
}

/**
* \brief return  IGame instance of nb element of _graphics
* \param[in] nb -> nth element we wanted
* \return _graphics[nb] -> Instance IGame of vector _graphics
*/
IGraphic *DLLoader::getGraphInstance(int nb)
{
    return _graphics[nb];
}

/**
* \brief close all handles create by dlopen
*/
void DLLoader::closeAllHandles()
{
    for (auto &handle : _handles)
        dlclose(handle);
}