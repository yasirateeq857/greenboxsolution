#include "greenboxsolutionlogginglibrary.h"

#include <QDebug>
#include <QDateTime>



GreenBoxSolutionLoggingLibrary* GreenBoxSolutionLoggingLibrary::mInstance = 0;

GreenBoxSolutionLoggingLibrary::GreenBoxSolutionLoggingLibrary()
{
    mLogFile.setFileName("");
}

GreenBoxSolutionLoggingLibrary* GreenBoxSolutionLoggingLibrary::Instance()
{
    if(mInstance == 0)
    {
        mInstance = new GreenBoxSolutionLoggingLibrary();
    }

    return mInstance;
}

void GreenBoxSolutionLoggingLibrary::AddToLogFile(LOGMSG_TYPE logType, QString logMsg)
{
    QString logFileName = "";


    switch(logType)
    {
    case APPLICATION:
        logFileName = "GreenBoxAppLog.txt";
        break;

    case FIRMWARE:
        logFileName = "GreenBoxFwmLog.txt";
        break;
    }


    mLogFile.setFileName(logFileName);
    mLogFile.open(QIODevice::Append);


        if(mLogFile.size() > 0)
        {
            QString comma  = ",";
            mLogFile.write(comma.toLatin1());  //YA correction req
        }
       mLogFile.write(QString("\r\n").toLatin1()); //YA correction req


    mLogFile.write(logMsg.toLatin1());  //YA correction req

    mLogFile.close();
//    qDebug() << logMsg;
    //fflush(stderr);
}


