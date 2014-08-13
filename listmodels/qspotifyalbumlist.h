#ifndef QSPOTIFYALBUMLIST_H
#define QSPOTIFYALBUMLIST_H

#include "../qspotifyalbum.h"
#include "listmodelbase.h"

class QSpotifyAlbumList : public ListModelBase<QSpotifyAlbum>
{
    Q_OBJECT
public:
    explicit QSpotifyAlbumList(QObject *parent = nullptr);

    enum Roles {
        IsAvailableRole = Qt::UserRole + 1,
        ArtistRole,
        NameRole,
        YearRole,
        TypeRole,
        SectionTypeRole,
        CoverIdRole
    };

    QVariant data(const QModelIndex &index, int role) const;
    QHash<int, QByteArray> roleNames() const { return m_roles; }

private:
    QHash<int, QByteArray> m_roles;
};

#endif // QSPOTIFYALBUMLIST_H
