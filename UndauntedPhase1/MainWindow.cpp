#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "SplashScreen.h"
#include "LoginScreen.h"
#include "MapSelectionDialog.h"
#include "BoardScreen.h"
#include "BoardLinkedList.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    splash = new SplashScreen(this);
    login = new LoginScreen();
    boardScreen = new BoardScreen();
    // board = new Board();

    setCentralWidget(splash);


    connect(splash, &SplashScreen::goToLogin, this, [this](){
        setCentralWidget(login);
    });


    connect(login, &LoginScreen::continueClicked, this, [this](const QString &p1, const QString &p2, const QString &map){
        qDebug() << "Player1:" << p1;
        qDebug() << "Player2:" << p2;
        qDebug() << "Selected Map:" << map;

        boardScreen->loadMap(map);
        setCentralWidget(boardScreen);
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
