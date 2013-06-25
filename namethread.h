#ifndef NAMETHREAD_H
#define NAMETHREAD_H

#include <QThread>
#include <QString>
#include <QDir>
class NameThread : public QThread
{
private:
    QString m_mainName;
    QDir* m_dir;
    volatile bool stopped;

    QString getFileType(const QString& fileName);
    bool isFile(const QString& fileName);
protected:
    void run();
public:
    NameThread();
    void setMainName(const QString& mainname);
    void setPath(const QString& path);
    void stop();
    void setFilter(const QString& filter);
};

#endif // NAMETHREAD_H
