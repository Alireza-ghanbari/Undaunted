#include "SplashScreen.h"
#include "ui_SplashScreen.h"

SplashScreen::SplashScreen(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SplashScreen)
{
    ui->setupUi(this);

    ui->logoLabel->setPixmap(QPixmap(":/images/logo.jpg"));

    connect(ui->enterGameBtn, &QPushButton::clicked, this, &SplashScreen::goToLogin);

}

SplashScreen::~SplashScreen()
{
    delete ui;
}
