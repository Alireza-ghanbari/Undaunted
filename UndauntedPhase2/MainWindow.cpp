#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "SplashScreen.h"
#include "LoginScreen.h"
#include "BoardScreen.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    splash = new SplashScreen(this);
    login = new LoginScreen();
    boardScreen = new BoardScreen();

    setCentralWidget(splash);

    connect(splash, &SplashScreen::goToLogin, this, [this](){
        setCentralWidget(login);
    });

    connect(login, &LoginScreen::continueClicked, this, [this](const QString &p1, const QString &p2, const QString &mapName){
        QString mapPath = ":/maps/" + mapName + ".txt";
        QString layoutPath = ":/layouts/layout" + mapName + ".txt";;

        boardScreen->loadDynamicMap(mapPath, layoutPath);
        setCentralWidget(boardScreen);
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
