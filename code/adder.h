#pragma once
#include "common.h"
#include "adder_itf.h"

class Adder : implements IAdder {
    int refCount ;

    int thisValue ;

    DISABLE_COPY( Adder ) ;
public:
    Adder() : refCount( 1 ), thisValue( 0 ) {
    }

    virtual ~Adder() {
        LOG_DESTRUCTION( Adder ) ;
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
        if ( iid == Iid< IAdder >::getIid() )
            return this ;
        return nullptr ;
    }

    virtual int value() {
        return thisValue ;
    }

    virtual int add( int addend ) {
        thisValue += addend ;
        return thisValue ;
    }
} ;
