#include "helpbrowser.h"

#include <QLibraryInfo>

HelpBrowser::HelpBrowser(QString collectionFile, QWidget *parent)
    : QTextBrowser(parent)
{
    m_helpEngine = new QHelpEngineCore(collectionFile, this);
    if (!m_helpEngine->setupData()) {
        delete m_helpEngine;
        m_helpEngine = NULL;
    }
}

void HelpBrowser::displayHelp(const QString &id) {
    if (m_helpEngine) {
        QMap<QString, QUrl> links = m_helpEngine->linksForIdentifier(id);
        if (!links.isEmpty())
            setSource(links.values().first());
    }
}

QVariant HelpBrowser::loadResource(int type, const QUrl &name) {
    if (name.scheme() == "qthelp")
        return m_helpEngine->fileData(name);
    else
        return QTextBrowser::loadResource(type, name);
}
