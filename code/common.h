#pragma once

#if 0
#include <iostream>
#define LOG_DESTRUCTION( cls ) \
    std::cout << #cls " Destroyed" << std::endl
#else
#define LOG_DESTRUCTION( cls )
#endif

#define DISABLE_COPY( cls ) \
    cls( const cls& ) ; \
    cls& operator =( const cls& )

#define interface  struct
#define extends    public
#define implements public
#define nullptr    0

typedef unsigned int uint ;

