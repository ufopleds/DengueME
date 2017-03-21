#ifndef VARIABLESFIELD_H
#define VARIABLESFIELD_H

#include <QWidget>

namespace Ui {
class VariablesField;
}

class VariablesField : public QWidget
{
    Q_OBJECT

public:
    explicit VariablesField(QWidget *parent = 0);
    ~VariablesField();

private:
    Ui::VariablesField *ui;
};

#endif // VARIABLESFIELD_H
