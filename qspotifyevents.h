#ifndef QSPOTIFYEVENTS_H
#define QSPOTIFYEVENTS_H

enum EventTypes {
    NotifyMainThreadEventType = QEvent::User,
    ConnectionErrorEventType = QEvent::User + 1,
    MetaDataEventType = QEvent::User + 2,
    StreamingStartedEventType = QEvent::User + 3,
    EndOfTrackEventType = QEvent::User + 4,
    StopEventType = QEvent::User + 5,
    ResumeEventType = QEvent::User + 6,
    SuspendEventType = QEvent::User + 7,
    AudioStopEventType = QEvent::User + 8,
    ResetBufferEventType = QEvent::User + 9,
    TrackProgressEventType = QEvent::User + 10,
    SendImageRequestEventType = QEvent::User + 11,
    ReceiveImageRequestEventType = QEvent::User + 12,
    PlayTokenLostEventType = QEvent::User + 13,
    LoggedInEventType = QEvent::User + 14,
    LoggedOutEventType = QEvent::User + 15,
    OfflineErrorEventType = QEvent::User + 16,
    ScrobbleLoginErrorEventType = QEvent::User + 17
};

class QSpotifyConnectionErrorEvent : public QEvent
{
public:
    QSpotifyConnectionErrorEvent(sp_error error, const QString &message)
        : QEvent(Type(ConnectionErrorEventType))
        , m_error(error)
        , m_message(message)
    { }

    sp_error error() const { return m_error; }
    QString message() const { return m_message; }

private:
    sp_error m_error;
    QString m_message;
};


class QSpotifyStreamingStartedEvent : public QEvent
{
public:
    QSpotifyStreamingStartedEvent(int channels, int sampleRate)
        : QEvent(Type(StreamingStartedEventType))
        , m_channels(channels)
        , m_sampleRate(sampleRate)
    { }

    int channels() const { return m_channels; }
    int sampleRate() const { return m_sampleRate; }

private:
    int m_channels;
    int m_sampleRate;
};


class QSpotifyTrackProgressEvent : public QEvent
{
public:
    QSpotifyTrackProgressEvent(int delta)
        : QEvent(Type(TrackProgressEventType))
        , m_delta(delta)
    { }

    int delta() const { return m_delta; }

private:
    int m_delta;
};

class QSpotifyRequestImageEvent : public QEvent
{
public:
    QSpotifyRequestImageEvent(const QString &id)
        : QEvent(Type(SendImageRequestEventType))
        , m_id(id)
    { }

    QString imageId() const { return m_id; }

private:
    QString m_id;
};

class QSpotifyReceiveImageEvent : public QEvent
{
public:
    QSpotifyReceiveImageEvent(sp_image *image)
        : QEvent(Type(ReceiveImageRequestEventType))
        , m_image(image)
    { }

    sp_image *image() const { return m_image; }

private:
    sp_image *m_image;
};

class QSpotifyOfflineErrorEvent : public QEvent
{
public:
    QSpotifyOfflineErrorEvent(sp_error error, const QString &message)
        : QEvent(Type(OfflineErrorEventType))
        , m_error(error)
        , m_message(message)
    { }

    sp_error error() const { return m_error; }
    QString message() const { return m_message; }

private:
    sp_error m_error;
    QString m_message;
};

#endif // QSPOTIFYEVENTS_H
