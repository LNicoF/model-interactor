#pragma once
#include "common.h"

#include <iostream>

#include "writer_itf.h"

class ConsoleWriter : implements IWriter {
    int refCount ;

    DISABLE_COPY( ConsoleWriter ) ;
public:
    ConsoleWriter() : refCount( 1 ) {
    }

    virtual ~ConsoleWriter() {
        LOG_DESTRUCTION( ConsoleWriter ) ;
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
        if ( iid == Iid< IWriter >::getIid() )
            return this ;
        return nullptr ;
    }

    virtual void write( int n ) {
        std::cout << n << std::endl ;
    }
} ;
