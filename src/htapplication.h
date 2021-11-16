#ifndef HTAPPLICATION_H
#define HTAPPLICATION_H

#include <mainmenu.h>
#include <stategame.h>
#include <iostream>

class HTApplication
{
    public:
        HTApplication();
        virtual ~HTApplication();
        int exec();
        int exitCode();
    private:
        int m_exitCode = 0;
};

#endif // HTAPPLICATION_H
