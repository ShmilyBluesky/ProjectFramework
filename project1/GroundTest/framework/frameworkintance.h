#ifndef FRAMEWORKINTANCE_H
#define FRAMEWORKINTANCE_H

#include <QObject>

class PluginsManager;
class FrameworkInterfaceImplement;

class FrameworkIntance : public QObject
{
    Q_OBJECT
protected:
    explicit FrameworkIntance(QObject *parent = 0);

public:
    ~FrameworkIntance();
    static FrameworkIntance *instance();

    // 初始化
    void initInstance();

    // 获取PluginsManager指针
    PluginsManager *pluginsManager() const;

    // 获取FrameworkInterfaceImplement指针
    FrameworkInterfaceImplement *framework();

signals:

public slots:

private:
    static FrameworkIntance* m_instance; // 单例类

    PluginsManager *m_pluginManager; // 插件管理器
    FrameworkInterfaceImplement *m_frameworkInIm; // 框架接口实现类
};

#endif // FRAMEWORKINTANCE_H
