#ifndef LOGINSCREEN_H
#define LOGINSCREEN_H

#include <QWidget>

namespace Ui {
class LoginScreen;
}

class LoginScreen : public QWidget
{
    Q_OBJECT

public:
    explicit LoginScreen(QWidget *parent = nullptr);
    ~LoginScreen();

signals:
    void continueClicked(const QString &, const QString & , const QString &);

protected:
    void showEvent(QShowEvent *event) override;

private slots:
    void onTextChange(const QString &text);
    void onContinueClicked();

private:
    Ui::LoginScreen *ui;

    bool isValidName(const QString &name) const;
    void updateContinueBtnState();
    QString getValidationError(const QString &name) const;
};

#endif // LOGINSCREEN_H
