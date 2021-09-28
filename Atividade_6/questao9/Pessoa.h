//
// Created by luis on 11/08/2021.
//

#ifndef PESSOA_H
#define PESSOA_H
#include <string>
using std::string;

class Pessoa {
private:
    string name;
    int age;
    float height;
public:
    Pessoa(string, int, float);
    Pessoa();
    inline string getName() const {return name;}
    inline int getAge() const {return age;}
    inline float getHeight() const {return height;}

    Pessoa &setName(string);
    Pessoa &setAge(int);
    Pessoa &setHeight(float);

    void getInfo() const;
};


#endif
