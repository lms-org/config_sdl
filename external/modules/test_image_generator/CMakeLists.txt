set(SOURCES
    "src/test_image_generator.cpp"
    "src/interface.cpp"
)

set(HEADERS
    "include/test_image_generator.h"
)

include_directories(include)
add_library(test_image_generator MODULE ${SOURCES} ${HEADERS})
target_link_libraries(test_image_generator PRIVATE lmscore imaging)
