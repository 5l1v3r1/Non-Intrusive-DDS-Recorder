###
#
#	CMAKE Build rules for DDSRecorder
#
####
cmake_minimum_required(VERSION 2.8.12)

#set CMAKE_BUILD_TYPE to Release as default
if(DEFINED CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE ${CMAKE_BUILD_TYPE} CACHE STRING "Choose Type of build, options are> None Debug Release RelWithDebInfo MinSizeRel."
	   )
else()
	set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose Type of build, options are> None Debug Release RelWithDebInfo MinSizeRel."
	   )
endif()

project("DDSRecorder")
set(PROJECT_NAME "DDSRecorder")
set(PROJECT_NAME_LARGE "DDSRecorder")
set(PROJECT_NAME_STYLED "DDSRecorder")
string(TOUPPER "${PROJECT_NAME}" PROJECT_NAME_UPPER)
set(${PROJECT_NAME}_DESCRIPTION_SUMMARY "Non-intrusive RTPS protocol packet analyzer.")
set(${PROJECT_NAME}_DESCRIPTION "eProsima ${PROJECT_NAME} non-intrusive RTPS protocol packet analyzer.")
message(STATUS "Configuring ${PROJECT_NAME}")

set(PROJECT_MAJOR_VERSION "1")
set(PROJECT_MINOR_VERSION "0")
set(PROJECT_MICRO_VERSION "0")
set(PROJECT_VERSION ${PROJECT_MAJOR_VERSION}.${PROJECT_MINOR_VERSION}.${PROJECT_MICRO_VERSION})

#Test System Configuration
include(${PROJECT_SOURCE_DIR}/cmake/dev/check_configuration.cmake)
check_stdcxx()
check_compile_feature()
check_endianness()

#Check MSVC Architecture
if(MSVC OR MSVC_IDE)
	check_msvc_arch()
endif()

#Installation paths

set(BIN_INSTALL_DIR bin/ CACHE PATH "Installation directory for binaries")
set(INCLUDE_INSTALL_DIR include/ CACHE PATH "Installation directory for C++ Headers")
set(LIB_INSTALL_DIR lib/ CACHE PATH "Installation directory for libraries")
set(DATA_INSTALL_DIR share/ CACHE PATH "Installation directory for data")
if(WIN32)
	set(DOC_DIR "doc")
else()
	set(DOC_DIR "${DATA_INSTALL_DIR}/doc")
endif()
set(DOC_INSTALL_DIR ${DOC_DIR} CACHE PATH "Installation directory for documentation")
if(WIN32)
	set(LICENSE_INSTALL_DIR . CACHE PATH "Installation directory for licenses")
else()
	set(LICENSE_INSTALL_DIR ${DATA_INSTALL_DIR}/${PROJECT_NAME} CACHE PATH "Installation directory for licenses")
endif()

# eProsima build options
option(EPROSIMA_BUILD "Activate internal building" OFF)

if(EPROSIMA_INSTALLER)
	set(EPROSIMA_BUILD ON)
endif()

#Load CMAKE mocules
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/cmake/modules)

#Check libraries
include(${PROJECT_SOURCE_DIR}/cmake/dev/boost_libraries.cmake)
set(BOOST_LIBRARIES_DEFAULT chrono date_time thread system)
check_boost(${BOOST_LIBRARIES_DEFAULT})

#Load external eProsima projects
option(THIRDPARTY "Activate the use of internal thirdparties" ON)

if(EPROSIMA_BUILD)
	set(THIRDPARTY ON)
endif()

include(${PROJECT_SOURCE_DIR}/cmake/dev/eprosima_libraries.cmake)
find_eprosima_package(fastcdr)
include(${PROJECT_SOURCE_DIR}/cmake/dev/external_dependencies.cmake)
#Remind the user the need to give the directories to sqlite and winpcap
if(WIN32)
    if(DEFINED WINPCAP_ROOT)
        #set(PCAP_INCLUDE_DIR ${WINPCAP_ROOT}/Include CACHE STRING "Include directory of the WinPCAP developer pack")
        #set(PCAP_LIBRARY ${WINPCAP_ROOT}/Lib/wpcap.lib ${WINPCAP_ROOT}/Lib/Packet.lib CACHE STRING "Library directory of the WinPCAP developer pack")
        find_pcap()
        if(NOT PCAP_FOUND)
            message(FATAL_ERROR "Could not find required libraries in the system. Please install pcap and run cmake again")
        endif()
	else()
        message(FATAL_ERROR "WinPCAP developer pack is needed on this project. You need to set -DWINPCAP_ROOT")
	endif()
else()
    find_pcap()
    find_sqlite3()
    if(NOT PCAP_FOUND)
        message(FATAL_ERROR "Could not find required libraries in the system. Please install pcap and run cmake again")
    endif()
    if(NOT SQLITE3_FOUND)
        message(FATAL_ERROR "Could not find required libraries in the system. Please install sqlite3 and run cmake again")
    endif()
endif()

add_compile_options(--std=c++0x)

#Compile library
add_subdirectory(src)

###############################################################################
# Documentation
###############################################################################
# Add an option to toggle the generation of the API documentation.
option(BUILD_DOCUMENTATION "Use doxygen and libreoffice to create product documentation" OFF)

if(EPROSIMA_INSTALLER)
	set(BUILD_DOCUMENTATION ON)
endif()

if(BUILD_DOCUMENTATION)
	find_program(LIBREOFFICE_EXE soffice)
	if(LIBREOFFICE_EXE)
		message(STATUS "Found Libreoffice: ${LIBREOFFICE_EXE}")
		message(STATUS "Recall you need to have installed eProsima macros for Libreoffice")
	else()
		message(FATAL_ERROR "Libreoffice is needed to build the documentation")
	endif()

	#Target to create documentation directories
	add_custom_target(docdirs
		COMMAND ${CMAKE_COMMAND} -E make_directory ${PROJECT_BINARY_DIR}/doc
		COMMAND ${CMAKE_COMMAND} -E make_directory ${PROJECT_BINARY_DIR}/doc/pdf
		COMMENT "Creating documentation directory" VERBATIM)
	#Libreoffice
	if(WIN32)
		set(LIBREOFFICE_CONVERT_README_MACRO "macro:///eProsima.documentation.changeHyperlinksAndVersionToHTML(${PROJECT_SOURCE_DIR}/doc/README.odt,${PROJECT_VERSION},./,/doc/)")
		set(README_LOCATION "${PROJECT_BINARY_DIR}/")
		set(README_INSTALL_LOCATION ".")
	else()
		set(LIBREOFFICE_CONVERT_README_MACRO "macro:///eProsima.documentation.changeVersionToHTML(${PROJECT_SOURCE_DIR}/doc/README.odt,${PROJECT_VERSION})")
		set(README_LOCATION "${PROJECT_BINARY_DIR}/doc/")
		set(README_INSTALL_LOCATION "${DOC_INSTALL_DIR}")
	endif()
	add_custom_target(libreoffice
        COMMAND "${LIBREOFFICE_EXE}" --headless
        "macro:///eProsima.documentation.changeVersion(${PROJECT_SOURCE_DIR}/doc/pdf/Installation Manual.odt,${PROJECT_VERSION})"
        COMMAND ${CMAKE_COMMAND} -E rename "${PROJECT_SOURCE_DIR}/doc/pdf/Installation Manual.pdf" "${PROJECT_BINARY_DIR}/doc/pdf/${PROJECT_NAME_LARGE} - Installation Manual.pdf"
        COMMAND "${LIBREOFFICE_EXE}" --headless
        "macro:///eProsima.documentation.changeVersion(${PROJECT_SOURCE_DIR}/doc/pdf/User Manual.odt,${PROJECT_VERSION})"
        COMMAND ${CMAKE_COMMAND} -E rename "${PROJECT_SOURCE_DIR}/doc/pdf/User Manual.pdf" "${PROJECT_BINARY_DIR}/doc/pdf/${PROJECT_NAME_LARGE} - User Manual.pdf"
        COMMAND "${LIBREOFFICE_EXE}" --headless
        "macro:///eProsima.documentation.changeVersion(${PROJECT_SOURCE_DIR}/doc/pdf/Release Notes.odt,${PROJECT_VERSION})"
        COMMAND ${CMAKE_COMMAND} -E rename "${PROJECT_SOURCE_DIR}/doc/pdf/Release Notes.pdf" "${PROJECT_BINARY_DIR}/doc/pdf/${PROJECT_NAME_LARGE} - Release Notes.pdf"
        COMMAND "${LIBREOFFICE_EXE}" --headless ${LIBREOFFICE_CONVERT_README_MACRO} 
        COMMAND ${CMAKE_COMMAND} -E rename "${PROJECT_SOURCE_DIR}/doc/README.html" "${README_LOCATION}/README.html"
        COMMAND ${CMAKE_COMMAND} -E rename "${PROJECT_SOURCE_DIR}/doc/README_html_181c5124a393013a.png" "${README_LOCATION}/README_html_181c5124a393013a.png"
        DEPENDS
        "${PROJECT_SOURCE_DIR}/doc/pdf/${PROJECT_NAME} - Installation Manual.odt"
        "${PROJECT_SOURCE_DIR}/doc/pdf/${PROJECT_NAME} - User Manual.odt"
        "${PROJECT_SOURCE_DIR}/doc/pdf/${PROJECT_NAME} - Release Notes.odt"
        "${PROJECT_SOURCE_DIR}/doc/README.odt"
        COMMENT "Generating documentation with libreoffice" VERBATIM)

    add_dependencies(libreoffice docdirs)

    add_custom_target(doc ALL
        COMMENT "Generated project documentation" VERBATIM)

    add_dependencies(doc libreoffice)

endif()
# Packaging
# Install external eprosima libraries
install_eprosima_libraries()
install_boost(ALL ${BOOST_LIBRARIES_DEFAULT})

# Install licenses
#install(FILES ${PROJECT_SOURCE_DIR}/doc/licencias/${PROJECT_NAME}_LIBRARY_LICENSE.txt
#    ${PROJECT_SOURCE_DIR}/doc/licencias/LGPLv3_LICENSE.txt
#    DESTINATION ${LICENSE_INSTALL_DIR}
#    COMPONENT licenses
#    )
set(CPACK_COMPONENT_LICENSES_HIDDEN 1)

# Install examples
install(DIRECTORY ${PROJECT_SOURCE_DIR}/examples
    DESTINATION .
    COMPONENT examples
    )

set(CPACK_COMPONENT_EXAMPLES_DISPLAY_NAME "Examples")
set(CPACK_COMPONENT_EXAMPLES_DESCRIPTION "eProsima ${PROJECT_NAME} examples")

set(CPACK_COMPONENTS_ALL licenses examples)

if(BUILD_DOCUMENTATION)
    # Instalation of pdf files
    install(FILES 
        "${PROJECT_BINARY_DIR}/doc/pdf/${PROJECT_NAME_LARGE} - Installation Manual.pdf"
        "${PROJECT_BINARY_DIR}/doc/pdf/${PROJECT_NAME_LARGE} - User Manual.pdf"
        "${PROJECT_BINARY_DIR}/doc/pdf/${PROJECT_NAME_LARGE} - Release Notes.pdf"
        DESTINATION ${DOC_INSTALL_DIR}/pdf
        COMPONENT documentation
        )

    install(FILES 
        "${README_LOCATION}/README.html"
        "${README_LOCATION}/README_html_181c5124a393013a.png"
        DESTINATION ${README_INSTALL_LOCATION}
        COMPONENT documentation
        )

    ### Documentation component
    set(CPACK_COMPONENT_DOCUMENTATION_DISPLAY_NAME "Documentation")
    set(CPACK_COMPONENT_DOCUMENTATION_DESCRIPTION "eProsima ${PROJECT_NAME} documentation")

    set(CPACK_COMPONENTS_ALL ${CPACK_COMPONENTS_ALL} documentation)
endif()

set(CPACK_COMPONENTS_ALL ${CPACK_COMPONENTS_ALL} binaries)

include(${PROJECT_SOURCE_DIR}/cmake/packaging/eProsimaPackaging.cmake)
