#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}


void MainWindow::on_pushButton_clicked() {
    QString a = ui->lineEdit->text();
    QString b = ui->lineEdit_2->text();
    QString c = ui->lineEdit_3->text();
    double x1, x2;
    double a1 = a.toDouble();
    double b1 = b.toDouble();
    double c1 = c.toDouble();
    double discriminant = (b1 * b1) - 4 * a1 * c1;
    if (discriminant >= 0) {
        if (a1 == 0) {
            x1 = -c1 / b1;
            x2 = x1;
        } else {
        x1 = (-b1 + sqrt(discriminant)) / (2 * a1);
        x2 = (-b1 - sqrt(discriminant)) / (2 * a1);
        }
        if (x1 == x2) ui->label_6->setText("X = " + QString::number(x1)); else
        ui->label_6->setText("x1 = " + QString::number(x1) + ", x2 = " + QString::number(x2));
    } else {
        ui->label_6->setText("Нет корней");
    }

}


void MainWindow::on_pushButton_2_clicked() {
    QString b = ui->lineEdit_4->text();
    QString c = ui->lineEdit_5->text();
    QString angle = ui->lineEdit_6->text();
    double b1 = b.toDouble();
    double c1 = c.toDouble();
    double angle1 = angle.toDouble();
    double a;
    if (ui->radioButton->isChecked()) {
        a = sqrt(b1*b1 + c1*c1 - 2 * b1 * c1 * cos(angle1));
    } else
    a = sqrt(b1*b1 + c1*c1 - 2 * b1 * c1 * cos(angle1/(180/M_PI)));
    ui->label_11->setText(QString::number(a));
}


void MainWindow::on_pushButton_3_clicked() {
    ui->plainTextEdit_2->insertPlainText(ui->plainTextEdit->toPlainText());
}


void MainWindow::on_pushButton_4_clicked() {
    ui->plainTextEdit_2->setPlainText(ui->plainTextEdit->toPlainText());
}


void MainWindow::on_pushButton_5_clicked() {
    QTextEdit* txt = new QTextEdit;
    txt->setHtml(ui->plainTextEdit->toPlainText());
    ui->plainTextEdit_2->setPlainText(txt->toPlainText());
}

