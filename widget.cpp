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
#ifdef _WIN32

	//Add the toolbar
	toolBar = new QToolBar(this);
	toolBar->setStyleSheet("QToolBar{background-color: lightGray; border: none;}");
	toolBar->setMovable(false);
	toolBar->setFloatable(false);
	addToolBar(toolBar);

	//Create a transparent-to-mouse-events widget that pads right for a fixed width equivalent to min/max/close buttons
	//QWidget* btnSpacer = new QWidget(toolBar);
	//btnSpacer->setAttribute(Qt::WA_TransparentForMouseEvents);
	//btnSpacer->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
	////btnSpacer->setStyleSheet("background-color: none; border: none;");
	//btnSpacer->setFixedWidth(135 /* rough width of close/min/max buttons */);
	//toolBar->addWidget(btnSpacer);
	QLabel *windowIcon = new QLabel();
	windowIcon->setFixedSize(24, 24);
	windowIcon->setAttribute(Qt::WA_TransparentForMouseEvents);
	windowIcon->setAlignment(Qt::AlignCenter);
	windowIcon->setPixmap(QApplication::style()->standardIcon((QStyle::StandardPixmap)0).pixmap(16, 16));
	toolBar->addWidget(windowIcon);

	//Create a title label just because
	QLabel* titleLabel = new QLabel("TrueFramelessWindow");
	titleLabel->setFixedWidth(160);

	//Set it transparent to mouse events such that you can click and drag when moused over the label
	titleLabel->setAttribute(Qt::WA_TransparentForMouseEvents);

	//Create spacer widgets to keep the title centered
	QWidget* rightSpacer = new QWidget(toolBar);

	//Set them transparent to mouse events + auto-expanding in size
	rightSpacer->setAttribute(Qt::WA_TransparentForMouseEvents);
	rightSpacer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	rightSpacer->setStyleSheet("background-color: none; border: none;");

	//Add spacers & title label
	toolBar->addWidget(titleLabel);
	toolBar->addWidget(rightSpacer);

	//Create the min/max/close buttons
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

	//An actual app should use icons for the buttons instead of text
	//and style the different button states / widget margins in css

#endif

}
