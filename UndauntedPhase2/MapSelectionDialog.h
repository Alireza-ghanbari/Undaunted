#ifndef MAPSELECTIONDIALOG_H
#define MAPSELECTIONDIALOG_H

#include <QDialog>
#include <QString>

namespace Ui {
class MapSelectionDialog;
}

class MapSelectionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MapSelectionDialog(QWidget *parent = nullptr);
    ~MapSelectionDialog();

    QString getSelectedMap() const;

signals:
    void mapSelected(const QString &mapName);

private:
    Ui::MapSelectionDialog *ui;

    QString selectedMap;
};

#endif // MAPSELECTIONDIALOG_H
