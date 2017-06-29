#include "Widget.h"
#include "ui_Widget.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QMessageBox>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    nucleo_is_available = false;
    nucleo_port_name = "";
    nucleo = new QSerialPort;


    qDebug() << "Number of available ports: " << QSerialPortInfo::availablePorts().length();
    foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){
        qDebug() << "Has vendor ID: " << serialPortInfo.hasVendorIdentifier();
        if(serialPortInfo.hasVendorIdentifier()){
            qDebug() << "Vendor ID: " << serialPortInfo.vendorIdentifier();
        }
        qDebug() << "Has Product ID: " << serialPortInfo.hasProductIdentifier();
        if(serialPortInfo.hasProductIdentifier()){
            qDebug() << "Product ID: " << serialPortInfo.productIdentifier();
        }
    }


    foreach(const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()){
        if(serialPortInfo.hasVendorIdentifier() && serialPortInfo.hasProductIdentifier()){
            if(serialPortInfo.vendorIdentifier() == nucleo_vendor_id){
                if(serialPortInfo.productIdentifier() == nucleo_product_id){
                    nucleo_port_name = serialPortInfo.portName();
                    nucleo_is_available = true;
                }
            }
        }
    }

    if(nucleo_is_available){
        // open and configure the serialport
        nucleo->setPortName(nucleo_port_name);
        nucleo->open(QSerialPort::WriteOnly);
        nucleo->setBaudRate(QSerialPort::Baud9600);
        nucleo->setDataBits(QSerialPort::Data8);
        nucleo->setParity(QSerialPort::NoParity);
        nucleo->setStopBits(QSerialPort::OneStop);
        nucleo->setFlowControl(QSerialPort::NoFlowControl);
    }else{
        // give error message if not available
        QMessageBox::warning(this, "Port error", "Couldn't find the nucleo!");
    }
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_ONPushButton_clicked()
{
    if(nucleo->isWritable()){
        nucleo->write("1");
    }else{
        qDebug() << "Couldn't write to serial!";
    }
}

void Widget::on_OFFPushButton_clicked()
{
    if(nucleo->isWritable()){
        nucleo->write("0");
    }else{
        qDebug() << "Couldn't write to serial!";
    }
}
