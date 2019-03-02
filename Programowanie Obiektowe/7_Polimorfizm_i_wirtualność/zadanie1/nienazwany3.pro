TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    person.cpp \
    teacher.cpp \
    student.cpp

HEADERS += \
    person.hpp \
    teacher.hpp \
    student.hpp
