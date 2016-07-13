#ifndef HELPBROWSER_H
#define HELPBROWSER_H

#include <QTextBrowser>
#include <QtHelp/QHelpEngine>

class HelpBrowser: public QTextBrowser {
    Q_OBJECT
public:
    HelpBrowser(QString collectionFile, QWidget *parent);
    void displayHelp(const QString &id);

private:
    QHelpEngineCore *m_helpEngine;

    QVariant loadResource(int type, const QUrl &name);
};

#endif // HELPBROWSER_H
