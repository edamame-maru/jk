#include <QApplication>
#include <QMainWindow>
#include <QTextEdit>
#include <QFont>
#include <QShortcut>
#include <QKeySequence>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QMainWindow window;
    QTextEdit *textEdit = new QTextEdit(&window);

    QFont font = textEdit->font();
    font.setPointSize(11);
    textEdit->setFont(font);

    textEdit->setPlaceholderText("Press Ctrl+Q to exit.");

    window.setCentralWidget(textEdit);

    window.setWindowTitle("jk");
    window.resize(800, 600);
    window.show();

    new QShortcut(QKeySequence(Qt::CTRL + Qt::Key_Q), &window, [&]() {
	app.quit();
    });

    return app.exec();
}

