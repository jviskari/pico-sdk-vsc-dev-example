add_library(pshell_example)

target_include_directories(pshell_example 
    INTERFACE 
        ${CMAKE_CURRENT_LIST_DIR}/inc 
    )

target_sources(pshell_example
    PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/src/pshell_example_cmd.c                   
    )

target_link_libraries(pshell_example
    PRIVATE
        pshell                 
)
