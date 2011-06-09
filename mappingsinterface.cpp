#include "mappingsinterface.h"
#include "ui_mappingsinterface.h"


MappingsInterface::MappingsInterface(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MappingsInterface)
{
    ui->setupUi(this);
}

MappingsInterface::~MappingsInterface()
{
    delete ui;
}

string MappingsInterface::GetBoxText(string note) 
{
	string boxName = note + "_input";
	QString qBoxName(boxName.c_str());
	QLineEdit* box = this->findChild<QLineEdit*>(qBoxName);
	return box->text().toStdString();
}