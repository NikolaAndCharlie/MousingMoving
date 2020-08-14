
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5
    COMPONENTS
    Core
	Widgets
	Gui
	Sql
	Xml
	REQUIRED
)

set(Qt5_LIBS Qt5::Core Qt5::Widgets Qt5::Gui Qt5::Sql Qt5::Xml)
add_executable(MouseMoving WIN32)
#qt5_add_resources(RC MouseMoving.qrc)

file(GLOB SRCS *cpp)
file(GLOB HDRS *h)

target_sources(MouseMoving
    PRIVATE
	${SRCS}
	${HDRS}

)

target_link_libraries(MouseMoving
    Qt5::Core
	Qt5::Widgets
	Qt5::Gui
	Qt5::Sql
	Qt5::Xml
)

