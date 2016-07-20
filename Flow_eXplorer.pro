HEADERS += \
    coord.h \
    headers.hpp \
    mainwindow.h \
    qcustomplot.h \
    dialogcompare.h \
    TextDef.h \
    dialogstats.h \
    dialogsettings.h \
    CssDef.h \
    ImgDef.h \
    TextDef__Stats.h \
    TextDef__Settings.h \
    TextDef__Compare.h \
    TextDef__Flow.h \
    TextDef__New.h \
    TextDef__Error.h \
    dialogdelete.h \
    dialogmodify.h \
    TextDef__Delete.h \
    TextDef__Modify.h \
    dialogquality.h \
    TextDef__Quality.h \
    ParamDef.h \
    dialognew.h \
    dialogflow.h \
    dialogflowconstructor.h \
    dialogflowepi.h \
    dialogflowconstructorepi.h \
    dialogabout.h

SOURCES += \
    coord.cpp \
    function.cpp \
    inout.cpp \
    main.cpp \
    mainwindow.cpp \
    qcustomplot.cpp \
    mainwindow_ICP.cpp \
    mainwindow_MRI.cpp \
    dialogcompare.cpp \
    dialogstats.cpp \
    dialogsettings.cpp \
    mainwindow_EPI.cpp \
    mainwindow_COMP.cpp \
    mainwindow_STAT.cpp \
    mainwindow_HELP.cpp \
    dialogdelete.cpp \
    dialogmodify.cpp \
    dialogquality.cpp \
    dialognew.cpp \
    dialogflow.cpp \
    dialogflowconstructor.cpp \
    dialogflowepi.cpp \
    dialogflowconstructorepi.cpp \
    dialogabout.cpp \
    kmeans.cpp

QT += \
    widgets \
    core \
    printsupport

#LINUX & MAC
LIBS += -lfftw3

#WINDOWS
#LIBS += \
#    -LC:/fftw3-32/ -lfftw3-3

#INCLUDEPATH += \
#    C:/fftw3-32
