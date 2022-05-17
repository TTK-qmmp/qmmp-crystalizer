include($$PWD/../../plugins.pri)

TARGET = $$PLUGINS_PREFIX/Effect/crystalizer

HEADERS += crystalizerplugin.h \
           effectcrystalizerfactory.h \
           settingsdialog.h

SOURCES += crystalizerplugin.cpp \
           effectcrystalizerfactory.cpp \
           settingsdialog.cpp

FORMS += settingsdialog.ui

unix{
    target.path = $$PLUGIN_DIR/Effect
    INSTALLS += target
}
