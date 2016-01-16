/****************************************************************************
**
** Copyright (c) 2011 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Yoann Lopes (yoann.lopes@nokia.com)
**
** This file is part of the MeeSpot project.
** 
** Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions
** are met:
** 
** Redistributions of source code must retain the above copyright notice,
** this list of conditions and the following disclaimer.
** 
** Redistributions in binary form must reproduce the above copyright
** notice, this list of conditions and the following disclaimer in the
** documentation and/or other materials provided with the distribution.
** 
** Neither the name of Nokia Corporation and its Subsidiary(-ies) nor the names of its
** contributors may be used to endorse or promote products derived from
** this software without specific prior written permission.
** 
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
** FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
** TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
** PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
** LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
** NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
** SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**
** If you have questions regarding the use of this file, please contact
** Nokia at qt-info@nokia.com.
**
****************************************************************************/

#include <QtQml/qqml.h>

#include "QtSpotify"
#include "qspotifyplugin.h"


static QObject *spotifySessionSingleton(QQmlEngine *engine, QJSEngine *scriptEngine)
{
    Q_UNUSED(engine)
    Q_UNUSED(scriptEngine)
    return QSpotifySession::instance();
}

void QSpotifyPlugin::initializeEngine(QQmlEngine *engine, const char *uri)
{
    Q_UNUSED(uri)
    engine->addImageProvider(QLatin1String("spotify"), new QSpotifyImageProvider);
}

void QSpotifyPlugin::registerTypes(const char *uri)
{
    Q_UNUSED(uri);

    qmlRegisterSingletonType<QSpotifySession>("QtSpotify", 1, 0, "SpotifySession", spotifySessionSingleton);
    qmlRegisterUncreatableType<QSpotifyUser>("QtSpotify", 1, 0, "SpotifyUser", QLatin1String("Retrieve it from the SpotifySession"));
    qmlRegisterUncreatableType<QSpotifyPlaylist>("QtSpotify", 1, 0, "SpotifyPlaylist", QLatin1String("Retrieve it from the SpotifySession"));
    qmlRegisterUncreatableType<QSpotifyTrack>("QtSpotify", 1, 0, "SpotifyTrack", QLatin1String("Retrieve it from the SpotifySession"));
    qmlRegisterUncreatableType<QSpotifyAlbum>("QtSpotify", 1, 0, "SpotifyAlbum", QLatin1String("Retrieve it from the SpotifySession"));
    qmlRegisterUncreatableType<QSpotifyArtist>("QtSpotify", 1, 0, "SpotifyArtist", QLatin1String("Retrieve it from the SpotifySession"));
    qmlRegisterUncreatableType<QSpotifyPlayQueue>("QtSpotify", 1, 0, "SpotifyPlayQueue", QLatin1String("Retrieve it from the SpotifySession"));
    qmlRegisterUncreatableType<QSpotifyTrackList>("QtSpotify", 1, 0, "QSpotifyTrackList", QLatin1String("Retrieve it from the SpotifySession"));
    qmlRegisterUncreatableType<QSpotifyArtistList>("QtSpotify", 1, 0, "QSpotifyArtistList", QLatin1String("Retrieve it from the SpotifySession"));
    qmlRegisterUncreatableType<QSpotifyAlbumList>("QtSpotify", 1, 0, "QSpotifyAlbumList", QLatin1String("Retrieve it from the SpotifySession"));
    qmlRegisterUncreatableType<QSpotifyPlaylistSearchList>("QtSpotify", 1, 0, "QSpotifyPlaylistSearchList", QLatin1String("Retrieve it from the SpotifySession"));

    qmlRegisterType<QSpotifySearch>("QtSpotify", 1, 0, "SpotifySearch");
    qmlRegisterType<QSpotifyAlbumBrowse>("QtSpotify", 1, 0, "SpotifyAlbumBrowse");
    qmlRegisterType<QSpotifyArtistBrowse>("QtSpotify", 1, 0, "SpotifyArtistBrowse");
    qmlRegisterType<QSpotifyToplist>("QtSpotify", 1, 0, "SpotifyToplist");

    qmlRegisterType<TrackListFilterModel>("QtSpotify", 1, 0,"TrackListFilterModel");
}
