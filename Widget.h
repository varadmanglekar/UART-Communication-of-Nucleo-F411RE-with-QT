#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui
{
class Widget;
}

class QSerialPort;

class Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
private slots:

    void on_ONPushButton_clicked();

    void on_OFFPushButton_clicked();

private:
    Ui::Widget *ui;
    QSerialPort *nucleo;
    static const quint16 nucleo_vendor_id = 9025;
    static const quint16 nucleo_product_id = 67;
    QString nucleo_port_name;
    bool nucleo_is_available;
};

#endif // WIDGET_H
