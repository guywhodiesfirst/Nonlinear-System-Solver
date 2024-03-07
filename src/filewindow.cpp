#include "filewindow.h"
#include "ui_filewindow.h"
#include <qclipboard.h>
#include <qfile.h>
#include <qtextstream.h>
#include <qmessagebox.h>
#include <qfiledialog.h>

FileWindow::FileWindow(QString& text, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FileWindow)
{
    ui->setupUi(this);
    ui->solved_system->setPlainText(text);
    ui->solved_system->setReadOnly(true); // Користувач не зможе змінювати текст

    // З'єднуємо сигнали при натисканні кнопок copyButton та saveButton з відповідними слотами
    connect(ui->copyButton, &QPushButton::clicked, this, &FileWindow::copy_to_clipboard);
    connect(ui->saveButton, &QPushButton::clicked, this, &FileWindow::save_to_file);

    setWindowTitle("NonlinearSystemSolver");
}

FileWindow::~FileWindow()
{
    delete ui;
}

// Копіює інформацію з текстового поля solved_system до буферу обміну
// та виводить відповідне повідомлення
void FileWindow::copy_to_clipboard()
{
    QClipboard* clipbrd = QApplication::clipboard();
    QString txt = ui->solved_system->toPlainText();
    clipbrd->setText(txt);
    QMessageBox::information(this, "Info", "Results copied to the clipboard");
}

// Пропонує користувачу обрати файл на пристрої та заносить до нього 
// вхідні дані, результуючий вектор та покроковий розв'язок
void FileWindow::save_to_file()
{
    QString filename = QFileDialog::getSaveFileName(this, ("Choose file"), QDir::homePath(), "Text Files (*.txt)");
    QFile file(filename);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream stream(&file);
        stream << ui->solved_system->toPlainText();
    }
    else
    {
        QMessageBox::warning(this, "Error", "File not found");
    }
    file.close();
}