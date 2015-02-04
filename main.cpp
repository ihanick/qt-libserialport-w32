#include <QCoreApplication>
#include <QDebug>
#include <QTextCodec>
#include <stdio.h>

#include "libserialport.h"

void enum_all_ports() {
    enum sp_return ret;
    struct sp_port **port, **port_list, *myport = NULL;

    qDebug() << "Enum start";

    if ( (ret = sp_list_ports(&port_list) ) != SP_OK) {
        int code = sp_last_error_code();
        char * msg = sp_last_error_message();
        QString DataAsString = QString::fromUtf16((const ushort*)msg);
        qDebug() << DataAsString;
        sp_free_error_message(msg);
        return;
    }

    for(port = port_list; port != NULL && *port != NULL; ++port) {
        char *name, *desc, *tran_str;
        enum sp_transport tran;

        if ( (name = sp_get_port_name(*port)) == NULL)
            name = "";

        if ((desc = sp_get_port_description(*port) ) == NULL)
            desc = "";

        tran = sp_get_port_transport(*port);
        if (tran == SP_TRANSPORT_USB && myport == NULL)
            sp_copy_port(*port, &myport);
        switch (tran) {
        case SP_TRANSPORT_NATIVE:
            tran_str = "native";
            break;
        case SP_TRANSPORT_USB:
            tran_str = "usb";
            break;
        case SP_TRANSPORT_BLUETOOTH:
            tran_str = "bt";
            break;
        default:
            tran_str = "unk";
        }

        qDebug() << name << " " << desc << tran_str;
    }
    qDebug() << "Enum end";
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    enum_all_ports();

    return a.exec();
}
