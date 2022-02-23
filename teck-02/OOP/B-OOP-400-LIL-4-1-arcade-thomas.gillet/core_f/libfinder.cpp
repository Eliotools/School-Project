/*
** EPITECH PROJECT, 2021
** B-OOP-400-LIL-4-1-arcade-thomas.gillet
** File description:
** libfinder
*/


#include <iostream>
#include <vector>
#include <dirent.h>

/**
* \file
* \brief Function for add new lib in actual lib vector
*/
/**
* \brief need help to known what function do
* \param[in] name
* \return 0 is not handle lib 2 if contains .so and arcade
*/
int niddleyearsold(std::string name)
{
    int i = 0;
    if (name.substr(name.find('.'), name.length()) == ".so")
        i++;
    if (name.substr(0, name.find('_')) == "arcade")
        i++;
    return (i);
}

/**
* \brief check if given name is one of graphics libs we wanted
* \param[in] name -> name of lib 
*/
int find_in_gra(std::string name)
{
    if (name.find('_') == name.length() || name.find('.') == name.length())
        return (0);
    name = name.substr(name.find('_')+1, name.length());
    name = name.substr(0, name.find('.'));
    std::vector<std::string> mylist{"ncurses", "sdl2", "sfml", "ndk++", "aallib", "libcaca", "allegro5", "xlib", "gtk+", "irrlicht", "opengl", "vulkan", "qt5"};

    for (std::vector<std::string>::const_iterator i = mylist.begin(); i != mylist.end(); ++i) {
        if (*i == name)
            return 1;
    }
    
    return 0;
}

/**
* \brief check if given name is one of graphics games we wanted
* \param[in] name -> name of game 
*/
int find_in_game(std::string name)
{
    if (name.find('_') == name.length() || name.find('.') == name.length())
        return (0);
    name = name.substr(name.find('_')+1, name.length());
    name = name.substr(0, name.find('.'));
    std::vector<std::string> mylist{"nibbler", "centipede", "pacman", "qix", "solarfox"};

    for (std::vector<std::string>::const_iterator i = mylist.begin(); i != mylist.end(); ++i) {
        if (*i == name)
            return 1;
    }
    return 0;
}

/**
* \brief find in directory new lib
* \param[in] i -> 1 for game 2 for graph
* \return files -> name of new lib
*/
std::vector<std::string> get_lib(int i) {
    DIR *dir; struct dirent *diread;
    std::vector<std::string> files;

    if ((dir = opendir("./lib")) != nullptr) {
        while ((diread = readdir(dir)) != nullptr) {
            if (i == 1)
                if (find_in_game(diread->d_name) && niddleyearsold(diread->d_name))
                    files.push_back(diread->d_name);
            if (i == 2)
                if (find_in_gra(diread->d_name) && niddleyearsold(diread->d_name))
                    files.push_back(diread->d_name);
        }
    }
    closedir (dir);
    return files;
}
