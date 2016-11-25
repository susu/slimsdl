
set(SOURCE_FILES
    Context.cpp
    ImageContext.cpp
    Window.cpp
    )

message("--> LIBS: ${LIBS}")

add_library(slimsdl SHARED ${SOURCE_FILES})
target_link_libraries(slimsdl ${LIBS})
install(TARGETS slimsdl DESTINATION lib)

