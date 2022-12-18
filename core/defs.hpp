#ifndef FILE_ENCODER_DEFS_HPP
#define FILE_ENCODER_DEFS_HPP

//region output helpers
#define INFO(msg) std::cout << "\033[46;37m" "[INFO]:" "\033[0;36m " msg "\033[0m" << std::endl
#define WARNING(msg) std::cout << "\033[43;37m" "[WARNING]:" "\033[0;33m " msg "\033[0m" << std::endl
#define ERROR(msg) std::cout << "\033[41;37m" "[ERROR]:" "\033[0;31m " msg "\033[0m" << std::endl
//endregion

//region exit codes
#define EXIT_OK                   exit(0)
#define EXIT_INVALID_PARAM_NUMBER exit(-1)
#define EXIT_FILE_NOT_FOUND       exit(-2)
#define EXIT_INVALID_PARAM        exit(-3)
//endregion

#define INIT_BINARY_IO std::freopen(nullptr, "rb", stdin); \
                       std::freopen(nullptr, "wb", stdout); \
                       std::ios_base::sync_with_stdio(false)

#endif //FILE_ENCODER_DEFS_HPP
