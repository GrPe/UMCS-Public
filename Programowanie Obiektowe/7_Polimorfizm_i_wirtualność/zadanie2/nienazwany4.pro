TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    regularpolyhedron.cpp \
    regularprism.cpp \
    regularpyramid.cpp

HEADERS += \
    regularpolyhedron.hpp \
    regularprism.hpp \
    regularpyramid.hpp
