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
    void on_actionSave_as_triggered();

    void on_actionCut_triggered();

    void on_actionCopy_triggered();

    void on_actionSave_triggered();

    void on_actionPaste_triggered();

    void on_actionRedo_triggered();

    void on_actionUndo_triggered();

    void on_actionInformation_triggered();

    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionFont_triggered();

    void on_actionText_Color_triggered();

    void on_actionBackground_color_of_the_Text_triggered();

    void on_actionBackground_Color_of_the_Plain_Text_triggered();

    void on_actionPrint_triggered();

private:
    Ui::MainWindow *ui;
    QString filePath;
};
#endif // MAINWINDOW_H
