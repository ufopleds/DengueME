#-------------------------------------------------
#
# Project created by QtCreator 2013-10-31T12:52:41
#
#-------------------------------------------------

QT += core xml network
QT += help
QT += widgets
QT += core

TARGET = dengueme
TEMPLATE = app
TRANSLATIONS = portuguese.ts

help.commands += $$[QT_INSTALL_BINS]/qcollectiongenerator help/dengueme.qhcp

QMAKE_EXTRA_TARGETS += help

target.path = /usr/local/bin

models.path = /usr/local/share/dengueme/Models
models.files = Models/*

shortcut.path = /usr/share/applications
shortcut.files = DengueME.desktop

INCLUDEPATH += quazip/zlib-1.2.11
LIBS += -Lquazip/zlib-1.2.11 -lz
INCLUDEPATH += quazip/quazip-0.7/quazip
LIBS += -Lquazip/quazip-0.7/quazip/release -lquazip

INSTALLS = target models shortcut

SOURCES += main.cpp \
    mainwindow.cpp \
    dengueme.cpp \
    options.cpp \
    about.cpp \
    changeworkspace.cpp \
    newmodel.cpp \
    editor/components/constraints/doublespinboxrules.cpp \
    editor/components/constraints/spinboxrules.cpp \
    builder/modelbuilder.cpp \
    workspaceview.cpp \
    dirmodel.cpp \
    workspacemodel.cpp \
    editor/group.cpp \
    editor/grouplist.cpp \
    builder/builderdirmodel.cpp \
    editor/components/field.cpp \
    editor/components/importcsv.cpp \
    editor/components/constraints/comboboxrules.cpp \
    editor.cpp \
    editor/views/modelview.cpp \
    descriptionwindow.cpp \
    openmodel.cpp \
    syncmodels.cpp \
    downloadmanager.cpp \
    downloadhttp.cpp \
    editor/observerslist.cpp \
    editor/chartgroup.cpp \
    editor/components/chartfield.cpp \
    editor/textscreengroup.cpp \
    editor/visualtablegroup.cpp \
    editor/components/logfield.cpp \
    editor/components/textscreenfield.cpp \
    editor/components/visualtablefield.cpp \
    editor/loggroup.cpp \
    builder/modeldocument.cpp \
    calculator/lepton/CompiledExpression.cpp \
    calculator/lepton/ExpressionProgram.cpp \
    calculator/lepton/ExpressionTreeNode.cpp \
    calculator/lepton/Operation.cpp \
    calculator/lepton/ParsedExpression.cpp \
    calculator/lepton/Parser.cpp \
    calculator/calculator.cpp \
    newproject.cpp \
    rename.cpp \
    builder/newmodelbuilder.cpp

HEADERS  += \
    mainwindow.h \
    dengueme.h \
    options.h \
    about.h \
    changeworkspace.h \
    newmodel.h \
    editor/components/constraints/doublespinboxrules.h \
    editor/components/constraints/spinboxrules.h \
    builder/modelbuilder.h \
    workspaceview.h \
    dirmodel.h \
    workspacemodel.h \
    editor/components/field.h \
    editor/group.h \
    editor/grouplist.h \
    builder/builderdirmodel.h \
    editor/components/importcsv.h \
    editor/component.h \
    editor/components/constraints/comboboxrules.h \
    editor.h \
    editor/views/modelview.h \
    descriptionwindow.h \
    openmodel.h \
    syncmodels.h \
    downloadmanager.h \
    downloadhttp.h \
    editor/observerslist.h \
    editor/chartgroup.h \
    editor/components/chartfield.h \
    editor/textscreengroup.h \
    editor/visualtablegroup.h \
    editor/components/logfield.h \
    editor/components/textscreenfield.h \
    editor/components/visualtablefield.h \
    editor/loggroup.h \
    builder/modeldocument.h \
    calculator/lepton/CompiledExpression.h \
    calculator/lepton/CustomFunction.h \
    calculator/lepton/Exception.h \
    calculator/lepton/ExpressionProgram.h \
    calculator/lepton/ExpressionTreeNode.h \
    calculator/lepton/Lepton.h \
    calculator/lepton/Operation.h \
    calculator/lepton/ParsedExpression.h \
    calculator/lepton/Parser.h \
    calculator/lepton/windowsIncludes.h \
    calculator/calculator.h \
    iconsFontAwesome.h \
    newproject.h \
    rename.h \
    builder/newmodelbuilder.h

FORMS    += \
    mainwindow.ui \
    editor/components/database.ui \
    options.ui \
    about.ui \
    editor/components/constraints/doublespinboxrules.ui \
    editor/components/constraints/spinboxrules.ui \
    builder/modelbuilder.ui \
    editor/components/field.ui \
    editor/group.ui \
    editor/grouplist.ui \
    editor/components/importcsv.ui \
    editor/components/constraints/comboboxrules.ui \
    editor.ui \
    editor/views/modelview.ui \
    descriptionwindow.ui \
    openmodel.ui \
    syncmodels.ui \
    editor/observerslist.ui \
    editor/components/chartfield.ui \
    editor/components/logfield.ui \
    editor/components/textscreenfield.ui \
    editor/components/visualtablefield.ui \
    editor/components/vttsfield.ui \
    builder/modeldocument.ui \
    calculator/calculator.ui \
    newproject.ui \
    rename.ui \
    changeworkspace.ui \
    newmodel.ui \
    builder/newmodelbuilder.ui

RESOURCES += \
    Resource.qrc

RC_FILE = DengueME.rc
