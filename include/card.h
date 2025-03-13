/* Berezkin Konstantin Evgenievich
./main st128027@student.spbu.ru*/
#ifndef CARD_H
#define CARD_H
#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <cstdlib>
#include <ctime>

class Card
{
private:
    std::string name;
    int manna;
public:
    Card(std::string name = "null", int manna = 0);
    std::string Get_Name();
    int Get_Manna();
    virtual void The_Card();
    virtual ~Card();
};

#endif
