#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "SplashScreen.h"
#include "LoginScreen.h"
// #include "Board.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    splash = new SplashScreen(this);
    login = new LoginScreen();
    // board = new Board();

    setCentralWidget(splash);


    connect(splash, &SplashScreen::goToLogin, this, [this](){
        setCentralWidget(login);
    });


    connect(login, &LoginScreen::continueClicked, this, [this](const QString &p1, const QString &p2){
        qDebug() << "Players: " << p1 << p2;
        // setCesetCentralWidget(borad);
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
