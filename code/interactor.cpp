#include "interactor.h"

IInteractor* createInteractor( IAdder* model ) {
    return new Interactor( model ) ;
}
