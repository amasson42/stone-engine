find_package(
        Doxygen
        REQUIRED dot
        # mscgen Will be required in network module
)

if (Doxygen_FOUND)
    set(DOXYGEN_OUTPUT_DIRECTORY docs)
    set(DOXYGEN_CREATE_SUBDIRS YES)
    set(DOXYGEN_INCLUDE_PATH ${INCLUDE_DIRS_FOR_DOCS})
    set(DOXYGEN_BUILTIN_STL_SUPPORT YES)

    set(DOXYGEN_CALLER_GRAPH YES)
    set(DOXYGEN_CALL_GRAPH YES)
    set(DOXYGEN_CLASS_GRAPH YES)
    set(DOXYGEN_DIR_GRAPH_MAX_DEPTH 2)
    set(DOXYGEN_SOURCE_BROWSER YES)
    set(DOXYGEN_TEMPLATE_RELATIONS YES)
    set(DOXYGEN_INCLUDE_GRAPH YES)
    set(DOXYGEN_INCLUDED_BY_GRAPH YES)

    set(DOXYGEN_DOT_IMAGE_FORMAT svg)
    set(DOXYGEN_INTERACTIVE_SVG YES)
    set(DOXYGEN_DOT_MAX_NODES 200)
    set(DOXYGEN_DOT_GRAPH_DEPTH 50)

    set(DOXYGEN_EXTRACT_ALL YES)
    set(DOXYGEN_EXTRACT_PRIVATE YES)
    set(DOXYGEN_EXTRACT_STATIC YES)
    set(DOXYGEN_EXTRACT_LOCAL_CLASSES YES)
    set(DOXYGEN_EXTRACT_ANON_NSPACES YES)
    set(DOXYGEN_EXTRACT_PRIV_VIRTUAL YES)

    set(DOXYGEN_GENERATE_TREEVIEW YES)

    set(DOXYGEN_UML_LOOK YES)
    set(DOXYGEN_UML_LIMIT_NUM_FIELDS 20)

    if (CMAKE_SYSTEM_NAME STREQUAL "Darwin")
        set(DOXYGEN_CASE_SENSE_NAMES NO)
    endif ()

    doxygen_add_docs(doxygen ${SRCS_FOR_DOCS})
endif ()
