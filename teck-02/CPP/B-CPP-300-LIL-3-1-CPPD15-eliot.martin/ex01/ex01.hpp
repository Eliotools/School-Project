/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPD15-eliot.martin
** File description:
** ex01
*/

#ifndef EX01_HPP_
#define EX01_HPP_

template<typename T>
int compare(T const &a, T const &b)
{
    if (a > b)
        return 1;
    if (a < b)
        return -1;
    return 0;
}

class  toto{
    public:
    toto() = default;
    toto &operator =( const  toto&) = delete;
    toto(const  toto &) = delete;
    bool  operator ==( const  toto&)  const 
    {
        return  true;
    }
    bool  operator >( const  toto&)  const 
    {
        return  false;
    }
    bool  operator <( const  toto&)  const { return  false;
    }
};

#endif /* !EX01_HPP_ */
