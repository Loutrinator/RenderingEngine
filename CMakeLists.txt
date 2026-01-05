cmake_minimum_required(VERSION 3.16)
project(RenderingEngine LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# =========================
# GLFW
# =========================
include(FetchContent)

FetchContent_Declare(
		glfw
		GIT_REPOSITORY https://github.com/glfw/glfw.git
		GIT_TAG 3.3.9
)

FetchContent_MakeAvailable(glfw)

# =========================
# GLM
# =========================
FetchContent_Declare(
		glm
		GIT_REPOSITORY https://github.com/g-truc/glm.git
		GIT_TAG 1.0.1
)

FetchContent_MakeAvailable(glm)

# =========================
# GLAD
# =========================
add_library(glad
		external/glad/src/glad.c
)

target_include_directories(glad PUBLIC
		external/glad/include
)

# =========================
# Executable
# =========================
set(SOURCES
		src/main.cpp
		src/Engine.cpp
		src/Shader.cpp
		src/Material.cpp
		src/Object.cpp
		src/Scene.cpp
		src/Transform.cpp
		src/Mesh.cpp
		src/Utils/FileReader.cpp
)

add_executable(RenderingEngine ${SOURCES})

target_include_directories(RenderingEngine PRIVATE
		external/glad/include
)

target_link_libraries(RenderingEngine
		glfw
		glad
		glm
)

# =========================
# Platform-specific OpenGL
# =========================
if (APPLE)
	find_library(OpenGL_LIBRARY OpenGL)
	target_link_libraries(RenderingEngine ${OpenGL_LIBRARY})
elseif (WIN32)
	target_link_libraries(RenderingEngine opengl32)
else()
	target_link_libraries(RenderingEngine GL)
endif()

add_custom_command(TARGET RenderingEngine PRE_BUILD
		COMMAND robocopy ${PROJECT_SOURCE_DIR}/resources/ ${PROJECT_BINARY_DIR}/resources /E /NS /NC /NFL /NDL /NP /NJH /NJS  || cmd /c "exit /b 0")