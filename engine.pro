TEMPLATE = app
CONFIG += windows c++11
CONFIG -= qt
CONFIG -= app_bundle

LIBS += -lopengl32

LIBS += -L$$PWD/deps/freeglut/lib/x64 -lfreeglut
LIBS += -L$$PWD/deps/libpng/lib -lpng
LIBS += -L$$PWD/deps/zlib/lib -lz

INCLUDEPATH += deps/freeglut/include
INCLUDEPATH += deps/libpng/include
INCLUDEPATH += deps/zlib/include

SOURCES += \
    src/main.cpp \
    src/animation.cpp \
    src/engine.cpp \
    src/gameobject.cpp \
    src/image.cpp \
    src/render.cpp \
    src/scene.cpp \
    src/strategies/freeglutrenderstrategy.cpp

HEADERS += \
    src/animation.h \
    src/engine.h \
    src/gameobject.h \
    src/image.h \
    src/render.h \
    src/scene.h \
    src/strategies/freeglutrenderstrategy.h
