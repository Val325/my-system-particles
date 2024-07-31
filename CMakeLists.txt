cmake_minimum_required(VERSION 3.5) 
project(particlesOpenGl)            

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)
#find_package(assimp REQUIRED)

include_directories(includes)

add_library(glad includes/glad/glad.h includes/glad/src/glad.c)
add_executable(particlesOpenGl particles.cpp)
target_link_libraries(particlesOpenGl ${OPENGL_gl_LIBRARY} glad glfw)
