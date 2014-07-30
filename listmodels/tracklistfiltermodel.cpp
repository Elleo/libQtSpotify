#include "tracklistfiltermodel.h"

#include "../qspotifytrack.h"

TrackListFilterModel::TrackListFilterModel(QObject *parent)
    : QSortFilterProxyModel(parent)
{
    setDynamicSortFilter(true);
    setFilterCaseSensitivity(Qt::CaseInsensitive);
    setFilterRole(QSpotifyTrack::NameRole);
    setSortRole(QSpotifyTrack::NameRole);
}

int TrackListFilterModel::getSourceIndex(const int idx)
{
    return mapToSource(index(idx, 0)).row();
}

bool TrackListFilterModel::filterAcceptsRow(int source_row, const QModelIndex &source_parent) const
{
    QModelIndex idx  = sourceModel()->index(source_row, 0, source_parent);
    bool ret = (sourceModel()->data(idx, QSpotifyTrack::ErrorRole) == QSpotifyTrack::Ok && (
                    sourceModel()->data(idx, QSpotifyTrack::NameRole).toString().contains(filterRegExp()) ||
                    sourceModel()->data(idx, QSpotifyTrack::ArtistsRole).toString().contains(filterRegExp()) ||
                    sourceModel()->data(idx, QSpotifyTrack::AlbumRole).toString().contains(filterRegExp())));
    return ret;
}
