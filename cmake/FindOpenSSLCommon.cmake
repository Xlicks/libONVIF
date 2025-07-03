find_library(OpenSSL_cryptro_PATH NAMES libeay libeay32 libcrypto libcrypto32 eay crypto PATHS /usr/local/lean/openssl-3.0.16 PATH_SUFFIXES "lib64" NO_DEFAULT_PATH)
find_library(OpenSSL_ssl_PATH NAMES ssleay ssleay32 libssl libssl32 eay ssl  PATHS /usr/local/lean/openssl-3.0.16 PATH_SUFFIXES "lib64" NO_DEFAULT_PATH)
find_path(OpenSSL_include_DIR NAMES openssl/ssl.h  PATHS /usr/local/lean/openssl-3.0.16 PATH_SUFFIXES "include" NO_DEFAULT_PATH)
message(STATUS "OpenSSL_cryptro_PATH: ${OpenSSL_cryptro_PATH}\n"
        "OpenSSL_ssl_PATH: ${OpenSSL_ssl_PATH}\n"
        "OpenSSL_include_DIR: ${OpenSSL_include_DIR}\n"
)
set(HAS_OPENSSL OFF)
if(OpenSSL_include_DIR AND OpenSSL_cryptro_PATH AND OpenSSL_ssl_PATH)
    set(HAS_OPENSSL ON)
    message(STATUS "OpenSSL found")
endif()