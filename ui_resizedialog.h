/********************************************************************************
** Form generated from reading UI file 'resizedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESIZEDIALOG_H
#define UI_RESIZEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ResizeDialog
{
public:
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *string_width;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *string_height;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ResizeDialog)
    {
        if (ResizeDialog->objectName().isEmpty())
            ResizeDialog->setObjectName(QStringLiteral("ResizeDialog"));
        ResizeDialog->resize(232, 70);
        ResizeDialog->setMinimumSize(QSize(232, 70));
        ResizeDialog->setMaximumSize(QSize(232, 70));
        QIcon icon;
        icon.addFile(QStringLiteral(":/img/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        ResizeDialog->setWindowIcon(icon);
        horizontalLayout_3 = new QHBoxLayout(ResizeDialog);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(ResizeDialog);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        string_width = new QLineEdit(ResizeDialog);
        string_width->setObjectName(QStringLiteral("string_width"));
        string_width->setAutoFillBackground(false);

        horizontalLayout->addWidget(string_width);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(ResizeDialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        string_height = new QLineEdit(ResizeDialog);
        string_height->setObjectName(QStringLiteral("string_height"));
        string_height->setAutoFillBackground(false);

        horizontalLayout_2->addWidget(string_height);


        verticalLayout->addLayout(horizontalLayout_2);


        horizontalLayout_3->addLayout(verticalLayout);

        buttonBox = new QDialogButtonBox(ResizeDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout_3->addWidget(buttonBox);


        retranslateUi(ResizeDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), ResizeDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ResizeDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(ResizeDialog);
    } // setupUi

    void retranslateUi(QDialog *ResizeDialog)
    {
        ResizeDialog->setWindowTitle(QApplication::translate("ResizeDialog", "Resize...", 0));
        label->setText(QApplication::translate("ResizeDialog", "Width ", 0));
        string_width->setText(QString());
        label_2->setText(QApplication::translate("ResizeDialog", "Height", 0));
        string_height->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ResizeDialog: public Ui_ResizeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESIZEDIALOG_H
