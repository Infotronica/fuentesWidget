#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    int x;

    x=fontDatabase.addApplicationFont(":/fonts/Open 24 Display St.ttf");

    if (x==-1)
    {
        ui->pushButton->setText("error");
        return;
    }

    stringList=fontDatabase.applicationFontFamilies(x);
    stringListModel.setStringList(stringList);
    ui->listView->setModel(&stringListModel);
}

void MainWindow::on_listView_doubleClicked(const QModelIndex &index)
{
    QString fontFamily;

    fontFamily=ui->listView->model()->data(index).toString();
    font.setFamily(fontFamily);
    font.setPointSize(25);
    ui->label->setText("0123456789");
    ui->label->setFont(font);
}
