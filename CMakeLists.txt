# Construo - A wire-frame construction game
# Copyright (C) 2015 Ingo Ruhnke <grumbel@gmail.com>
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

cmake_minimum_required(VERSION 3.0)
project(construo VERSION 0.2.4)

find_package(OpenGL)
find_package(GLUT)
find_package(X11)
find_package(ZLIB)

set(WARNINGS OFF CACHE BOOL "Enable extra compiler warnings")
set(CONSTRUO_BINDIR "${CMAKE_INSTALL_PREFIX}/bin" CACHE PATH "Install location for binaries")
set(CONSTRUO_DATADIR "${CMAKE_INSTALL_PREFIX}/share/${PROJECT_NAME}" CACHE PATH "Install location for datafiles")

if(WARNINGS)
  set(WARNINGS_CXX_FLAGS
    -pedantic -Wall -Wextra -Wno-c++0x-compat -Wnon-virtual-dtor
    -Werror -Wcast-qual -Winit-self -Wno-unused-parameter)
  # -Wconversion -Weffc++ -Wshadow
  # -Winline -Wfloat-equal -Wunreachable-code
endif()

include_directories(SYSTEM external/lispreader-0.5)

file(GLOB LISPREADER_SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
  external/lispreader-0.5/lispreader.c
  external/lispreader-0.5/pools.c
  external/lispreader-0.5/allocator.c)
add_library(lispreader ${LISPREADER_SOURCES})

set(CONSTRUO_SOURCES_CXX
  src/bounding_box.cpp
  src/bounding_box.hpp
  src/buttons.hpp
  src/collider.hpp
  src/color.hpp
  src/colors.cpp
  src/colors.hpp
  src/command_line.cpp
  src/command_line.hpp
  src/config.cpp
  src/config.hpp
  src/construo.cpp
  src/construo.hpp
  src/construo_error.hpp
  src/controller.cpp
  src/controller.hpp
  src/cursors/cursor_collider.xbm
  src/cursors/cursor_collider_mask.xbm
  src/cursors/cursor_insert.xbm
  src/cursors/cursor_insert_mask.xbm
  src/cursors/cursor_scroll.xbm
  src/cursors/cursor_scroll_mask.xbm
  src/cursors/cursor_select.xbm
  src/cursors/cursor_select_mask.xbm
  src/cursors/cursor_zoom.xbm
  src/cursors/cursor_zoom_mask.xbm
  src/cursors/cursors.hpp
  src/cursor_type.hpp
  src/delta_manager.hpp
  src/events.hpp
  src/force_emitter.hpp
  src/graphic_context.hpp
  src/gui_buttons.cpp
  src/gui_buttons.hpp
  src/gui_child_manager.cpp
  src/gui_child_manager.hpp
  src/gui_component.cpp
  src/gui_component.hpp
  src/gui_directory.cpp
  src/gui_directory.hpp
  src/gui_directory_button.cpp
  src/gui_directory_button.hpp
  src/gui_file_button.cpp
  src/gui_file_button.hpp
  src/gui_file_manager.cpp
  src/gui_file_manager.hpp
  src/gui_label.cpp
  src/gui_label.hpp
  src/gui_manager.cpp
  src/gui_manager.hpp
  src/gui_new_file_button.cpp
  src/gui_new_file_button.hpp
  src/gui_window.cpp
  src/gui_window.hpp
  src/input_context.cpp
  src/input_context.hpp
  src/keep_alive.hpp
  src/keep_alive_mgr.cpp
  src/keep_alive_mgr.hpp
  src/keys.hpp
  src/lisp_reader.cpp
  src/lisp_reader.hpp
  src/lisp_writer.cpp
  src/lisp_writer.hpp
  src/load_gui_manager.cpp
  src/load_gui_manager.hpp
  src/math.hpp
  src/particle.cpp
  src/particle.hpp
  src/particle_factory.cpp
  src/particle_factory.hpp
  src/path_manager.cpp
  src/path_manager.hpp
  src/rect.hpp
  src/rect_collider.cpp
  src/rect_collider.hpp
  src/root_graphic_context.cpp
  src/root_graphic_context.hpp
  src/save_gui_manager.cpp
  src/save_gui_manager.hpp
  src/screen_manager.cpp
  src/screen_manager.hpp
  src/selection.cpp
  src/selection.hpp
  src/settings.cpp
  src/settings.hpp
  src/spring.cpp
  src/spring.hpp
  src/spring_type.hpp
  src/string_utils.cpp
  src/string_utils.hpp
  src/system_context.hpp
  src/unix_system.cpp
  src/unix_system.hpp
  src/vector.cpp
  src/vector.hpp
  src/vector2d.hpp
  src/world.cpp
  src/world.hpp
  src/world_button.cpp
  src/world_button.hpp
  src/world_gui_manager.cpp
  src/world_gui_manager.hpp
  src/worldview_collider_tool.cpp
  src/worldview_collider_tool.hpp
  src/worldview_component.cpp
  src/worldview_component.hpp
  src/worldview_insert_tool.cpp
  src/worldview_insert_tool.hpp
  src/worldview_select_tool.cpp
  src/worldview_select_tool.hpp
  src/worldview_tool.cpp
  src/worldview_tool.hpp
  src/worldview_zoom_tool.cpp
  src/worldview_zoom_tool.hpp
  src/zoom_graphic_context.cpp
  src/zoom_graphic_context.hpp
  )

set(CONSTRUO_GLUT_SOURCES_CXX
  src/construo_main.cpp
  src/construo_main.hpp
  src/glut_display.hpp
  src/glut_display.cpp
  )

set(CONSTRUO_X11_SOURCES_CXX
  src/construo_main.cpp
  src/construo_main.hpp
  src/x11_display.hpp
  src/x11_display.cpp
  )

include_directories(src/)
include_directories(.)

add_definitions(-DVERSION="0.2.4")
add_definitions(-DPACKAGE="construo")
add_definitions(-DPACKAGE_STRING="construo 0.2.4")
add_definitions(-DCONSTRUO_DATADIR="${DATADIR}")

if(ZLIB_FOUND)
  add_definitions(-DHAVE_LIBZ)
  include_directories(${ZLIB_INCLUDE_DIRS})
  link_libraries(${ZLIB_LIBRARIES})
endif()

add_library(libconstruo STATIC ${CONSTRUO_SOURCES_CXX})
set_target_properties(libconstruo PROPERTIES OUTPUT_NAME construo)
target_compile_options(libconstruo PRIVATE -std=c++11)

if(GLUT_FOUND AND OPENGL_FOUND)
  add_executable(construo.glut ${CONSTRUO_GLUT_SOURCES_CXX})
  target_compile_options(construo.glut PRIVATE -std=c++11 ${WARNINGS_CXX_FLAGS})
  target_compile_definitions(construo.glut PUBLIC -DUSE_GLUT_DISPLAY)
  target_include_directories(construo.glut SYSTEM PUBLIC ${OPENGL_INCLUDE_DIR} ${GLUT_INCLUDE_DIRS})
  target_link_libraries(construo.glut libconstruo lispreader ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES})

  install(TARGETS construo.glut RUNTIME DESTINATION ${CONSTRUO_BINDIR})
endif()

if(X11_FOUND)
  add_executable(construo.x11 ${CONSTRUO_X11_SOURCES_CXX})
  target_compile_options(construo.x11 PRIVATE -std=c++11 ${WARNINGS_CXX_FLAGS})
  target_compile_definitions(construo.x11 PUBLIC -DUSE_X11_DISPLAY)
  target_include_directories(construo.x11 SYSTEM PUBLIC ${X11_INCLUDE_DIR})
  target_link_libraries(construo.x11 libconstruo lispreader ${X11_LIBRARIES})

  if(X11_Xext_FOUND)
    target_link_libraries(construo.x11 ${X11_Xext_LIB})
  endif()

  if(X11_xf86vmode_FOUND)
    target_include_directories(construo.x11 SYSTEM PUBLIC ${X11_xf86vmode_INCLUDE_PATH})
    target_link_libraries(construo.x11 ${X11_xf86vm_LIB})
  endif()

  install(TARGETS construo.x11 RUNTIME DESTINATION ${CONSTRUO_BINDIR})
endif()

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/examples DESTINATION ${CONSTRUO_DATADIR})

# EOF #
