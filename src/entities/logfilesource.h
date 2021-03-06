#pragma once

#include <QSqlQuery>
#include <QDebug>
#include <QStringList>

class LogFileSource
{
public:
    enum LogFileSourceType {
        LocalType = 1,
        EzPublishServerType
    };

    explicit LogFileSource();

    int getId();
    static LogFileSource fetch(int id);
    static LogFileSource logFileSourceFromQuery(QSqlQuery query);
    bool store();
    friend QDebug operator<<(QDebug dbg, const LogFileSource &logFileSource);
    bool exists();
    bool fillFromQuery(QSqlQuery query);
    bool remove();
    bool isFetched();
    static QList<LogFileSource> fetchAll();
    QString getName();
    int getType();
    QString getLocalPath();
    QString getEzpServerUrl();
    int getPriority();
    QString getEzpUsername();
    QString getEzpPassword(bool decrypt = true);
    void setName(QString text);
    void setLocalPath(QString text);
    void setPriority(int value);
    void setType(int id);
    void setEzpServerUrl(QString text);
    void setEzpUsername(QString text);
    void setEzpPassword(QString text, bool encrypt = true);
    static int countAll();
    void setAsActive();
    bool isActive();
    static int activeLogFileSourceId();
    static LogFileSource activeLogFileSource();
    bool localPathExists();
    bool isEzPublishTypeValid();
    void setAddDownloadedFilePrefix(bool state);
    bool getAddDownloadedFilePrefix();

private:
    int id;
    QString name;
    QString localPath;
    int type;
    QString ezpServerUrl;
    QString ezpUsername;
    QString ezpPassword;
    int priority;
    bool addDownloadedFilePrefix;
};
