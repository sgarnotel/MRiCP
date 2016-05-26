HEADERS += \
    headers.h \
    mainwindow.h \
    qcustomplot.h \
    dialogflowlocation.h \
    dialogsettings.h \
    dialogexportdata.h \
    dialogexportreport.h \
    dialogimportflowexplorer.h

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    qcustomplot.cpp \
    functions.cpp \
    mainwindow_icp.cpp \
    io.cpp \
    mainwindow_patient.cpp \
    mainwindow_mri.cpp \
    mainwindow_epi.cpp \
    dialogflowlocation.cpp \
    dialogsettings.cpp \
    settings.cpp \
    mainwindow_mri_spinal.cpp \
    mainwindow_mri_intracranial.cpp \
    mainwindow_mri_spinal_intracranial.cpp \
    mainwindow_compliance.cpp \
    mainwindow_mri_spectrum.cpp \
    mainwindow_mri_all.cpp \
    mainwindow_statistics.cpp \
    mainwindow_transfertfunction.cpp \
    dialogexportdata.cpp \
    dialogexportreport.cpp \
    dialogimportflowexplorer.cpp

QT += \
    widgets \
    core \
    printsupport

linux:LIBS += -lfftw3
win32:LIBS += -LC:/fftw3-32/ -lfftw3-3
win32:INCLUDEPATH += C:/fftw3-32


