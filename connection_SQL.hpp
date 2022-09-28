#ifndef CONNECTIONSQL_H
#define CONNECTIONSQL_H

#include <QSqlDatabase>
#include <QSqlQuery>

static bool vraiconnexionBD(){
    QSqlDatabase conn = QSqlDatabase::addDatabase("QSQLITE"); //SGBD a utiliser
    //definir l'adresse ip de l'équipement sur lequel se trouve notre BD
    conn.setHostName("127.0.0.1");
    //  Definir le nom de l'utilisateur qui va se connecter a la BD
    conn.setUserName("root");
    //  definir le nom de la BD
    conn.setDatabaseName("mydatabase");
    //  Preciser le port de connexion
    conn.setPort(3306);
    //preciser le mot de passe
    //conn.setPassword("");

    //verifier si la connection a reussi opu pas
    if(conn.open()){
        return true;
    }else{
        return false;
    }
}

#endif // CONNECTIONSQL_H
