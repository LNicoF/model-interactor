#include "console_writer.h"

IWriter* createWriter() {
    return new ConsoleWriter ;
}
