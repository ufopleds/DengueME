#ifndef VISUALTABLEFIEDL_H
#define VISUALTABLEFIEDL_H

#include <QWidget>

namespace Ui {
class VisualTableFiedl;
}

class VisualTableFiedl : public QWidget
{
    Q_OBJECT

public:
    explicit VisualTableFiedl(QWidget *parent = 0);
    ~VisualTableFiedl();

private:
    Ui::VisualTableFiedl *ui;
};

#endif // VISUALTABLEFIEDL_H
