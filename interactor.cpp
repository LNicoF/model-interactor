#include "interactor.h"
#include "adder_itf.h"

void Interactor::init() {
    IAdder* adder = ::request< IAdder >( model ) ;
    if ( adder != nullptr ) {
        adder->acquire() ;

        int currentValue = adder->value() ;
        writer->write( currentValue ) ;

        adder->release() ;
    }
}

void Interactor::edit() {
    IAdder* adder = ::request< IAdder >( model ) ;
    if ( adder != nullptr ) {
        adder->acquire() ;

        int input ;
looper:
        input = reader->read() ;
        if ( input != 0 ) {
            writer->write( adder->add( input ) ) ;
            goto looper ;
        }

        adder->release() ;
    }
}

IInteractor* createInteractor( IModel* model ) {
    return new Interactor( model ) ;
}
