#pragma once
#include <iostream>

class I_Print {
    friend std::ostream &operator<<(std::ostream &os, const I_Print &obj){
        obj.print(os);
        return os;
    }
public:
    virtual void print (std::ostream &os) const = 0;
};
