/********************************************************************************
** Form generated from reading UI file 'server.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERVER_H
#define UI_SERVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_server_winClass
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTextBrowser *server_encode;
    QVBoxLayout *verticalLayout_2;
    QPushButton *s_decode;
    QPushButton *m_encode;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_2;
    QTextBrowser *server_decode;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *s_send;
    QSpacerItem *horizontalSpacer;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *server_winClass)
    {
        if (server_winClass->objectName().isEmpty())
            server_winClass->setObjectName(QStringLiteral("server_winClass"));
        server_winClass->resize(660, 442);
        centralwidget = new QWidget(server_winClass);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 20, 609, 363));
        verticalLayout_4 = new QVBoxLayout(layoutWidget);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetMaximumSize);
        horizontalLayout->setContentsMargins(-1, -1, -1, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetMaximumSize);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        server_encode = new QTextBrowser(layoutWidget);
        server_encode->setObjectName(QStringLiteral("server_encode"));
        server_encode->setMinimumSize(QSize(0, 300));

        verticalLayout->addWidget(server_encode);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        s_decode = new QPushButton(layoutWidget);
        s_decode->setObjectName(QStringLiteral("s_decode"));

        verticalLayout_2->addWidget(s_decode);

        m_encode = new QPushButton(layoutWidget);
        m_encode->setObjectName(QStringLiteral("m_encode"));

        verticalLayout_2->addWidget(m_encode);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_2);

        server_decode = new QTextBrowser(layoutWidget);
        server_decode->setObjectName(QStringLiteral("server_decode"));

        verticalLayout_3->addWidget(server_decode);


        horizontalLayout->addLayout(verticalLayout_3);


        verticalLayout_4->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(88, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        s_send = new QPushButton(layoutWidget);
        s_send->setObjectName(QStringLiteral("s_send"));

        horizontalLayout_2->addWidget(s_send);

        horizontalSpacer = new QSpacerItem(418, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout_4->addLayout(horizontalLayout_2);

        server_winClass->setCentralWidget(centralwidget);
        menubar = new QMenuBar(server_winClass);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 660, 23));
        server_winClass->setMenuBar(menubar);
        statusbar = new QStatusBar(server_winClass);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        server_winClass->setStatusBar(statusbar);

        retranslateUi(server_winClass);

        QMetaObject::connectSlotsByName(server_winClass);
    } // setupUi

    void retranslateUi(QMainWindow *server_winClass)
    {
        server_winClass->setWindowTitle(QApplication::translate("server_winClass", "MainWindow", Q_NULLPTR));
        label->setText(QApplication::translate("server_winClass", "\345\257\206\346\226\207", Q_NULLPTR));
        s_decode->setText(QApplication::translate("server_winClass", "\350\247\243\345\257\206 >", Q_NULLPTR));
        m_encode->setText(QApplication::translate("server_winClass", "< \346\216\210\346\235\203\347\240\201", Q_NULLPTR));
        label_2->setText(QApplication::translate("server_winClass", "\346\230\216\346\226\207", Q_NULLPTR));
        s_send->setText(QApplication::translate("server_winClass", "\345\217\221\351\200\201", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class server_winClass: public Ui_server_winClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERVER_H
