#pragma once
#include "common.h"
#include "object_itf.h"

interface IAdder : extends IObject {
    virtual int value() = 0 ;
    virtual int add( int addend ) = 0 ;
} ;
SET_IID( IAdder, 19743 ) ;

IAdder* createAdder() ;
