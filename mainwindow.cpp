#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //this->setCentralWidget(ui->TextEdit);
    //this->setCentralWidget(ui->ResultEdit);
    //this->setCentralWidget(ui->RegExpEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_Text_triggered()
{
    QString file = QFileDialog::getOpenFileName(this,"Open Text");

    if(!file.isEmpty())
    {
        QFile srcFile(file);
        if(srcFile.open(QFile::ReadOnly | QFile::Text))
        {
            mFileText = file;
            QTextStream fromFile(&srcFile);
            QString text = fromFile.readAll();
            srcFile.close();

            ui->TextEdit->setPlainText(text);
        }
    }
}

void MainWindow::on_actionOpen_RegExp_triggered()
{
    QString file = QFileDialog::getOpenFileName(this,"Open RegExp");

    if(!file.isEmpty())
    {
        QFile srcFile(file);
        if(srcFile.open(QFile::ReadOnly | QFile::Text))
        {
            mFileRegExp = file;
            QTextStream fromFile(&srcFile);
            QString text = fromFile.readAll();
            srcFile.close();

            ui->RegExpEdit->setPlainText(text);
        }
    }
}

void MainWindow::on_actionSave_Text_triggered()
{
    if(mFileText != "")
    {
        SaveFile(mFileText, TextEdit);
    }
    else
    {
        QString file = QFileDialog::getSaveFileName(this,"Save Text file");
        if(!file.isEmpty())
        {
            mFileText = file;
            SaveFile(mFileText, TextEdit);
        }
    }
}

void MainWindow::on_actionSave_RegExp_triggered()
{
    if(mFileRegExp != "")
    {
        SaveFile(mFileText, RegExpEdit);
    }
    else
    {
        QString file = QFileDialog::getSaveFileName(this,"Save RegExp file");
        if(!file.isEmpty())
        {
            mFileRegExp = file;
            SaveFile(mFileRegExp, RegExpEdit);
        }
    }
}

void MainWindow::SaveFile(QString lFileName, WidgetStuff lWhatWidget)
{
    QFile sFile(lFileName);
    if(sFile.open(QFile::WriteOnly | QFile::Text))
    {
        QTextStream out(&sFile);

        switch(lWhatWidget) {
            case TextEdit   : out << ui->TextEdit->toPlainText();
                     break;
            case RegExpEdit : out << ui->RegExpEdit->toPlainText();
                     break;
            case ResultEdit : out << ui->ResultEdit->toPlainText();
                     break;
        }

        sFile.flush();
        sFile.close();
    }
}

void MainWindow::on_actionNew_Tex_triggered()
{
    mFileText = "";
    ui->TextEdit->setPlainText("");
}

void MainWindow::on_actionNew_RegExp_triggered()
{
    mFileRegExp = "";
    ui->RegExpEdit->setPlainText("");
}

void MainWindow::on_GoButton_clicked()
{
    std::string text = ui->TextEdit->toPlainText().toStdString();
    std::string reg  = ui->RegExpEdit->toPlainText().toStdString();
    std::string res;
    QString qstr;
    if(!text.empty() && !reg.empty())
    {
            RegExp lReg(reg,text);
            res = lReg.mResultStr;
            lReg.Timer();

        mMatches = lReg.mMatchNum;


        std::chrono::steady_clock::time_point BeginTimer, EndTimer;

        ui->TotalMatches->setText(QString::number(mMatches));

        BeginTimer = std::chrono::steady_clock::now();

        qstr = QString::fromStdString(lReg.mResultStr);
        ui->ResultEdit->setPlainText(qstr);

        EndTimer = std::chrono::steady_clock::now();

        std::cout << "MainWindow Timer:" << std::endl;
        std::cout << "Time difference minutes      = " << std::chrono::duration_cast<std::chrono::minutes>     (EndTimer - BeginTimer).count() <<std::endl;
        std::cout << "Time difference seconds      = " << std::chrono::duration_cast<std::chrono::seconds>     (EndTimer - BeginTimer).count() <<std::endl;
        std::cout << "Time difference microseconds = " << std::chrono::duration_cast<std::chrono::microseconds>(EndTimer - BeginTimer).count() <<std::endl;
        std::cout << "Time difference nanoseconds  = " << std::chrono::duration_cast<std::chrono::nanoseconds> (EndTimer - BeginTimer).count() <<std::endl;
    }
    else
    {
        QMessageBox::warning(this, "You're moron", "Text or RegExp is empty!");
    }
}

void MainWindow::on_actionSave_Result_triggered()
{
    QString file = QFileDialog::getSaveFileName(this,"Save Result file");
    if(!file.isEmpty())
    {
        SaveFile(file, ResultEdit);
    }
}

void MainWindow::on_actionClear_Result_triggered()
{
    ui->ResultEdit->setPlainText("");
    mMatches = 0;
    ui->TotalMatches->setText(QString::number(mMatches));
}
