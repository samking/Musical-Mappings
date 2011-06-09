#ifndef MAPPINGSINTERFACE_H
#define MAPPINGSINTERFACE_H

#include <QtGui/QMainWindow>
#include <QtGui/QApplication>
#include <string>
using namespace std;

namespace Ui {
    class MappingsInterface;
}

class MappingsInterface : public QMainWindow
{
    Q_OBJECT

public:
    explicit MappingsInterface(QWidget *parent = 0);
    ~MappingsInterface();
	string GetBoxText(string note);

private:
    Ui::MappingsInterface *ui;
};

#endif // MAPPINGSINTERFACE_H
