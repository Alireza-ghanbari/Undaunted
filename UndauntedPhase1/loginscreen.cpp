#include "LoginScreen.h"
#include "ui_LoginScreen.h"
#include <QRegularExpression>
#include <QShowEvent>
#include <QDebug>

LoginScreen::LoginScreen(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LoginScreen)
{
    ui->setupUi(this);


    ui->continueBtn->setEnabled(false);
    if(ui->errorLabel) ui->errorLabel->clear();


    connect(ui->lineEditP1, &QLineEdit::textChanged, this, &LoginScreen::onTextChange);
    connect(ui->lineEditP2, &QLineEdit::textChanged, this, &LoginScreen::onTextChange);


    connect(ui->lineEditP1, &QLineEdit::returnPressed, this, &LoginScreen::onContinueClicked);
    connect(ui->lineEditP2, &QLineEdit::returnPressed, this, &LoginScreen::onContinueClicked);


    connect(ui->continueBtn, &QPushButton::clicked, this, &LoginScreen::onContinueClicked);
}

LoginScreen::~LoginScreen()
{
    delete ui;
}


QString LoginScreen::getValidationError(const QString &name) const
{
    if (name.length() < 8)
        return ("Must be at least 8 characters.");
    if (!name[0].isLetter())
        return ("Must start with a letter.");
    if (!name.contains(QRegularExpression("[a-z]")))
        return ("Must contain at least one lowercase letter.");
    if (!name.contains(QRegularExpression("[A-Z]")))
        return ("Must contain at least one uppercase letter.");
    if (!name.contains(QRegularExpression("\\d")))
        return ("Must contain at least one number.");
    if (!name.contains(QRegularExpression("[@!#$]")))
        return ("Must contain at least one special character (@!#$).");
    return QString();
}

void LoginScreen::showEvent(QShowEvent *event)
{
    QWidget::showEvent(event);

    ui->lineEditP1->clear();
    ui->lineEditP2->clear();
    ui->lineEditP1->setFocus();
    updateContinueBtnState();
    if(ui->errorLabel) ui->errorLabel->clear();
}

bool LoginScreen::isValidName(const QString &name) const
{
    static const QRegularExpression re("^(?=[A-Za-z])(?=.*[a-z])(?=.*[A-Z])(?=.*\\d)(?=.*[@!#$])[A-Za-z\\d@!#$]{8,}$");
    return re.match(name).hasMatch();
}

void LoginScreen::updateContinueBtnState()
{
    const QString p1 = ui->lineEditP1->text().trimmed();
    const QString p2 = ui->lineEditP2->text().trimmed();

    const bool ok = isValidName(p1) && isValidName(p2) && (p1 != p2);
    ui->continueBtn->setEnabled(ok);

    if (ui->errorLabel) {
        if (p1.isEmpty() && p2.isEmpty()) {
            ui->errorLabel->clear();
        } else if (!isValidName(p1) || !isValidName(p2)) {
            QString err1 = getValidationError(p1);
            QString err2 = getValidationError(p2);
            ui->errorLabel->setText(err1.isEmpty() ? err2 : err1);
        } else if (p1 == p2) {
            ui->errorLabel->setText("Names must not be equal.");
        } else {
            ui->errorLabel->clear();
        }
    }
}

void LoginScreen::onTextChange(const QString &)
{
    updateContinueBtnState();
}

void LoginScreen::onContinueClicked()
{
    const QString p1 = ui->lineEditP1->text().trimmed();
    const QString p2 = ui->lineEditP2->text().trimmed();

    emit continueClicked(p1, p2);
}
