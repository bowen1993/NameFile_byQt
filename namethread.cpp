#include "namethread.h"
#include <QStringList>
#include <QVariant>
#include <QDebug>
NameThread::NameThread()
{
    m_dir = new QDir;
    stopped = false;
}

void NameThread::run()
{
    stopped = false;
    while (!stopped)
    {
        QStringList nameList = m_dir->entryList();
        int number = 1;
        //qDebug() << "there" << endl;
        //qDebug() << nameList.length() << endl;
        for (QStringList::const_iterator i= nameList.begin(); i != nameList.end(); i++)
        {
            QVariant n(number);
            //qDebug() << *i << endl;
            if (*i == "." || *i == "..")
            {
                continue;
            }
            if (m_dir->rename(*i, m_mainName + n.toString() + getFileType(*i)))
            {
                //qDebug() << 1 << endl;
            }
            //qDebug() << 2 << endl;
            number++;
        }
        break;
    }
}

void NameThread::setMainName(const QString &mainname)
{
    m_mainName = mainname;
}

void NameThread::setPath(const QString &path)
{
    m_dir->setPath(path);
    //qDebug() << m_dir->path() << endl;
    //qDebug() << m_dir->isReadable() << endl;

}

void NameThread::stop()
{
    stopped = true;
}

void NameThread::setFilter(const QString &filter)
{
    qDebug() << 1 << endl;
    QStringList f;
    QString s;
    for (int i = 0; i < filter.length(); i++)
    {
        if (filter[i] == ' ' )
        {
            f << "*."+s;

            qDebug() << s << endl;
            s = "";
        }
        else
            s += filter[i];
    }
    f << "*." + s;
    qDebug() << s << endl;
    m_dir->setNameFilters(f);
}

QString NameThread::getFileType(const QString &fileName)
{
    QString fileType;
    bool isType = false;
    for (int i = 0; i < fileName.length(); i++)
    {
        if (!isType)
        {
            if (fileName[i] == '.')
            {
                fileType += '.';
                isType = true;
            }
        }
        else
        {
            fileType += fileName[i];
        }
    }
    return fileType;
}

/*bool NameThread::isFile(const QString &fileName)
{
    for (int i = 0; i < fileName.length(); i++)
    {
        if (fileName[i] == '.')
        {
            if (i != fileName.length()-1 && fileName[i+1] )
            return true;
    }
    return false;
}
*/
