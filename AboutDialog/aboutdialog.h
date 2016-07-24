#ifndef ABOUTDIALOG_H
#define ABOUTDIALOG_H

#include <QDialog>
#include "ui_aboutdialog.h"

class AboutDialog : public QDialog{
	Q_OBJECT
public:
	explicit AboutDialog(QWidget *parent = 0):
		QDialog(parent),
		ui(new Ui::AboutDialog)
	{
		ui->setupUi(this);
		resize(0, 0);
		setFixedSize(size());
	}

	~AboutDialog(){delete ui;}

private:
	Ui::AboutDialog *ui;

};

#endif // ABOUTDIALOG_H
