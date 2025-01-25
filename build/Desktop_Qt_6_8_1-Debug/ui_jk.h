/********************************************************************************
** Form generated from reading UI file 'jk.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JK_H
#define UI_JK_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_jk
{
public:
    QAction *actionExit;
    QAction *actionCut;
    QAction *actionCopy;
    QAction *actionPaste;
    QAction *action_About;
    QAction *actionSelectAll;
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionSaveAs;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QTextEdit *textEdit;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menu_Help;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *jk)
    {
        if (jk->objectName().isEmpty())
            jk->setObjectName("jk");
        jk->resize(800, 600);
        actionExit = new QAction(jk);
        actionExit->setObjectName("actionExit");
        actionCut = new QAction(jk);
        actionCut->setObjectName("actionCut");
        actionCopy = new QAction(jk);
        actionCopy->setObjectName("actionCopy");
        actionPaste = new QAction(jk);
        actionPaste->setObjectName("actionPaste");
        action_About = new QAction(jk);
        action_About->setObjectName("action_About");
        actionSelectAll = new QAction(jk);
        actionSelectAll->setObjectName("actionSelectAll");
        actionNew = new QAction(jk);
        actionNew->setObjectName("actionNew");
        actionOpen = new QAction(jk);
        actionOpen->setObjectName("actionOpen");
        actionSave = new QAction(jk);
        actionSave->setObjectName("actionSave");
        actionSaveAs = new QAction(jk);
        actionSaveAs->setObjectName("actionSaveAs");
        centralwidget = new QWidget(jk);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName("textEdit");
        textEdit->setContextMenuPolicy(Qt::ContextMenuPolicy::DefaultContextMenu);
        textEdit->setAutoFillBackground(false);
        textEdit->setFrameShape(QFrame::Shape::NoFrame);
        textEdit->setFrameShadow(QFrame::Shadow::Plain);

        verticalLayout->addWidget(textEdit);

        jk->setCentralWidget(centralwidget);
        menubar = new QMenuBar(jk);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        menu_Help = new QMenu(menubar);
        menu_Help->setObjectName("menu_Help");
        jk->setMenuBar(menubar);
        statusbar = new QStatusBar(jk);
        statusbar->setObjectName("statusbar");
        jk->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menu_Help->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen);
        menuFile->addSeparator();
        menuFile->addAction(actionSaveAs);
        menuFile->addAction(actionSave);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menu_Help->addAction(actionCut);
        menu_Help->addAction(actionCopy);
        menu_Help->addAction(actionPaste);
        menu_Help->addSeparator();
        menu_Help->addAction(actionSelectAll);

        retranslateUi(jk);

        QMetaObject::connectSlotsByName(jk);
    } // setupUi

    void retranslateUi(QMainWindow *jk)
    {
        jk->setWindowTitle(QCoreApplication::translate("jk", "jk", nullptr));
        actionExit->setText(QCoreApplication::translate("jk", "E&xit", nullptr));
#if QT_CONFIG(shortcut)
        actionExit->setShortcut(QCoreApplication::translate("jk", "Ctrl+Q", nullptr));
#endif // QT_CONFIG(shortcut)
        actionCut->setText(QCoreApplication::translate("jk", "Cu&t", nullptr));
#if QT_CONFIG(shortcut)
        actionCut->setShortcut(QCoreApplication::translate("jk", "Ctrl+X", nullptr));
#endif // QT_CONFIG(shortcut)
        actionCopy->setText(QCoreApplication::translate("jk", "&Copy", nullptr));
#if QT_CONFIG(shortcut)
        actionCopy->setShortcut(QCoreApplication::translate("jk", "Ctrl+C", nullptr));
#endif // QT_CONFIG(shortcut)
        actionPaste->setText(QCoreApplication::translate("jk", "&Paste", nullptr));
#if QT_CONFIG(shortcut)
        actionPaste->setShortcut(QCoreApplication::translate("jk", "Ctrl+V", nullptr));
#endif // QT_CONFIG(shortcut)
        action_About->setText(QCoreApplication::translate("jk", "&About", nullptr));
        actionSelectAll->setText(QCoreApplication::translate("jk", "Select &All", nullptr));
#if QT_CONFIG(shortcut)
        actionSelectAll->setShortcut(QCoreApplication::translate("jk", "Ctrl+A", nullptr));
#endif // QT_CONFIG(shortcut)
        actionNew->setText(QCoreApplication::translate("jk", "&New", nullptr));
#if QT_CONFIG(shortcut)
        actionNew->setShortcut(QCoreApplication::translate("jk", "Ctrl+N", nullptr));
#endif // QT_CONFIG(shortcut)
        actionOpen->setText(QCoreApplication::translate("jk", "&Open", nullptr));
#if QT_CONFIG(shortcut)
        actionOpen->setShortcut(QCoreApplication::translate("jk", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSave->setText(QCoreApplication::translate("jk", "&Save", nullptr));
#if QT_CONFIG(shortcut)
        actionSave->setShortcut(QCoreApplication::translate("jk", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSaveAs->setText(QCoreApplication::translate("jk", "Save &As...", nullptr));
#if QT_CONFIG(shortcut)
        actionSaveAs->setShortcut(QCoreApplication::translate("jk", "Ctrl+Shift+S", nullptr));
#endif // QT_CONFIG(shortcut)
        menuFile->setTitle(QCoreApplication::translate("jk", "&File", nullptr));
        menu_Help->setTitle(QCoreApplication::translate("jk", "&Edit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class jk: public Ui_jk {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JK_H
