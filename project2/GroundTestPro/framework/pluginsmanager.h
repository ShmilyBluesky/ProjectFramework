#ifndef PLUGINSMANAGER_H
#define PLUGINSMANAGER_H

#include <QObject>

class Interface4SelfCheck;

class PluginsManager : public QObject
{
    Q_OBJECT
public:
    explicit PluginsManager(QObject *parent = 0);
    ~PluginsManager();

public:
    // 初始化插件
    void initPlugins(const QString& dir);

    // 自检插件
    Interface4SelfCheck *getPlugin4SelfCheck() const;

signals:

public slots:

private:
    Interface4SelfCheck *m_plugin4SelfCheck; // 自检测试
};

#endif // PLUGINSMANAGER_H
