﻿
# =========== 3rdparty libiniloader ==================
if(NOT 3RD_PARTY_LIBINILOADER_BASE_DIR)
    set (3RD_PARTY_LIBINILOADER_BASE_DIR ${CMAKE_CURRENT_LIST_DIR})
endif()

set (3RD_PARTY_LIBINILOADER_INC_DIR ${3RD_PARTY_LIBINILOADER_BASE_DIR})
set (3RD_PARTY_LIBINILOADER_SRC_DIR ${3RD_PARTY_LIBINILOADER_BASE_DIR})
# set (3RD_PARTY_LIBINILOADER_LINK_NAME)

if(NOT EXISTS "${3RD_PARTY_LIBINILOADER_BASE_DIR}/ini_loader.h")
    FindConfigurePackageDownloadFile("https://raw.githubusercontent.com/owt5008137/libiniloader/master/ini_loader.h" "${3RD_PARTY_LIBINILOADER_BASE_DIR}/ini_loader.h")
endif()

if(NOT EXISTS "${3RD_PARTY_LIBINILOADER_BASE_DIR}/ini_loader.cpp")
    FindConfigurePackageDownloadFile("https://raw.githubusercontent.com/owt5008137/libiniloader/master/ini_loader.cpp" "${3RD_PARTY_LIBINILOADER_BASE_DIR}/ini_loader.cpp")
endif()

include_directories(${3RD_PARTY_LIBINILOADER_INC_DIR})
list(APPEND PROJECT_3RD_PARTY_SRC_LIST "${3RD_PARTY_LIBINILOADER_SRC_DIR}/ini_loader.cpp")