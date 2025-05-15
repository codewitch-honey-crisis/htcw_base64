# Copyright (c) 2025 honey the codewitch
#
# SPDX-License-Identifier: Apache-2.0

if(CONFIG_HTCW_BASE64)
zephyr_library()
zephyr_include_directories(../src)
zephyr_library_include_directories(../src)
zephyr_interface_library_named(HTCW_BASE64)
zephyr_library_sources(../src/source/base64.c)
#zephyr_library_sources_ifdef(CONFIG_PARAM_DEF, file.cpp)
zephyr_library_link_libraries(HTCW_BASE64)
target_link_libraries(HTCW_BASE64 INTERFACE zephyr_interface)

endif()