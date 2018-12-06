#include "openssl_win.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<openssl/rsa.h>
#include<openssl/pem.h>
#include<openssl/err.h>
#include <string>
#include <errno.h>
#include <iostream>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/err.h>
#include <openssl/bio.h>
#include <fstream>
#include <QDebug>
#include <QFile>
#include <String>
#include <fstream>
#include <cassert>
#include <limits>
#include <stdexcept>
#include <cctype>
#include <QMessageBox>
#include "ZBase64.h"

#pragma comment(lib,"libssl.lib")
#pragma comment(lib,"libcrypto.lib")

#define USER_PUBPATH "pub.pem"
#define USER_PRIVPATH "priv.pem"
#define USER_INFO "info.txt"
#define S_PUBPATH "s_pub.pem"
#define S_PRIVPATH "s_priv.pem"
#define AUTH_INFO "auth_info.pem"
#define REG_INFO "register code.pem"

//ZBase64 base64;
//::std::string base64_decode(const ::std::string &ascdata);

openssl_win::openssl_win(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

void openssl_win::genRegisterCode() 
{
	QString name = ui.user_name->toPlainText();
	QString info = "name:";
	info.append(name);
	string s;
	
	char* pChar ;
	pChar = (char *)malloc(1025);
	memset(pChar, 0, 1025);
	//info = QString::fromLocal8Bit("胡");
	strcpy(pChar, info.toStdString().c_str());
	
	char *pResult = my_encrypt(pChar, S_PUBPATH);
	int dataLength = (int)strlen(pResult);
	QByteArray keyData(pResult,  dataLength);

	//string keyStr = keyData;
	//printf((char*)info.toStdString().c_str());
	//ofstream rcode_file("register code.pem");
	//rcode_file << keyData;
	//rcode_file.close;
	//BIO *b64 = NULL;
	//b64 = BIO_new(BIO_f_base64());
	//BIO_read_filename(b64, "register code.pem");

	//ui.user_encode->setText(QString::fromStdString(keyData.toStdString()));	//base64.Decode(keyData, keyStr.length(), outbyte))
	ui.user_encode->setText(QString::fromStdString(keyData.toBase64().toStdString()));
	//printf("%s", Base64Decode(keyData, keyStr.length(), true));
	//printf("%s", keyData);
	//ofstream regFile("register code.pem");
	//regFile << keyStr;
	//regFile.close();
	QFile file(REG_INFO);
	if (file.open(QIODevice::WriteOnly))
	{
		file.write(keyData);
	}
	file.flush();
	file.close();

	delete[] pChar;
	delete[] pResult;
}

void openssl_win::decode()
{
	/*
	QFile codeFile("auth_info.pem");
	if (codeFile.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		QTextStream in(&codeFile);
		string qstr = in.readAll().toStdString();
		//string str = qstr.toStdString();
		//my_decrypt((char *)str.c_str(), S_PRIVPATH);

		QString auth_info = my_decrypt(de_pub((char *)qstr.c_str(), S_PUBPATH), USER_PRIVPATH);
		this->ui.user_decode->setText(auth_info);

		QString auth = (auth_info.split(";")[1]).split(":")[1];
		if (auth == "YES") {
			ofstream userFile("info.txt");
			userFile << (auth_info.split(";")[0]).toStdString();
			QMessageBox::information(NULL, "Authorization Information", "Registered Successfully!", QMessageBox::Ok);
		}
		else {
			QMessageBox::critical(NULL, "Authorization Information", "Failed to Register!", QMessageBox::Ok);
		}
	}
	*/

	QFile decodeFile(AUTH_INFO);
	if (decodeFile.open(QIODevice::ReadOnly))
	{
		QDataStream in(&decodeFile);
		char buff[1024];
		in.readRawData(buff, 1024);
		//QString f_qstr = de_pub(buff, S_PUBPATH);
		//qDebug() << "first decode: " << de_pub << '\n';
		//char  *f_decode =(char *) f_qstr.toStdString().c_str();
		QString auth_info = my_decrypt(buff, USER_PRIVPATH);		//USER_PRIVPATH	(char *)f_decode.toStdString().c_str()
		//QString auth_info = my_decrypt(de_pub(buff, S_PUBPATH), USER_PRIVPATH);
		this->ui.user_decode->setText(auth_info);
		//qDebug() << auth_info;
		//if (auth_info.contains(';'))	
		decodeFile.flush();
		decodeFile.close();
		//else cout << "flush failed!";
		QString auth = (auth_info.split(";")[1]).split(":")[1];
		if (auth == "YES") {
			QFile userFile(USER_INFO);
			if (userFile.open(QIODevice::ReadOnly | QIODevice::Text))
			{
				QTextStream out(&userFile);
				out << auth_info.split(";")[0];
			}
			userFile.flush();
			userFile.close();
			QMessageBox::information(NULL, "Authorization Information", "Registered Successfully!", QMessageBox::Ok);
		}
		else {
			QMessageBox::critical(NULL, "Authorization Information", "Failed to Register!", QMessageBox::Ok);
		}
	}
	else {
		QMessageBox::critical(NULL, "Authorization Information", "File not Found!", QMessageBox::Ok);
	}

}

void openssl_win::recAuth()
{
	/*
	QFile codeFile("auth_info.pem");
	if (codeFile.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		QTextStream in(&codeFile);
		QString qstr = in.readAll();
		this->ui.user_encode->setText(qstr);
		//string str = qstr.toStdString();
		//my_decrypt((char *)str.c_str(), S_PRIVPATH);
	}
	*/
	QFile authFile(AUTH_INFO);
	if (authFile.open(QIODevice::ReadOnly))
	{
		QDataStream in(&authFile);
		char buff[1024];
		in.readRawData(buff, 1024);
		QByteArray keyData = QByteArray(buff, (int)strlen(buff));
		this->ui.user_encode->setText(QString::fromStdString(keyData.toBase64().toStdString()));
	}
	authFile.flush();
	authFile.close();
	//else cout << "flush failed!";
}

void openssl_win::sendMultiEncode()
{

}

server_win::server_win(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

void server_win::receive()
{
	QFile regFile(REG_INFO);
	if (regFile.open(QIODevice::ReadOnly))
	{
		QDataStream in(&regFile);
		char buff[1024];
		in.readRawData(buff, 1024);
		QByteArray keyData = QByteArray(buff, (int)strlen(buff)).toBase64();
		this->ui.server_encode->setText(QString::fromStdString(keyData.toStdString()));
		//string str = qstr.toStdString();
		//my_decrypt((char *)str.c_str(), S_PRIVPATH);
	}
	regFile.flush();
	regFile.close();
}

void server_win::showCode()
{
	//ifstream file("auth_info.pem");
	//string data;
	//file >> data;
	//QString code = my_decrypt((char *)data.c_str(), S_PRIVPATH);
	//this->ui.server_decode->setText(code);

	QFile registerFile(REG_INFO);
	if (registerFile.open(QIODevice::ReadOnly))
	{
		//QTextStream in(&codeFile);
		QDataStream in(&registerFile);
		char byteArr[1024];
		memset(byteArr, 0, 1024);
		in.readRawData(byteArr, 1024);
		//qDebug() << QByteArray::fromBase64(ba);
		//string str = (this->ui.server_encode->toPlainText()).toStdString();
		char *ch = my_decrypt(byteArr, S_PRIVPATH);
		QString code = ch;
		//qDebug() << code;
		this->ui.server_decode->setText(code);
		//string str = qstr.toStdString();
		//my_decrypt((char *)str.c_str(), S_PRIVPATH);
		delete[] ch;
	}
	registerFile.flush();
	registerFile.close();
	//else cout << "flush failed!";

	//string qstr = (this->ui.server_encode->toPlainText()).toStdString();
	//QString code = my_decrypt((char *)qstr.c_str(), S_PRIVPATH);
	//this->ui.server_decode->setText(code);
}

void server_win::multiEncode()
{
	if ((this->ui.server_decode->toPlainText()) != NULL)
	{
		QString name = (this->ui.server_decode->toPlainText().split(":"))[1];
		//qDebug() << name;
		QString auth_info = "name:";
		auth_info.append(name);
		auth_info.append(";isAuthorized:");
		if ((name == "huth") || (name == "huth511"))
		{
			auth_info.append("YES");
		}
		else {
			auth_info.append("NO");
		}

		//char * auth = en_priv(my_encrypt((char *)auth_info.toStdString().c_str(), USER_PUBPATH),	S_PRIVPATH);
		
		
		//char *u_pubArr = my_encrypt((char *)auth_info.toStdString().c_str(), USER_PUBPATH);
		//QString u_pub = my_encrypt((char *)auth_info.toStdString().c_str(), USER_PUBPATH);		//USER_PUBPATH
		//qDebug() << "auth_info: " << auth_info << '\n' << "first encode: " << u_pub << '\n'
						  //<< "char code: " << my_encrypt((char *)auth_info.toStdString().c_str(), USER_PUBPATH);
		char* pChar;
		pChar = (char *)malloc(1025);
		memset(pChar, 0, 1025);
		//string strData = "胡";
		strcpy(pChar, auth_info.toStdString().c_str());
		char *pResult = my_encrypt(pChar, USER_PUBPATH);
		int dataLength = (int)strlen(pResult);
		QByteArray auth(pResult, dataLength);
		//QByteArray auth(my_encrypt((char *)auth_info.toStdString().c_str(), USER_PUBPATH));		//(char *)u_pub.toStdString().c_str()
		//QByteArray auth(en_priv(my_encrypt((char *)auth_info.toStdString().c_str(), USER_PUBPATH), S_PRIVPATH));
		QFile authinfoFile(AUTH_INFO);
		if (authinfoFile.open(QIODevice::WriteOnly))
		{
			authinfoFile.write(auth);
		}
		//ofstream authFile("auth_info.pem");
		//authFile << auth;
		//authFile.close();
		authinfoFile.flush();
		authinfoFile.close();
		this->ui.server_encode->setText(QString::fromStdString(auth.toBase64().toStdString()));

		delete[] pChar;
		delete[] pResult;
	}
}

//公钥加密
char * my_encrypt(char *str, char *path_key) {
	//errno_t err;
	char *p_en;
	RSA *p_rsa;
	//FILE *file;
	int flen, rsa_len;

	BIO* file = NULL;
	//生成IO对象
	file = BIO_new(BIO_s_file());
	//将Key文件读入IO
	BIO_read_filename(file, path_key);
	if (file == NULL)
	{
		perror(path_key);
		return NULL;
	}

	if ((p_rsa = PEM_read_bio_RSA_PUBKEY(file, NULL, NULL, NULL)) == NULL) {
		//if((p_rsa=PEM_read_RSAPublicKey(file,NULL,NULL,NULL))==NULL){  // 换成这句死活通不过，无论是否将公钥分离源文件
		ERR_print_errors_fp(stdout);
		return NULL;
	}

	flen = (int)strlen(str);
	rsa_len = RSA_size(p_rsa);
	p_en = (char *)malloc(rsa_len + 1);
	memset(p_en, 0, rsa_len + 1);
	if (RSA_public_encrypt(flen, (unsigned char *)str, (unsigned char*)p_en, p_rsa, RSA_NO_PADDING) < 0) {
		return NULL;
	}
	RSA_free(p_rsa);
	BIO_free(file);
	return p_en;
}

//私钥解密
char *my_decrypt(char *str, char *path_key) {
	//errno_t err;
	char *p_de;
	RSA *p_rsa;
	//FILE *file;
	int rsa_len, flen;

	BIO* file = NULL;
	//生成IO对象
	file = BIO_new(BIO_s_file());
	//将Key文件读入IO
	BIO_read_filename(file, path_key);
	if (file == NULL)
	{
		perror(path_key);
		return NULL;
	}

	if ((p_rsa = PEM_read_bio_RSAPrivateKey(file, NULL, NULL, NULL)) == NULL) {
		ERR_print_errors_fp(stdout);
		return NULL;
	}
	flen = (int)strlen(str);
	rsa_len = RSA_size(p_rsa);
	p_de = (char *)malloc(rsa_len + 1);
	memset(p_de, 0, rsa_len + 1);
	if (RSA_private_decrypt(flen, (unsigned char *)str, (unsigned char*)p_de, p_rsa, RSA_NO_PADDING) < 0) {
		return NULL;
	}
	RSA_free(p_rsa);
	BIO_free(file);
	return p_de;
}

//私钥加密
char * en_priv(char *str, char *path_key) {
	//errno_t err;
	char *p_en;
	RSA *p_rsa;
	//FILE *file;
	int flen, rsa_len;

	BIO* file = NULL;
	//生成IO对象
	file = BIO_new(BIO_s_file());
	//将Key文件读入IO
	BIO_read_filename(file, path_key);
	if (file == NULL)
	{
		perror(path_key);
		return NULL;
	}

	if ((p_rsa = PEM_read_bio_RSAPrivateKey(file, NULL, NULL, NULL)) == NULL) {
		//if((p_rsa=PEM_read_RSAPublicKey(file,NULL,NULL,NULL))==NULL){  // 换成这句死活通不过，无论是否将公钥分离源文件
		ERR_print_errors_fp(stdout);
		return NULL;
	}

	flen = (int)strlen(str);
	rsa_len = RSA_size(p_rsa);
	p_en = (char *)malloc(rsa_len + 1);
	memset(p_en, 0, rsa_len + 1);
	if (RSA_private_encrypt(flen, (unsigned char *)str, (unsigned char*)p_en, p_rsa, RSA_NO_PADDING) < 0) {
		return NULL;
	}
	RSA_free(p_rsa);
	BIO_free(file);
	return p_en;
}		//

//公钥解密
char * de_pub(char *str, char *path_key) {
	//errno_t err;
	char *p_en;
	RSA *p_rsa;
	//FILE *file;
	int flen, rsa_len;

	BIO* file = NULL;
	//生成IO对象
	file = BIO_new(BIO_s_file());
	//将Key文件读入IO
	BIO_read_filename(file, path_key);
	if (file == NULL)
	{
		perror(path_key);
		return NULL;
	}

	if ((p_rsa = PEM_read_bio_RSA_PUBKEY(file, NULL, NULL, NULL)) == NULL) {
		//if((p_rsa=PEM_read_RSAPublicKey(file,NULL,NULL,NULL))==NULL){  // 换成这句死活通不过，无论是否将公钥分离源文件
		ERR_print_errors_fp(stdout);
		return NULL;
	}

	flen = (int)strlen(str);
	rsa_len = RSA_size(p_rsa);
	p_en = (char *)malloc(rsa_len + 1);
	memset(p_en, 0, rsa_len + 1);
	if (RSA_public_decrypt(flen, (unsigned char *)str, (unsigned char*)p_en, p_rsa, RSA_NO_PADDING) < 0) {
		return NULL;
	}
	RSA_free(p_rsa);
	BIO_free(file);
	return p_en;
}		//

void generate_pem()
{
	RSA *r = RSA_new();
	int bits = 2048;
	BIGNUM *e = BN_new();
	BN_set_word(e, 65537);
	RSA_generate_key_ex(r, bits, e, NULL);

	//RSA_print_fp(stdout, r, 0);

	BIO *out;
	out = BIO_new_file(USER_PRIVPATH, "w");
	//这里生成的私钥没有加密，可选加密
	int ret = PEM_write_bio_RSAPrivateKey(out, r, NULL, NULL, 0, NULL, NULL);
	BIO *out_priv;
	
	BIO_flush(out);
	BIO_free(out);

	out = BIO_new_file(USER_PUBPATH, "w");
	ret = PEM_write_bio_RSA_PUBKEY(out, r);
	BIO_flush(out);
	BIO_free(out);

	BN_free(e);
	RSA_free(r);
}


/*
char* toStr(QString qstr)
{
	//string *str = & qstr.toStdString();
	//char *cs = new char();
	//cs = (char *)((qstr.toStdString()).c_str());
	//printf("%s", (char *)((qstr.toStdString()).c_str()));
	std::string str = qstr.toStdString();
	//char c[20];
	//printf(c);
	//return c;
	//char *cs = new char();
	//cs = (char *)((qstr.toStdString()).c_str());
	char *p = new char();
	int len = qstr.length();
	//p	= (char *)((qstr.toStdString()).c_str());
	for (int i=0; i < len; i++)
	{
		*(p + i) = str[i];
		i++;
	}
	*(p + len) = '\0';
	//char c[20];
	//return strcpy(c, (qstr.toStdString()).c_str());
	return p;
}

char * Base64Decode(char * input, int length, bool with_new_line)
{
	BIO * b64 = NULL;
	BIO * bmem = NULL;
	char * buffer = (char *)malloc(length);
	memset(buffer, 0, length);

	b64 = BIO_new(BIO_f_base64());
	if (!with_new_line) {
		BIO_set_flags(b64, BIO_FLAGS_BASE64_NO_NL);
	}
	bmem = BIO_new_mem_buf(input, length);
	bmem = BIO_push(b64, bmem);
	BIO_read(bmem, buffer, length);

	BIO_free_all(bmem);

	//printf("ddddd");
	return buffer;
}

static const char b64_table[65] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

static const char reverse_table[128] = {
   64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
   64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
   64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 64, 62, 64, 64, 64, 63,
   52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 64, 64, 64, 64, 64, 64,
   64,  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14,
   15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 64, 64, 64, 64, 64,
   64, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40,
   41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 64, 64, 64, 64, 64
};

::std::string base64_decode(const ::std::string &ascdata)
{
	using ::std::string;
	string retval;
	const string::const_iterator last = ascdata.end();
	int bits_collected = 0;
	unsigned int accumulator = 0;

	for (string::const_iterator i = ascdata.begin(); i != last; ++i) {
		const int c = *i;
		if (::std::isspace(c) || c == '=') {
			// Skip whitespace and padding. Be liberal in what you accept.
			continue;
		}
		if ((c > 127) || (c < 0) || (reverse_table[c] > 63)) {
			throw ::std::invalid_argument("This contains characters not legal in a base64 encoded string.");
		}
		accumulator = (accumulator << 6) | reverse_table[c];
		bits_collected += 6;
		if (bits_collected >= 8) {
			bits_collected -= 8;
			retval += static_cast<char>((accumulator >> bits_collected) & 0xffu);
		}
	}
	return retval;
}
*/