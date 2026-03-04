add_executable(hl2rtx_pkg_extractor
        main.cpp
        GameLocator.cpp
        GameLocator.h
        ui/main.ui
)

target_include_directories(hl2rtx_pkg_extractor PRIVATE "${CMAKE_CURRENT_BINARY_DIR}/hl2rtx_pkg_extractor_autogen/include")