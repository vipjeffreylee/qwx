QT_VERSION = $$[QT_VERSION]
QT_VERSION = $$split(QT_VERSION, ".")
QT_VER_MAJ = $$member(QT_VERSION, 0)
QT_VER_MIN = $$member(QT_VERSION, 1)

lessThan(QT_VER_MAJ, 5) | lessThan(QT_VER_MIN, 2) | {
	error(qwx is only tested under Qt 5.2!)
}

QT += qml quick network xml
QMAKE_CXXFLAGS += -std=c++11 -Werror
!android: !ios: !blackberry: qtHaveModule(widgets): QT += widgets
TARGET = qwx
CODECFORSRC = UTF-8

include(src/src.pri)

OTHER_FILES += \
    qml/main.qml    \
    qml/LoginView.qml   \
    qml/ContactListView.qml

RESOURCES += \
    resources.qrc

!isEmpty(QWX_DEBUG) {
    DEFINES += QWX_DEBUG
}

unix {
    #VARIABLES
    isEmpty(PREFIX) {
        PREFIX = /usr
    }
    BINDIR = $$PREFIX/bin
    DATADIR = $$PREFIX/share

    DEFINES += PREFIX=\\\"$$PREFIX\\\"
    DEFINES += TARGET=\\\"$$TARGET\\\"
    DEFINES += DATADIR=\\\"$$DATADIR\\\" PKGDATADIR=\\\"$$PKGDATADIR\\\"

    #MAKE INSTALL
    INSTALLS += target desktop

    target.path = $$BINDIR

    desktop.path = $$DATADIR/applications
    desktop.files += $${TARGET}.desktop
}
