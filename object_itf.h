#pragma once
#include "common.h"

#define SET_IID( itf, iid ) \
    template<> struct Iid< interface itf > { \
        static uint getIid() { return iid ; } \
    }

template< typename Itf >
struct Iid {
    static uint getIid() { return 0 ; }
} ;

interface IObject {
    virtual void acquire() = 0 ;
    virtual void release() = 0 ;
    virtual IObject* request( const uint& iid ) = 0 ;
} ;
SET_IID( IObject, 1 ) ;

template< typename Itf >
Itf* request( IObject* obj ) {
    return ( Itf* )obj->request( Iid< Itf >::getIid() ) ;
}

