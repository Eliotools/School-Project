/*
** EPITECH PROJECT, 2021
** R-Type
** File description:
** Locked Queue for message
*/

#ifndef LOCKEDQUEUE_HPP_
#define LOCKEDQUEUE_HPP_

#include <mutex>
#include <queue>
#include <list>

template<typename _T> class LockedQueue {
public:
    void push(_T value) {
        std::unique_lock<std::mutex> lock(mutex);
        queue.push(value);
    };

    _T pop() {
        std::unique_lock<std::mutex> lock(mutex);
        _T value;
        std::swap(value, queue.front());
        queue.pop();
        return value;
    };

    bool empty() {
        std::unique_lock<std::mutex> lock(mutex);
        return queue.empty();
    }
private:
    std::mutex mutex;
    std::queue<_T> queue;
};

#endif