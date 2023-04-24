#pragma once
#include "common.h"
#include "object_itf.h"

interface IReader : extends IObject {
    virtual int read() = 0 ;
} ;
SET_IID( IReader, 8531 ) ;

IReader* createReader() ;
