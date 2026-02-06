#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "SplashScreen.h"
#include "LoginScreen.h"
#include "boardscreen.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    SplashScreen *splash;
    LoginScreen *login;
    BoardScreen *boardScreen;
};
#endif // MAINWINDOW_H
