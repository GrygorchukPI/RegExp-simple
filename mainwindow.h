#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QString>
#include <QFileDialog>
#include <QMessageBox>

#include <chrono>
#include "RegExp.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionOpen_Text_triggered();

    void on_actionOpen_RegExp_triggered();

    void on_actionSave_Text_triggered();

    void on_actionSave_RegExp_triggered();

    void on_actionNew_Tex_triggered();

    void on_actionNew_RegExp_triggered();

    void on_GoButton_clicked();

    void on_actionSave_Result_triggered();

    void on_actionClear_Result_triggered();

private:
    Ui::MainWindow *ui;

    unsigned long int mMatches;
    QString mFileText;
    QString mFileRegExp;
    enum   WidgetStuff {TextEdit, RegExpEdit, ResultEdit};
    void SaveFile(QString lFileName, WidgetStuff lWhatWidget);

};

#endif // MAINWINDOW_H
