/********************************************************************************
** Form generated from reading UI file 'openssl_win.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPENSSL_WIN_H
#define UI_OPENSSL_WIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_openssl_winClass
{
public:
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    QTextBrowser *user_pub;
    QLabel *label;
    QLabel *label_2;
    QTextBrowser *user_priv;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QTextEdit *user_name;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QTextBrowser *user_decode;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_4;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_2;
    QPushButton *gen_key;
    QSpacerItem *verticalSpacer;
    QPushButton *decode;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *horizontalSpacer_3;
    QTextEdit *user_encode;
    QPushButton *send;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *openssl_winClass)
    {
        if (openssl_winClass->objectName().isEmpty())
            openssl_winClass->setObjectName(QStringLiteral("openssl_winClass"));
        openssl_winClass->resize(812, 826);
        centralWidget = new QWidget(openssl_winClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 736, 738));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetMinimumSize);
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        user_pub = new QTextBrowser(layoutWidget);
        user_pub->setObjectName(QStringLiteral("user_pub"));

        gridLayout->addWidget(user_pub, 1, 0, 1, 1);

        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 1, 1, 1);

        user_priv = new QTextBrowser(layoutWidget);
        user_priv->setObjectName(QStringLiteral("user_priv"));

        gridLayout->addWidget(user_priv, 1, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout);

        widget = new QWidget(layoutWidget);
        widget->setObjectName(QStringLiteral("widget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        widget->setMaximumSize(QSize(16777215, 60));
        horizontalLayout_3 = new QHBoxLayout(widget);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        user_name = new QTextEdit(widget);
        user_name->setObjectName(QStringLiteral("user_name"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(user_name->sizePolicy().hasHeightForWidth());
        user_name->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(user_name);

        horizontalSpacer = new QSpacerItem(330, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);


        verticalLayout_2->addWidget(widget);


        verticalLayout_3->addLayout(verticalLayout_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        user_decode = new QTextBrowser(layoutWidget);
        user_decode->setObjectName(QStringLiteral("user_decode"));

        horizontalLayout_2->addWidget(user_decode);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetMinimumSize);
        horizontalSpacer_4 = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalSpacer_2 = new QSpacerItem(20, 68, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        gen_key = new QPushButton(layoutWidget);
        gen_key->setObjectName(QStringLiteral("gen_key"));

        verticalLayout->addWidget(gen_key);

        verticalSpacer = new QSpacerItem(20, 58, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        decode = new QPushButton(layoutWidget);
        decode->setObjectName(QStringLiteral("decode"));

        verticalLayout->addWidget(decode);

        verticalSpacer_3 = new QSpacerItem(20, 98, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);


        horizontalLayout->addLayout(verticalLayout);

        horizontalSpacer_3 = new QSpacerItem(18, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);


        horizontalLayout_2->addLayout(horizontalLayout);

        user_encode = new QTextEdit(layoutWidget);
        user_encode->setObjectName(QStringLiteral("user_encode"));

        horizontalLayout_2->addWidget(user_encode);

        send = new QPushButton(layoutWidget);
        send->setObjectName(QStringLiteral("send"));

        horizontalLayout_2->addWidget(send);


        verticalLayout_3->addLayout(horizontalLayout_2);

        openssl_winClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(openssl_winClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 812, 23));
        openssl_winClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(openssl_winClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        openssl_winClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(openssl_winClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        openssl_winClass->setStatusBar(statusBar);

        retranslateUi(openssl_winClass);

        QMetaObject::connectSlotsByName(openssl_winClass);
    } // setupUi

    void retranslateUi(QMainWindow *openssl_winClass)
    {
        openssl_winClass->setWindowTitle(QApplication::translate("openssl_winClass", "openssl_win", Q_NULLPTR));
        label->setText(QApplication::translate("openssl_winClass", "\347\224\250\346\210\267\345\205\254\351\222\245", Q_NULLPTR));
        label_2->setText(QApplication::translate("openssl_winClass", "\347\224\250\346\210\267\347\247\201\351\222\245", Q_NULLPTR));
        label_3->setText(QApplication::translate("openssl_winClass", "\347\224\250\346\210\267\345\220\215", Q_NULLPTR));
        gen_key->setText(QApplication::translate("openssl_winClass", "\347\224\237\346\210\220\345\207\255\350\257\201 >", Q_NULLPTR));
        decode->setText(QApplication::translate("openssl_winClass", "< \346\230\216\346\226\207", Q_NULLPTR));
        send->setText(QApplication::translate("openssl_winClass", "\345\217\221\351\200\201", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class openssl_winClass: public Ui_openssl_winClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPENSSL_WIN_H
