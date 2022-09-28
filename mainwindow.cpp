#include "mainwindow.hpp"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //appeler la fonction permettantr de se connecter à la bd
    if(!vraiconnexionBD()){
        QMessageBox::warning(this, "attention", "Pas de connection à la BD!");
    }else{
        QMessageBox::information(this, "information", "Connection reussi ouhwouhhh !!");
    }
    //vraiconnexionBD();
    printUsersData();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QSqlQuery requete;

    QString prenom = ui->lineEdit->text();
    QString nom = ui->lineEdit_2->text();
    QString sexe = ui->comboBox->currentText();
    QDate date = ui->dateEdit->date();
    QString adresse = ui->lineEdit_3->text();
    QString code = ui->lineEdit_4->text();
    QString ville = ui->label_5->text();
    //QString pays = ui->comboBox_2->currentText();

    requete.prepare("insert into mydatabase.clients(Prenom, Nom, Sexe, Naissance, Adresse) values(:prenom, :nom, :sexe, :date, :adresse+" "+:code+" ":ville)");
    requete.bindValue(":prenom", prenom);
    requete.bindValue(":nom", nom);
    requete.bindValue(":sexe", sexe);
    requete.bindValue(":adresse", adresse + " " + code + " " + ville);
    requete.bindValue(":date", date);
    requete.exec();

    //QMessageBox::information(this, "information", "Vos données ont été enregistré avec succes !");
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();

    QMessageBox::warning(this, "Attention", "Vous avez supprimer votre saisie");
}

void MainWindow::printUsersData(){
    QSqlQuery requete; int line(0);
    requete.exec("select count * from clients");
    while(requete.next()){
        line = requete.value(0).toInt();
    }
    QMessageBox::warning(this, "Attention", QString::number(line));
}
