#ifndef DATA_HPP
#define DATA_HPP

struct Data {
    int number;         // An integer member
    char character;     // A character member
    float decimal;      // A float member

    Data(int n, char c, float d) : number(n), character(c), decimal(d) {}
};

#endif