add_library(pshell)

target_include_directories(pshell 
    PRIVATE 
        ${CMAKE_CURRENT_LIST_DIR}/inc 
    INTERFACE 
        ${CMAKE_CURRENT_LIST_DIR}/inc 

    )

target_sources(pshell
    PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/src/pshell.c
        ${CMAKE_CURRENT_LIST_DIR}/src/pshell_std_input.c        
        
    )
