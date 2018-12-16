#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QContextMenuEvent>
#include <QStatusBar>
#include <QImage>
#include <QWidget>
#include <QLabel>
#include <QBoxLayout>
#include <QPixmap>
#include <iostream>
#include <QColor>
#include <QPushButton>
#include <QLineEdit>
#include <QCheckBox>
#include <QComboBox>
#include <QProgressBar>
#include <QDebug>
#include <QGroupBox>
#include <QButtonGroup>

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);

private:
    void createActions();
    void createMenus();

public:
signals:

public slots:

private slots:
    void loadVideo();
    void startProcess();
    void stopProcess();

protected:
#ifndef QT_NO_CONTEXTMENU
    void contextMenuEvent(QContextMenuEvent *event) override;
#endif // QT_NO_CONTEXTMENU

private:
    QMenu *fileMenu;
    QActionGroup *alignmentGroup;
    QAction *loadAct;
    QAction *startAct;
    QAction *exitAct;

    QAction *leftAlignAct;
    QAction *rightAlignAct;
    QAction *justifyAct;
    QAction *centerAct;

    QBoxLayout* phbxLayout0;
    QPushButton *loadButt;
    QPushButton *start_stop;
    QBoxLayout* phbxLayout1;
    QBoxLayout *qvbl0;
    QLabel *title0;
    QLabel *img0;
    QBoxLayout *qvbl1;
    QLabel *title1;
    QLabel *img1;
    QBoxLayout *qvbl2;
    QLabel *title2;
    QLabel *img2;
    QBoxLayout *qvbl3;
    QLabel *title3;
    QLabel *img3;

    QBoxLayout *phbxLayout2;
    QBoxLayout *qvbl4;
    QLabel *title4;
    QLabel *img4;

    QBoxLayout *pbxLayout;
    QWidget *window;

};

#endif // MAINWINDOW_H
