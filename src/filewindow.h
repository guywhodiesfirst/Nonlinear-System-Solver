#ifndef FILEWINDOW_H
#define FILEWINDOW_H

#include <QDialog>

namespace Ui {
class FileWindow;
}

class FileWindow : public QDialog
{
    Q_OBJECT

public: 
    FileWindow(QString& text, QWidget* parent = nullptr);
    ~FileWindow();
private slots:
    void copy_to_clipboard();
    void save_to_file();

private:
    Ui::FileWindow *ui;
};

#endif // FILEWINDOW_H
