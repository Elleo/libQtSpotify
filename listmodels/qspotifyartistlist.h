#ifndef QSPOTIFYARTISTLIST_H
#define QSPOTIFYARTISTLIST_H

#include "../qspotifyartist.h"
#include "listmodelbase.h"

class QSpotifyArtistList : public ListModelBase<QSpotifyArtist>
{
    Q_OBJECT
public:
    explicit QSpotifyArtistList(QObject *parent = nullptr);

    enum Roles {
        NameRole = Qt::UserRole+1,
        PictureIdRole
    };

    QVariant data(const QModelIndex &index, int role) const;
    QHash<int, QByteArray> roleNames() const { return m_roles; }


private:
    QHash<int, QByteArray> m_roles;
};

#endif // QSPOTIFYARTISTLIST_H
