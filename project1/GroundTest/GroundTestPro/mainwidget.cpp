#include "mainwidget.h"
#include "ui_mainwidget.h"
#include "frameworkintance.h"
#include "frameworkinterfaceimplement.h"
#include "global_process_define.h"
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
    ui->wnd_selfCheck->setLayout(hLayout);
}

void MainWidget::on_btn_selfCheck_clicked()
{
    FrameworkInterfaceImplement *framework = FrameworkIntance::instance()->framework();
    framework->process(Plugin_SelfCheck, Cmd4SelfCheck_Debug, QString("from main ui1."));

    framework->process(Plugin_StatusMonitor, Cmd4StatusMonitor_Debug, QString("from main ui2."));
}
