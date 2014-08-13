
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
    ../libQtSpotify/qspotifytoplist.cpp \
    ../libQtSpotify/listmodels/listmodelbase.cpp \
    ../libQtSpotify/listmodels/tracklistfiltermodel.cpp \
    ../libQtSpotify/qspotifyaudiothreadworker.cpp \
    ../libQtSpotify/qspotifyevents.cpp \
    ../libQtSpotify/listmodels/qspotifyartistlist.cpp \
    ../libQtSpotify/listmodels/qspotifyalbumlist.cpp

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
    ../libQtSpotify/qspotifyevents.h \
    ../libQtSpotify/listmodels/listmodelbase.h \
    ../libQtSpotify/listmodels/tracklistfiltermodel.h \
    ../libQtSpotify/shared_ptr.h \
    ../libQtSpotify/qspotifyaudiothreadworker.h \
    ../libQtSpotify/listmodels/qspotifyartistlist.h \
    ../libQtSpotify/listmodels/qspotifyalbumlist.h

QMAKE_CXXFLAGS += -std=c++0x

INCLUDEPATH += ../libspotify/include
LIBS += -L$$PWD/../libspotify/lib -lspotify
