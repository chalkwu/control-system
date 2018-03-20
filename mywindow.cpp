#include "mywindow.h"
#include "ui_mywindow.h"
#include <QMessageBox>
#include <QDebug>
#include <QString>
#include "evaluate_string.h"
#include "math.h"

MyWindow::MyWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MyWindow)
{
    ui->setupUi(this);


    connect(ui->horizontalSlider_2, SIGNAL(valueChanged(int)),
            ui->progressBar_2, SLOT(setValue(int)));

    //connect(ui->btn_calcu, SIGNAL(released()), this, SLOT(on_btn_calcu_clicked()));

}

MyWindow::~MyWindow()
{
    delete ui;
}

void MyWindow::on_pushButtonclose_clicked()
{
    ui->label->setText("Button is clicked");
}

void MyWindow::on_pushButton_clicked()
{
    //void                about          3
    //void                aboutQt        2 arguments
    //StandardButton      critical       3
    //StandardButton      information    3
    //standardButton      question       3
    //standardButton      warning        3

    QMessageBox::StandardButton reply = QMessageBox::question(this, "My title", "I do think of this",
                                                    QMessageBox::Yes | QMessageBox::No   );

    if (reply == QMessageBox::Yes)
    {
        QApplication::quit();
    }
    else
    {
        // show something
        qDebug() << "No is clicked" ;
    }
}

void MyWindow::on_btn_calcu_clicked()
{

    //ui->lb_res->setText(ui->input_ode->text());

    QString a = ui->input_ode->text();

    int id = a.indexOf("=");

    QString b = a.mid(id+1);

    int a_lx = 3;
    int a_lu = 2;
    double x[3] = { 1 , 2, 4 };
    double u[2] = { 1, 1.57 };

    qDebug() << id;
    qDebug() << b;
    qDebug() << evaluate_a_string(b.toStdString(), x, u, a_lx, a_lu);
}
