#ifndef THREADSAFECALLS_H
#define THREADSAFECALLS_H

#include <QtCore/QMutex>
#include <QtCore/QMutexLocker>
#include <QtCore/QDebug>

#include <libspotify/api.h>

static QMutex f_mutex;

static const char* s_sp_error_message(sp_error error) {
    qDebug() << "static const char* s_sp_error_message(sp_error error) {";
    QMutexLocker lock(&f_mutex);
    return sp_error_message(error);
}
static sp_error s_sp_session_release(sp_session *sess) {
    qDebug() << "static sp_error s_sp_session_release(sp_session *sess) {";
    QMutexLocker lock(&f_mutex);
    return sp_session_release(sess);
}
static sp_error s_sp_session_login(sp_session *session, const char *username, const char *password, bool remember_me, const char *blob) {
    qDebug() << "static sp_error s_sp_session_login(sp_session *session, const char *username, const char *password, bool remember_me, const char *blob) {";
    QMutexLocker lock(&f_mutex);
    return sp_session_login(session, username, password, remember_me, blob);
}
static sp_error s_sp_session_relogin(sp_session *session) {
    qDebug() << "static sp_error s_sp_session_relogin(sp_session *session) {";
    QMutexLocker lock(&f_mutex);
    return sp_session_relogin(session);
}
static int s_sp_session_remembered_user(sp_session *session, char *buffer, size_t buffer_size) {
    qDebug() << "static int s_sp_session_remembered_user(sp_session *session, char *buffer, size_t buffer_size) {";
    QMutexLocker lock(&f_mutex);
    return sp_session_remembered_user(session, buffer, buffer_size);
}
static const char * s_sp_session_user_name(sp_session *session) {
    qDebug() << "static const char * s_sp_session_user_name(sp_session *session) {";
    QMutexLocker lock(&f_mutex);
    return sp_session_user_name(session);
}
static sp_error s_sp_session_forget_me(sp_session *session) {
    qDebug() << "static sp_error s_sp_session_forget_me(sp_session *session) {";
    QMutexLocker lock(&f_mutex);
    return sp_session_forget_me(session);
}
static sp_user * s_sp_session_user(sp_session *session) {
    qDebug() << "static sp_user * s_sp_session_user(sp_session *session) {";
    QMutexLocker lock(&f_mutex);
    return sp_session_user(session);
}
static sp_error s_sp_session_logout(sp_session *session) {
    qDebug() << "static sp_error s_sp_session_logout(sp_session *session) {";
    QMutexLocker lock(&f_mutex);
    return sp_session_logout(session);
}
static int s_sp_session_num_unaccepted_licenses(sp_session *session) {
    qDebug() << "static int s_sp_session_num_unaccepted_licenses(sp_session *session) {";
    QMutexLocker lock(&f_mutex);
    return sp_session_num_unaccepted_licenses(session);
}
static const char * s_sp_session_unaccepted_license_id(sp_session *session, int license_id_index) {
    qDebug() << "static const char * s_sp_session_unaccepted_license_id(sp_session *session, int license_id_index) {";
    QMutexLocker lock(&f_mutex);
    return sp_session_unaccepted_license_id(session, license_id_index);
}
static const char * s_sp_session_url_for_license(sp_session *session, const char *license_id) {
    qDebug() << "static const char * s_sp_session_url_for_license(sp_session *session, const char *license_id) {";
    QMutexLocker lock(&f_mutex);
    return sp_session_url_for_license(session, license_id);
}
static sp_error s_sp_session_accept_licenses(sp_session *session, const char **license_ids, int license_id_count) {
    qDebug() << "static sp_error s_sp_session_accept_licenses(sp_session *session, const char **license_ids, int license_id_count) {";
    QMutexLocker lock(&f_mutex);
    return sp_session_accept_licenses(session, license_ids, license_id_count);
}
static sp_error s_sp_session_flush_caches(sp_session *session) {
    qDebug() << "static sp_error s_sp_session_flush_caches(sp_session *session) {";
    QMutexLocker lock(&f_mutex);
    return sp_session_flush_caches(session);
}
static sp_connectionstate s_sp_session_connectionstate(sp_session *session) {
    qDebug() << "static sp_connectionstate s_sp_session_connectionstate(sp_session *session) {";
    QMutexLocker lock(&f_mutex);
    return sp_session_connectionstate(session);
}
static void * s_sp_session_userdata(sp_session *session) {
    qDebug() << "static void * s_sp_session_userdata(sp_session *session) {";
    QMutexLocker lock(&f_mutex);
    return sp_session_userdata(session);
}
static sp_error s_sp_session_set_cache_size(sp_session *session, size_t size) {
    qDebug() << "static sp_error s_sp_session_set_cache_size(sp_session *session, size_t size) {";
    QMutexLocker lock(&f_mutex);
    return sp_session_set_cache_size(session, size);
}
static sp_error s_sp_session_process_events(sp_session *session, int *next_timeout) {
    qDebug() << "static sp_error s_sp_session_process_events(sp_session *session, int *next_timeout) {";
    QMutexLocker lock(&f_mutex);
    return sp_session_process_events(session, next_timeout);
}
static sp_error s_sp_session_player_load(sp_session *session, sp_track *track) {
    qDebug() << "static sp_error s_sp_session_player_load(sp_session *session, sp_track *track) {";
    QMutexLocker lock(&f_mutex);
    return sp_session_player_load(session, track);
}
static sp_error s_sp_session_player_seek(sp_session *session, int offset) {
    qDebug() << "static sp_error s_sp_session_player_seek(sp_session *session, int offset) {";
    QMutexLocker lock(&f_mutex);
    return sp_session_player_seek(session, offset);
}
static sp_error s_sp_session_player_play(sp_session *session, bool play) {
    qDebug() << "static sp_error s_sp_session_player_play(sp_session *session, bool play) {";
    QMutexLocker lock(&f_mutex);
    return sp_session_player_play(session, play);
}
static sp_error s_sp_session_player_unload(sp_session *session) {
    qDebug() << "static sp_error s_sp_session_player_unload(sp_session *session) {";
    QMutexLocker lock(&f_mutex);
    return sp_session_player_unload(session);
}
static sp_error s_sp_session_player_prefetch(sp_session *session, sp_track *track) {
    qDebug() << "static sp_error s_sp_session_player_prefetch(sp_session *session, sp_track *track) {";
    QMutexLocker lock(&f_mutex);
    return sp_session_player_prefetch(session, track);
}
static sp_playlistcontainer * s_sp_session_playlistcontainer(sp_session *session) {
    qDebug() << "static sp_playlistcontainer * s_sp_session_playlistcontainer(sp_session *session) {";
    QMutexLocker lock(&f_mutex);
    return sp_session_playlistcontainer(session);
}
static sp_playlist * s_sp_session_inbox_create(sp_session *session) {
    qDebug() << "static sp_playlist * s_sp_session_inbox_create(sp_session *session) {";
    QMutexLocker lock(&f_mutex);
    return sp_session_inbox_create(session);
}
static sp_playlist * s_sp_session_starred_create(sp_session *session) {
    qDebug() << "static sp_playlist * s_sp_session_starred_create(sp_session *session) {";
    QMutexLocker lock(&f_mutex);
    return sp_session_starred_create(session);
}
static sp_playlist * s_sp_session_starred_for_user_create(sp_session *session, const char *canonical_username) {
    qDebug() << "static sp_playlist * s_sp_session_starred_for_user_create(sp_session *session, const char *canonical_username) {";
    QMutexLocker lock(&f_mutex);
    return sp_session_starred_for_user_create(session, canonical_username);
}
static sp_playlist * s_sp_session_toplist_for_user_create(sp_session *session, const char *canonical_username) {
    qDebug() << "static sp_playlist * s_sp_session_toplist_for_user_create(sp_session *session, const char *canonical_username) {";
    QMutexLocker lock(&f_mutex);
    return sp_session_toplist_for_user_create(session, canonical_username);
}
static sp_playlistcontainer * s_sp_session_publishedcontainer_for_user_create(sp_session *session, const char *canonical_username) {
    qDebug() << "static sp_playlistcontainer * s_sp_session_publishedcontainer_for_user_create(sp_session *session, const char *canonical_username) {";
    QMutexLocker lock(&f_mutex);
    return sp_session_publishedcontainer_for_user_create(session, canonical_username);
}
static sp_error s_sp_session_preferred_bitrate(sp_session *session, sp_bitrate bitrate) {
    qDebug() << "static sp_error s_sp_session_preferred_bitrate(sp_session *session, sp_bitrate bitrate) {";
    QMutexLocker lock(&f_mutex);
    return sp_session_preferred_bitrate(session, bitrate);
}
static sp_error s_sp_session_preferred_offline_bitrate(sp_session *session, sp_bitrate bitrate, bool allow_resync) {
    qDebug() << "static sp_error s_sp_session_preferred_offline_bitrate(sp_session *session, sp_bitrate bitrate, bool allow_resync) {";
    QMutexLocker lock(&f_mutex);
    return sp_session_preferred_offline_bitrate(session, bitrate, allow_resync);
}
static bool s_sp_session_get_volume_normalization(sp_session *session) {
    qDebug() << "static bool s_sp_session_get_volume_normalization(sp_session *session) {";
    QMutexLocker lock(&f_mutex);
    return sp_session_get_volume_normalization(session);
}
static sp_error s_sp_session_set_volume_normalization(sp_session *session, bool on) {
    qDebug() << "static sp_error s_sp_session_set_volume_normalization(sp_session *session, bool on) {";
    QMutexLocker lock(&f_mutex);
    return sp_session_set_volume_normalization(session, on);
}
static sp_error s_sp_session_set_private_session(sp_session *session, bool enabled) {
    qDebug() << "static sp_error s_sp_session_set_private_session(sp_session *session, bool enabled) {";
    QMutexLocker lock(&f_mutex);
    return sp_session_set_private_session(session, enabled);
}
static bool s_sp_session_is_private_session(sp_session *session) {
    qDebug() << "static bool s_sp_session_is_private_session(sp_session *session) {";
    QMutexLocker lock(&f_mutex);
    return sp_session_is_private_session(session);
}
static sp_error s_sp_session_set_scrobbling(sp_session *session, sp_social_provider provider, sp_scrobbling_state state) {
    qDebug() << "static sp_error s_sp_session_set_scrobbling(sp_session *session, sp_social_provider provider, sp_scrobbling_state state) {";
    QMutexLocker lock(&f_mutex);
    return sp_session_set_scrobbling(session, provider, state);
}
static sp_error s_sp_session_is_scrobbling(sp_session *session, sp_social_provider provider, sp_scrobbling_state* state) {
    qDebug() << "static sp_error s_sp_session_is_scrobbling(sp_session *session, sp_social_provider provider, sp_scrobbling_state* state) {";
    QMutexLocker lock(&f_mutex);
    return sp_session_is_scrobbling(session, provider, state);
}
static sp_error s_sp_session_is_scrobbling_possible(sp_session *session, sp_social_provider provider, bool* out) {
    qDebug() << "static sp_error s_sp_session_is_scrobbling_possible(sp_session *session, sp_social_provider provider, bool* out) {";
    QMutexLocker lock(&f_mutex);
    return sp_session_is_scrobbling_possible(session, provider, out);
}
static sp_error s_sp_session_set_social_credentials(sp_session *session, sp_social_provider provider, const char* username, const char* password) {
    qDebug() << "static sp_error s_sp_session_set_social_credentials(sp_session *session, sp_social_provider provider, const char* username, const char* password) {";
    QMutexLocker lock(&f_mutex);
    return sp_session_set_social_credentials(session,  provider, username, password);
}
static sp_error s_sp_session_set_connection_type(sp_session *session, sp_connection_type type) {
    qDebug() << "static sp_error s_sp_session_set_connection_type(sp_session *session, sp_connection_type type) {";
    QMutexLocker lock(&f_mutex);
    return sp_session_set_connection_type(session, type);
}
static sp_error s_sp_session_set_connection_rules(sp_session *session, sp_connection_rules rules) {
    qDebug() << "static sp_error s_sp_session_set_connection_rules(sp_session *session, sp_connection_rules rules) {";
    QMutexLocker lock(&f_mutex);
    return sp_session_set_connection_rules(session, rules);
}
static int s_sp_offline_tracks_to_sync(sp_session *session) {
    qDebug() << "static int s_sp_offline_tracks_to_sync(sp_session *session) {";
    QMutexLocker lock(&f_mutex);
    return sp_offline_tracks_to_sync(session);
}
static int s_sp_offline_num_playlists(sp_session *session) {
    qDebug() << "static int s_sp_offline_num_playlists(sp_session *session) {";
    QMutexLocker lock(&f_mutex);
    return sp_offline_num_playlists(session);
}
static bool s_sp_offline_sync_get_status(sp_session *session, sp_offline_sync_status *status) {
    qDebug() << "static bool s_sp_offline_sync_get_status(sp_session *session, sp_offline_sync_status *status) {";
    QMutexLocker lock(&f_mutex);
    return sp_offline_sync_get_status(session, status);
}
static int s_sp_offline_time_left(sp_session *session) {
    qDebug() << "static int s_sp_offline_time_left(sp_session *session) {";
    QMutexLocker lock(&f_mutex);
    return sp_offline_time_left(session);
}
static int s_sp_session_user_country(sp_session *session) {
    qDebug() << "static int s_sp_session_user_country(sp_session *session) {";
    QMutexLocker lock(&f_mutex);
    return sp_session_user_country(session);
}
static sp_link * s_sp_link_create_from_track(sp_track *track, int offset) {
    qDebug() << "static sp_link * s_sp_link_create_from_track(sp_track *track, int offset) {";
    QMutexLocker lock(&f_mutex);
    return sp_link_create_from_track(track, offset);
}
static sp_link * s_sp_link_create_from_album(sp_album *album) {
    qDebug() << "static sp_link * s_sp_link_create_from_album(sp_album *album) {";
    QMutexLocker lock(&f_mutex);
    return sp_link_create_from_album(album);
}
static sp_link * s_sp_link_create_from_album_cover(sp_album *album, sp_image_size size) {
    qDebug() << "static sp_link * s_sp_link_create_from_album_cover(sp_album *album, sp_image_size size) {";
    QMutexLocker lock(&f_mutex);
    return sp_link_create_from_album_cover(album, size);
}
static sp_link * s_sp_link_create_from_artist(sp_artist *artist) {
    qDebug() << "static sp_link * s_sp_link_create_from_artist(sp_artist *artist) {";
    QMutexLocker lock(&f_mutex);
    return sp_link_create_from_artist(artist);
}
static sp_link * s_sp_link_create_from_artist_portrait(sp_artist *artist, sp_image_size size) {
    qDebug() << "static sp_link * s_sp_link_create_from_artist_portrait(sp_artist *artist, sp_image_size size) {";
    QMutexLocker lock(&f_mutex);
    return sp_link_create_from_artist_portrait(artist, size);
}
static sp_link * s_sp_link_create_from_artistbrowse_portrait(sp_artistbrowse *arb, int index) {
    qDebug() << "static sp_link * s_sp_link_create_from_artistbrowse_portrait(sp_artistbrowse *arb, int index) {";
    QMutexLocker lock(&f_mutex);
    return sp_link_create_from_artistbrowse_portrait(arb, index);
}
static sp_link * s_sp_link_create_from_search(sp_search *search) {
    qDebug() << "static sp_link * s_sp_link_create_from_search(sp_search *search) {";
    QMutexLocker lock(&f_mutex);
    return sp_link_create_from_search(search);
}
static sp_link * s_sp_link_create_from_playlist(sp_playlist *playlist) {
    qDebug() << "static sp_link * s_sp_link_create_from_playlist(sp_playlist *playlist) {";
    QMutexLocker lock(&f_mutex);
    return sp_link_create_from_playlist(playlist);
}
static sp_link * s_sp_link_create_from_user(sp_user *user) {
    qDebug() << "static sp_link * s_sp_link_create_from_user(sp_user *user) {";
    QMutexLocker lock(&f_mutex);
    return sp_link_create_from_user(user);
}
static sp_link * s_sp_link_create_from_image(sp_image *image) {
    qDebug() << "static sp_link * s_sp_link_create_from_image(sp_image *image) {";
    QMutexLocker lock(&f_mutex);
    return sp_link_create_from_image(image);
}
static int s_sp_link_as_string(sp_link *link, char *buffer, int buffer_size) {
    qDebug() << "static int s_sp_link_as_string(sp_link *link, char *buffer, int buffer_size) {";
    QMutexLocker lock(&f_mutex);
    return sp_link_as_string(link, buffer, buffer_size);
}
static sp_linktype s_sp_link_type(sp_link *link) {
    qDebug() << "static sp_linktype s_sp_link_type(sp_link *link) {";
    QMutexLocker lock(&f_mutex);
    return sp_link_type(link);
}
static sp_track * s_sp_link_as_track(sp_link *link) {
    qDebug() << "static sp_track * s_sp_link_as_track(sp_link *link) {";
    QMutexLocker lock(&f_mutex);
    return sp_link_as_track(link);
}
static sp_track * s_sp_link_as_track_and_offset(sp_link *link, int *offset) {
    qDebug() << "static sp_track * s_sp_link_as_track_and_offset(sp_link *link, int *offset) {";
    QMutexLocker lock(&f_mutex);
    return sp_link_as_track_and_offset(link, offset);
}
static sp_album * s_sp_link_as_album(sp_link *link) {
    qDebug() << "static sp_album * s_sp_link_as_album(sp_link *link) {";
    QMutexLocker lock(&f_mutex);
    return sp_link_as_album(link);
}
static sp_artist * s_sp_link_as_artist(sp_link *link) {
    qDebug() << "static sp_artist * s_sp_link_as_artist(sp_link *link) {";
    QMutexLocker lock(&f_mutex);
    return sp_link_as_artist(link);
}
static sp_user * s_sp_link_as_user(sp_link *link) {
    qDebug() << "static sp_user * s_sp_link_as_user(sp_link *link) {";
    QMutexLocker lock(&f_mutex);
    return sp_link_as_user(link);
}
static sp_error s_sp_link_add_ref(sp_link *link) {
    qDebug() << "static sp_error s_sp_link_add_ref(sp_link *link) {";
    QMutexLocker lock(&f_mutex);
    return sp_link_add_ref(link);
}
static sp_error s_sp_link_release(sp_link *link) {
    qDebug() << "static sp_error s_sp_link_release(sp_link *link) {";
    QMutexLocker lock(&f_mutex);
    return sp_link_release(link);
}
static bool s_sp_track_is_loaded(sp_track *track) {
    qDebug() << "static bool s_sp_track_is_loaded(sp_track *track) {";
    QMutexLocker lock(&f_mutex);
    return sp_track_is_loaded(track);
}
static sp_error s_sp_track_error(sp_track *track) {
    qDebug() << "static sp_error s_sp_track_error(sp_track *track) {";
    QMutexLocker lock(&f_mutex);
    return sp_track_error(track);
}
static sp_track_offline_status s_sp_track_offline_get_status(sp_track *track) {
    qDebug() << "static sp_track_offline_status s_sp_track_offline_get_status(sp_track *track) {";
    QMutexLocker lock(&f_mutex);
    return sp_track_offline_get_status(track);
}
static sp_track_availability s_sp_track_get_availability(sp_session *session, sp_track *track) {
    qDebug() << "static sp_track_availability s_sp_track_get_availability(sp_session *session, sp_track *track) {";
    QMutexLocker lock(&f_mutex);
    return sp_track_get_availability(session, track);
}
static bool s_sp_track_is_local(sp_session *session, sp_track *track) {
    qDebug() << "static bool s_sp_track_is_local(sp_session *session, sp_track *track) {";
    QMutexLocker lock(&f_mutex);
    return sp_track_is_local(session, track);
}
static bool s_sp_track_is_autolinked(sp_session *session, sp_track *track) {
    qDebug() << "static bool s_sp_track_is_autolinked(sp_session *session, sp_track *track) {";
    QMutexLocker lock(&f_mutex);
    return sp_track_is_autolinked(session, track);
}
static sp_track * s_sp_track_get_playable(sp_session *session, sp_track *track) {
    qDebug() << "static sp_track * s_sp_track_get_playable(sp_session *session, sp_track *track) {";
    QMutexLocker lock(&f_mutex);
    return sp_track_get_playable(session, track);
}
static bool s_sp_track_is_placeholder(sp_track *track) {
    qDebug() << "static bool s_sp_track_is_placeholder(sp_track *track) {";
    QMutexLocker lock(&f_mutex);
    return sp_track_is_placeholder(track);
}
static bool s_sp_track_is_starred(sp_session *session, sp_track *track) {
    qDebug() << "static bool s_sp_track_is_starred(sp_session *session, sp_track *track) {";
    QMutexLocker lock(&f_mutex);
    return sp_track_is_starred(session, track);
}
static sp_error s_sp_track_set_starred(sp_session *session, sp_track *const*tracks, int num_tracks, bool star) {
    qDebug() << "static sp_error s_sp_track_set_starred(sp_session *session, sp_track *const*tracks, int num_tracks, bool star) {";
    QMutexLocker lock(&f_mutex);
    return sp_track_set_starred(session, tracks, num_tracks, star);
}
static int s_sp_track_num_artists(sp_track *track) {
    qDebug() << "static int s_sp_track_num_artists(sp_track *track) {";
    QMutexLocker lock(&f_mutex);
    return sp_track_num_artists(track);
}
static sp_artist * s_sp_track_artist(sp_track *track, int index) {
    qDebug() << "static sp_artist * s_sp_track_artist(sp_track *track, int index) {";
    QMutexLocker lock(&f_mutex);
    return sp_track_artist(track, index);
}
static sp_album * s_sp_track_album(sp_track *track) {
    qDebug() << "static sp_album * s_sp_track_album(sp_track *track) {";
    QMutexLocker lock(&f_mutex);
    return sp_track_album(track);
}
static const char * s_sp_track_name(sp_track *track) {
    qDebug() << "static const char * s_sp_track_name(sp_track *track) {";
    QMutexLocker lock(&f_mutex);
    return sp_track_name(track);
}
static int s_sp_track_duration(sp_track *track) {
    qDebug() << "static int s_sp_track_duration(sp_track *track) {";
    QMutexLocker lock(&f_mutex);
    return sp_track_duration(track);
}
static int s_sp_track_popularity(sp_track *track) {
    qDebug() << "static int s_sp_track_popularity(sp_track *track) {";
    QMutexLocker lock(&f_mutex);
    return sp_track_popularity(track);
}
static int s_sp_track_disc(sp_track *track) {
    qDebug() << "static int s_sp_track_disc(sp_track *track) {";
    QMutexLocker lock(&f_mutex);
    return sp_track_disc(track);
}
static int s_sp_track_index(sp_track *track) {
    qDebug() << "static int s_sp_track_index(sp_track *track) {";
    QMutexLocker lock(&f_mutex);
    return sp_track_index(track);
}
static bool s_sp_track_has_explicit_lyrics(sp_track *track) {
    qDebug() << "static bool s_sp_track_has_explicit_lyrics(sp_track *track) {";
    QMutexLocker lock(&f_mutex);
    return sp_track_has_explicit_lyrics(track);
}
static sp_error s_sp_track_add_ref(sp_track *track) {
    qDebug() << "static sp_error s_sp_track_add_ref(sp_track *track) {";
    QMutexLocker lock(&f_mutex);
    return sp_track_add_ref(track);
}
static sp_error s_sp_track_release(sp_track *track) {
    qDebug() << "static sp_error s_sp_track_release(sp_track *track) {";
    QMutexLocker lock(&f_mutex);
    return sp_track_release(track);
}
static bool s_sp_album_is_loaded(sp_album *album) {
    qDebug() << "static bool s_sp_album_is_loaded(sp_album *album) {";
    QMutexLocker lock(&f_mutex);
    return sp_album_is_loaded(album);
}
static bool s_sp_album_is_available(sp_album *album) {
    qDebug() << "static bool s_sp_album_is_available(sp_album *album) {";
    QMutexLocker lock(&f_mutex);
    return sp_album_is_available(album);
}
static sp_artist * s_sp_album_artist(sp_album *album) {
    qDebug() << "static sp_artist * s_sp_album_artist(sp_album *album) {";
    QMutexLocker lock(&f_mutex);
    return sp_album_artist(album);
}
static const byte * s_sp_album_cover(sp_album *album, sp_image_size size) {
    qDebug() << "static const byte * s_sp_album_cover(sp_album *album, sp_image_size size) {";
    QMutexLocker lock(&f_mutex);
    return sp_album_cover(album, size);
}
static const char * s_sp_album_name(sp_album *album) {
    qDebug() << "static const char * s_sp_album_name(sp_album *album) {";
    QMutexLocker lock(&f_mutex);
    return sp_album_name(album);
}
static int s_sp_album_year(sp_album *album) {
    qDebug() << "static int s_sp_album_year(sp_album *album) {";
    QMutexLocker lock(&f_mutex);
    return sp_album_year(album);
}
static sp_albumtype s_sp_album_type(sp_album *album) {
    qDebug() << "static sp_albumtype s_sp_album_type(sp_album *album) {";
    QMutexLocker lock(&f_mutex);
    return sp_album_type(album);
}
static sp_error s_sp_album_add_ref(sp_album *album) {
    qDebug() << "static sp_error s_sp_album_add_ref(sp_album *album) {";
    QMutexLocker lock(&f_mutex);
    return sp_album_add_ref(album);
}
static sp_error s_sp_album_release(sp_album *album) {
    qDebug() << "static sp_error s_sp_album_release(sp_album *album) {";
    QMutexLocker lock(&f_mutex);
    return sp_album_release(album);
}
static const char * s_sp_artist_name(sp_artist *artist) {
    qDebug() << "static const char * s_sp_artist_name(sp_artist *artist) {";
    QMutexLocker lock(&f_mutex);
    return sp_artist_name(artist);
}
static bool s_sp_artist_is_loaded(sp_artist *artist) {
    qDebug() << "static bool s_sp_artist_is_loaded(sp_artist *artist) {";
    QMutexLocker lock(&f_mutex);
    return sp_artist_is_loaded(artist);
}
static const byte * s_sp_artist_portrait(sp_artist *artist, sp_image_size size) {
    qDebug() << "static const byte * s_sp_artist_portrait(sp_artist *artist, sp_image_size size) {";
    QMutexLocker lock(&f_mutex);
    return sp_artist_portrait(artist, size);
}
static sp_error s_sp_artist_add_ref(sp_artist *artist) {
    qDebug() << "static sp_error s_sp_artist_add_ref(sp_artist *artist) {";
    QMutexLocker lock(&f_mutex);
    return sp_artist_add_ref(artist);
}
static sp_error s_sp_artist_release(sp_artist *artist) {
    qDebug() << "static sp_error s_sp_artist_release(sp_artist *artist) {";
    QMutexLocker lock(&f_mutex);
    return sp_artist_release(artist);
}
static sp_albumbrowse * s_sp_albumbrowse_create(sp_session *session, sp_album *album, albumbrowse_complete_cb *callback, void *userdata) {
    qDebug() << "static sp_albumbrowse * s_sp_albumbrowse_create(sp_session *session, sp_album *album, albumbrowse_complete_cb *callback, void *userdata) {";
    QMutexLocker lock(&f_mutex);
    return sp_albumbrowse_create(session, album, callback, userdata);
}
static bool s_sp_albumbrowse_is_loaded(sp_albumbrowse *alb) {
    qDebug() << "static bool s_sp_albumbrowse_is_loaded(sp_albumbrowse *alb) {";
    QMutexLocker lock(&f_mutex);
    return sp_albumbrowse_is_loaded(alb);
}
static sp_error s_sp_albumbrowse_error(sp_albumbrowse *alb) {
    qDebug() << "static sp_error s_sp_albumbrowse_error(sp_albumbrowse *alb) {";
    QMutexLocker lock(&f_mutex);
    return sp_albumbrowse_error(alb);
}
static sp_album * s_sp_albumbrowse_album(sp_albumbrowse *alb) {
    qDebug() << "static sp_album * s_sp_albumbrowse_album(sp_albumbrowse *alb) {";
    QMutexLocker lock(&f_mutex);
    return sp_albumbrowse_album(alb);
}
static sp_artist * s_sp_albumbrowse_artist(sp_albumbrowse *alb) {
    qDebug() << "static sp_artist * s_sp_albumbrowse_artist(sp_albumbrowse *alb) {";
    QMutexLocker lock(&f_mutex);
    return sp_albumbrowse_artist(alb);
}
static int s_sp_albumbrowse_num_copyrights(sp_albumbrowse *alb) {
    qDebug() << "static int s_sp_albumbrowse_num_copyrights(sp_albumbrowse *alb) {";
    QMutexLocker lock(&f_mutex);
    return sp_albumbrowse_num_copyrights(alb);
}
static const char * s_sp_albumbrowse_copyright(sp_albumbrowse *alb, int index) {
    qDebug() << "static const char * s_sp_albumbrowse_copyright(sp_albumbrowse *alb, int index) {";
    QMutexLocker lock(&f_mutex);
    return sp_albumbrowse_copyright(alb, index);
}
static int s_sp_albumbrowse_num_tracks(sp_albumbrowse *alb) {
    qDebug() << "static int s_sp_albumbrowse_num_tracks(sp_albumbrowse *alb) {";
    QMutexLocker lock(&f_mutex);
    return sp_albumbrowse_num_tracks(alb);
}
static sp_track * s_sp_albumbrowse_track(sp_albumbrowse *alb, int index) {
    qDebug() << "static sp_track * s_sp_albumbrowse_track(sp_albumbrowse *alb, int index) {";
    QMutexLocker lock(&f_mutex);
    return sp_albumbrowse_track(alb, index);
}
static const char * s_sp_albumbrowse_review(sp_albumbrowse *alb) {
    qDebug() << "static const char * s_sp_albumbrowse_review(sp_albumbrowse *alb) {";
    QMutexLocker lock(&f_mutex);
    return sp_albumbrowse_review(alb);
}
static int s_sp_albumbrowse_backend_request_duration(sp_albumbrowse *alb) {
    qDebug() << "static int s_sp_albumbrowse_backend_request_duration(sp_albumbrowse *alb) {";
    QMutexLocker lock(&f_mutex);
    return sp_albumbrowse_backend_request_duration(alb);
}
static sp_error s_sp_albumbrowse_add_ref(sp_albumbrowse *alb) {
    qDebug() << "static sp_error s_sp_albumbrowse_add_ref(sp_albumbrowse *alb) {";
    QMutexLocker lock(&f_mutex);
    return sp_albumbrowse_add_ref(alb);
}
static sp_error s_sp_albumbrowse_release(sp_albumbrowse *alb) {
    qDebug() << "static sp_error s_sp_albumbrowse_release(sp_albumbrowse *alb) {";
    QMutexLocker lock(&f_mutex);
    return sp_albumbrowse_release(alb);
}
static sp_artistbrowse * s_sp_artistbrowse_create(sp_session *session, sp_artist *artist, sp_artistbrowse_type type, artistbrowse_complete_cb *callback, void *userdata) {
    qDebug() << "static sp_artistbrowse * s_sp_artistbrowse_create(sp_session *session, sp_artist *artist, sp_artistbrowse_type type, artistbrowse_complete_cb *callback, void *userdata) {";
    QMutexLocker lock(&f_mutex);
    return sp_artistbrowse_create(session, artist, type, callback, userdata);
}
static bool s_sp_artistbrowse_is_loaded(sp_artistbrowse *arb) {
    qDebug() << "static bool s_sp_artistbrowse_is_loaded(sp_artistbrowse *arb) {";
    QMutexLocker lock(&f_mutex);
    return sp_artistbrowse_is_loaded(arb);
}
static sp_error s_sp_artistbrowse_error(sp_artistbrowse *arb) {
    qDebug() << "static sp_error s_sp_artistbrowse_error(sp_artistbrowse *arb) {";
    QMutexLocker lock(&f_mutex);
    return sp_artistbrowse_error(arb);
}
static sp_artist * s_sp_artistbrowse_artist(sp_artistbrowse *arb) {
    qDebug() << "static sp_artist * s_sp_artistbrowse_artist(sp_artistbrowse *arb) {";
    QMutexLocker lock(&f_mutex);
    return sp_artistbrowse_artist(arb);
}
static int s_sp_artistbrowse_num_portraits(sp_artistbrowse *arb) {
    qDebug() << "static int s_sp_artistbrowse_num_portraits(sp_artistbrowse *arb) {";
    QMutexLocker lock(&f_mutex);
    return sp_artistbrowse_num_portraits(arb);
}
static const byte * s_sp_artistbrowse_portrait(sp_artistbrowse *arb, int index) {
    qDebug() << "static const byte * s_sp_artistbrowse_portrait(sp_artistbrowse *arb, int index) {";
    QMutexLocker lock(&f_mutex);
    return sp_artistbrowse_portrait(arb, index);
}
static int s_sp_artistbrowse_num_tracks(sp_artistbrowse *arb) {
    qDebug() << "static int s_sp_artistbrowse_num_tracks(sp_artistbrowse *arb) {";
    QMutexLocker lock(&f_mutex);
    return sp_artistbrowse_num_tracks(arb);
}
static sp_track * s_sp_artistbrowse_track(sp_artistbrowse *arb, int index) {
    qDebug() << "static sp_track * s_sp_artistbrowse_track(sp_artistbrowse *arb, int index) {";
    QMutexLocker lock(&f_mutex);
    return sp_artistbrowse_track(arb, index);
}
static int s_sp_artistbrowse_num_tophit_tracks(sp_artistbrowse *arb) {
    qDebug() << "static int s_sp_artistbrowse_num_tophit_tracks(sp_artistbrowse *arb) {";
    QMutexLocker lock(&f_mutex);
    return sp_artistbrowse_num_tophit_tracks(arb);
}
static sp_track * s_sp_artistbrowse_tophit_track(sp_artistbrowse *arb, int index) {
    qDebug() << "static sp_track * s_sp_artistbrowse_tophit_track(sp_artistbrowse *arb, int index) {";
    QMutexLocker lock(&f_mutex);
    return sp_artistbrowse_tophit_track(arb, index);
}
static int s_sp_artistbrowse_num_albums(sp_artistbrowse *arb) {
    qDebug() << "static int s_sp_artistbrowse_num_albums(sp_artistbrowse *arb) {";
    QMutexLocker lock(&f_mutex);
    return sp_artistbrowse_num_albums(arb);
}
static sp_album * s_sp_artistbrowse_album(sp_artistbrowse *arb, int index) {
    qDebug() << "static sp_album * s_sp_artistbrowse_album(sp_artistbrowse *arb, int index) {";
    QMutexLocker lock(&f_mutex);
    return sp_artistbrowse_album(arb, index);
}
static int s_sp_artistbrowse_num_similar_artists(sp_artistbrowse *arb) {
    qDebug() << "static int s_sp_artistbrowse_num_similar_artists(sp_artistbrowse *arb) {";
    QMutexLocker lock(&f_mutex);
    return sp_artistbrowse_num_similar_artists(arb);
}
static sp_artist * s_sp_artistbrowse_similar_artist(sp_artistbrowse *arb, int index) {
    qDebug() << "static sp_artist * s_sp_artistbrowse_similar_artist(sp_artistbrowse *arb, int index) {";
    QMutexLocker lock(&f_mutex);
    return sp_artistbrowse_similar_artist(arb, index);
}
static const char * s_sp_artistbrowse_biography(sp_artistbrowse *arb) {
    qDebug() << "static const char * s_sp_artistbrowse_biography(sp_artistbrowse *arb) {";
    QMutexLocker lock(&f_mutex);
    return sp_artistbrowse_biography(arb);
}
static int s_sp_artistbrowse_backend_request_duration(sp_artistbrowse *arb) {
    qDebug() << "static int s_sp_artistbrowse_backend_request_duration(sp_artistbrowse *arb) {";
    QMutexLocker lock(&f_mutex);
    return sp_artistbrowse_backend_request_duration(arb);
}
static sp_error s_sp_artistbrowse_add_ref(sp_artistbrowse *arb) {
    qDebug() << "static sp_error s_sp_artistbrowse_add_ref(sp_artistbrowse *arb) {";
    QMutexLocker lock(&f_mutex);
    return sp_artistbrowse_add_ref(arb);
}
static sp_error s_sp_artistbrowse_release(sp_artistbrowse *arb) {
    qDebug() << "static sp_error s_sp_artistbrowse_release(sp_artistbrowse *arb) {";
    QMutexLocker lock(&f_mutex);
    return sp_artistbrowse_release(arb);
}
static sp_image * s_sp_image_create_from_link(sp_session *session, sp_link *l) {
    qDebug() << "static sp_image * s_sp_image_create_from_link(sp_session *session, sp_link *l) {";
    QMutexLocker lock(&f_mutex);
    return sp_image_create_from_link(session, l);
}
static sp_error s_sp_image_add_load_callback(sp_image *image, image_loaded_cb *callback, void *userdata) {
    qDebug() << "static sp_error s_sp_image_add_load_callback(sp_image *image, image_loaded_cb *callback, void *userdata) {";
    QMutexLocker lock(&f_mutex);
    return sp_image_add_load_callback(image, callback, userdata);
}
static sp_error s_sp_image_remove_load_callback(sp_image *image, image_loaded_cb *callback, void *userdata) {
    qDebug() << "static sp_error s_sp_image_remove_load_callback(sp_image *image, image_loaded_cb *callback, void *userdata) {";
    QMutexLocker lock(&f_mutex);
    return sp_image_remove_load_callback(image, callback, userdata);
}
static bool s_sp_image_is_loaded(sp_image *image) {
    qDebug() << "static bool s_sp_image_is_loaded(sp_image *image) {";
    QMutexLocker lock(&f_mutex);
    return sp_image_is_loaded(image);
}
static sp_error s_sp_image_error(sp_image *image) {
    qDebug() << "static sp_error s_sp_image_error(sp_image *image) {";
    QMutexLocker lock(&f_mutex);
    return sp_image_error(image);
}
static sp_imageformat s_sp_image_format(sp_image *image) {
    qDebug() << "static sp_imageformat s_sp_image_format(sp_image *image) {";
    QMutexLocker lock(&f_mutex);
    return sp_image_format(image);
}
static const void * s_sp_image_data(sp_image *image, size_t *data_size) {
    qDebug() << "static const void * s_sp_image_data(sp_image *image, size_t *data_size) {";
    QMutexLocker lock(&f_mutex);
    return sp_image_data(image, data_size);
}
static const byte * s_sp_image_image_id(sp_image *image) {
    qDebug() << "static const byte * s_sp_image_image_id(sp_image *image) {";
    QMutexLocker lock(&f_mutex);
    return sp_image_image_id(image);
}
static sp_error s_sp_image_add_ref(sp_image *image) {
    qDebug() << "static sp_error s_sp_image_add_ref(sp_image *image) {";
    QMutexLocker lock(&f_mutex);
    return sp_image_add_ref(image);
}
static sp_error s_sp_image_release(sp_image *image) {
    qDebug() << "static sp_error s_sp_image_release(sp_image *image) {";
    QMutexLocker lock(&f_mutex);
    return sp_image_release(image);
}
static sp_search * s_sp_search_create(sp_session *session, const char *query, int track_offset, int track_count, int album_offset, int album_count, int artist_offset, int artist_count, int playlist_offset, int playlist_count, sp_search_type search_type, search_complete_cb *callback, void *userdata) {
    qDebug() << "static sp_search * s_sp_search_create(sp_session *session, const char *query, int track_offset, int track_count, int album_offset, int album_count, int artist_offset, int artist_count, int playlist_offset, int playlist_count, sp_search_type search_type, search_complete_cb *callback, void *userdata) {";
    QMutexLocker lock(&f_mutex);
    return sp_search_create(session, query, track_offset, track_count, album_offset, album_count, artist_offset, artist_count, playlist_offset, playlist_count, search_type, callback, userdata);
}
static bool s_sp_search_is_loaded(sp_search *search) {
    qDebug() << "static bool s_sp_search_is_loaded(sp_search *search) {";
    QMutexLocker lock(&f_mutex);
    return sp_search_is_loaded(search);
}
static sp_error s_sp_search_error(sp_search *search) {
    qDebug() << "static sp_error s_sp_search_error(sp_search *search) {";
    QMutexLocker lock(&f_mutex);
    return sp_search_error(search);
}
static int s_sp_search_num_tracks(sp_search *search) {
    qDebug() << "static int s_sp_search_num_tracks(sp_search *search) {";
    QMutexLocker lock(&f_mutex);
    return sp_search_num_tracks(search);
}
static sp_track * s_sp_search_track(sp_search *search, int index) {
    qDebug() << "static sp_track * s_sp_search_track(sp_search *search, int index) {";
    QMutexLocker lock(&f_mutex);
    return sp_search_track(search, index);
}
static int s_sp_search_num_albums(sp_search *search) {
    qDebug() << "static int s_sp_search_num_albums(sp_search *search) {";
    QMutexLocker lock(&f_mutex);
    return sp_search_num_albums(search);
}
static sp_album * s_sp_search_album(sp_search *search, int index) {
    qDebug() << "static sp_album * s_sp_search_album(sp_search *search, int index) {";
    QMutexLocker lock(&f_mutex);
    return sp_search_album(search, index);
}
static int s_sp_search_num_playlists(sp_search *search) {
    qDebug() << "static int s_sp_search_num_playlists(sp_search *search) {";
    QMutexLocker lock(&f_mutex);
    return sp_search_num_playlists(search);
}
static sp_playlist * s_sp_search_playlist(sp_search *search, int index) {
    qDebug() << "static sp_playlist * s_sp_search_playlist(sp_search *search, int index) {";
    QMutexLocker lock(&f_mutex);
    return sp_search_playlist(search, index);
}
static const char * s_sp_search_playlist_name(sp_search *search, int index) {
    qDebug() << "static const char * s_sp_search_playlist_name(sp_search *search, int index) {";
    QMutexLocker lock(&f_mutex);
    return sp_search_playlist_name(search, index);
}
static const char * s_sp_search_playlist_uri(sp_search *search, int index) {
    qDebug() << "static const char * s_sp_search_playlist_uri(sp_search *search, int index) {";
    QMutexLocker lock(&f_mutex);
    return sp_search_playlist_uri(search, index);
}
static const char * s_sp_search_playlist_image_uri(sp_search *search, int index) {
    qDebug() << "static const char * s_sp_search_playlist_image_uri(sp_search *search, int index) {";
    QMutexLocker lock(&f_mutex);
    return sp_search_playlist_image_uri(search, index);
}
static int s_sp_search_num_artists(sp_search *search) {
    qDebug() << "static int s_sp_search_num_artists(sp_search *search) {";
    QMutexLocker lock(&f_mutex);
    return sp_search_num_artists(search);
}
static sp_artist * s_sp_search_artist(sp_search *search, int index) {
    qDebug() << "static sp_artist * s_sp_search_artist(sp_search *search, int index) {";
    QMutexLocker lock(&f_mutex);
    return sp_search_artist(search, index);
}
static const char * s_sp_search_query(sp_search *search) {
    qDebug() << "static const char * s_sp_search_query(sp_search *search) {";
    QMutexLocker lock(&f_mutex);
    return sp_search_query(search);
}
static const char * s_sp_search_did_you_mean(sp_search *search) {
    qDebug() << "static const char * s_sp_search_did_you_mean(sp_search *search) {";
    QMutexLocker lock(&f_mutex);
    return sp_search_did_you_mean(search);
}
static int s_sp_search_total_tracks(sp_search *search) {
    qDebug() << "static int s_sp_search_total_tracks(sp_search *search) {";
    QMutexLocker lock(&f_mutex);
    return sp_search_total_tracks(search);
}
static int s_sp_search_total_albums(sp_search *search) {
    qDebug() << "static int s_sp_search_total_albums(sp_search *search) {";
    QMutexLocker lock(&f_mutex);
    return sp_search_total_albums(search);
}
static int s_sp_search_total_artists(sp_search *search) {
    qDebug() << "static int s_sp_search_total_artists(sp_search *search) {";
    QMutexLocker lock(&f_mutex);
    return sp_search_total_artists(search);
}
static int s_sp_search_total_playlists(sp_search *search) {
    qDebug() << "static int s_sp_search_total_playlists(sp_search *search) {";
    QMutexLocker lock(&f_mutex);
    return sp_search_total_playlists(search);
}
static sp_error s_sp_search_add_ref(sp_search *search) {
    qDebug() << "static sp_error s_sp_search_add_ref(sp_search *search) {";
    QMutexLocker lock(&f_mutex);
    return sp_search_add_ref(search);
}
static sp_error s_sp_search_release(sp_search *search) {
    qDebug() << "static sp_error s_sp_search_release(sp_search *search) {";
    QMutexLocker lock(&f_mutex);
    return sp_search_release(search);
}
static bool s_sp_playlist_is_loaded(sp_playlist *playlist) {
    qDebug() << "static bool s_sp_playlist_is_loaded(sp_playlist *playlist) {";
    QMutexLocker lock(&f_mutex);
    return sp_playlist_is_loaded(playlist);
}
static sp_error s_sp_playlist_add_callbacks(sp_playlist *playlist, sp_playlist_callbacks *callbacks, void *userdata) {
    qDebug() << "static sp_error s_sp_playlist_add_callbacks(sp_playlist *playlist, sp_playlist_callbacks *callbacks, void *userdata) {";
    QMutexLocker lock(&f_mutex);
    return sp_playlist_add_callbacks(playlist, callbacks, userdata);
}
static sp_error s_sp_playlist_remove_callbacks(sp_playlist *playlist, sp_playlist_callbacks *callbacks, void *userdata) {
    qDebug() << "static sp_error s_sp_playlist_remove_callbacks(sp_playlist *playlist, sp_playlist_callbacks *callbacks, void *userdata) {";
    QMutexLocker lock(&f_mutex);
    return sp_playlist_remove_callbacks(playlist, callbacks, userdata);
}
static int s_sp_playlist_num_tracks(sp_playlist *playlist) {
    qDebug() << "static int s_sp_playlist_num_tracks(sp_playlist *playlist) {";
    QMutexLocker lock(&f_mutex);
    return sp_playlist_num_tracks(playlist);
}
static sp_track * s_sp_playlist_track(sp_playlist *playlist, int index) {
    qDebug() << "static sp_track * s_sp_playlist_track(sp_playlist *playlist, int index) {";
    QMutexLocker lock(&f_mutex);
    return sp_playlist_track(playlist, index);
}
static int s_sp_playlist_track_create_time(sp_playlist *playlist, int index) {
    qDebug() << "static int s_sp_playlist_track_create_time(sp_playlist *playlist, int index) {";
    QMutexLocker lock(&f_mutex);
    return sp_playlist_track_create_time(playlist, index);
}
static sp_user * s_sp_playlist_track_creator(sp_playlist *playlist, int index) {
    qDebug() << "static sp_user * s_sp_playlist_track_creator(sp_playlist *playlist, int index) {";
    QMutexLocker lock(&f_mutex);
    return sp_playlist_track_creator(playlist, index);
}
static bool s_sp_playlist_track_seen(sp_playlist *playlist, int index) {
    qDebug() << "static bool s_sp_playlist_track_seen(sp_playlist *playlist, int index) {";
    QMutexLocker lock(&f_mutex);
    return sp_playlist_track_seen(playlist, index);
}
static sp_error s_sp_playlist_track_set_seen(sp_playlist *playlist, int index, bool seen) {
    qDebug() << "static sp_error s_sp_playlist_track_set_seen(sp_playlist *playlist, int index, bool seen) {";
    QMutexLocker lock(&f_mutex);
    return sp_playlist_track_set_seen(playlist, index, seen);
}
static const char * s_sp_playlist_track_message(sp_playlist *playlist, int index) {
    qDebug() << "static const char * s_sp_playlist_track_message(sp_playlist *playlist, int index) {";
    QMutexLocker lock(&f_mutex);
    return sp_playlist_track_message(playlist, index);
}
static const char * s_sp_playlist_name(sp_playlist *playlist) {
    qDebug() << "static const char * s_sp_playlist_name(sp_playlist *playlist) {";
    QMutexLocker lock(&f_mutex);
    return sp_playlist_name(playlist);
}
static sp_error s_sp_playlist_rename(sp_playlist *playlist, const char *new_name) {
    qDebug() << "static sp_error s_sp_playlist_rename(sp_playlist *playlist, const char *new_name) {";
    QMutexLocker lock(&f_mutex);
    return sp_playlist_rename(playlist, new_name);
}
static sp_user * s_sp_playlist_owner(sp_playlist *playlist) {
    qDebug() << "static sp_user * s_sp_playlist_owner(sp_playlist *playlist) {";
    QMutexLocker lock(&f_mutex);
    return sp_playlist_owner(playlist);
}
static bool s_sp_playlist_is_collaborative(sp_playlist *playlist) {
    qDebug() << "static bool s_sp_playlist_is_collaborative(sp_playlist *playlist) {";
    QMutexLocker lock(&f_mutex);
    return sp_playlist_is_collaborative(playlist);
}
static sp_error s_sp_playlist_set_collaborative(sp_playlist *playlist, bool collaborative) {
    qDebug() << "static sp_error s_sp_playlist_set_collaborative(sp_playlist *playlist, bool collaborative) {";
    QMutexLocker lock(&f_mutex);
    return sp_playlist_set_collaborative(playlist, collaborative);
}
static sp_error s_sp_playlist_set_autolink_tracks(sp_playlist *playlist, bool link) {
    qDebug() << "static sp_error s_sp_playlist_set_autolink_tracks(sp_playlist *playlist, bool link) {";
    QMutexLocker lock(&f_mutex);
    return sp_playlist_set_autolink_tracks(playlist, link);
}
static const char * s_sp_playlist_get_description(sp_playlist *playlist) {
    qDebug() << "static const char * s_sp_playlist_get_description(sp_playlist *playlist) {";
    QMutexLocker lock(&f_mutex);
    return sp_playlist_get_description(playlist);
}
static bool s_sp_playlist_has_pending_changes(sp_playlist *playlist) {
    qDebug() << "static bool s_sp_playlist_has_pending_changes(sp_playlist *playlist) {";
    QMutexLocker lock(&f_mutex);
    return sp_playlist_has_pending_changes(playlist);
}
static sp_error s_sp_playlist_add_tracks(sp_playlist *playlist, sp_track *const*tracks, int num_tracks, int position, sp_session *session) {
    qDebug() << "static sp_error s_sp_playlist_add_tracks(sp_playlist *playlist, sp_track *const*tracks, int num_tracks, int position, sp_session *session) {";
    QMutexLocker lock(&f_mutex);
    return sp_playlist_add_tracks(playlist, tracks, num_tracks, position, session);
}
static sp_error s_sp_playlist_remove_tracks(sp_playlist *playlist, const int *tracks, int num_tracks) {
    qDebug() << "static sp_error s_sp_playlist_remove_tracks(sp_playlist *playlist, const int *tracks, int num_tracks) {";
    QMutexLocker lock(&f_mutex);
    return sp_playlist_remove_tracks(playlist, tracks, num_tracks);
}
static sp_error s_sp_playlist_reorder_tracks(sp_playlist *playlist, const int *tracks, int num_tracks, int new_position) {
    qDebug() << "static sp_error s_sp_playlist_reorder_tracks(sp_playlist *playlist, const int *tracks, int num_tracks, int new_position) {";
    QMutexLocker lock(&f_mutex);
    return sp_playlist_reorder_tracks(playlist, tracks, num_tracks, new_position);
}
static unsigned int s_sp_playlist_num_subscribers(sp_playlist *playlist) {
    qDebug() << "static unsigned int s_sp_playlist_num_subscribers(sp_playlist *playlist) {";
    QMutexLocker lock(&f_mutex);
    return sp_playlist_num_subscribers(playlist);
}
static sp_subscribers * s_sp_playlist_subscribers(sp_playlist *playlist) {
    qDebug() << "static sp_subscribers * s_sp_playlist_subscribers(sp_playlist *playlist) {";
    QMutexLocker lock(&f_mutex);
    return sp_playlist_subscribers(playlist);
}
static sp_error s_sp_playlist_subscribers_free(sp_subscribers *subscribers) {
    qDebug() << "static sp_error s_sp_playlist_subscribers_free(sp_subscribers *subscribers) {";
    QMutexLocker lock(&f_mutex);
    return sp_playlist_subscribers_free(subscribers);
}
static sp_error s_sp_playlist_update_subscribers(sp_session *session, sp_playlist *playlist) {
    qDebug() << "static sp_error s_sp_playlist_update_subscribers(sp_session *session, sp_playlist *playlist) {";
    QMutexLocker lock(&f_mutex);
    return sp_playlist_update_subscribers(session, playlist);
}
static bool s_sp_playlist_is_in_ram(sp_session *session, sp_playlist *playlist) {
    qDebug() << "static bool s_sp_playlist_is_in_ram(sp_session *session, sp_playlist *playlist) {";
    QMutexLocker lock(&f_mutex);
    return sp_playlist_is_in_ram(session, playlist);
}
static sp_error s_sp_playlist_set_in_ram(sp_session *session, sp_playlist *playlist, bool in_ram) {
    qDebug() << "static sp_error s_sp_playlist_set_in_ram(sp_session *session, sp_playlist *playlist, bool in_ram) {";
    QMutexLocker lock(&f_mutex);
    return sp_playlist_set_in_ram(session, playlist, in_ram);
}
static sp_playlist * s_sp_playlist_create(sp_session *session, sp_link *link) {
    qDebug() << "static sp_playlist * s_sp_playlist_create(sp_session *session, sp_link *link) {";
    QMutexLocker lock(&f_mutex);
    return sp_playlist_create(session, link);
}
static sp_error s_sp_playlist_set_offline_mode(sp_session *session, sp_playlist *playlist, bool offline) {
    qDebug() << "static sp_error s_sp_playlist_set_offline_mode(sp_session *session, sp_playlist *playlist, bool offline) {";
    QMutexLocker lock(&f_mutex);
    return sp_playlist_set_offline_mode(session, playlist, offline);
}
static sp_playlist_offline_status s_sp_playlist_get_offline_status(sp_session *session, sp_playlist *playlist) {
    qDebug() << "static sp_playlist_offline_status s_sp_playlist_get_offline_status(sp_session *session, sp_playlist *playlist) {";
    QMutexLocker lock(&f_mutex);
    return sp_playlist_get_offline_status(session, playlist);
}
static int s_sp_playlist_get_offline_download_completed(sp_session *session, sp_playlist *playlist) {
    qDebug() << "static int s_sp_playlist_get_offline_download_completed(sp_session *session, sp_playlist *playlist) {";
    QMutexLocker lock(&f_mutex);
    return sp_playlist_get_offline_download_completed(session, playlist);
}
static sp_error s_sp_playlist_add_ref(sp_playlist *playlist) {
    qDebug() << "static sp_error s_sp_playlist_add_ref(sp_playlist *playlist) {";
    QMutexLocker lock(&f_mutex);
    return sp_playlist_add_ref(playlist);
}
static sp_error s_sp_playlist_release(sp_playlist *playlist) {
    qDebug() << "static sp_error s_sp_playlist_release(sp_playlist *playlist) {";
    QMutexLocker lock(&f_mutex);
    return sp_playlist_release(playlist);
}
static sp_error s_sp_playlistcontainer_add_callbacks(sp_playlistcontainer *pc, sp_playlistcontainer_callbacks *callbacks, void *userdata) {
    qDebug() << "static sp_error s_sp_playlistcontainer_add_callbacks(sp_playlistcontainer *pc, sp_playlistcontainer_callbacks *callbacks, void *userdata) {";
    QMutexLocker lock(&f_mutex);
    return sp_playlistcontainer_add_callbacks(pc, callbacks, userdata);
}
static sp_error s_sp_playlistcontainer_remove_callbacks(sp_playlistcontainer *pc, sp_playlistcontainer_callbacks *callbacks, void *userdata) {
    qDebug() << "static sp_error s_sp_playlistcontainer_remove_callbacks(sp_playlistcontainer *pc, sp_playlistcontainer_callbacks *callbacks, void *userdata) {";
    QMutexLocker lock(&f_mutex);
    return sp_playlistcontainer_remove_callbacks(pc, callbacks, userdata);
}
static int s_sp_playlistcontainer_num_playlists(sp_playlistcontainer *pc) {
    qDebug() << "static int s_sp_playlistcontainer_num_playlists(sp_playlistcontainer *pc) {";
    QMutexLocker lock(&f_mutex);
    return sp_playlistcontainer_num_playlists(pc);
}
static bool s_sp_playlistcontainer_is_loaded(sp_playlistcontainer *pc) {
    qDebug() << "static bool s_sp_playlistcontainer_is_loaded(sp_playlistcontainer *pc) {";
    QMutexLocker lock(&f_mutex);
    return sp_playlistcontainer_is_loaded(pc);
}
static sp_playlist * s_sp_playlistcontainer_playlist(sp_playlistcontainer *pc, int index) {
    qDebug() << "static sp_playlist * s_sp_playlistcontainer_playlist(sp_playlistcontainer *pc, int index) {";
    QMutexLocker lock(&f_mutex);
    return sp_playlistcontainer_playlist(pc, index);
}
static sp_playlist_type s_sp_playlistcontainer_playlist_type(sp_playlistcontainer *pc, int index) {
    qDebug() << "static sp_playlist_type s_sp_playlistcontainer_playlist_type(sp_playlistcontainer *pc, int index) {";
    QMutexLocker lock(&f_mutex);
    return sp_playlistcontainer_playlist_type(pc, index);
}
static sp_error s_sp_playlistcontainer_playlist_folder_name(sp_playlistcontainer *pc, int index, char *buffer, int buffer_size) {
    qDebug() << "static sp_error s_sp_playlistcontainer_playlist_folder_name(sp_playlistcontainer *pc, int index, char *buffer, int buffer_size) {";
    QMutexLocker lock(&f_mutex);
    return sp_playlistcontainer_playlist_folder_name(pc, index, buffer, buffer_size);
}
static sp_playlist * s_sp_playlistcontainer_add_new_playlist(sp_playlistcontainer *pc, const char *name) {
    qDebug() << "static sp_playlist * s_sp_playlistcontainer_add_new_playlist(sp_playlistcontainer *pc, const char *name) {";
    QMutexLocker lock(&f_mutex);
    return sp_playlistcontainer_add_new_playlist(pc, name);
}
static sp_playlist * s_sp_playlistcontainer_add_playlist(sp_playlistcontainer *pc, sp_link *link) {
    qDebug() << "static sp_playlist * s_sp_playlistcontainer_add_playlist(sp_playlistcontainer *pc, sp_link *link) {";
    QMutexLocker lock(&f_mutex);
    return sp_playlistcontainer_add_playlist(pc, link);
}
static sp_error s_sp_playlistcontainer_remove_playlist(sp_playlistcontainer *pc, int index) {
    qDebug() << "static sp_error s_sp_playlistcontainer_remove_playlist(sp_playlistcontainer *pc, int index) {";
    QMutexLocker lock(&f_mutex);
    return sp_playlistcontainer_remove_playlist(pc, index);
}
static sp_error s_sp_playlistcontainer_move_playlist(sp_playlistcontainer *pc, int index, int new_position, bool dry_run) {
    qDebug() << "static sp_error s_sp_playlistcontainer_move_playlist(sp_playlistcontainer *pc, int index, int new_position, bool dry_run) {";
    QMutexLocker lock(&f_mutex);
    return sp_playlistcontainer_move_playlist(pc, index, new_position, dry_run);
}
static sp_error s_sp_playlistcontainer_add_folder(sp_playlistcontainer *pc, int index, const char *name) {
    qDebug() << "static sp_error s_sp_playlistcontainer_add_folder(sp_playlistcontainer *pc, int index, const char *name) {";
    QMutexLocker lock(&f_mutex);
    return sp_playlistcontainer_add_folder(pc, index, name);
}
static sp_user * s_sp_playlistcontainer_owner(sp_playlistcontainer *pc) {
    qDebug() << "static sp_user * s_sp_playlistcontainer_owner(sp_playlistcontainer *pc) {";
    QMutexLocker lock(&f_mutex);
    return sp_playlistcontainer_owner(pc);
}
static sp_error s_sp_playlistcontainer_add_ref(sp_playlistcontainer *pc) {
    qDebug() << "static sp_error s_sp_playlistcontainer_add_ref(sp_playlistcontainer *pc) {";
    QMutexLocker lock(&f_mutex);
    return sp_playlistcontainer_add_ref(pc);
}
static sp_error s_sp_playlistcontainer_release(sp_playlistcontainer *pc) {
    qDebug() << "static sp_error s_sp_playlistcontainer_release(sp_playlistcontainer *pc) {";
    QMutexLocker lock(&f_mutex);
    return sp_playlistcontainer_release(pc);
}
static int s_sp_playlistcontainer_get_unseen_tracks(sp_playlistcontainer *pc, sp_playlist *playlist, sp_track **tracks, int num_tracks) {
    qDebug() << "static int s_sp_playlistcontainer_get_unseen_tracks(sp_playlistcontainer *pc, sp_playlist *playlist, sp_track **tracks, int num_tracks) {";
    QMutexLocker lock(&f_mutex);
    return sp_playlistcontainer_get_unseen_tracks(pc, playlist, tracks, num_tracks);
}
static int s_sp_playlistcontainer_clear_unseen_tracks(sp_playlistcontainer *pc, sp_playlist *playlist) {
    qDebug() << "static int s_sp_playlistcontainer_clear_unseen_tracks(sp_playlistcontainer *pc, sp_playlist *playlist) {";
    QMutexLocker lock(&f_mutex);
    return sp_playlistcontainer_clear_unseen_tracks(pc, playlist);
}
static const char * s_sp_user_canonical_name(sp_user *user) {
    qDebug() << "static const char * s_sp_user_canonical_name(sp_user *user) {";
    QMutexLocker lock(&f_mutex);
    return sp_user_canonical_name(user);
}
static const char * s_sp_user_display_name(sp_user *user) {
    qDebug() << "static const char * s_sp_user_display_name(sp_user *user) {";
    QMutexLocker lock(&f_mutex);
    return sp_user_display_name(user);
}
static bool s_sp_user_is_loaded(sp_user *user) {
    qDebug() << "static bool s_sp_user_is_loaded(sp_user *user) {";
    QMutexLocker lock(&f_mutex);
    return sp_user_is_loaded(user);
}
static sp_error s_sp_user_add_ref(sp_user *user) {
    qDebug() << "static sp_error s_sp_user_add_ref(sp_user *user) {";
    QMutexLocker lock(&f_mutex);
    return sp_user_add_ref(user);
}
static sp_error s_sp_user_release(sp_user *user) {
    qDebug() << "static sp_error s_sp_user_release(sp_user *user) {";
    QMutexLocker lock(&f_mutex);
    return sp_user_release(user);
}
static sp_toplistbrowse * s_sp_toplistbrowse_create(sp_session *session, sp_toplisttype type, sp_toplistregion region, const char *username, toplistbrowse_complete_cb *callback, void *userdata) {
    qDebug() << "static sp_toplistbrowse * s_sp_toplistbrowse_create(sp_session *session, sp_toplisttype type, sp_toplistregion region, const char *username, toplistbrowse_complete_cb *callback, void *userdata) {";
    QMutexLocker lock(&f_mutex);
    return sp_toplistbrowse_create(session, type, region, username, callback, userdata);
}
static bool s_sp_toplistbrowse_is_loaded(sp_toplistbrowse *tlb) {
    qDebug() << "static bool s_sp_toplistbrowse_is_loaded(sp_toplistbrowse *tlb) {";
    QMutexLocker lock(&f_mutex);
    return sp_toplistbrowse_is_loaded(tlb);
}
static sp_error s_sp_toplistbrowse_error(sp_toplistbrowse *tlb) {
    qDebug() << "static sp_error s_sp_toplistbrowse_error(sp_toplistbrowse *tlb) {";
    QMutexLocker lock(&f_mutex);
    return sp_toplistbrowse_error(tlb);
}
static sp_error s_sp_toplistbrowse_add_ref(sp_toplistbrowse *tlb) {
    qDebug() << "static sp_error s_sp_toplistbrowse_add_ref(sp_toplistbrowse *tlb) {";
    QMutexLocker lock(&f_mutex);
    return sp_toplistbrowse_add_ref(tlb);
}
static sp_error s_sp_toplistbrowse_release(sp_toplistbrowse *tlb) {
    qDebug() << "static sp_error s_sp_toplistbrowse_release(sp_toplistbrowse *tlb) {";
    QMutexLocker lock(&f_mutex);
    return sp_toplistbrowse_release(tlb);
}
static int s_sp_toplistbrowse_num_artists(sp_toplistbrowse *tlb) {
    qDebug() << "static int s_sp_toplistbrowse_num_artists(sp_toplistbrowse *tlb) {";
    QMutexLocker lock(&f_mutex);
    return sp_toplistbrowse_num_artists(tlb);
}
static sp_artist * s_sp_toplistbrowse_artist(sp_toplistbrowse *tlb, int index) {
    qDebug() << "static sp_artist * s_sp_toplistbrowse_artist(sp_toplistbrowse *tlb, int index) {";
    QMutexLocker lock(&f_mutex);
    return sp_toplistbrowse_artist(tlb, index);
}
static int s_sp_toplistbrowse_num_albums(sp_toplistbrowse *tlb) {
    qDebug() << "static int s_sp_toplistbrowse_num_albums(sp_toplistbrowse *tlb) {";
    QMutexLocker lock(&f_mutex);
    return sp_toplistbrowse_num_albums(tlb);
}
static sp_album * s_sp_toplistbrowse_album(sp_toplistbrowse *tlb, int index) {
    qDebug() << "static sp_album * s_sp_toplistbrowse_album(sp_toplistbrowse *tlb, int index) {";
    QMutexLocker lock(&f_mutex);
    return sp_toplistbrowse_album(tlb, index);
}
static int s_sp_toplistbrowse_num_tracks(sp_toplistbrowse *tlb) {
    qDebug() << "static int s_sp_toplistbrowse_num_tracks(sp_toplistbrowse *tlb) {";
    QMutexLocker lock(&f_mutex);
    return sp_toplistbrowse_num_tracks(tlb);
}
static sp_track * s_sp_toplistbrowse_track(sp_toplistbrowse *tlb, int index) {
    qDebug() << "static sp_track * s_sp_toplistbrowse_track(sp_toplistbrowse *tlb, int index) {";
    QMutexLocker lock(&f_mutex);
    return sp_toplistbrowse_track(tlb, index);
}
static int s_sp_toplistbrowse_backend_request_duration(sp_toplistbrowse *tlb) {
    qDebug() << "static int s_sp_toplistbrowse_backend_request_duration(sp_toplistbrowse *tlb) {";
    QMutexLocker lock(&f_mutex);
    return sp_toplistbrowse_backend_request_duration(tlb);
}
static sp_inbox * s_sp_inbox_post_tracks(sp_session *session, const char *user, sp_track * const *tracks, int num_tracks, const char *message, inboxpost_complete_cb *callback, void *userdata) {
    qDebug() << "static sp_inbox * s_sp_inbox_post_tracks(sp_session *session, const char *user, sp_track * const *tracks, int num_tracks, const char *message, inboxpost_complete_cb *callback, void *userdata) {";
    QMutexLocker lock(&f_mutex);
    return sp_inbox_post_tracks(session, user, tracks, num_tracks, message, callback, userdata);
}
static sp_error s_sp_inbox_error(sp_inbox *inbox) {
    qDebug() << "static sp_error s_sp_inbox_error(sp_inbox *inbox) {";
    QMutexLocker lock(&f_mutex);
    return sp_inbox_error(inbox);
}
static sp_error s_sp_inbox_add_ref(sp_inbox *inbox) {
    qDebug() << "static sp_error s_sp_inbox_add_ref(sp_inbox *inbox) {";
    QMutexLocker lock(&f_mutex);
    return sp_inbox_add_ref(inbox);
}
static sp_error s_sp_inbox_release(sp_inbox *inbox) {
    qDebug() << "static sp_error s_sp_inbox_release(sp_inbox *inbox) {";
    QMutexLocker lock(&f_mutex);
    return sp_inbox_release(inbox);
}
static sp_error s_sp_session_create(const sp_session_config *config, sp_session **sess) {
    qDebug() << "static sp_error s_sp_session_create(const sp_session_config *config, sp_session **sess) {";
    QMutexLocker lock(&f_mutex);
    return sp_session_create(config, sess);
}
static sp_link * s_sp_link_create_from_string(const char *link) {
    qDebug() << "static sp_link * s_sp_link_create_from_string(const char *link) {";
    QMutexLocker lock(&f_mutex);
    return sp_link_create_from_string(link);
}
static sp_track * s_sp_localtrack_create(const char *artist, const char *title, const char *album, int length) {
    qDebug() << "static sp_track * s_sp_localtrack_create(const char *artist, const char *title, const char *album, int length) {";
    QMutexLocker lock(&f_mutex);
    return sp_localtrack_create(artist, title, album, length);
}
static const char * s_sp_build_id(void) {
    qDebug() << "static const char * s_sp_build_id(void) {";
    QMutexLocker lock(&f_mutex);
    return sp_build_id();
}
static sp_image * s_sp_image_create(sp_session *session, const byte image_id[20]) {
    qDebug() << "static sp_image * s_sp_image_create(sp_session *session, const byte image_id[20]) {";
    QMutexLocker lock(&f_mutex);
    return sp_image_create(session, image_id);
}
static sp_uint64 s_sp_playlistcontainer_playlist_folder_id(sp_playlistcontainer *pc, int index) {
    qDebug() << "static sp_uint64 s_sp_playlistcontainer_playlist_folder_id(sp_playlistcontainer *pc, int index) {";
    QMutexLocker lock(&f_mutex);
    return sp_playlistcontainer_playlist_folder_id(pc, index);
}
static bool s_sp_playlist_get_image(sp_playlist *playlist, byte image[20]) {
    qDebug() << "static bool s_sp_playlist_get_image(sp_playlist *playlist, byte image[20]) {";
    QMutexLocker lock(&f_mutex);
    return sp_playlist_get_image(playlist, image);
}


#endif // THREADSAFECALLS_H
