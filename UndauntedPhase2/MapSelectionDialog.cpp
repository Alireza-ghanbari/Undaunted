#include "MapSelectionDialog.h"
#include "ui_MapSelectionDialog.h"

MapSelectionDialog::MapSelectionDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MapSelectionDialog)
{
    ui->setupUi(this);


    connect(ui->map1Btn, &QToolButton::clicked, this, [this]() {
        selectedMap = "map1";
        accept();
    });

    connect(ui->map2Btn, &QToolButton::clicked, this, [this]() {
        selectedMap = "map2";
        accept();
    });

    connect(ui->map3Btn, &QToolButton::clicked, this, [this]() {
        selectedMap = "map3";
        accept();
    });
}

QString MapSelectionDialog::getSelectedMap() const {
    return selectedMap;
}

MapSelectionDialog::~MapSelectionDialog()
{
    delete ui;
}
