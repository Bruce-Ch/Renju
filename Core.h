//
// Created by pc on 2020/6/6.
//

#ifndef RENJU_CORE_H
#define RENJU_CORE_H


#include <vector>

class Core {
public:
    void configure();
    bool play();
    void show(const std::vector<int>& config);
};


#endif //RENJU_CORE_H
