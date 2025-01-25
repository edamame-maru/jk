#ifndef JK_H
#define JK_H

#include <QMainWindow>
#include <QAction>
#include <QClipboard>
#include <QApplication>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QIcon>

QT_BEGIN_NAMESPACE
namespace Ui {
class jk;
}
QT_END_NAMESPACE

class jk : public QMainWindow
{
    Q_OBJECT

public:
    jk(QWidget *parent = nullptr);
    ~jk();

    // slots for menu actions
private slots:
    void onExit();
    void onCopy();
    void onCut();
    void onPaste();
    void onSelectAll();
    void onNew();
    void onOpen();
    void onSave();
    void onSaveAs();

private:
    Ui::jk *ui;

    // Member variable to track the current file name
    QString currentFile;
};

#endif // JK_H
