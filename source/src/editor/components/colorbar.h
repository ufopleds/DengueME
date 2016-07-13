#ifndef COLORBAR_H
#define COLORBAR_H

#include <QtGui>

namespace Ui {
class ColorBar;
}

class ColorBar : public QDialog
{
    Q_OBJECT
    
public:
    explicit ColorBar(QWidget *parent = 0);
    QString color;
    ~ColorBar();
    
public slots:
    void selectColor();
    void insert();
    void closeDialog();

signals:
    void valueChanged(const QString&);

private slots:
    void on_pushButton_OK_clicked();
    void delItem();
    void enableDelButton();

private:
    Ui::ColorBar *ui;
};

#endif // COLORBAR_H
