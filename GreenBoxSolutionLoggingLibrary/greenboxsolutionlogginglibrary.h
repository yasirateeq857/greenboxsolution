#ifndef GREENBOXSOLUTIONLOGGINGLIBRARY_H
#define GREENBOXSOLUTIONLOGGINGLIBRARY_H

#include "greenboxsolutionlogginglibrarydefines.h"
#include <QString>
#include <QFile>
#include <QMutex>

class GreenBoxSolutionLoggingLibrary
{

private:
    static GreenBoxSolutionLoggingLibrary* mInstance;
    QFile mLogFile;

    // Hide Default Constructor
    GreenBoxSolutionLoggingLibrary();

    // Hide Copy Constructor
    GreenBoxSolutionLoggingLibrary(const GreenBoxSolutionLoggingLibrary&);
    \
    // Hide Assign Up
    GreenBoxSolutionLoggingLibrary& operator = (const GreenBoxSolutionLoggingLibrary&);


public:
    static GreenBoxSolutionLoggingLibrary* Instance();
    void AddToLogFile(LOGMSG_TYPE logType, QString logMsg);


};





#endif // GREENBOXSOLUTIONLOGGINGLIBRARY_H
