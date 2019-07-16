#include "selfcheckmainwnd.h"
#include "ui_selfcheckmainwnd.h"

SelfCheckMainWnd::SelfCheckMainWnd(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SelfCheckMainWnd)
{
    ui->setupUi(this);
}

SelfCheckMainWnd::~SelfCheckMainWnd()
{
    delete ui;
}
