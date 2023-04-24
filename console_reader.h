#pragma once
#include "common.h"

#include <iostream>

#include "reader_itf.h"

class ConsoleReader : implements IReader {
    int refCount ;

    DISABLE_COPY( ConsoleReader ) ;
public:
    ConsoleReader() : refCount( 1 ) {
    }

    virtual ~ConsoleReader() {
        LOG_DESTRUCTION( ConsoleReader ) ;
    }

    virtual void acquire() {
        ++refCount ;
    }

    virtual void release() {
        --refCount ;
        if ( refCount == 0 )
            delete this ;
    }

    virtual IObject* request( const uint& iid ) {
        if ( iid == Iid< IObject >::getIid() )
            return this ;
        if ( iid == Iid< IReader >::getIid() )
            return this ;
        return nullptr ;
    }

    virtual int read() {
        int res ;
        std::cin >> res ;
        return res ;
    }
} ;
