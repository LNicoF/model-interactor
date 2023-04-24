#pragma once

#define interface  struct
#define extends    public
#define implements public
#define nullptr    0

#define DISABLE_COPY( cls ) \
    cls( const cls& ) ; \
    cls& operator =( const cls& )

#ifdef _GLIBCXX_IOSTREAM
#define LOG_DESTRUCTION( cls ) \
    std::cout << #cls " Destroyed" << std::endl
#else
#define LOG_DESTRUCTION( cls )
#endif

typedef unsigned int uint ;

