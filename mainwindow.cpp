#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

double pierwsza_liczba;
bool spra = false;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_0, SIGNAL(released()), this,SLOT(klikniecie_cyfry()));
    connect(ui->pushButton_1, SIGNAL(released()), this,SLOT(klikniecie_cyfry()));
    connect(ui->pushButton_2, SIGNAL(released()), this,SLOT(klikniecie_cyfry()));
    connect(ui->pushButton_3, SIGNAL(released()), this,SLOT(klikniecie_cyfry()));
    connect(ui->pushButton_4, SIGNAL(released()), this,SLOT(klikniecie_cyfry()));
    connect(ui->pushButton_5, SIGNAL(released()), this,SLOT(klikniecie_cyfry()));
    connect(ui->pushButton_6, SIGNAL(released()), this,SLOT(klikniecie_cyfry()));
    connect(ui->pushButton_7, SIGNAL(released()), this,SLOT(klikniecie_cyfry()));
    connect(ui->pushButton_8, SIGNAL(released()), this,SLOT(klikniecie_cyfry()));
    connect(ui->pushButton_9, SIGNAL(released()), this,SLOT(klikniecie_cyfry()));

    connect(ui->pushButton_plus, SIGNAL(released()), this,SLOT(operacje()));
    connect(ui->pushButton_minus, SIGNAL(released()), this,SLOT(operacje()));
    connect(ui->pushButton_dzielenie, SIGNAL(released()), this,SLOT(operacje()));
    connect(ui->pushButton_mnozenie, SIGNAL(released()), this,SLOT(operacje()));

    ui->pushButton_plus->setCheckable(true);
    ui->pushButton_minus->setCheckable(true);
    ui->pushButton_mnozenie->setCheckable(true);
    ui->pushButton_dzielenie->setCheckable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::klikniecie_cyfry()
{
    QPushButton * button = (QPushButton*)sender();

    double nr;
    QString n_et;

    if((ui->pushButton_plus->isChecked() || ui->pushButton_minus->isChecked() ||
       ui->pushButton_mnozenie->isChecked() || ui->pushButton_dzielenie->isChecked()) && (!spra))
    {
        nr = button->text().toDouble();
        spra = true;
    }
    else
    {
        nr = (ui->label->text() + button->text()).toDouble();
    }

    n_et = QString::number(nr);

    ui->label->setText(n_et);
}

void MainWindow::operacje()
{
    QPushButton * button = (QPushButton*) sender();

    pierwsza_liczba = ui->label->text().toDouble();

    button->setChecked(true);

}

void MainWindow::on_pushButton_rowna_sie_released()
{
    double nr, druga_liczba;
    QString n_et;

    druga_liczba = ui->label->text().toDouble();

    if(ui->pushButton_plus->isChecked())
    {
        nr = pierwsza_liczba + druga_liczba;
        n_et = QString::number(nr);
        ui->label->setText(n_et);
        ui->pushButton_plus->setChecked(false);
    }

    else if(ui->pushButton_minus->isChecked())
    {
        nr = pierwsza_liczba - druga_liczba;
        n_et = QString::number(nr);
        ui->label->setText(n_et);
        ui->pushButton_minus->setChecked(false);
    }

    else if(ui->pushButton_mnozenie->isChecked())
    {
        nr = pierwsza_liczba * druga_liczba;
        n_et = QString::number(nr);
        ui->label->setText(n_et);
        ui->pushButton_mnozenie->setChecked(false);
    }

    else if(ui->pushButton_dzielenie->isChecked())
    {
        nr = pierwsza_liczba / druga_liczba;
        n_et = QString::number(nr);
        ui->label->setText(n_et);
        ui->pushButton_dzielenie->setChecked(false);
    }

    spra = false;
}

void MainWindow::on_actionZakoncz_triggered()
{
    QMessageBox::StandardButton answer;
    answer = QMessageBox::warning(this, "Ostrzezenie", "Czy na pewno chcesz zamknąć?", QMessageBox::Yes | QMessageBox::No , QMessageBox::No);
    if(answer == QMessageBox::Yes)
        QApplication::exit();
}

void MainWindow::on_actionWyczysc_triggered()
{
    ui->label->clear();
    ui->label->setText("0");
}

void MainWindow::on_pushButton_wyczysc_clicked()
{
    ui->label->clear();
    ui->label->setText("0");
}

