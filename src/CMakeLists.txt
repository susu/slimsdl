
set(SOURCE_FILES
    Context.cpp
    )

add_library(slimsdl SHARED ${SOURCE_FILES})
target_link_libraries(slimsdl ${LIBS})
install(TARGETS slimsdl DESTINATION lib)

