#ifndef SELFCHECKMAINWND_H
#define SELFCHECKMAINWND_H

#include <QWidget>

namespace Ui {
class SelfCheckMainWnd;
}

class SelfCheckMainWnd : public QWidget
{
    Q_OBJECT

public:
    explicit SelfCheckMainWnd(QWidget *parent = 0);
    ~SelfCheckMainWnd();

private:
    Ui::SelfCheckMainWnd *ui;
};

#endif // SELFCHECKMAINWND_H
