#ifndef PLUGINSMANAGER_H
#define PLUGINSMANAGER_H

#include <QObject>
#include <QHash>

class PluginInterface;

class PluginsManager : public QObject
{
    Q_OBJECT
public:
    explicit PluginsManager(QObject *parent = 0);
    ~PluginsManager();

public:
    // 初始化插件
    void initPlugins(const QString& dir);

    // 插件
    PluginInterface *getPluginInterface(int id) const;
    bool hasPluginInterface(int id) const;

signals:

public slots:

private:
    QHash<int,PluginInterface*> m_hashPlugins; // 插件
};

#endif // PLUGINSMANAGER_H
