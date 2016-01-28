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


#ifndef QSPOTIFYTRACK_H
#define QSPOTIFYTRACK_H

#include <memory>

#include <QtCore/QDateTime>
#include <QtCore/QVector>

#include <libspotify/api.h>

#include "qspotifyobject.h"

class QSpotifyAlbum;
class QSpotifyArtist;
class QSpotifyPlaylist;
class QSpotifyTrackList;

class QSpotifyTrack : public QSpotifyObject, public std::enable_shared_from_this<QSpotifyTrack>
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name NOTIFY trackDataChanged)
    Q_PROPERTY(QString artists READ artists NOTIFY trackDataChanged)
    Q_PROPERTY(QString album READ album NOTIFY trackDataChanged)
    Q_PROPERTY(QString albumCoverId READ albumCoverId NOTIFY trackDataChanged)
    Q_PROPERTY(int discNumber READ discNumber NOTIFY trackDataChanged)
    Q_PROPERTY(QString duration READ durationString NOTIFY trackDataChanged)
    Q_PROPERTY(int durationMs READ duration NOTIFY trackDataChanged)
    Q_PROPERTY(TrackError error READ error NOTIFY trackDataChanged)
    Q_PROPERTY(int discIndex READ discIndex NOTIFY trackDataChanged)
    Q_PROPERTY(bool isAvailable READ isAvailable NOTIFY isAvailableChanged)
    Q_PROPERTY(bool isStarred READ isStarred WRITE setIsStarred NOTIFY isStarredChanged)
    Q_PROPERTY(int popularity READ popularity NOTIFY trackDataChanged)
    Q_PROPERTY(bool isCurrentPlayingTrack READ isCurrentPlayingTrack NOTIFY isCurrentPlayingTrackChanged)
    Q_PROPERTY(bool seen READ seen WRITE setSeen NOTIFY seenChanged)
    Q_PROPERTY(QString creator READ creator NOTIFY trackDataChanged)
    Q_PROPERTY(QDateTime creationDate READ creationDate NOTIFY trackDataChanged)
    Q_PROPERTY(QSpotifyAlbum *albumObject READ albumObject NOTIFY trackDataChanged)
    Q_PROPERTY(QSpotifyArtist *artistObject READ artistObject NOTIFY trackDataChanged)
    Q_PROPERTY(OfflineStatus offlineStatus READ offlineStatus NOTIFY offlineStatusChanged)
    Q_PROPERTY(QString url READ url NOTIFY trackDataChanged)
    Q_ENUMS(TrackError)
    Q_ENUMS(OfflineStatus)
public:
    enum TrackError {
        Ok = SP_ERROR_OK,
        IsLoading = SP_ERROR_IS_LOADING,
        OtherPermanent = SP_ERROR_OTHER_PERMANENT
    };

    enum OfflineStatus {
        No = SP_TRACK_OFFLINE_NO,
        Waiting = SP_TRACK_OFFLINE_WAITING,
        Downloading = SP_TRACK_OFFLINE_DOWNLOADING,
        Yes = SP_TRACK_OFFLINE_DONE,
        Error = SP_TRACK_OFFLINE_ERROR,
        DoneExpired = SP_TRACK_OFFLINE_DONE_EXPIRED,
        LimitExceeded = SP_TRACK_OFFLINE_LIMIT_EXCEEDED,
        DoneResync = SP_TRACK_OFFLINE_DONE_RESYNC
    };

    ~QSpotifyTrack();

    bool isLoaded();

    QString artists() const;
    QString album() const;
    QString albumCoverId() const;
    int numArtists() const { return m_numArtists; }
    int discNumber() const { return m_discNumber; }
    int duration() const { return m_duration; }
    QString durationString() const { return m_durationString; }
    TrackError error() const { return m_error; }
    int discIndex() const { return m_discIndex; }
    bool isAvailable() const;
    bool isStarred() const;
    void setIsStarred(bool v);
    QString name() const { return m_name; }
    int popularity() const { return m_popularity; }
    QSpotifyAlbum *albumObject() const { return m_album.get(); }
    QSpotifyArtist *artistObject() const { return m_artist.get(); }
    bool seen() const { return m_seen; }
    void setSeen(bool s);
    QString creator() const { return m_creator; }
    QDateTime creationDate() const { return m_creationDate; }
    OfflineStatus offlineStatus() const { return m_offlineStatus; }
    QString url() const { return m_url; }

    bool isCurrentPlayingTrack() const { return m_isCurrentPlayingTrack; }

    bool isAvailableOffline() const;

    sp_track *sptrack() const { return m_sp_track; }

    void updateSeen(bool s);

    void destroy();

public Q_SLOTS:
    void pause();
    void resume();
    void stop();
    void seek(int offset);
    void enqueue();
    void removeFromPlaylist();

Q_SIGNALS:
    void isCurrentPlayingTrackChanged();
    void trackDataChanged();
    void isStarredChanged();
    void seenChanged();
    void isAvailableChanged();
    void offlineStatusChanged();

protected:
    bool updateData();

private Q_SLOTS:
    void onSessionCurrentTrackChanged();
    void onStarredListTracksAdded(QVector<sp_track *>);
    void onStarredListTracksRemoved(QVector<sp_track *>);
    void onSessionOfflineModeChanged();

private:
    QSpotifyTrack(sp_track *track, QSpotifyPlaylist *playlist);

    sp_track *m_sp_track;
    QSpotifyPlaylist *m_playlist;

    std::shared_ptr<QSpotifyAlbum> m_album;
    std::shared_ptr<QSpotifyArtist> m_artist;
    QString m_albumString;
    QString m_artistsString;
    int m_discNumber;
    int m_duration;
    QString m_durationString;
    TrackError m_error;
    int m_discIndex;
    bool m_isAvailable;
    QString m_name;
    int m_numArtists;
    int m_popularity;
    bool m_seen;
    QString m_creator;
    QDateTime m_creationDate;
    OfflineStatus m_offlineStatus;
    QString m_url;

    bool m_isCurrentPlayingTrack;

    friend class QSpotifyPlaylist;
    friend class QSpotifySession;
    friend class QSpotifySearch;
    friend class QSpotifyPlayQueue;
    friend class QSpotifyUser;
    friend class QSpotifyAlbumBrowse;
    friend class QSpotifyArtistBrowse;
    friend class QSpotifyToplist;

    friend class QSpotifyCacheManager;
};

#endif // QSPOTIFYTRACK_H
