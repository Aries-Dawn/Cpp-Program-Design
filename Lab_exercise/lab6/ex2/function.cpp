#include <iostream>
#include "include/function.h"
#include <cstring>

char* match(char* s, char ch){
    int len = strlen(s);
    char *moved = s;
    for (int i = 0; i < len; i++)
    {
        if (*s == ch)
        {
            return s;
        }
        s += 1;
    }
    return nullptr;
}