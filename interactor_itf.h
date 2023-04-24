#pragma once
#include "common.h"
#include "object_itf.h"
#include "model_itf.h"

interface IInteractor : extends IObject {
    virtual void init() = 0 ;
    virtual void edit() = 0 ;
} ;
SET_IID(IInteractor, 15058) ;

IInteractor* createInteractor( IModel* model ) ;
