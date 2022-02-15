#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QFontDialog>
#include <QFont>
#include <QColor>
#include <QColorDialog>
#include <QPrinter>
#include <QPrintDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
}


void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}


void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}


void MainWindow::on_actionSave_triggered()
{
    QFile file(filePath);

    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this,"Not Opened","File couldn't open!");
        return;
    }

    QTextStream out(&file);
    out << ui->textEdit->toPlainText();
    file.flush();
    file.close();
}

void MainWindow::on_actionSave_as_triggered()
{
    filePath = QFileDialog::getSaveFileName(this,"Save as");
    QFile file(filePath);

    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this,"Not Opened","File couldn't open!");
        return;
    }

    QTextStream out(&file);
    out << ui->textEdit->toPlainText();
    file.flush();
    file.close();
}


void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}


void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}


void MainWindow::on_actionInformation_triggered()
{
    QString info = "Auther: Arda Erdoğan\n";
    info += "Date: 2/12/2022\n";
    info += "(C) Notepad (R)";

    QMessageBox::about(this,"About",info);
}


void MainWindow::on_actionNew_triggered()
{
    this->filePath = "";
    ui->textEdit->setText("");
}


void MainWindow::on_actionOpen_triggered()
{
    filePath = QFileDialog::getOpenFileName(this,"Open File");
    QFile file(filePath);

    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this,"Not Opened","File couldn't open!");
        return;
    }

    QTextStream in(&file);
    QString text = in.readAll();
    ui->textEdit->setText(text);
    file.close();
}


void MainWindow::on_actionFont_triggered()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok,this);

    if (ok)
        ui->textEdit->setFont(font);
    else
        return;
}


void MainWindow::on_actionText_Color_triggered()
{
    QColor color = QColorDialog::getColor(Qt::white,this,"Chose Color");

    if (color.isValid())
        ui->textEdit->setTextColor(color);
    else
        return;
}


void MainWindow::on_actionBackground_color_of_the_Text_triggered()
{
    QColor color = QColorDialog::getColor(Qt::white,this,"Chose Color");

    if (color.isValid())
        ui->textEdit->setTextBackgroundColor(color);
}


void MainWindow::on_actionBackground_Color_of_the_Plain_Text_triggered()
{
    QColor color = QColorDialog::getColor(Qt::white,this,"Chose Color");

    if (color.isValid())
        ui->textEdit->setPalette(QPalette(color));
}


void MainWindow::on_actionPrint_triggered()
{
    QPrinter printer;
    printer.setPrinterName("Desired printer name");
    QPrintDialog dialog(&printer,this);

    if (dialog.exec() == QDialog::Rejected)
        return;

    ui->textEdit->print(&printer);
}

