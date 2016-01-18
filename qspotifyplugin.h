#ifndef QSPOTIFYPLUGIN_H
#define QSPOTIFYPLUGIN_H

#include <QtCore/QtGlobal>
#include <QtQml/QQmlExtensionPlugin>

class QSpotifyPlugin : public QQmlExtensionPlugin
{   
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QQmlExtensionInterface")

public:
    void initializeEngine(QQmlEngine *engine, const char *uri);
    void registerTypes(const char *uri);
};

#endif /* QSPOTIFYPLUGIN_H */
