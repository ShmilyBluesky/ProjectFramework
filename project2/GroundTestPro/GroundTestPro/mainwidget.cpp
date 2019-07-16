#include "mainwidget.h"
#include "ui_mainwidget.h"
#include <QHBoxLayout>

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);
}

MainWidget::~MainWidget()
{
    delete ui;
}

void MainWidget::setSelfCheckWnd(QWidget *wnd)
{
    QHBoxLayout *hLayout = new QHBoxLayout();
    hLayout->addWidget(wnd);
    this->setLayout(hLayout);
}
