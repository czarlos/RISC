#ifndef RISCVIEW_H
#define RISCVIEW_H

#include <QtWidgets/QMainWindow>
#include "ui_RiscView.h"

class RiscView : public QMainWindow
{
	Q_OBJECT

public:
	RiscView(QWidget *parent = 0);
	~RiscView();

private:
	Ui::RiscViewClass ui;
};

#endif // RISCVIEW_H
