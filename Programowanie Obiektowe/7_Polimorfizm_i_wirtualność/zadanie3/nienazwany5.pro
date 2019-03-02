TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    triangle.cpp \
    rectangle.cpp

HEADERS += \
    polygon.hpp \
    triangle.hpp \
    rectangle.hpp
