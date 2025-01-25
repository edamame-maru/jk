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

    textEdit->setPlaceholderText("Press Ctrl+Q to exit; Ctrl+S to write.");

    window.setCentralWidget(textEdit);

    window.setWindowTitle("jk");
    window.resize(800, 600);
    window.show();

    // Ctrl+Q to quit.
    new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_Q), &window, [&]() {
	app.quit();
    });

    // Ctrl+S to save.
    new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_S), &window, [&]() {
        QString fileName = QFileDialog::getSaveFileName(&window, "Save File", "", "Text Files (*.txt);;All Files (*)");
        if (!fileName.isEmpty()) {
            QFile file(fileName);
            if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
                QTextStream out(&file);
                out << textEdit->toPlainText();
                file.close();
            }
        }
    }); 

    return app.exec();
}

