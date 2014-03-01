#ifndef RISCVIEW_H
#define RISCVIEW_H

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
