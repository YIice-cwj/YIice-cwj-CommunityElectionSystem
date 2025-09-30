#include "exception/database_exception.h"
#include <iostream>
#include "exception/database_error_code.h"

int main() {
    try {
        throw database_exception(
            database_error_code_t::db_authentication_failed);
    } catch (database_exception& e) {
        std::cout << "Error code: " << e.error_code() << std::endl;
        std::cout << "Error message: " << e.what() << std::endl;
    }
    return 0;
}