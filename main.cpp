#include <QApplication>
#include <QMainWindow>
#include <QTextEdit>
#include <QFont>
#include <QShortcut>
#include <QKeySequence>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QMainWindow window;
    QTextEdit *textEdit = new QTextEdit(&window);

    QFont font = textEdit->font();
    font.setPointSize(11);
    textEdit->setFont(font);

    textEdit->setPlaceholderText("Press Ctrl+Q to exit; Ctrl+S to save; Ctrl+O to open.");

    window.setCentralWidget(textEdit);

    window.setWindowTitle("jk");
    window.resize(800, 600);
    window.show();

    // To keep track of the current file path
    QString currentFilePath;

    // Ctrl+Q to quit.
    new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_Q), &window, [&]() {
        app.quit();
    });

    // Ctrl+O to open a file.
    new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_O), &window, [&]() {
        QString fileName = QFileDialog::getOpenFileName(&window, "Open File", "", "All Files (*)");
        if (!fileName.isEmpty()) {
            QFile file(fileName);
            if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
                QTextStream in(&file);
                textEdit->setPlainText(in.readAll());
                file.close();
                currentFilePath = fileName; // Save the current file path
            } else {
                textEdit->setPlainText("Could not open the file.");
            }
        }
    });

    // Ctrl+S to save.
    new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_S), &window, [&]() {
        if (currentFilePath.isEmpty()) {
            // If no file is opened, prompt the user to save it as a new file.
            QString fileName = QFileDialog::getSaveFileName(&window, "Save File", "", "All Files (*)");
            if (!fileName.isEmpty()) {
                QFile file(fileName);
                if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
                    QTextStream out(&file);
                    out << textEdit->toPlainText();
                    file.close();
                    currentFilePath = fileName; // Update the current file path
                }
            }
        } else {
            // Save to the currently opened file.
            QFile file(currentFilePath);
            if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
                QTextStream out(&file);
                out << textEdit->toPlainText();
                file.close();
            }
        }
    });

    return app.exec();
}
