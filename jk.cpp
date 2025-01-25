#include "jk.h"
#include "ui_jk.h"

jk::jk(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::jk), currentFile("") // Initialize currentFile to an empty string
{
    ui->setupUi(this);

    // connect menu actions to their slots
    connect(ui->actionExit, &QAction::triggered, this, &jk::onExit);
    connect(ui->actionCopy, &QAction::triggered, this, &jk::onCopy);
    connect(ui->actionCut, &QAction::triggered, this, &jk::onCut);
    connect(ui->actionPaste, &QAction::triggered, this, &jk::onPaste);
    connect(ui->actionSelectAll, &QAction::triggered, this, &jk::onSelectAll);
    connect(ui->actionNew, &QAction::triggered, this, &jk::onNew);
    connect(ui->actionOpen, &QAction::triggered, this, &jk::onOpen);
    connect(ui->actionSave, &QAction::triggered, this, &jk::onSave);
    connect(ui->actionSaveAs, &QAction::triggered, this, &jk::onSaveAs);
}

jk::~jk()
{
    delete ui;
}

//slot for "New" action
void jk::onNew() {
    ui->textEdit->clear();  // Clears the textEdit widget
    currentFile = "";      // Reset the current file name
}

// slot for "Open" action
void jk::onOpen() {
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("Text Files (*.txt);;All Files (*)"));
    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&file);
            ui->textEdit->setPlainText(in.readAll());
            file.close();
            currentFile = fileName; // Update the current file name
        }
    }
}

// slot for "Save" action
void jk::onSave() {
    if (currentFile.isEmpty()) {
        // If no file is currently open, fall back to "Save As"
        onSaveAs();
        return;
    }

    QFile file(currentFile);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        out << ui->textEdit->toPlainText();
        file.close();
    }
}

// slot for "Save As" action
void jk::onSaveAs() {
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File As"), "", tr("Text Files (*.txt);;All Files (*)"));
    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);
            out << ui->textEdit->toPlainText();
            file.close();
            currentFile = fileName; // Update the current file name
        }
    }
}

// slot for "Exit" action
void jk::onExit() {
    QApplication::quit();
}

// slot for "Copy" action
void jk::onCopy() {
    QTextEdit *textEdit = ui->textEdit;
    textEdit->copy();
}

// slot for "Cut" action
void jk::onCut() {
    QTextEdit *textEdit = ui->textEdit;
    textEdit->cut();
}

// slot for "Paste" action
void jk::onPaste() {
    QTextEdit *textEdit = ui->textEdit;
    textEdit->paste();
}

//slot for "Select All" action
void jk::onSelectAll()
{
    if (ui->textEdit) {
        ui->textEdit->selectAll();
    }
}
