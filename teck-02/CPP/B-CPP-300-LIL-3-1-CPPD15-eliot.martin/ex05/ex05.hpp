/*
** EPITECH PROJECT, 2021
** B-CPP-300-LIL-3-1-CPPD15-eliot.martin
** File description:
** ex05
*/

#ifndef EX05_HPP_
#define EX05_HPP_

template <typename T>
class array 
{
    public :
        array()
        {
            _array = new T* array[];
        }
        array(unsigned int n)
        {
            _array = new T *array[n];
        }
        array(array old)
        {
            _array = old._array;
        }
        array operator=(array odl)
        {
            _array = old.array;
        }
        array operator[](const int nb)
        {
            
        }
    private :
     T *_array;

};

#endif /* !EX05_HPP_ */
