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
    int age, height;
public:
    Pessoa(string, int, int);
    inline string getName() const {return name;}
    inline int getAge() const {return age;}
    inline int getHeight() const {return height;}

    Pessoa &setName(string);
    Pessoa &setAge(int);
    Pessoa &setHeight(int);

    void getInfo() const;
};


#endif
