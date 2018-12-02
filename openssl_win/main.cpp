#include "openssl_win.h"
#include <QtWidgets/QApplication>
#include <QFile>
#include <QMainWindow>
#include <QTextStream>
#include <String>
#include <QObject>
#include <QDebug>

#define USER_PUBPATH "d:/temp/pub.pem"
#define USER_PRIVPATH "d:/temp/priv.pem"
#define USER_INFO "d:/temp/info.txt"
#define S_PUBPATH "d:/temp/s_pub.pem"
#define S_PRIVPATH "d:/temp/s_priv.pem"
#define AUTH_INFO "d:/temp/auth_info.pem"
#define REG_INFO "d:/temp/register code.pem"

//#pragma comment(lib,"libssl.lib")
//#pragma comment(lib,"libcrypto.lib")

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	openssl_win ow;
	server_win sw;
	QMainWindow registered_win;
	QLabel label;

	/*
	QFile codeFile("auth_info.pem");
	if (codeFile.open(QIODevice::ReadOnly))
	{
		QDataStream in(&codeFile);
		char buff[1024];
		in.readRawData(buff, 1024);
		QString f_qstr = de_pub(buff, S_PUBPATH);
		char  *f_decode = (char *)f_qstr.toStdString().c_str();
		QString auth_info = my_decrypt(f_decode, USER_PRIVPATH);		//(char *)f_decode.toStdString().c_str()
		qDebug() << "first decode: " << f_qstr << '\n' << "seconde decode: " << auth_info << '\n';
	}
	*/


	QFile *activatedFile = new QFile(AUTH_INFO);
	if (activatedFile->open(QIODevice::ReadOnly))
	{
		QDataStream in(activatedFile);
		//String activ_str = in.readAll().toStdString();
		char buff[1024];
		in.readRawData(buff, 1024);
		

		QFile *info = new QFile(USER_INFO);
		if (info->open(QIODevice::ReadOnly | QIODevice::Text))
		{
			QTextStream info_in(info);
			QString line = my_decrypt(buff, USER_PRIVPATH);
			//QString line = my_decrypt(de_pub(buff, S_PUBPATH), USER_PRIVPATH);
			QString info_str = ((info_in.readAll()).split(':'))[1];											// 如果授权pem文件内容乱码，以下会出错
			
			QStringList list = line.split(';');

			if ((list[0].split(':'))[1] == info_str && (list[1].split(':'))[1] == "YES")
			{
				label.setText("You have registered!");
				registered_win.setCentralWidget(&label);
				registered_win.resize(300, 300);
				registered_win.show();

				return a.exec();
			}
		}
		info->flush();
		info->close();
	}
	activatedFile->flush();
	activatedFile->close();

	ow.show();
	sw.show();
	generate_pem();
	QFile priv(USER_PRIVPATH);
	if (priv.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		QTextStream in(&priv);
		QString priv_str = in.readAll();
		
		ow.ui.user_priv->setText(priv_str);
	}
	priv.flush();
	priv.close();
	QFile pub(USER_PUBPATH);
	if (pub.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		QTextStream in(&pub);
		QString pub_str = in.readAll();
		
		ow.ui.user_pub->setText(pub_str);
	}
	pub.flush();
	pub.close();
	QObject::connect(ow.ui.gen_key, &QPushButton::clicked, &ow, &openssl_win::genRegisterCode);
	QObject::connect(ow.ui.decode, &QPushButton::clicked, &ow, &openssl_win::decode);
	QObject::connect(ow.ui.send, &QPushButton::clicked, &sw, &server_win::receive);
	QObject::connect(sw.ui.s_decode, &QPushButton::clicked, &sw, &server_win::showCode);
	QObject::connect(sw.ui.m_encode, &QPushButton::clicked, &sw, &server_win::multiEncode);
	//QObject::connect(sw.ui.m_encode, &QPushButton::clicked, &ow, &server_win::sendMultiEncode);
	QObject::connect(sw.ui.s_send, &QPushButton::clicked, &ow, &openssl_win::recAuth);
	//QObject::connect(&sw, &server_win::s_send(), &ow, &openssl_win::recAuth);

	return a.exec();
}
