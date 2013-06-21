/********************************************************************************
** Form generated from reading UI file 'painter.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAINTER_H
#define UI_PAINTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "colorbox.h"
#include "paintarea.h"

QT_BEGIN_NAMESPACE

class Ui_Painter
{
public:
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionSave_As;
    QAction *actionExit;
    QAction *actionRecover;
    QAction *actionRedo;
    QAction *actionAbout;
    QAction *actionCut;
    QAction *actionCopy;
    QAction *actionPaste;
    QAction *actionAbout_Qt;
    QAction *actionResize;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_12;
    QVBoxLayout *verticalLayout_2;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *toolbox;
    QVBoxLayout *settings;
    QVBoxLayout *tools;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *tool_Cursor;
    QPushButton *tool_pencil;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *tool_eraser;
    QPushButton *tool_line;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *tool_rectangle;
    QPushButton *tool_eclipse;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *tool_RoundRect;
    QPushButton *tool_word;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *tool_Bucket;
    QPushButton *tool_Select;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *tool_spray;
    QPushButton *tool_glass;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QLineEdit *width_string;
    QPushButton *setwidth;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_11;
    QLineEdit *spray_string;
    QPushButton *setSpray;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_8;
    QFrame *color_pen_frame;
    ColorBox *color_pen;
    QFrame *color_back_frame;
    ColorBox *color_back;
    QLabel *label_3;
    QLabel *label_Font;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *set_Font;
    QSpacerItem *verticalSpacer;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QFormLayout *formLayout;
    PaintArea *paint_area;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuAbout;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Painter)
    {
        if (Painter->objectName().isEmpty())
            Painter->setObjectName(QStringLiteral("Painter"));
        Painter->resize(800, 640);
        Painter->setMinimumSize(QSize(800, 640));
        QIcon icon;
        icon.addFile(QStringLiteral(":/img/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        Painter->setWindowIcon(icon);
        actionNew = new QAction(Painter);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        actionOpen = new QAction(Painter);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionSave = new QAction(Painter);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionSave_As = new QAction(Painter);
        actionSave_As->setObjectName(QStringLiteral("actionSave_As"));
        actionExit = new QAction(Painter);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionRecover = new QAction(Painter);
        actionRecover->setObjectName(QStringLiteral("actionRecover"));
        actionRecover->setEnabled(false);
        actionRedo = new QAction(Painter);
        actionRedo->setObjectName(QStringLiteral("actionRedo"));
        actionRedo->setEnabled(false);
        actionAbout = new QAction(Painter);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionCut = new QAction(Painter);
        actionCut->setObjectName(QStringLiteral("actionCut"));
        actionCut->setEnabled(false);
        actionCopy = new QAction(Painter);
        actionCopy->setObjectName(QStringLiteral("actionCopy"));
        actionCopy->setEnabled(false);
        actionPaste = new QAction(Painter);
        actionPaste->setObjectName(QStringLiteral("actionPaste"));
        actionPaste->setEnabled(false);
        actionAbout_Qt = new QAction(Painter);
        actionAbout_Qt->setObjectName(QStringLiteral("actionAbout_Qt"));
        actionResize = new QAction(Painter);
        actionResize->setObjectName(QStringLiteral("actionResize"));
        centralWidget = new QWidget(Painter);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_12 = new QHBoxLayout(centralWidget);
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        frame = new QFrame(centralWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setMinimumSize(QSize(125, 0));
        frame->setMaximumSize(QSize(130, 16777215));
        frame->setFrameShape(QFrame::Panel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        toolbox = new QVBoxLayout();
        toolbox->setSpacing(6);
        toolbox->setObjectName(QStringLiteral("toolbox"));
        settings = new QVBoxLayout();
        settings->setSpacing(6);
        settings->setObjectName(QStringLiteral("settings"));
        tools = new QVBoxLayout();
        tools->setSpacing(6);
        tools->setObjectName(QStringLiteral("tools"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        tool_Cursor = new QPushButton(frame);
        tool_Cursor->setObjectName(QStringLiteral("tool_Cursor"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(50);
        sizePolicy.setVerticalStretch(35);
        sizePolicy.setHeightForWidth(tool_Cursor->sizePolicy().hasHeightForWidth());
        tool_Cursor->setSizePolicy(sizePolicy);
        tool_Cursor->setMinimumSize(QSize(50, 40));
        tool_Cursor->setMaximumSize(QSize(50, 40));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/img/tool_arrow.png"), QSize(), QIcon::Normal, QIcon::Off);
        tool_Cursor->setIcon(icon1);
        tool_Cursor->setIconSize(QSize(32, 32));

        horizontalLayout_2->addWidget(tool_Cursor);

        tool_pencil = new QPushButton(frame);
        tool_pencil->setObjectName(QStringLiteral("tool_pencil"));
        sizePolicy.setHeightForWidth(tool_pencil->sizePolicy().hasHeightForWidth());
        tool_pencil->setSizePolicy(sizePolicy);
        tool_pencil->setMinimumSize(QSize(50, 40));
        tool_pencil->setMaximumSize(QSize(50, 40));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/img/tool_pencil.png"), QSize(), QIcon::Normal, QIcon::Off);
        tool_pencil->setIcon(icon2);
        tool_pencil->setIconSize(QSize(32, 32));

        horizontalLayout_2->addWidget(tool_pencil);


        tools->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        tool_eraser = new QPushButton(frame);
        tool_eraser->setObjectName(QStringLiteral("tool_eraser"));
        sizePolicy.setHeightForWidth(tool_eraser->sizePolicy().hasHeightForWidth());
        tool_eraser->setSizePolicy(sizePolicy);
        tool_eraser->setMinimumSize(QSize(50, 40));
        tool_eraser->setMaximumSize(QSize(50, 40));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/img/tool_eraser.gif"), QSize(), QIcon::Normal, QIcon::Off);
        tool_eraser->setIcon(icon3);
        tool_eraser->setIconSize(QSize(32, 32));

        horizontalLayout_3->addWidget(tool_eraser);

        tool_line = new QPushButton(frame);
        tool_line->setObjectName(QStringLiteral("tool_line"));
        sizePolicy.setHeightForWidth(tool_line->sizePolicy().hasHeightForWidth());
        tool_line->setSizePolicy(sizePolicy);
        tool_line->setMinimumSize(QSize(50, 40));
        tool_line->setMaximumSize(QSize(50, 40));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/img/tool_line.gif"), QSize(), QIcon::Normal, QIcon::Off);
        tool_line->setIcon(icon4);
        tool_line->setIconSize(QSize(32, 32));

        horizontalLayout_3->addWidget(tool_line);


        tools->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        tool_rectangle = new QPushButton(frame);
        tool_rectangle->setObjectName(QStringLiteral("tool_rectangle"));
        sizePolicy.setHeightForWidth(tool_rectangle->sizePolicy().hasHeightForWidth());
        tool_rectangle->setSizePolicy(sizePolicy);
        tool_rectangle->setMinimumSize(QSize(50, 35));
        tool_rectangle->setMaximumSize(QSize(50, 40));
        tool_rectangle->setCursor(QCursor(Qt::ArrowCursor));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/img/tool_rectangle.png"), QSize(), QIcon::Normal, QIcon::Off);
        tool_rectangle->setIcon(icon5);
        tool_rectangle->setIconSize(QSize(32, 32));

        horizontalLayout_4->addWidget(tool_rectangle);

        tool_eclipse = new QPushButton(frame);
        tool_eclipse->setObjectName(QStringLiteral("tool_eclipse"));
        sizePolicy.setHeightForWidth(tool_eclipse->sizePolicy().hasHeightForWidth());
        tool_eclipse->setSizePolicy(sizePolicy);
        tool_eclipse->setMinimumSize(QSize(50, 40));
        tool_eclipse->setMaximumSize(QSize(50, 40));
        tool_eclipse->setCursor(QCursor(Qt::ArrowCursor));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/img/tool_eclipse.png"), QSize(), QIcon::Normal, QIcon::Off);
        tool_eclipse->setIcon(icon6);
        tool_eclipse->setIconSize(QSize(32, 32));

        horizontalLayout_4->addWidget(tool_eclipse);


        tools->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        tool_RoundRect = new QPushButton(frame);
        tool_RoundRect->setObjectName(QStringLiteral("tool_RoundRect"));
        sizePolicy.setHeightForWidth(tool_RoundRect->sizePolicy().hasHeightForWidth());
        tool_RoundRect->setSizePolicy(sizePolicy);
        tool_RoundRect->setMinimumSize(QSize(50, 40));
        tool_RoundRect->setMaximumSize(QSize(50, 40));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/img/tool_rectangle2.png"), QSize(), QIcon::Normal, QIcon::Off);
        tool_RoundRect->setIcon(icon7);
        tool_RoundRect->setIconSize(QSize(32, 32));

        horizontalLayout_5->addWidget(tool_RoundRect);

        tool_word = new QPushButton(frame);
        tool_word->setObjectName(QStringLiteral("tool_word"));
        tool_word->setMinimumSize(QSize(50, 40));
        tool_word->setMaximumSize(QSize(50, 40));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/img/tool_word.gif"), QSize(), QIcon::Normal, QIcon::Off);
        tool_word->setIcon(icon8);
        tool_word->setIconSize(QSize(32, 32));

        horizontalLayout_5->addWidget(tool_word);


        tools->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        tool_Bucket = new QPushButton(frame);
        tool_Bucket->setObjectName(QStringLiteral("tool_Bucket"));
        sizePolicy.setHeightForWidth(tool_Bucket->sizePolicy().hasHeightForWidth());
        tool_Bucket->setSizePolicy(sizePolicy);
        tool_Bucket->setMinimumSize(QSize(50, 40));
        tool_Bucket->setMaximumSize(QSize(50, 40));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/img/tool_bucket.png"), QSize(), QIcon::Normal, QIcon::Off);
        tool_Bucket->setIcon(icon9);
        tool_Bucket->setIconSize(QSize(32, 32));

        horizontalLayout_6->addWidget(tool_Bucket);

        tool_Select = new QPushButton(frame);
        tool_Select->setObjectName(QStringLiteral("tool_Select"));
        sizePolicy.setHeightForWidth(tool_Select->sizePolicy().hasHeightForWidth());
        tool_Select->setSizePolicy(sizePolicy);
        tool_Select->setMinimumSize(QSize(50, 40));
        tool_Select->setMaximumSize(QSize(50, 40));
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/img/tool_select.gif"), QSize(), QIcon::Normal, QIcon::Off);
        tool_Select->setIcon(icon10);
        tool_Select->setIconSize(QSize(32, 32));

        horizontalLayout_6->addWidget(tool_Select);


        tools->addLayout(horizontalLayout_6);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        tool_spray = new QPushButton(frame);
        tool_spray->setObjectName(QStringLiteral("tool_spray"));
        sizePolicy.setHeightForWidth(tool_spray->sizePolicy().hasHeightForWidth());
        tool_spray->setSizePolicy(sizePolicy);
        tool_spray->setMinimumSize(QSize(50, 40));
        tool_spray->setMaximumSize(QSize(50, 40));
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/img/cursor_spray.png"), QSize(), QIcon::Normal, QIcon::Off);
        tool_spray->setIcon(icon11);
        tool_spray->setIconSize(QSize(32, 32));

        horizontalLayout_10->addWidget(tool_spray);

        tool_glass = new QPushButton(frame);
        tool_glass->setObjectName(QStringLiteral("tool_glass"));
        tool_glass->setMinimumSize(QSize(50, 40));
        tool_glass->setMaximumSize(QSize(50, 40));
        QIcon icon12;
        icon12.addFile(QStringLiteral(":/img/cursor_glass.png"), QSize(), QIcon::Normal, QIcon::Off);
        tool_glass->setIcon(icon12);
        tool_glass->setIconSize(QSize(32, 32));

        horizontalLayout_10->addWidget(tool_glass);


        tools->addLayout(horizontalLayout_10);


        settings->addLayout(tools);

        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);

        settings->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        width_string = new QLineEdit(frame);
        width_string->setObjectName(QStringLiteral("width_string"));

        horizontalLayout->addWidget(width_string);

        setwidth = new QPushButton(frame);
        setwidth->setObjectName(QStringLiteral("setwidth"));
        setwidth->setMinimumSize(QSize(50, 25));
        setwidth->setMaximumSize(QSize(50, 30));

        horizontalLayout->addWidget(setwidth);


        settings->addLayout(horizontalLayout);

        label_4 = new QLabel(frame);
        label_4->setObjectName(QStringLiteral("label_4"));

        settings->addWidget(label_4);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        spray_string = new QLineEdit(frame);
        spray_string->setObjectName(QStringLiteral("spray_string"));

        horizontalLayout_11->addWidget(spray_string);

        setSpray = new QPushButton(frame);
        setSpray->setObjectName(QStringLiteral("setSpray"));
        setSpray->setMinimumSize(QSize(50, 25));
        setSpray->setMaximumSize(QSize(50, 30));

        horizontalLayout_11->addWidget(setSpray);


        settings->addLayout(horizontalLayout_11);

        label_2 = new QLabel(frame);
        label_2->setObjectName(QStringLiteral("label_2"));

        settings->addWidget(label_2);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        color_pen_frame = new QFrame(frame);
        color_pen_frame->setObjectName(QStringLiteral("color_pen_frame"));
        color_pen_frame->setMinimumSize(QSize(50, 30));
        color_pen_frame->setLayoutDirection(Qt::RightToLeft);
        color_pen_frame->setAutoFillBackground(true);
        color_pen_frame->setFrameShape(QFrame::Box);
        color_pen_frame->setFrameShadow(QFrame::Raised);
        color_pen = new ColorBox(color_pen_frame);
        color_pen->setObjectName(QStringLiteral("color_pen"));
        color_pen->setGeometry(QRect(0, 0, 50, 30));
        color_pen->setMinimumSize(QSize(50, 30));
        color_pen->setMaximumSize(QSize(50, 30));
        color_pen->setLayoutDirection(Qt::LeftToRight);
        color_pen->setAutoFillBackground(true);

        horizontalLayout_8->addWidget(color_pen_frame);

        color_back_frame = new QFrame(frame);
        color_back_frame->setObjectName(QStringLiteral("color_back_frame"));
        color_back_frame->setMinimumSize(QSize(50, 30));
        color_back_frame->setLayoutDirection(Qt::RightToLeft);
        color_back_frame->setAutoFillBackground(true);
        color_back_frame->setFrameShape(QFrame::Box);
        color_back_frame->setFrameShadow(QFrame::Raised);
        color_back = new ColorBox(color_back_frame);
        color_back->setObjectName(QStringLiteral("color_back"));
        color_back->setGeometry(QRect(0, 0, 50, 30));
        color_back->setMinimumSize(QSize(50, 30));
        color_back->setMaximumSize(QSize(50, 30));
        color_back->setLayoutDirection(Qt::LeftToRight);
        color_back->setAutoFillBackground(true);

        horizontalLayout_8->addWidget(color_back_frame);


        settings->addLayout(horizontalLayout_8);

        label_3 = new QLabel(frame);
        label_3->setObjectName(QStringLiteral("label_3"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy2);

        settings->addWidget(label_3);

        label_Font = new QLabel(frame);
        label_Font->setObjectName(QStringLiteral("label_Font"));
        sizePolicy2.setHeightForWidth(label_Font->sizePolicy().hasHeightForWidth());
        label_Font->setSizePolicy(sizePolicy2);

        settings->addWidget(label_Font);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        set_Font = new QPushButton(frame);
        set_Font->setObjectName(QStringLiteral("set_Font"));
        sizePolicy2.setHeightForWidth(set_Font->sizePolicy().hasHeightForWidth());
        set_Font->setSizePolicy(sizePolicy2);

        horizontalLayout_9->addWidget(set_Font);


        settings->addLayout(horizontalLayout_9);


        toolbox->addLayout(settings);


        verticalLayout->addLayout(toolbox);


        verticalLayout_2->addWidget(frame);

        verticalSpacer = new QSpacerItem(20, 16777215, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout_12->addLayout(verticalLayout_2);

        scrollArea = new QScrollArea(centralWidget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 386, 579));
        formLayout = new QFormLayout(scrollAreaWidgetContents);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        paint_area = new PaintArea(scrollAreaWidgetContents);
        paint_area->setObjectName(QStringLiteral("paint_area"));
        sizePolicy2.setHeightForWidth(paint_area->sizePolicy().hasHeightForWidth());
        paint_area->setSizePolicy(sizePolicy2);
        paint_area->setMinimumSize(QSize(0, 0));

        formLayout->setWidget(0, QFormLayout::LabelRole, paint_area);

        scrollArea->setWidget(scrollAreaWidgetContents);

        horizontalLayout_12->addWidget(scrollArea);

        Painter->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Painter);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuAbout = new QMenu(menuBar);
        menuAbout->setObjectName(QStringLiteral("menuAbout"));
        Painter->setMenuBar(menuBar);
        statusBar = new QStatusBar(Painter);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Painter->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuAbout->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_As);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuFile->addSeparator();
        menuEdit->addAction(actionRecover);
        menuEdit->addAction(actionRedo);
        menuEdit->addSeparator();
        menuEdit->addAction(actionCut);
        menuEdit->addAction(actionCopy);
        menuEdit->addAction(actionPaste);
        menuEdit->addSeparator();
        menuEdit->addAction(actionResize);
        menuAbout->addAction(actionAbout);
        menuAbout->addAction(actionAbout_Qt);

        retranslateUi(Painter);

        QMetaObject::connectSlotsByName(Painter);
    } // setupUi

    void retranslateUi(QMainWindow *Painter)
    {
        Painter->setWindowTitle(QApplication::translate("Painter", "Painter", 0));
        actionNew->setText(QApplication::translate("Painter", "New", 0));
#ifndef QT_NO_TOOLTIP
        actionNew->setToolTip(QApplication::translate("Painter", "Create a new image.", 0));
#endif // QT_NO_TOOLTIP
        actionNew->setShortcut(QApplication::translate("Painter", "Ctrl+N", 0));
        actionOpen->setText(QApplication::translate("Painter", "Open", 0));
#ifndef QT_NO_TOOLTIP
        actionOpen->setToolTip(QApplication::translate("Painter", "Open a image file.", 0));
#endif // QT_NO_TOOLTIP
        actionOpen->setShortcut(QApplication::translate("Painter", "Ctrl+O", 0));
        actionSave->setText(QApplication::translate("Painter", "Save", 0));
#ifndef QT_NO_TOOLTIP
        actionSave->setToolTip(QApplication::translate("Painter", "Save the image.", 0));
#endif // QT_NO_TOOLTIP
        actionSave->setShortcut(QApplication::translate("Painter", "Ctrl+S", 0));
        actionSave_As->setText(QApplication::translate("Painter", "Save As...", 0));
#ifndef QT_NO_TOOLTIP
        actionSave_As->setToolTip(QApplication::translate("Painter", "Save the image as a new file.", 0));
#endif // QT_NO_TOOLTIP
        actionSave_As->setShortcut(QApplication::translate("Painter", "Ctrl+Shift+S", 0));
        actionExit->setText(QApplication::translate("Painter", "Exit", 0));
#ifndef QT_NO_TOOLTIP
        actionExit->setToolTip(QApplication::translate("Painter", "Exit the application.", 0));
#endif // QT_NO_TOOLTIP
        actionExit->setShortcut(QApplication::translate("Painter", "Ctrl+Q", 0));
        actionRecover->setText(QApplication::translate("Painter", "Undo", 0));
        actionRecover->setShortcut(QApplication::translate("Painter", "Ctrl+Z", 0));
        actionRedo->setText(QApplication::translate("Painter", "Redo", 0));
        actionRedo->setShortcut(QApplication::translate("Painter", "Ctrl+R", 0));
        actionAbout->setText(QApplication::translate("Painter", "About", 0));
        actionCut->setText(QApplication::translate("Painter", "Cut", 0));
        actionCut->setShortcut(QApplication::translate("Painter", "Ctrl+X", 0));
        actionCopy->setText(QApplication::translate("Painter", "Copy", 0));
        actionCopy->setShortcut(QApplication::translate("Painter", "Ctrl+C", 0));
        actionPaste->setText(QApplication::translate("Painter", "Paste", 0));
        actionPaste->setShortcut(QApplication::translate("Painter", "Ctrl+V", 0));
        actionAbout_Qt->setText(QApplication::translate("Painter", "About Qt", 0));
        actionResize->setText(QApplication::translate("Painter", "Resize", 0));
        tool_Cursor->setText(QString());
        tool_pencil->setText(QString());
        tool_eraser->setText(QString());
        tool_line->setText(QString());
        tool_rectangle->setText(QString());
        tool_eclipse->setText(QString());
        tool_RoundRect->setText(QString());
        tool_word->setText(QString());
        tool_Bucket->setText(QString());
        tool_Select->setText(QString());
        tool_spray->setText(QString());
        tool_glass->setText(QString());
        label->setText(QApplication::translate("Painter", "Pen Width", 0));
        width_string->setText(QApplication::translate("Painter", "1", 0));
        setwidth->setText(QApplication::translate("Painter", "Ok", 0));
        label_4->setText(QApplication::translate("Painter", "Spray Width", 0));
        spray_string->setText(QApplication::translate("Painter", "10", 0));
        setSpray->setText(QApplication::translate("Painter", "Ok", 0));
        label_2->setText(QApplication::translate("Painter", "Color", 0));
        label_3->setText(QApplication::translate("Painter", "Font", 0));
        label_Font->setText(QApplication::translate("Painter", "Font 123456789", 0));
        set_Font->setText(QApplication::translate("Painter", "Change Font", 0));
        menuFile->setTitle(QApplication::translate("Painter", "File", 0));
        menuEdit->setTitle(QApplication::translate("Painter", "Edit", 0));
        menuAbout->setTitle(QApplication::translate("Painter", "Help", 0));
    } // retranslateUi

};

namespace Ui {
    class Painter: public Ui_Painter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAINTER_H
