#include "app_itf.h"

int main() {
    IApp* app = createApp() ;

    try {
        app->init() ;
        app->run() ;
    } catch ( ... ) {
        ;
    }

    app->release() ;
}
