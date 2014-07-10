
QT += network
CONFIG       += mobility
MOBILITY += multimedia systeminfo

INCLUDEPATH += $$PWD

SOURCES += ../libQtSpotify/qspotifysession.cpp \
    ../libQtSpotify/qspotifyuser.cpp \
    ../libQtSpotify/qspotifyobject.cpp \
    ../libQtSpotify/qspotifytrack.cpp \
    ../libQtSpotify/qspotifyplaylist.cpp \
    ../libQtSpotify/qspotifyplaylistcontainer.cpp \
    ../libQtSpotify/qspotifyplaylistsearchentry.cpp \
    ../libQtSpotify/qspotifytracklist.cpp \
    ../libQtSpotify/qspotifyartist.cpp \
    ../libQtSpotify/qspotifyalbum.cpp \
    ../libQtSpotify/qspotifyimageprovider.cpp \
    ../libQtSpotify/qspotifysearch.cpp \
    ../libQtSpotify/qspotifyplayqueue.cpp \
    ../libQtSpotify/qspotifyalbumbrowse.cpp \
    ../libQtSpotify/qspotifyartistbrowse.cpp \
    ../libQtSpotify/qspotifytoplist.cpp

HEADERS += ../libQtSpotify/qspotifysession.h \
    ../libQtSpotify/spotify_key.h \
    ../libQtSpotify/qspotifyuser.h \
    ../libQtSpotify/qspotifyobject.h \
    ../libQtSpotify/qspotifytrack.h \
    ../libQtSpotify/qspotifyplaylist.h \
    ../libQtSpotify/qspotifyplaylistcontainer.h \
    ../libQtSpotify/qspotifyplaylistsearchentry.h \
    ../libQtSpotify/qspotifytracklist.h \
    ../libQtSpotify/QtSpotify \
    ../libQtSpotify/qspotify_qmlplugin.h \
    ../libQtSpotify/qspotifyartist.h \
    ../libQtSpotify/qspotifyalbum.h \
    ../libQtSpotify/qspotifyimageprovider.h \
    ../libQtSpotify/qspotifysearch.h \
    ../libQtSpotify/qspotifyplayqueue.h \
    ../libQtSpotify/qspotifyalbumbrowse.h \
    ../libQtSpotify/qspotifyartistbrowse.h \
    ../libQtSpotify/qspotifytoplist.h \
    ../libQtSpotify/qspotifyevents.h

QMAKE_CXXFLAGS += -std=c++0x

INCLUDEPATH += $$PWD/../libspotify/include
LIBS += -L$$PWD/../libspotify/lib -lspotify

INCLUDEPATH += /usr/include/resource/qt5
PKGCONFIG += libresourceqt5






