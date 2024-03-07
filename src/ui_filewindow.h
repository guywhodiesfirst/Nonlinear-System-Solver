/********************************************************************************
** Form generated from reading UI file 'filewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILEWINDOW_H
#define UI_FILEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_FileWindow
{
public:
    QPlainTextEdit *solved_system;
    QPushButton *copyButton;
    QPushButton *saveButton;

    void setupUi(QDialog *FileWindow)
    {
        if (FileWindow->objectName().isEmpty())
            FileWindow->setObjectName("FileWindow");
        FileWindow->resize(617, 377);
        solved_system = new QPlainTextEdit(FileWindow);
        solved_system->setObjectName("solved_system");
        solved_system->setGeometry(QRect(160, 10, 291, 301));
        copyButton = new QPushButton(FileWindow);
        copyButton->setObjectName("copyButton");
        copyButton->setGeometry(QRect(160, 320, 141, 24));
        saveButton = new QPushButton(FileWindow);
        saveButton->setObjectName("saveButton");
        saveButton->setGeometry(QRect(310, 320, 141, 24));

        retranslateUi(FileWindow);

        QMetaObject::connectSlotsByName(FileWindow);
    } // setupUi

    void retranslateUi(QDialog *FileWindow)
    {
        FileWindow->setWindowTitle(QCoreApplication::translate("FileWindow", "Dialog", nullptr));
        copyButton->setText(QCoreApplication::translate("FileWindow", "\320\241\320\272\320\276\320\277\321\226\321\216\320\262\320\260\321\202\320\270", nullptr));
        saveButton->setText(QCoreApplication::translate("FileWindow", "\320\227\320\261\320\265\321\200\320\265\320\263\321\202\320\270 \320\264\320\276 \321\204\320\260\320\271\320\273\321\203", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FileWindow: public Ui_FileWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILEWINDOW_H
