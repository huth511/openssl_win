#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_openssl_win.h"
#include "ui_server.h"
#include <string>

//#pragma comment(lib,"libssl.lib")
//#pragma comment(lib,"libcrypto.lib")

class openssl_win : public QMainWindow
{
	Q_OBJECT

public:
	openssl_win(QWidget *parent = Q_NULLPTR);
	Ui::openssl_winClass ui;

public slots:
	void genRegisterCode();
	void decode();
	void recAuth();
	void sendMultiEncode();
};

class server_win : public QMainWindow
{
	Q_OBJECT

public:
	server_win(QWidget *parent = Q_NULLPTR);
	Ui::server_winClass ui;

signals:
	//void s_send(Q);

public slots:
	void receive();
	void showCode();
	void multiEncode();
	//void sSend();
};

char *my_encrypt(char *str, char *path_key);
char *my_decrypt(char *str, char *path_key);
char * en_priv(char *str, char *path_key);
char * de_pub(char *str, char *path_key);
void generate_pem();

//char* toStr(QString qstr);
//char* toStr(QString qstr);
//char * Base64Decode(char * input, int length, bool with_new_line);