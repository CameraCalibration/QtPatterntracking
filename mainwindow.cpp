#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    phbxLayout0 = new QBoxLayout(QBoxLayout::LeftToRight);
        loadButt = new QPushButton("Load");
        start_stop = new QPushButton("Start");
        loadButt->setMaximumWidth(100);
        start_stop->setMaximumWidth(100);
        phbxLayout0->addWidget(loadButt);
        phbxLayout0->addWidget(start_stop);

    phbxLayout1 = new QBoxLayout(QBoxLayout::LeftToRight);
        qvbl0 = new QBoxLayout(QBoxLayout::TopToBottom);
            title0 = new QLabel("Fase 1");
            img0 = new QLabel();
            title0->setStyleSheet("font-size:8pt; font-weight:600; color:#000000;");
            title0->setAlignment(Qt::AlignCenter);
            img0->setStyleSheet("border: 1px solid gray");
            img0->setMaximumSize(QSize(261,231));
            img0->setMinimumSize(QSize(261,231));
            qvbl0->addWidget(title0);
            qvbl0->addWidget(img0);
        qvbl1 = new QBoxLayout(QBoxLayout::TopToBottom);
            title1 = new QLabel("Fase 2");
            img1 = new QLabel();
            title1->setStyleSheet("font-size:8pt; font-weight:600; color:#000000;");
            title1->setAlignment(Qt::AlignCenter);
            img1->setStyleSheet("border: 1px solid gray");
            img1->setMaximumSize(QSize(261,231));
            img1->setMinimumSize(QSize(261,231));
            qvbl1->addWidget(title1);
            qvbl1->addWidget(img1);
        qvbl2 = new QBoxLayout(QBoxLayout::TopToBottom);
            title2 = new QLabel("Fase 3");
            img2 = new QLabel();
            title2->setStyleSheet("font-size:8pt; font-weight:600; color:#000000;");
            title2->setAlignment(Qt::AlignCenter);
            img2->setStyleSheet("border: 1px solid gray");
            img2->setMaximumSize(QSize(261,231));
            img2->setMinimumSize(QSize(261,231));
            qvbl2->addWidget(title2);
            qvbl2->addWidget(img2);
        qvbl3 = new QBoxLayout(QBoxLayout::TopToBottom);
            title3 = new QLabel("Fase 4");
            img3 = new QLabel();
            title3->setStyleSheet("font-size:8pt; font-weight:600; color:#000000;");
            title3->setAlignment(Qt::AlignCenter);
            img3->setStyleSheet("border: 1px solid gray");
            img3->setMaximumSize(QSize(261,231));
            img3->setMinimumSize(QSize(261,231));
            qvbl3->addWidget(title3);
            qvbl3->addWidget(img3);

        phbxLayout1->addItem(qvbl0);
        phbxLayout1->addItem(qvbl1);
        phbxLayout1->addItem(qvbl2);
        phbxLayout1->addItem(qvbl3);

    phbxLayout2 = new  QBoxLayout(QBoxLayout::LeftToRight);
        qvbl4 = new QBoxLayout(QBoxLayout::TopToBottom);
            title4 = new QLabel("Results");
            img4 = new QLabel();
            title4->setStyleSheet("font-size:10pt; font-weight:600; color:#000000;");
            title4->setAlignment(Qt::AlignCenter);
            img4->setStyleSheet("border: 1px solid gray");
            img4->setMaximumSize(QSize(522,462));
            img4->setMinimumSize(QSize(522,462));
            qvbl4->addWidget(title4);
            qvbl4->addWidget(img4);
        phbxLayout2->addLayout(qvbl4);

    pbxLayout = new QBoxLayout(QBoxLayout::TopToBottom);
        pbxLayout->addLayout(phbxLayout0);
        pbxLayout->addLayout(phbxLayout1);
        pbxLayout->addLayout(phbxLayout2);

    // Set layout in QWidget
    window = new QWidget();
    window->setLayout(pbxLayout);

    // Set QWidget as the central layout of the main window
    setCentralWidget(window);

    createActions();
    createMenus();

    QString message = tr("A context menu is available by right-clicking");
    statusBar()->showMessage(message);
}

void MainWindow::createActions()
{
    loadAct = new QAction(tr("&Load"), this);
    loadAct->setShortcuts(QKeySequence::New);
    loadAct->setStatusTip(tr("Load a Video"));
    loadAct->setChecked(true);
    connect(loadAct, &QAction::triggered, this, &MainWindow::loadVideo);

    startAct = new QAction(tr("&Start"), this);
    startAct->setShortcuts(QKeySequence::New);
    startAct->setStatusTip(tr("Start the Process"));
    connect(startAct, &QAction::triggered, this, &MainWindow::startProcess);

    exitAct = new QAction(tr("&Exit"), this);
    exitAct->setShortcuts(QKeySequence::New);
    exitAct->setStatusTip(tr("Exit the Program"));
    connect(exitAct, &QAction::triggered, this, &QWidget::close);
}

void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(loadAct);
    fileMenu->addAction(startAct);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAct);
}

#ifndef QT_NO_CONTEXTMENU
void MainWindow::contextMenuEvent(QContextMenuEvent *event)
{
    QMenu menu(this);
    menu.addAction(loadAct);
    menu.addAction(startAct);
    menu.exec(event->globalPos());
}
#endif // QT_NO_CONTEXTMENU

void MainWindow::loadVideo()
{

}

void MainWindow::startProcess()
{

}

void MainWindow::stopProcess()
{

}
