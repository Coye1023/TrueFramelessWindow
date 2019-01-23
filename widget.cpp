#include "widget.h"

#include <QLabel>
#include <QLayout>
#include <QApplication>
#include <QStyle>

Widget::Widget(QWidget *parent)
	: QMainWindow(parent)
{
	//Set a black background for funsies
	QPalette Pal(palette());
	Pal.setColor(QPalette::Background, Qt::darkGray);
	setAutoFillBackground(true);
	setPalette(Pal);

	//Windows example of adding a toolbar + min/max/close buttons

	//Add the toolbar
	toolBar = new QToolBar(this);
	toolBar->setStyleSheet("QToolBar{background-color: lightGray; border: none;}");
	toolBar->setMovable(false);
	toolBar->setFloatable(false);
	addToolBar(toolBar);

	QLabel *windowIcon = new QLabel();
	windowIcon->setFixedSize(24, 24);
	windowIcon->setAttribute(Qt::WA_TransparentForMouseEvents);
	windowIcon->setAlignment(Qt::AlignCenter);
	windowIcon->setPixmap(QApplication::style()->standardIcon((QStyle::StandardPixmap)0).pixmap(16, 16));
	toolBar->addWidget(windowIcon);

	QLabel* titleLabel = new QLabel("TrueFramelessWindow");
	titleLabel->setFixedWidth(160); 
	titleLabel->setAttribute(Qt::WA_TransparentForMouseEvents);
	toolBar->addWidget(titleLabel);

	QWidget* rightSpacer = new QWidget(toolBar);
	rightSpacer->setAttribute(Qt::WA_TransparentForMouseEvents);
	rightSpacer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	rightSpacer->setStyleSheet("background-color: none; border: none;");
	toolBar->addWidget(rightSpacer);

	//An actual app should use icons for the buttons instead of text
	//and style the different button states / widget margins in css
	minimizeButton = new QToolButton();
	minimizeButton->setText("-");

	maximizeButton = new QToolButton();
	maximizeButton->setText("O");

	closeButton = new QToolButton();
	closeButton->setText("X");

	minimizeButton->setAutoRaise(true);
	maximizeButton->setAutoRaise(true);
	closeButton->setAutoRaise(true);

	minimizeButton->setFixedSize(28, 28);
	maximizeButton->setFixedSize(28, 28);
	closeButton->setFixedSize(28, 28);

	toolBar->addWidget(minimizeButton);
	toolBar->addWidget(maximizeButton);
	toolBar->addWidget(closeButton);
}
