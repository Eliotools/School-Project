/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPD16-eliot.martin
** File description:
** BF_Translator
*/

#include "BF_Translator.hpp"
#include <fstream>
#include <iostream>

BF_Translator::BF_Translator()
{
    map['+'] = (char *)"(*ptr)++;\n";
    map['-'] = (char *)"(*ptr)--;\n";
    map['>'] = (char *)"(ptr)++;\n";
    map['<'] = (char *)"(ptr)--;\n";
    map['.'] = (char *)"putchar(*ptr);\n";
    map[','] = (char *)"(*ptr)=getchar();\n";
    map['['] = (char *)"while(*ptr){\n";
    map[']'] = (char *)"}\n";
}

BF_Translator::~BF_Translator()
{
}

int plus()
{
     return 0;
}

int BF_Translator::translate(const std::string &in, const std::string &out)
{
    std::fstream read(in);
    std::ofstream write(out);
    std::string str;
    if (!read) {
        std::cout << "no file" << std::endl;
        return -1;
    }
    write << "/*\n** EPITECH PROJECT, 2021\n** B-CPP-300-LIL-3-1-CPPD16-eliot.martin\n** File description:\n** main\n*/\n#include <stdlib.h>\n#include <unistd.h>\n#include <stdio.h>\nint  main()\n{\n";
    write << "char *ptr;\n ptr = malloc(60000*sizeof(char));\n";
    getline(read, str);
    for (int i = 0; i != str.size(); i++)
    {
        for (auto it = map.begin(); it != map.end(); it++)
        {
            pair = *it;

            if (str[i] == pair.first)
            {
                write << pair.second;
                break;
            }
        }
    }
    write << "return;}";
    return 0;
}