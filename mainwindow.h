#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionZakoncz_triggered();

     void operacje();

    void on_pushButton_wyczysc_clicked();

    void on_pushButton_rowna_sie_released();
    
    void on_actionWyczysc_triggered();
 
    void klikniecie_cyfry();


private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
