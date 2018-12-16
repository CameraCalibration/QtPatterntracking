#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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

signals:

public slots:

private:
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
