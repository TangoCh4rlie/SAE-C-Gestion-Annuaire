cmake_minimum_required(VERSION 3.23)
project(c_project_sae C)

set(CMAKE_C_STANDARD 99)

set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99 -Wall")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

include_directories(fichiers_struc)

add_executable(c_project_sae
        #        fichiers_struc/function.c
        #        fichiers_struc/SAE_anuaire.c
        #        fichiers_struc/SAE_anuaire.h
        #        fichiers_struc/tools.c
        #        fichiers_struc/elouan_fuctions.c
        #        fichiers_struc/erwan_functions.c
        #        fichiers_struc/nabile_functions.c
        rendu_api/src/api_sae.c
        rendu_api/headers/api_sae.h
        rendu_api/src/tools.c
        rendu_api/src/lecture.c
        rendu_api/main.c
        rendu_api/src/ecriture.c
        rendu_api/headers/lecture.h
        rendu_api/headers/ecriture.h
        rendu_api/headers/tools.h rendu_api/src/menu.c rendu_api/headers/menu.h)