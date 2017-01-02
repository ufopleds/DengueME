#ifndef CHART_H
#define CHART_H

#include <QWidget>

namespace Ui {
class Chart;
}

class Chart : public QWidget
{
    Q_OBJECT

public:
    explicit Chart(QWidget *parent = 0);
    ~Chart();

private:
    Ui::Chart *ui;
};

#endif // CHART_H
